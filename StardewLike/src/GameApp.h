#pragma once

/*
	GameApp is the class that holds the information of the whole game.
	This class is responsible for updating and drawing all the entities in the game.

	It has a 'Window' to which it will draw to, as well as a collection of entities that the game has 
	and a structure that knows what objects are in which tiles of the map.
	In the future this collection should be moved to some kind of level abstraction, and GameApp should have
	a collection of those instead.
*/

class Window;
class Tilemap;
class TileData;
class GameObject;

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
	Tilemap* m_Tilemap;										// | these should be abstracted into a 'Level' script
	TileData* m_tileData;									// |
	std::vector<std::unique_ptr<GameObject>> m_GameObjects;	// |
};