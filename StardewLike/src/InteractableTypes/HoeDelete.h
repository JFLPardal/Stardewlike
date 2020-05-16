#pragma once
#include "IInteractable.h"

/*
	HoeDelete is one of the tools on the game. 
	It only interacts with a tile if on that tile there is a Seed, in which case it destroys it.
*/

class HoeDelete : public IInteractable
{
public:
	HoeDelete();
	~HoeDelete() { printf("destroyed hoe\n"); }

	void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) override;
protected:
	void PopulateInteractables() override;
private:
	void InteractWithSeed(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap);
};