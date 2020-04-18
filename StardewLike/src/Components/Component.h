#pragma once
#include <memory>

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
	GameObject* m_owner;
private:
};