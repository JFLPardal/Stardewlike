#pragma once
#include "Components/Component.h"

/*
	IInteractable is responsible for defining the functions
	that all Interactable entities in the game should implement.
	
	An IInteractable is something that the player can interact 
	(perform some action up) with.
*/

class GameObject;
class GameObjectGridMap;

// from the point of view of the item being held
// p.e. a seed being held can interact with an empty(soilable) tile
enum InteractableType
{
	notDefined = -1,
	empty,
	seed,
	hoe
};

typedef std::function<void(GameObject*, GameObjectGridMap&)> InteractionFuncToCall;

#define FUNC_TO_CALLBACK(callbackFunction) InteractionFuncToCall(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))

class IInteractable : public Component
{
public:
	virtual ~IInteractable() {};

	virtual void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap) = 0;
	InteractableType GetInteractableType() const { return m_type; }
protected:
	virtual void PopulateInteractables() = 0;
	std::vector<std::pair<InteractableType, InteractionFuncToCall>> m_interactableTypes;
	InteractableType m_type = notDefined;
};