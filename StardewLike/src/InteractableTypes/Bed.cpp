#include "pch.h"
#include "Bed.h"

#include "GameObject.h"

Bed::Bed()
{
	m_type = InteractableType::bed;
	PopulateInteractables();
}

void Bed::PopulateInteractables()
{
	// TODO  this pair is used just for testing, change it 
	std::pair<ItemType, InteractionFuncToCall> empty(ItemType::hoe, FUNC_TO_CALLBACK(&Bed::InteractWithEmpty));
	m_interactionWithItems.emplace_back(empty);
}

void Bed::InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap)
{
	InteractWithEmpty(aObjectToInteractWith, aGridMap);
}

void Bed::InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap)
{
	printf("bed interacted with empty");
}
