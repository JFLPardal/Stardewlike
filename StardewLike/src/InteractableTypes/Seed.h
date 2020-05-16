#pragma once
#include "IInteractable.h"

/*
	Seed defines what Items it can interact with and 
	what that interaction will be
*/

class Seed : public IInteractable
{
public:
	Seed();
	~Seed() { printf("destroyed seed\n"); }

protected:
	void PopulateInteractables() override;
private:
	void InteractWithHoe(GameObject* aObjectOnTileToInteractWith, GameObjectGridMap& aGridMap);
};