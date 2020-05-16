#include "pch.h"
#include "IInteractable.h"

#include "GameObject.h"

void IInteractable::InteractWith(GameObject* aObjectOnTileToInteractWith, GameObjectGridMap& aGridMap)
{
	if (aObjectOnTileToInteractWith->GetInteractable() != nullptr)
	{
		printf("interacting with: ");
		// TODO change hereeeeeeeeee
		const auto otherGOinteractableType = aObjectOnTileToInteractWith->GetInteractable()->GetInteractableType();
		for (auto& interactableType : m_interactableTypes)
		{
			if (interactableType.first == otherGOinteractableType)
				interactableType.second(aObjectOnTileToInteractWith, aGridMap);
		}
	}
}
