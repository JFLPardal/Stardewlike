#pragma once

/*
	This class is responsible for storing all the callback functions that should be called when a given action of interest (Event) 
	happens in the game. This is a (very inefficient) homebrew version of an Observer.

	To add a new Event (trigger side):

		* create a  class that has this one as a pointer member variable with the signature of the callback as the template; 
			p.e. std::unique_ptr<IEvent<void(short,short)>> OnMovementKeyPressedEvent;

		* on the new class define the macro that encapsulates the callback's signature; 
			p.e. #define MOVEMENT_KEY_PRESSED(callbackFunction) std::function<void(short, short)>(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))

	To add a new Observer:

		* on the class that has the function that should be called when an event happens, define a 'EventIndex' member variable that will hold an index;
			p.e. EventIndex m_moveKeyPressedIndex;

		* in the 'Start' function of the component class initialize the EventIndex by calling 'AddCallback' to the 'Component' that has the event of interest
			p.e. m_moveKeyPressedIndex = m_owner->GetComponent<Input>()->OnMovementKeyPressedEvent->AddCallback(MOVEMENT_KEY_PRESSED(&Transform::UpdateMovement));

		* in the destructor of the component call 'RemoveCallback' on the same function that was previously registered, with the 'EventIndex' as the arg
			p.e. m_owner->GetComponent<Input>()->OnMovementKeyPressedEvent->RemoveCallback(m_moveKeyPressedIndex);

	 TODO very inefficient way of doing the removal, the index is nulled and is not reused, furthermore, 
	 every time a function is added there is a risk of needing to reallocate the vector that holds the callbacks
*/
typedef size_t EventIndex;

template <typename FuncSignature>
class IEvent
{
public:
	// ATTENTION: call this function with the event's macro, defined in the header file, of the Component you are trying to use
	EventIndex AddCallback(std::function<FuncSignature> aFunctionToAdd)
	{
		printf("function added to event\n");
		m_CallbacksList.emplace_back(aFunctionToAdd);
		return m_CallbacksList.size() - 1; // risky, if the RemoveObserver function deletes the item instead of just = nullptr, this can be a problem
	}

	void RemoveCallback(int aIndexToRemove)
	{
		printf("function removed from event\n");
		m_CallbacksList[aIndexToRemove] = nullptr;
	}

	template <typename... FuncArgs>
	void TriggerEvent(FuncArgs... aCallbackArgs)
	{
		for(auto callback : m_CallbacksList)
		{
			if(callback) callback(std::forward<FuncArgs>(aCallbackArgs)...);
		}
	}

private:
	std::vector<std::function<FuncSignature>> m_CallbacksList;
};