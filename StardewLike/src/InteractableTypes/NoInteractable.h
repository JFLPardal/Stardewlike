#pragma once
#include "IInteractable.h"

/*
	Empty IInteractble is used when the player is interacting
	with a tile that has no other interactable and defines what
	items can interact with an empty tile.
*/

class NoInteractable : public IInteractable
{
public:
	NoInteractable(Vector2i aGridPosition);
	NoInteractable(int aGridPositionX, int aGridPositionY);
	~NoInteractable() {	printf("destroyed NoInteractable.\n"); }

	InteractableType GetInteractableType() const { return m_type; }
protected:
	virtual void PopulateInteractables() override;
private:
	Vector2i m_gridPosition;
	void InteractWithSeed(GameObject* aSeedToInteractWith, GameObjectGridMap& aGridMap);
};