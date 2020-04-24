#pragma once
#include "Component.h"

class Orientation;

/*
	SpriteRenderer is responsible for drawing the 'GameObject' it is attached to,
	as well as update that GO's sprite based on conditions.	 
*/
class Transform;

class SpriteRenderer : public Component, public sf::Drawable
{
public:
	SpriteRenderer(const char* spriteFilePath);
	~SpriteRenderer();
	
	void Start() override;
	void Update() override;
	void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const;
private:
	void SetSpriteBasedOnDirection(short aX, short aY);
	// TODO optimize, this should store a pointer to a texture and all textures should be stored in a single class
	sf::Texture m_texture;
	sf::Sprite  m_sprite;
	Transform* m_transform{nullptr};
	EventIndex m_eMoveKeyPressedIndex;
	Orientation* m_orientation{ nullptr };
};