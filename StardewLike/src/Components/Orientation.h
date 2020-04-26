#pragma once
#include "Component.h"
#include "IEvent.h"

/*
	Orientation is responsible for storing the GO's orientation.
	This represents which of the 4 possible directions this GO is facing.

	The curent implementation is based on the mouse position on the window 
	compared to the player's position, making this the PlayerOrientation and 
	not an overall Orientation. P.e. an enemy should not use this definition
*/

class WindowEventHandler;
class Transform;

enum PossibleOrientation : short 
{
	up, right, down, left
};

class Orientation : public IComponent
{
public:
	explicit Orientation(WindowEventHandler* aWindow);
	~Orientation();

	void Start() override;
	void Update() override;

	PossibleOrientation GetOrientation() const { return m_currentOrientation; }
private:
	void UpdateOrientation(int aX, int aY);

	PossibleOrientation m_currentOrientation = up;
	Transform* m_transform{ nullptr };
	WindowEventHandler* m_windowEventHandler{ nullptr };
	EventIndex m_mouseMovedIndex;
};