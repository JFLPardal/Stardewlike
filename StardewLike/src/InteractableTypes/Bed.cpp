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
	std::pair<InteractableType, InteractionFuncToCall> empty(hoe, FUNC_TO_CALLBACK(&Bed::InteractWithEmpty));
	m_interactableTypes.emplace_back(empty);
}

void Bed::InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap)
{
	InteractWithEmpty(aObjectToInteractWith, aGridMap);
}

void Bed::InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap)
{
	printf("bed interacted with empty");
}
