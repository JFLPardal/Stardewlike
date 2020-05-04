#include "pch.h"
#include "Seed.h"

#include "GameObject.h"
#include "Transform.h"
#include "GameObjectGridMap.h"

Seed::Seed()
{
	m_type = InteractableType::seed;

}

void Seed::PopulateInteractables()
{
	std::pair<InteractableType, std::function<void(GameObject*, GameObjectGridMap&)>> nho (empty, std::bind(&Seed::InteractWithEmpty, this, std::placeholders::_1, std::placeholders::_2));
	m_interactableTypes.emplace_back(nho);
}

void Seed::InteractWith(GameObject* aObjectToInteractWith, GameObjectGridMap& aGridMap)
{
	if (aObjectToInteractWith == nullptr)
	{
		printf("no object on tile\n");
		InteractWithEmpty(aObjectToInteractWith, aGridMap);
	}
	else
	{
		printf("object on tile\n");
		const auto otherGOinteractableType = aObjectToInteractWith->GetInteractable()->GetInteractableType();
		for (const auto interactableType : m_interactableTypes)
		{
			if (interactableType.first == otherGOinteractableType)
				interactableType.second(aObjectToInteractWith, aGridMap);
		}
	}
}

void Seed::InteractWithEmpty(GameObject* aObject, GameObjectGridMap& aGridMap)
{
	printf("seed interacting with empty.\n");
	//auto positionToAdd = aObject->GetComponent<Transform>()->GetPositionInGrid();
	
	static int f = 0;
	sf::Vector2i positionToAdd(f, 4);
	f++;

	std::shared_ptr<GameObject> seed = std::make_shared<GameObject>(positionToAdd);
	seed->AddComponent<SpriteRenderer>("assets\\player.png");
	seed->AddComponent<Seed>();
	seed->Start();
	//std::shared_ptr<GameObject> sss = std::make_shared<GameObject>(m_seed);
	aGridMap.AddToGrid(seed, positionToAdd);
}