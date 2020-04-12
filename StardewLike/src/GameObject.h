#pragma once
#include <vector>
#include <memory>

class Component;

class GameObject
{
private:
	std::vector<std::unique_ptr<Component>> m_componentList; // TODO encapsulate this in a IComponentList
public:
	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)	// TODO same component can be added twice to the same object
	{
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
	void GetComponent()
	{

	}
};