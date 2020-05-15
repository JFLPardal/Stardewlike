#include "pch.h"
#include "Hoe.h"

#include "GameObject.h"
#include "MapRepresentation/GameObjectGridMap.h"
#include "Components/Transform.h"

Hoe::Hoe()
{
	m_type = InteractableType::hoe;
	PopulateInteractables();
}

void Hoe::InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap)
{
	if (aObjectToInteractWith->GetInteractable() == nullptr)
	{
		printf("no object on tile hoooooooe\n");
	}/*
	else
	{
		printf("object on tile: ");
		const auto otherGOinteractableType = aObjectToInteractWith->GetInteractable()->GetInteractableType();
		for (auto& interactableType : m_interactableTypes)
		{
			if (interactableType.first == otherGOinteractableType)
				interactableType.second(aObjectToInteractWith, aGridMap);
		}
	}*/
}

void Hoe::PopulateInteractables()
{/**
	std::pair<InteractableType, InteractionFuncToCall> seed (seed, FUNC_TO_CALLBACK(&Hoe::InteractWithSeed));
	m_interactableTypes.emplace_back(seed);
	printf("populate hoe\n");*/
}

void Hoe::InteractWithSeed(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap)
{/*
	auto seedGridPos = aObjectToInteractWith->GetComponent<Transform>()->GetPositionInGrid();
	aGridMap.RemoveFromGrid(seedGridPos);*/
}
