#include "pch.h"
#include "NoInteractable.h"

#include "GameObject.h"
#include "MapRepresentation/GameObjectGridMap.h"

#include "Seed.h"
#include "StateMachine/SeedStateMachine.h"
#include "GameObjectData/SeedData.h"
#include "Components/Animator.h"

NoInteractable::NoInteractable(Vector2i aGridPosition)
	: m_gridPosition(aGridPosition)
{
	m_type = InteractableType::noInteractable;
	PopulateInteractables();
}

NoInteractable::NoInteractable(int aGridPositionX, int aGridPositionY)
	: NoInteractable(Vector2i(aGridPositionX, aGridPositionY))
{}

void NoInteractable::PopulateInteractables()
{
	std::pair<ItemType, InteractionFuncToCall> seedPack (ItemType::seedPack, FUNC_TO_CALLBACK(&NoInteractable::InteractWithSeedPack));
	m_interactionWithItems.emplace_back(seedPack);
}

void NoInteractable::InteractWithSeedPack(GameObject* aSeedToInteractWith, GameObjectGridMap& aGridMap)
{
	printf("no interactable, creating seed from seedPack.\n");
	std::shared_ptr<GameObject> seed = std::make_shared<GameObject>(std::make_unique<SeedData>(),
																	std::make_unique<SeedStateMachine>(),
																	m_gridPosition.GetVector());
	seed->AddComponent<SpriteRenderer>("assets\\purple_cabbage.png");
	seed->AddComponent<Animator>();
	seed->AddComponent<Seed>();
	seed->Start();

	aGridMap.AddToGrid(seed, m_gridPosition.GetVector());
}
