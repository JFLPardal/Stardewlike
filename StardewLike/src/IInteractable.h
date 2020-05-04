#pragma once
#include "Components/Component.h"

class GameObject;
class GameObjectGridMap;

// from the point of view of the item being held
// p.e. a seed being held can interact with an empty(soilable) tile
enum InteractableType
{
	notDefined = -1,
	empty,
	seed
};

class IInteractable : public Component
{
public:
	virtual void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) = 0;
	InteractableType GetInteractableType() const { return m_type; }
protected:
	virtual void PopulateInteractables() = 0;
	std::vector<std::pair<InteractableType, std::function<void(GameObject*, GameObjectGridMap&)>>> m_interactableTypes;
	InteractableType m_type = notDefined;
};