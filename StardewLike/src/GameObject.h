#pragma once
#include "Components/Component.h"
#include "Components/SpriteRenderer.h"

/*
	GameObject is the class that represents any entity on the game.
	It consists in a collection of 'Component's that make up this GO, as well as some functionality like 
	adding and removing components from a GO.
*/

typedef unsigned int ComponentTypeId;

inline ComponentTypeId GetNextTypeId()
{
	static ComponentTypeId componentTypeId = 0;
	return componentTypeId++;
}

template <typename T>
inline ComponentTypeId GetTypeId()
{
	static ComponentTypeId m_currentTypeId = GetNextTypeId();

	if (DEBUG)
		printf("getting typeId for %s: %d\n", typeid(T).name(), m_currentTypeId);

	return m_currentTypeId;
}

class GameObject
{
public:
	~GameObject();
	
	void Start();
	void Update();
	//void Draw();

	inline bool IsDrawable() const { return m_renderer != nullptr; }
	sf::Drawable& GetRenderer() const { return static_cast<sf::Drawable&>(*m_renderer); }

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)	// TODO same component can be added twice to the same object
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");
		
		m_componentTypeIdList.push_back(std::move(GetTypeId<T>()));

		// instantiate the component
		T* newComponent(new T(std::forward<TArgs>(args)...));
		newComponent->SetOwner(*this);
		std::unique_ptr<Component> newComponentPtr { newComponent };
		
		// add it to the component list
		m_componentList.emplace_back(std::move(newComponentPtr));
		return *newComponent;
	}

	template<typename T>
	T* GetComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");
		unsigned int thisComponentTypeId = GetTypeId<T>();
		for (ComponentTypeId& componentTypeId : m_componentTypeIdList)
		{
			if (thisComponentTypeId == componentTypeId) 
			{
				auto ptr(m_componentList[thisComponentTypeId].get());
				return static_cast<T*>(ptr);
			}
		}
		return nullptr;
	}


private:
	SpriteRenderer* m_renderer = nullptr;
	std::vector<std::unique_ptr<Component>> m_componentList; // TODO encapsulate this in a IComponentList
	std::vector<ComponentTypeId> m_componentTypeIdList; // this is being deleted before all the components can be unregistered
};