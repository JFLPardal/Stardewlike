#pragma once
#include "Component.h"
#include <vector>
#include <functional>

class Input : public Component
{
public:
	void Update() override;

	void OnInputMoveAddObserver(std::function<void(short, short)> functionToCall)
	{
		if (functionToCall != nullptr)

		{
			printf("function added to the OnInputMove\n");
			e_onInputMove.emplace_back(functionToCall);
		}
	}
	
	// TODO last argument of remove is probably wrong
	void OnInputMoveRemoveObserver(std::function<void(short, short)> functionToCall)
	{
		printf("function removed to the OnInputMove\n");
		std::remove(e_onInputMove.begin(), e_onInputMove.end(), functionToCall);
	}
	
	std::vector<std::function<void(short,short)>> e_onInputMove;
private:
	void OnInputMove(short x, short y);

};
