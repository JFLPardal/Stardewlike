#pragma once
#include "Component.h"
#include "IEvent.h"
#include "Enums.h"

/*
	Orientation is responsible for storing the GO's orientation.
	This represents which of the 4 possible directions this GO is facing.

	The curent implementation is based on the mouse position on the window 
	compared to the player's position, making this the PlayerOrientation and 
	not an overall Orientation. P.e. an enemy should not use this definition
*/

class WindowEventHandler;
class Transform;

typedef IEvent<void(PossibleOrientation)> OrientationChangedEvent;

#define ORIENTATION_CHANGED(callbackFunction) std::function<void(PossibleOrientation)>(std::bind(callbackFunction,this, std::placeholders::_1 ))

class Orientation : public Component
{
public:
	explicit Orientation(WindowEventHandler* aWindow);
	~Orientation();

	std::unique_ptr<OrientationChangedEvent> OnOrientationChangedEvent;

	void Start() override;

	PossibleOrientation GetOrientation() const noexcept { return m_currentOrientation; }
	Vector2i GetOrientationAsGridIncrement() const;
private:
	void UpdateOrientation(int aX, int aY);

	PossibleOrientation m_currentOrientation = PossibleOrientation::up;
	Transform* m_transform{ nullptr };
	WindowEventHandler* m_windowEventHandler{ nullptr };
	EventIndex m_mouseMovedIndex = -2;
};