#include "pch.h"
#include "GameApp.h"

#include "Window.h"
#include "Tilemap.h"
#include "GameObject.h"
#include "TileData.h"
#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include "Components/Input.h"
#include "Components/Orientation.h"
#include "Components/InteractWithWorld.h"

void GameApp::InitPlayerComponents(GameObject& aPlayer)	// TODO this should be done in some external file, like XML or something
{
	aPlayer.AddComponent<Orientation>(m_GameWindow.GetWindowEventHandler());
	aPlayer.AddComponent<SpriteRenderer>("assets\\cherry.png");
	aPlayer.AddComponent<Input>();
	aPlayer.AddComponent<InteractWithWorld>(m_GameWindow.GetWindowEventHandler());
	aPlayer.Start();


	auto v(sf::Vector2i(0, 0));
	auto v1(sf::Vector2i(3, 15));
	auto v2(sf::Vector2i(0, 2));
	auto data = m_tileData->CheckForGameObjectOnTile(v);
	if (data == nullptr)
		printf("[1st] no data\n");
	std::unique_ptr<GameObject> testObj = std::make_unique<GameObject>();
	m_tileData->AddToGrid(testObj.get(), v);

	auto data2 = m_tileData->CheckForGameObjectOnTile(v);
	if (data2 == nullptr)
		printf("[2st] no data\n");
	else
		printf("[2st] added :D\n");


	m_tileData->AddToGrid(nullptr, v1);
	m_tileData->AddToGrid(nullptr, v2);

}

GameApp::GameApp(Window& aWindow)
	: m_GameWindow(aWindow)
	, m_tileData(new TileData())
{
	// create and load map
	m_Tilemap = new Tilemap();
	m_Tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8); // TODO if this is not deleted, extract numbers to 'Constants'

	// TODO this and the 'move game entities...' should be done in one go to make sure the programmer doesn't forget to add the GO to the structure
	// create Game Entities 
	std::unique_ptr<GameObject> player = std::make_unique<GameObject>();
	InitPlayerComponents(*player);

	// move game entities to the m_gameObjects structure
	m_GameObjects.push_back(std::move(player));
}

void GameApp::Update()
{
	for (auto& gameObject : m_GameObjects)
	{
		gameObject->Update();
	}
}

void GameApp::Draw() const
{
	m_GameWindow.Draw(m_Tilemap);
	m_GameWindow.Draw(m_GameObjects);
}

GameApp::~GameApp()
{
	delete m_Tilemap;
	delete m_tileData;
}