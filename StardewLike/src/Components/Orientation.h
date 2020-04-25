#pragma once
#include "Component.h"
#include "IEvent.h"

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

	PossibleOrientation GetOrientation() const;
private:
	void UpdateOrientation(int aX, int aY);

	PossibleOrientation m_currentOrientation = up;
	Transform* m_transform{ nullptr };
	WindowEventHandler* m_windowEventHandler{ nullptr };
	EventIndex m_eMouseMovementIndex;
};