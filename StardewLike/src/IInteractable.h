#pragma once
#include "Enums.h"
#include "Components/Component.h"
/*
	IInteractable is responsible for defining the functions
	that all Interactable entities in the game should implement.
	
	An IInteractable is something that the player can interact 
	(perform some action up) with.
*/

class GameObject;
class GameObjectGridMap;

enum class InteractableType
{
	notDefined = -1,
	noInteractable,
	seed,
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
	std::vector<std::pair<ItemType, InteractionFuncToCall>> m_interactionWithItems;
	InteractableType m_type = InteractableType::notDefined;
};