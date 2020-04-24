#pragma once
#include "Component.h"

enum PossibleOrientation : short 
{
	up, right, down, left
};

class Orientation : public Component
{
public:
	void Update() override;

	PossibleOrientation GetOrientation() const;
private:
	PossibleOrientation m_currentOrientation = up;
};