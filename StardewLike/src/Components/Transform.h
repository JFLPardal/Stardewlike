#pragma once
#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	virtual void Update() override;

	int X() const { return m_x; }
private:
	int m_x = 43;
};