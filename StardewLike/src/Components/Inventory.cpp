#include "pch.h"
#include "Inventory.h"

#include "GameObject.h"
#include "Seed.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "SeedData.h"
#include "SeedStateMachine.h"

Inventory::Inventory()
	:m_objectBeingHeld(std::make_unique<GameObject>(std::make_unique<SeedData>(), std::make_unique<SeedStateMachine>(), sf::Vector2i(50, 50)))
{
	m_objectBeingHeld->AddComponent<SpriteRenderer>("assets\\player.png");
	m_objectBeingHeld->AddComponent<Animator>();
	m_objectBeingHeld->AddComponent<Seed>();
	m_objectBeingHeld->Start();
}
