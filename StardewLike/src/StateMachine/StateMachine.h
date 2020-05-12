#pragma once
#include "IEvent.h"
#include "Enums.h"
/*
	StateMachine is responsible for calculating the transitions between the different
	states that a GameObject can have.
	This class also has an Event that is triggered every time the GO changes its state.
*/

class GameObject;
class GameObjectData;

typedef IEvent<void(State)> StateChangeEvent;

#define ON_STATE_CHANGE(callbackFunction) std::function<void(State)>(std::bind(callbackFunction, this, std::placeholders::_1))

class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine() = default; 

	virtual void Start(GameObject* aOwner);

	State CurrentState() const { return m_currentState; }

	std::unique_ptr<StateChangeEvent> OnStateChangeEvent;
protected:
	GameObject* m_owner;
	GameObjectData* m_data;
	State m_currentState = idle;
};