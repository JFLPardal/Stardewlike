#include "pch.h"
#include "Inventory.h"

#include "GameObject.h"
#include "Components/Seed.h"
#include "Components/SpriteRenderer.h"

Inventory::Inventory()
	:m_objectBeingHeld(std::make_unique<GameObject>())
{
	m_objectBeingHeld->AddComponent<SpriteRenderer>("assets\\player.png");
	m_objectBeingHeld->AddComponent<Seed>();
	m_objectBeingHeld->Start();
}
