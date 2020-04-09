#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window;
class Tilemap;
class DrawableEntity;

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
	std::vector<std::shared_ptr<DrawableEntity>> m_Drawables;
};