#pragma once
#include "IInteractable.h"
#include "IEvent.h"

/*
	Bed is the interactable that will bring the day to an end
	when the player interacts with it.
*/

typedef IEvent<void()> DayOverEvent;

#define DAY_OVER(callbackFunction) std::function<void()>(std::bind(callbackFunction, this))

class Bed : public IInteractable
{
public:
	std::unique_ptr<DayOverEvent> m_OnDayOverEvent{ nullptr };

	Bed();
	~Bed() { printf("bed destroyed\n"); }

	virtual void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) override;
protected:
	virtual void PopulateInteractables() override; 
private:
	void InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap);
};