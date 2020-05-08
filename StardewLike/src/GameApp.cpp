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
#include "Components/Animator.h"
#include "PlayerStateMachine.h"
#include "PlayerData.h"


GameApp::GameApp(Window& aWindow)
	: m_gameWindow(aWindow)
	, m_tilemap(std::make_unique<Tilemap>())
	, m_GOgridMap(std::make_unique<GameObjectGridMap>())
	, m_player(std::make_unique<GameObject>(std::make_unique<PlayerData>(), std::make_unique<PlayerStateMachine>()))
{
	m_tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8); // TODO if this is not deleted, extract numbers to 'Constants'
		
	InitPlayerComponents();
	SubscribeToPlayerEvents();
}

void GameApp::InitPlayerComponents()	// TODO this should be done in some external file, like XML or something
{
	m_player->AddComponent<Orientation>(m_gameWindow.GetWindowEventHandler());
	m_player->AddComponent<SpriteRenderer>("assets\\player_sheet.png", true);
	m_player->AddComponent<Animator>();
	m_player->AddComponent<Input>();
	m_player->AddComponent<InteractWithWorld>(m_gameWindow.GetWindowEventHandler(), *m_GOgridMap);
	m_player->AddComponent<Inventory>();
	m_player->Start();
}

void GameApp::SubscribeToPlayerEvents()
{
	m_tryCreateGameObjectIndex = m_GOgridMap->OnTryToCreateGameObjectEvent->AddCallback(TRY_CREATE_GAME_OBJECT(&GameApp::CreateGameObject));
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

void GameApp::CreateGameObject(std::shared_ptr<GameObject> aGOtoCreate, const sf::Vector2i& aGOgridPos)
{
	m_gameObjects.push_back(aGOtoCreate);
}

// m_GOgridMap should NOT be deleted, since it points at the same objects as m_gameObjects, when this is destroyed those 
// heap allocated objects are destroyed as well
GameApp::~GameApp()
{
	m_GOgridMap->OnTryToCreateGameObjectEvent->RemoveCallback(m_tryCreateGameObjectIndex);
}