#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window;
class Tilemap;
class DrawableEntity;
class GameObject;

class GameApp
{
public:
	GameApp(Window& aWindow);
	~GameApp();

	void Update();
	void Draw() const;
private:
	Window& m_GameWindow;
	Tilemap* m_Tilemap;
	//std::vector<sf::Drawable*> m_Drawables;
	std::vector<std::shared_ptr<DrawableEntity>> m_Drawables; // TODO for now, delete this and on draw see if m_gameObjects has drawable component, if it does, draw it
	std::vector<std::unique_ptr<GameObject>> m_GameObjects;
};