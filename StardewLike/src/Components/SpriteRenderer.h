#pragma once
#include "Component.h"
#include "Enums.h"

/*
	SpriteRenderer is responsible for drawing the 'GameObject' it is attached to.
*/

class Transform;
class Orientation;
class Animator;

class SpriteRenderer : public Component, public sf::Drawable
{
public:
	SpriteRenderer(const char* spriteFilePath, bool aKeepOriginalScale = true);
	~SpriteRenderer();
	
	void Start() override;
	void Update() override;
	void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const override;
private:
	// TODO optimize, this should store a pointer to a texture and all textures should be stored in a single class
	sf::Texture m_texture;
	sf::Sprite  m_sprite;
	Animator* m_animator{ nullptr };
	Transform* m_transform{ nullptr };
	Orientation* m_orientation{ nullptr };
};