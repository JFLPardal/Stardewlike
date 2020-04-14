#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"

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
	// TODO optimize, this should store a pointer to a texture and all textures should be stored in a single class
	sf::Texture m_Texture;
	sf::Sprite  m_Sprite;
	Transform* m_transform;
};