#include "pch.h"
#include "Inventory.h"

#include "GameObject.h"
#include "InteractableTypes/Seed.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "GameObjectData/SeedData.h"
#include "StateMachine/SeedStateMachine.h"
#include "InteractableTypes/Hoe.h"
#include "WindowEventHandler.h"

Inventory::Inventory(WindowEventHandler* aWindow)
	:m_windowEventHandler(aWindow)
{
	std::unique_ptr<GameObject> hoe = std::make_unique<GameObject>(sf::Vector2i(50, 50));
	hoe->AddComponent<Hoe>();
	hoe->Start();
	m_objectsHeld.push_back(std::move(hoe));

	std::unique_ptr<GameObject> seed = std::make_unique<GameObject>(std::make_unique<SeedData>(), std::make_unique<SeedStateMachine>(), sf::Vector2i(50, 50));
	seed->AddComponent<SpriteRenderer>("assets\\player.png");
	seed->AddComponent<Animator>();
	seed->AddComponent<Seed>();
	seed->Start();
	m_objectsHeld.push_back(std::move(seed));

	m_numberKeyPressedIndex = m_windowEventHandler->m_onNumberKeyPressedEvent->AddCallback(KEY_PRESSED(&Inventory::ChangeActiveItem));
}

void Inventory::ChangeActiveItem(int aNewIndex)
{
	printf("FWAAAAAAAAAA\n");
	if (aNewIndex <= m_objectsHeld.size())
		m_indexOfCurrentGO = --aNewIndex;
}

Inventory::~Inventory()
{
	m_windowEventHandler->m_onNumberKeyPressedEvent->RemoveCallback(m_numberKeyPressedIndex);
}