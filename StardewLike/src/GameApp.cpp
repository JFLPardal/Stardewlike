#include "pch.h"
#include "GameApp.h"

#include "Window.h"
#include "Tilemap.h"
#include "GameObject.h"
#include "GameObjectGridMap.h"
#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include "Components/Input.h"
#include "Components/Orientation.h"
#include "Components/InteractWithWorld.h"
#include "Components/Inventory.h"

GameApp::GameApp(Window& aWindow)
	: m_gameWindow(aWindow)
	, m_tilemap(std::make_unique<Tilemap>())
	, m_GOgridMap(std::make_unique<GameObjectGridMap>())
	, m_player(std::make_unique<GameObject>())
{
	m_tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8); // TODO if this is not deleted, extract numbers to 'Constants'
		
	InitPlayerComponents();
	SubscribeToPlayerEvents();
}

void GameApp::InitPlayerComponents()	// TODO this should be done in some external file, like XML or something
{
	m_player->AddComponent<Orientation>(m_gameWindow.GetWindowEventHandler());
	m_player->AddComponent<SpriteRenderer>("assets\\cherry.png", false);
	m_player->AddComponent<Input>();
	m_player->AddComponent<InteractWithWorld>(m_gameWindow.GetWindowEventHandler(), *m_GOgridMap);
	m_player->AddComponent<Inventory>();
	m_player->Start();
}

void GameApp::SubscribeToPlayerEvents()
{
	m_tryCreateGameObjectIndex = m_player->GetComponent<InteractWithWorld>()->OnTryToCreateGameObjectEvent->AddCallback(TRY_CREATE_GAME_OBJECT(&GameApp::CreateGameObject));
}

void GameApp::Update()
{
	for (auto& gameObject : m_gameObjects)
	{
		gameObject->Update();
	}
	m_player->Update();
}

void GameApp::Draw() const
{
	m_gameWindow.Draw(m_tilemap.get());
	m_gameWindow.Draw(m_gameObjects);
	m_gameWindow.Draw(*m_player);
}

void GameApp::CreateGameObject(std::unique_ptr<GameObject> aGOtoCreate, const sf::Vector2i& aGOgridPos)
{
	std::shared_ptr<GameObject> newGOinstance{ aGOtoCreate.release() };
	m_gameObjects.push_back(newGOinstance);
	m_GOgridMap->AddToGrid(newGOinstance, aGOgridPos);
}

// m_GOgridMap should NOT be deleted, since it points at the same objects as m_gameObjects, when this is destroyed those 
// heap allocated objects are destroyed as well
GameApp::~GameApp()
{
	m_player->GetComponent<InteractWithWorld>()->OnTryToCreateGameObjectEvent->RemoveCallback(m_tryCreateGameObjectIndex);
}