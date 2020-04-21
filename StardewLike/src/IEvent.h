#pragma once
#include <vector>

/*
	This class is responsible for storing all the callback functions that should be called when a given action of interest (event) 
	happens in the game. This is a (very inefficient )homebrew version of an Observer.

	 TODO very inefficient way of doing the removal, the index is nulled and is not reused, furthermore, 
	 every time a function is added there is a risk of needing to reallocate the vector that holds the callbacks
*/
template <typename FuncSignature>
class IEvent
{
public:
	// ATTENTION: call this function with the event's macro, defined in the header file, of the Component you are trying to use
	int AddCallback(std::function<FuncSignature> aFunctionToAdd)
	{
		printf("function added to the OnInputMove\n");
		m_CallbacksList.emplace_back(aFunctionToAdd);
		return m_CallbacksList.size() - 1; // risky, if the RemoveObserver function deletes the item instead of just = nullptr, this can be a problem
	}

	void RemoveCallback(int aIndexToRemove)
	{
		printf("function removed to the OnInputMove\n");
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