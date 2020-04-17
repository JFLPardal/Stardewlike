#pragma once
#include "Component.h"
#include <vector>
#include <functional>

// 0. Add SpriteRenderer's functions to the list of callbacks		DONE
// 1. Make sure it I can remove functions from the observer list
// 2. clean up the signature to add a function
// 3. extract to an Observer class

class Input : public Component
{
public:
	void Update() override;

	int OnInputMoveAddObserver(std::function<void(short, short)> functionToCall)
	{
		if (functionToCall != nullptr)
		{
			printf("function added to the OnInputMove\n");
			e_onInputMove.emplace_back(functionToCall);
			return e_onInputMove.size() - 1; // risky, if the RemoveObserver function deletes the item instead of just = nullptr, this can be a problem
		}
		return -1; // TODO change for exception?
	}
	
	// TODO last argument of remove is probably wrong
	
	void OnInputMoveRemoveObserver(size_t aIndex)
	{
		printf("function removed to the OnInputMove\n");
		e_onInputMove[aIndex] = nullptr;
	}
	
	std::vector<std::function<void(short,short)>> e_onInputMove;
private:
	void OnInputMove(short x, short y);

};
