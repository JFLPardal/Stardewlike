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

// with which interactables is the new interactable going to interact?
// IMPORTANT: if the interactable can be held by the player and it can interact 
// with an empty tile, it should define that behaviour as well, see 'Seed::InteractWithEmpty'
enum InteractableType
{
	notDefined = -1,
	noInteractable,
	seed,
	hoe,
	bed
};

typedef std::function<void(GameObject*, GameObjectGridMap&)> InteractionFuncToCall;

#define FUNC_TO_CALLBACK(callbackFunction) InteractionFuncToCall(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))

class IInteractable : public Component
{
public:
	virtual ~IInteractable() {};

	virtual void InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap);
	InteractableType GetInteractableType() const { return m_type; }
protected:
	virtual void PopulateInteractables() = 0;
	std::vector<std::pair<InteractableType, InteractionFuncToCall>> m_interactableTypes;
	InteractableType m_type = notDefined;
};