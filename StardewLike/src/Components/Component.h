#pragma once

/*
	Component is responsible for defining the base behaviours a Component should have, as well has a reference to its owner 'GameObject'.
	This is the base class for all the components on the engine.
*/

typedef size_t EventIndex;

class GameObject;

class Component
{
public:
	virtual ~Component() { printf("^destroyed component^\n"); }

	virtual void Start() {};
	virtual void Update() {};
	void SetOwner(GameObject& aOwner) noexcept;
protected:
	Component() noexcept;

	GameObject* m_owner{ nullptr };
};