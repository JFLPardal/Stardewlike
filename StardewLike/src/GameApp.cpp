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
	/*
	auto v(sf::Vector2i(0, 0));
	auto v1(sf::Vector2i(3, 15));
	auto v2(sf::Vector2i(0, 2));
	auto data = m_GOgridMap->CheckForGameObjectOnTile(v);
	if (data == nullptr)
		printf("[1st] no data\n");
	std::unique_ptr<GameObject> testObj = std::make_unique<GameObject>();
	m_GOgridMap->AddToGrid(testObj.get(), v);

	auto data2 = m_GOgridMap->CheckForGameObjectOnTile(v);
	if (data2 == nullptr)
		printf("[2st] no data\n");
	else
		printf("[2st] added :D\n");


	m_GOgridMap->AddToGrid(nullptr, v1);
	m_GOgridMap->AddToGrid(nullptr, v2);*/

}

GameApp::GameApp(Window& aWindow)
	: m_GameWindow(aWindow)
	, m_GOgridMap(new GameObjectGridMap())
	, m_player(std::make_unique<GameObject>())
{
	// create and load map
	m_Tilemap = new Tilemap();
	m_Tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8); // TODO if this is not deleted, extract numbers to 'Constants'

	// TODO this and the 'move game entities...' should be done in one go to make sure the programmer doesn't forget to add the GO to the structure
	// create Game Entities 
	
	InitPlayerComponents();

	// move game entities to the m_gameObjects structure
	//m_GameObjects.push_back(std::move(player));
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

void GameApp::CreateGameObject(GameObject* aGOtoCreate, const sf::Vector2i& aGOgridPos)
{
	printf("creating GO with event on position [%d, %d]\n", aGOgridPos.x, aGOgridPos.y);
	std::shared_ptr<GameObject> obj{ aGOtoCreate };
	m_GameObjects.push_back(obj);
	m_GOgridMap->AddToGrid(obj.get(), aGOgridPos);
}

GameApp::~GameApp()
{
	m_player->GetComponent<InteractWithWorld>()->OnTryToCreateGameObjectEvent->RemoveCallback(m_tryCreateGameObjectIndex);
	delete m_Tilemap;
	delete m_GOgridMap;
}