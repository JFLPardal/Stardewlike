#pragma once
#include "Component.h"
#include <vector>
#include <functional>

// 0. Add SpriteRenderer's functions to the list of callbacks		DONE
// 1. Make sure it I can remove functions from the observer list
//    Make sure remove is being called on destructor
// 2. clean up the signature to add a function
// 3. extract to an Observer class

class Input : public Component
{
public:
	~Input();
	void Update() override;
	
	size_t OnMoveKeyPressedRegister(std::function<void(short, short)> functionToCall)
	{
		if (functionToCall != nullptr)
		{
			printf("function added to the OnInputMove\n");
			m_OnMoveKeyPressedCallbacks.emplace_back(functionToCall);
			return m_OnMoveKeyPressedCallbacks.size() - 1; // risky, if the RemoveObserver function deletes the item instead of just = nullptr, this can be a problem
		}
		return -1; // TODO change for exception?
	}
	
	void OnMoveKeyPressedUnregister(size_t aIndex)
	{
		printf("function removed to the OnInputMove\n");
		m_OnMoveKeyPressedCallbacks[aIndex] = nullptr;
	}
private:
	void OnInputMove(short x, short y);

	std::vector<std::function<void(short,short)>> m_OnMoveKeyPressedCallbacks;
};
