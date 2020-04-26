#pragma once

/*
	IComponent is responsible for defining the base behaviours a Component should have, as well has a reference to its owner 'GameObject'.
	This is the base class for all the components on the engine.
*/
typedef size_t EventIndex;

class GameObject;

class IComponent
{
public:
	IComponent();
	virtual ~IComponent() { printf("^destroyed IComponent^\n"); }

	virtual void Start() {};
	virtual void Update() = 0;
	void SetOwner(GameObject& aOwner);
protected:
	GameObject* m_owner{nullptr};
};