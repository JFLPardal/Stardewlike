#pragma once
#include "Components/Component.h"
#include "Components/SpriteRenderer.h"

/*
	GameObject is the class that represents any entity on the game.
	It consists in a collection of 'Component's that make up this GO, as well as some functionality like 
	adding and removing components from a GO.

	When a GO is created, Transform is automatically added to it.
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
	GameObject(int aInitialX = 100, int aInitialY = 100);
	~GameObject();
	
	void Start();
	void Update();

	inline bool IsDrawable() const { return m_renderer != nullptr; }
	sf::Drawable& GetRenderer() const { return static_cast<sf::Drawable&>(*m_renderer); }

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");
		assert(GetComponent<T>() == nullptr && "GameObject can't have 2 instances of the same Component");

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
				Component* ptr(m_componentList[thisComponentTypeId].get());
				return static_cast<T*>(ptr);
			}
		}
		return nullptr;
	}

private:
	SpriteRenderer* m_renderer = nullptr;
	std::vector<ComponentTypeId> m_componentTypeIdList;
	std::vector<std::unique_ptr<Component>> m_componentList; // TODO encapsulate this in a IComponentList - not that easy because it is being used in template functions
};