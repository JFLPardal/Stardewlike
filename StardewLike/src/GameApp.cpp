#include "pch.h"
#include "GameApp.h"

#include "Window.h"
#include "MapRepresentation/Tilemap.h"
#include "GameObject.h"
#include "MapRepresentation/GameObjectGridMap.h"
#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include "Components/Input.h"
#include "Components/Orientation.h"
#include "Components/InteractWithWorld.h"
#include "Components/Inventory.h"
#include "Components/Animator.h"
#include "InteractableTypes/Bed.h"
#include "StateMachine/PlayerStateMachine.h"
#include "GameObjectData/PlayerData.h"
#include "MapRepresentation/GridRepresentation.h"


GameApp::GameApp(Window& aWindow)
	: m_gameWindow(aWindow)
	, m_tilemap(std::make_unique<Tilemap>())
	, m_GOgridMap(std::make_unique<GameObjectGridMap>())
	, m_player(std::make_unique<GameObject>(std::make_unique<PlayerData>(), std::make_unique<PlayerStateMachine>()))
{
	m_tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8); // TODO if this is not deleted, extract numbers to 'Constants'
		
	InitPlayerComponents();
	InitBed();
	SubscribeToPlayerEvents();
}

void GameApp::InitPlayerComponents()	// TODO this should be done in some external file, like XML or something
{
	m_player->AddComponent<Orientation>(m_gameWindow.GetWindowEventHandler());
	m_player->AddComponent<SpriteRenderer>("assets\\player_sheet.png", true);
	m_player->AddComponent<Animator>();
	m_player->AddComponent<Input>();
	m_player->AddComponent<InteractWithWorld>(m_gameWindow.GetWindowEventHandler(), *m_GOgridMap);
	m_player->AddComponent<Inventory>(m_gameWindow.GetWindowEventHandler());
	m_player->Start();
}

void GameApp::InitBed()
{
	std::shared_ptr<GameObject> bed = std::make_shared<GameObject>(sf::Vector2i(0, 0));
	bed->AddComponent<SpriteRenderer>("assets\\player_sheet.png", true);
	bed->AddComponent<Bed>();
	bed->Start();
	m_gameObjects.emplace_back(bed);
	m_GOgridMap->AddToGrid(bed, GridRepresentation::ScreenToGridPosition(1, 1));
}

void GameApp::SubscribeToPlayerEvents()
{
	m_tryCreateGameObjectIndex = m_GOgridMap->OnTryToCreateGameObjectEvent->AddCallback(TRY_CREATE_GAME_OBJECT(&GameApp::CreateGameObject));
	m_RemoveGameObjectIndex = m_GOgridMap->OnRemoveGameObjectEvent->AddCallback(REMOVE_GAME_OBJECT(&GameApp::RemoveGameObject));
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

void GameApp::RemoveGameObject(std::shared_ptr<GameObject> aGameObjectToRemove)
{
	auto iteratorForGOtoRemove = std::find(m_gameObjects.begin(), m_gameObjects.end(), aGameObjectToRemove);
	if (iteratorForGOtoRemove != m_gameObjects.end())
		m_gameObjects.erase(iteratorForGOtoRemove);
}

GameApp::~GameApp()
{
	m_GOgridMap->OnTryToCreateGameObjectEvent->RemoveCallback(m_tryCreateGameObjectIndex);
	m_GOgridMap->OnRemoveGameObjectEvent->RemoveCallback(m_RemoveGameObjectIndex);
}