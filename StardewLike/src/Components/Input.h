#pragma once
#include "Component.h"
#include <functional>
#include <memory>

#include "../IEvent.h"

// 0. Add SpriteRenderer's functions to the list of callbacks		DONE
// 1. Make sure it I can remove functions from the observer list	DONE (poorly)
//    Make sure remove is being called on destructor
// 2. clean up the signature to add a function
// 3. extract to an Observer class									DONE
	
class Input : public Component
{
public:
	Input();
	~Input();
	void Update() override;
	
	size_t OnMoveKeyPressedRegister(std::function<void(short, short)> functionToCall);
	void OnMoveKeyPressedUnregister(size_t aIndex);

private:
	std::unique_ptr<IEvent<void(short,short)>> OnInputMoveEvent;
};
