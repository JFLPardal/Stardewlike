#pragma once
#include "Component.h"
#include "Enums.h"

/*
	SpriteRenderer is responsible for drawing the 'GameObject' it is attached to,
	as well as update that GO's sprite based on conditions.	 
*/

class Transform;
class Orientation;

class SpriteRenderer : public Component, public sf::Drawable
{
public:
	SpriteRenderer(const char* spriteFilePath, bool aKeepOriginalScale = true);
	~SpriteRenderer();
	
	void Start() override;
	void Update() override;
	void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const override;
private:
	void OrientationChanged(PossibleOrientation aNewOrientation);
	static std::map<PossibleOrientation, sf::Vector2i> orientationToSpriteIndex;
	// TODO optimize, this should store a pointer to a texture and all textures should be stored in a single class
	sf::Texture m_texture;
	sf::Sprite  m_sprite;
	Transform* m_transform{nullptr};
	Orientation* m_orientation{ nullptr };
};