#pragma once
#include "Item.h"

/*
	SeedPack represents a pack of seeds the player can plant
	when interacting with a 'NoInteractable' map tile
*/

class SeedPack : public Item
{
public:
	SeedPack() : Item(ItemType::seedPack) {}
};