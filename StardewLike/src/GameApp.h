#pragma once
/*
	GameApp is the class that holds the information of the whole game.
	This class is responsible for updating and drawing all the entities in the game.

	It has a 'Window' to which it will draw to, as well as a collection of entities that the game has 
	and a structure that knows what objects are in which tiles of the map.
	It also holds a reference to the player, as well as an observer to a 'TryCreateGameObject' event.

	In the future this collection should be moved to some kind of level abstraction, and GameApp should have
	a collection of those instead.
*/
typedef size_t EventIndex;

class Window;
class Tilemap;
class GameObjectGridMap;
class GameObject;

class GameApp
{
public:
	GameApp(Window& aWindow);
	~GameApp();

	void Update();
	void Draw() const;
	void CreateGameObject(std::shared_ptr<GameObject> aGOtoCreate, const sf::Vector2i& aGOgridPos);
	void RemoveGameObject(std::shared_ptr<GameObject> aGameObjectToRemove);
private:
	
	void InitPlayerComponents();
	void SubscribeToPlayerEvents();

	Window& m_gameWindow;
	std::unique_ptr<Tilemap> m_tilemap;						// | these should be abstracted into a 'Level' script
	std::unique_ptr<GameObjectGridMap> m_GOgridMap;			// |
	std::vector<std::shared_ptr<GameObject>> m_gameObjects;	// |
	std::unique_ptr<GameObject> m_player;
	
	EventIndex m_tryCreateGameObjectIndex = -1;
	EventIndex m_RemoveGameObjectIndex = -1;
};