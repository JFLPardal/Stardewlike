#pragma once

#include "Item.h"

/*
	Hoe will allow 'Seed's to be removed from the map
*/

class Hoe : public Item
{
public:
	Hoe() : Item(ItemType::hoe) {}
};