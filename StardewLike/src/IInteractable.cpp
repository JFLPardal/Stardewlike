#include "pch.h"
#include "IInteractable.h"

#include "GameObject.h"
#include "Items/Item.h"

void IInteractable::InteractWith(GameObject* aObjectOnTileToInteractWith, GameObjectGridMap& aGridMap)
{
	auto itemComponent = aObjectOnTileToInteractWith->GetItem();
	if (itemComponent != nullptr)
	{
		printf("interacting with: ");
		const auto itemType = itemComponent->GetItemType();
		for (auto& interactableItem : m_interactionWithItems)
		{
			if (interactableItem.first == itemType)
				interactableItem.second(aObjectOnTileToInteractWith, aGridMap);
		}
	}
}
