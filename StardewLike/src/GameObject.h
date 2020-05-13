#pragma once
#include "Components/Component.h"
#include "Components/SpriteRenderer.h"
#include "StateMachine/StateMachine.h"
#include "GameObjectData/GameObjectData.h"
#include "Constants.h"

/*
	GameObject is the class that represents any entity on the game.
	It consists in a collection of 'Component's that make up this GO, as well as some functionality like
	adding and removing components from a GO.

	When a GO is created, Transform is automatically added to it.
*/

class IInteractable;
class StateMachine;

typedef unsigned int ComponentTypeId;

inline ComponentTypeId GetNextTypeId() noexcept
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
	explicit GameObject(std::unique_ptr<GameObjectData> aGOdata, std::unique_ptr<StateMachine> aStateMachine, int aInitialX = DEFAULT_POS_X, int aInitialY = DEFAULT_POS_Y) noexcept;
	explicit GameObject(std::unique_ptr<GameObjectData> aGOdata, std::unique_ptr<StateMachine> aStateMachine, sf::Vector2i aGridPosition) noexcept;
	explicit GameObject(sf::Vector2i aGridPosition) noexcept;

	friend bool operator==(const GameObject& aGO1, const GameObject& aGO2) { return aGO1.m_ID == aGO2.m_ID; }

	~GameObject();

	void Start();
	void Update();

	inline bool IsDrawable() const noexcept		{ return m_renderer != nullptr; }
	sf::Drawable& GetRenderer() const noexcept	{ return static_cast<sf::Drawable&>(*m_renderer); }
	IInteractable* GetInteractable() const		{ return m_interactable; }
	StateMachine* GetStateMachine() const		{ return m_stateMachine.get(); }
	GameObjectData* GetData() const				{ return m_data.get(); }

	template <typename T, typename... TArgs>
	T* AddComponent(TArgs&&... args)
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");
		assert(GetComponent<T>() == nullptr && "GameObject can't have 2 instances of the same Component");

		m_componentTypeIdList.push_back(std::move(GetTypeId<T>()));

		std::unique_ptr<Component> newComponent = std::make_unique<T>(std::forward<TArgs>(args)...);
		newComponent->SetOwner(*this);

		// add it to the component list
		m_componentList.emplace_back(std::move(newComponent));

		return static_cast<T*>(m_componentList.at(m_componentList.size() - 1).get());
	}

	template<typename T>
	T* GetComponent() 
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");

		const unsigned int thisComponentTypeId = GetTypeId<T>();
		size_t index = 0;
		for (const ComponentTypeId& componentTypeId : m_componentTypeIdList)
		{
			if (thisComponentTypeId == componentTypeId)
			{
				Component* ptr(m_componentList.at(index).get());
				return dynamic_cast<T*>(ptr);
			}
			index++;
		}
		return nullptr;
	}


private:
	void RemoveAllComponents();
	
	static unsigned int m_nextID;
	unsigned int m_ID;
	std::unique_ptr<StateMachine> m_stateMachine;
	std::unique_ptr<GameObjectData> m_data;
	SpriteRenderer* m_renderer{ nullptr };
	IInteractable* m_interactable{ nullptr };
	std::vector<ComponentTypeId> m_componentTypeIdList;
	std::vector<std::unique_ptr<Component>> m_componentList; // TODO encapsulate this in a IComponentList - not that easy because it is being used in template functions
};