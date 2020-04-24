#pragma once

class Window;
class Tilemap;
class DrawableEntity;
class GameObject;

/*
	GameApp is the class that holds the information of the whole game.
	This class is responsible for updating and drawing all the entities in the game.

	It has a 'Window' to which it will draw to, as well as a collection of entities that the game has. 
	In the future this collection should be moved to some kind of level abstraction, and GameApp should have
	a collection of those instead.
*/

class GameApp
{
public:
	GameApp(Window& aWindow);
	~GameApp();

	void Update();
	void Draw() const;
private:
	void InitPlayerComponents(GameObject& aPlayer);

	Window& m_GameWindow;
	Tilemap* m_Tilemap;
	//std::vector<sf::Drawable*> m_Drawables;
	std::vector<std::shared_ptr<DrawableEntity>> m_Drawables; // TODO for now, delete this and on draw see if m_gameObjects has drawable component, if it does, draw it
	std::vector<std::unique_ptr<GameObject>> m_GameObjects;
};