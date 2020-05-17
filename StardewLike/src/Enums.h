#pragma once

enum class PossibleOrientation : short
{
	up, right, down, left
};

enum class State
{
	idle, walk,
	buried, plant, fruit
};

enum class ItemType
{
	notDefined = -1,
	hoe = 1, wateringCan,
	seedPack
};