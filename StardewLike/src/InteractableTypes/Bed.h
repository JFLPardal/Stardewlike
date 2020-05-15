#pragma once
#include "IInteractable.h"

/*
	Bed is the interactable that will bring the day to an end
	when the player interacts with it.
*/

class Bed : public IInteractable
{
public:
	Bed();
	~Bed() { printf("bed destroyed\n"); }

	virtual void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) override;
protected:
	virtual void PopulateInteractables() override; 
private:
	void InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap);
};