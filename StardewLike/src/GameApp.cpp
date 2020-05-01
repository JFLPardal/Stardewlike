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

void GameApp::InitPlayerComponents()	// TODO this should be done in some external file, like XML or something
{
	m_player->AddComponent<Orientation>(m_GameWindow.GetWindowEventHandler());
	m_player->AddComponent<SpriteRenderer>("assets\\cherry.png", false);
	m_player->AddComponent<Input>();
	m_player->AddComponent<InteractWithWorld>(m_GameWindow.GetWindowEventHandler(), *m_GOgridMap);
	m_player->Start();

	m_tryCreateGameObjectIndex = m_player->GetComponent<InteractWithWorld>()->OnTryToCreateGameObjectEvent->AddCallback(TRY_CREATE_GAME_OBJECT(&GameApp::CreateGameObject));
}

GameApp::GameApp(Window& aWindow)
	: m_GameWindow(aWindow)
	, m_GOgridMap(new GameObjectGridMap())
	, m_player(std::make_unique<GameObject>())
{
	m_Tilemap = new Tilemap();
	m_Tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8); // TODO if this is not deleted, extract numbers to 'Constants'
		
	InitPlayerComponents();
}

void GameApp::Update()
{
	for (auto& gameObject : m_GameObjects)
	{
		gameObject->Update();
	}
	m_player->Update();
}

void GameApp::Draw() const
{
	m_GameWindow.Draw(m_Tilemap);
	m_GameWindow.Draw(m_GameObjects);
	m_GameWindow.Draw(m_player);
}

void GameApp::CreateGameObject(std::unique_ptr<GameObject> aGOtoCreate, const sf::Vector2i& aGOgridPos)
{
	std::shared_ptr<GameObject> newGOinstance{ aGOtoCreate.release() };
	m_GameObjects.push_back(newGOinstance);
	m_GOgridMap->AddToGrid(newGOinstance.get(), aGOgridPos);
}

// m_GOgridMap should NOT be deleted, since it points at the same objects as m_GameObjects, when this is destroyed those 
// heap allocated objects are destroyed as well
GameApp::~GameApp()
{
	m_player->GetComponent<InteractWithWorld>()->OnTryToCreateGameObjectEvent->RemoveCallback(m_tryCreateGameObjectIndex);
	delete m_Tilemap;
}