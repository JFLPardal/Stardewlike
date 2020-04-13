#pragma once
#include <vector>
#include <memory>
#include "Components/Component.h"
//class Component;


using ComponentTypeId = unsigned int;

ComponentTypeId inline GetNextTypeId()
{
	static ComponentTypeId componentTypeId = -1;
	return componentTypeId++;
}

template <typename T>
inline ComponentTypeId GetTypeId(int s)
{
	static ComponentTypeId m_currentTypeId = GetNextTypeId();
	return m_currentTypeId;
}

class GameObject
{
private:
	std::vector<std::unique_ptr<Component>> m_componentList; // TODO encapsulate this in a IComponentList
public:
	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)	// TODO same component can be added twice to the same object
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");
		// instantiate the component
		T* newComponent(new T(std::forward<TArgs>(args)...));
		//newComponent->SetOwner(*this);
		std::unique_ptr<Component> newComponentPtr { newComponent };
		printf("%d", m_componentList.size());
		
		// add it to the component list
		m_componentList.emplace_back(std::move(newComponentPtr));
		return *newComponent;
	}

	template<typename T>
	T* GetComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "GetComponent must be called on a Component type");
		unsigned int d = GetTypeId<T>(7);
		/*for (auto& component : m_componentList)
		{
			if (d == GetTypeId<*component>()) // this doesn't work
			{*/
				auto ptr(m_componentList[0].get());
				return static_cast<T*>(ptr);
			//}
		//}
		//return nullptr;
	}
};