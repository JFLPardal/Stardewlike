#pragma once
#include "IInteractable.h"

class Hoe : public IInteractable
{
public:
	Hoe();
	~Hoe() { printf("destroyed hoe\n"); }

	void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) override;
protected:
	void PopulateInteractables() override;
private:
	void InteractWithSeed(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap);
};