#pragma once
#include "Component.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	virtual void Update() override;
};