#pragma once
#include "IInteractable.h"

/*
	Seed is one of the interactable entities in the game
	If the player is holding a Seed and he interacts
	with an empty tile, the Seed gets planted, otherwise, 
	nothing happens.
*/

class Seed : public IInteractable
{
public:
	Seed();
	~Seed() { printf("destroyed seed\n"); }

	void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) override;
protected:
	void PopulateInteractables() override;
private:
	void InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap);
	void InteractWithSeed(GameObject* aObject, GameObjectGridMap& aGridMap);
};