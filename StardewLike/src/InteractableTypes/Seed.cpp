#include "pch.h"
#include "Seed.h"

#include "GameObject.h"
#include "Components/Transform.h"
#include "MapRepresentation/GameObjectGridMap.h"

Seed::Seed()
{
	m_type = InteractableType::seed;
	PopulateInteractables();
}

void Seed::PopulateInteractables()
{
	std::pair<ItemType, InteractionFuncToCall> hoe (ItemType::hoe, FUNC_TO_CALLBACK(&Seed::InteractWithHoe));
	m_interactionWithItems.emplace_back(hoe);
}

void Seed::InteractWithHoe(GameObject* aObject, GameObjectGridMap& aGridMap)
{
	printf("hoe\n");
	aGridMap.RemoveFromGrid(m_owner->GetGridPosition());
}
