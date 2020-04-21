#pragma once
#include "Component.h"
#include <functional>
#include <memory>

#include "../IEvent.h"

// 0. Add SpriteRenderer's functions to the list of callbacks			DONE
// 1. Make sure it I can remove functions from the observer list		DONE (poorly)
//    Make sure remove is being called on destructor
// 2. clean up the signature to add a function							DONE
// 3. extract to an Observer class										DONE
// 4. remove m_owener from the GetComponent call
// 5. look at the scalability of events from the callee's perspective

#define MOVE_KEY_PRESSED(callbackFunction) std::function<void(short, short)>(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))

class Input : public Component
{
public:
	Input();
	~Input();

	void Update() override;

	std::unique_ptr<IEvent<void(short,short)>> OnInputMoveEvent;
};
