#pragma once
#include "IInteractable.h"

class Seed : public IInteractable
{
public:
	Seed();
	~Seed() { printf("destroyed seed\n"); }

	void PopulateInteractables() override;
	void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) override;
	void InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap);
private:
	GameObject* m_seed{ nullptr };
};