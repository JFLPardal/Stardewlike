#pragma once
#include "Component.h"

/*
	InteractWithWorld is responsible for the attempt of the player to interact with the world
	and will be responsible	for passing down that interaction attempt to the correct tile.
*/

class WindowEventHandler;

class InteractWithWorld : public Component
{
public:
	InteractWithWorld(WindowEventHandler* aWindowEventHandler);
	~InteractWithWorld();

	void Start() override;
private:
	void Interact(int aScreenCoordsX, int aScreenCoordsY);

	WindowEventHandler* m_windowEventHandler{ nullptr };
	EventIndex m_mouseLeftClickedIndex;
};