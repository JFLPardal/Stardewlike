#pragma once

enum PossibleOrientation : short
{
	up, right, down, left
};

enum State
{
	idle, walk,
	buried, plant, fruit
};