#include "pch.h"
#include "Seed.h"

#include "GameObject.h"
#include "Components/Transform.h"
#include "Components/Animator.h"
#include "MapRepresentation/GameObjectGridMap.h"
#include "StateMachine/SeedStateMachine.h"
#include "GameObjectData/SeedData.h"

Seed::Seed()
{
	m_type = InteractableType::seed;
	PopulateInteractables();
}

void Seed::PopulateInteractables()
{
	std::pair<InteractableType, InteractionFuncToCall> empty (empty, FUNC_TO_CALLBACK(&Seed::InteractWithEmpty));
	std::pair<InteractableType, InteractionFuncToCall> seed	 (seed, FUNC_TO_CALLBACK(&Seed::InteractWithSeed));
	m_interactableTypes.emplace_back(empty);
	m_interactableTypes.emplace_back(seed);
}

void Seed::InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap)
{
	if (aObjectToInteractWith->GetInteractable() == nullptr)
	{
		printf("no object on tile\n");
		InteractWithEmpty(aObjectToInteractWith, aGridMap);
	}
	else
	{
		printf("object on tile: ");
		const auto otherGOinteractableType = aObjectToInteractWith->GetInteractable()->GetInteractableType();
		for (auto& interactableType : m_interactableTypes)
		{
			if (interactableType.first == otherGOinteractableType)
				interactableType.second(aObjectToInteractWith, aGridMap);
		}
	}
}

void Seed::InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap)
{
	printf("seed interacting with empty.\n");
	auto positionToAdd = aObject->GetComponent<Transform>()->GetPositionInGrid();

	std::shared_ptr<GameObject> seed = std::make_shared<GameObject>(std::make_unique<SeedData>(), 
																	std::make_unique<SeedStateMachine>(), 
																	positionToAdd);
	seed->AddComponent<SpriteRenderer>("assets\\purple_cabbage.png");
	seed->AddComponent<Animator>();
	seed->AddComponent<Seed>();
	seed->Start();

	aGridMap.AddToGrid(seed, positionToAdd);
}

void Seed::InteractWithSeed(GameObject* aObject, GameObjectGridMap& aGridMap)
{
	printf("seed interacting with seed\n");
}
