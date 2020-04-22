#pragma once

/*
	Component is responsible for defining the base behaviours a Component should have, as well has a reference to its owner 'GameObject'.
	This is the base class for all the components on the engine.
*/

class GameObject;

class Component
{
public:
	Component();
	virtual ~Component() { printf(" ^^^^^ destroyed Component ^^^^^\n"); };

	virtual void Start();
	virtual void Update() = 0;
	void SetOwner(GameObject& aOwner);
protected:
	GameObject* m_owner{nullptr};
};