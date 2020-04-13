#pragma once
#include <memory>
//#include "..\GameObject.h"

class Component
{
public:
	//void SetOwner(const GameObject& aOwner)	{ m_owner = std::make_unique<GameObject>(aOwner); }
	Component();
	virtual ~Component() {};
	virtual void Update() = 0;
private:
	//std::unique_ptr<GameObject> m_owner;
};