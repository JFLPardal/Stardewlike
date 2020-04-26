#include "pch.h"
#include "GameApp.h"

#include "Window.h"
#include "Tilemap.h"
#include "GameObject.h"
#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include "Components/Input.h"
#include "Components/Orientation.h"

void GameApp::InitPlayerComponents(GameObject& aPlayer)	// TODO this should be done in some external file, like XML or something
{
	aPlayer.AddComponent<Orientation>(m_GameWindow.GetWindowEventHandler());
	aPlayer.AddComponent<SpriteRenderer>("assets\\cherry.png");
	aPlayer.AddComponent<Input>();
	aPlayer.Start();
}

GameApp::GameApp(Window& aWindow)
	:m_GameWindow(aWindow)
{
	// create and load map
	m_Tilemap = new Tilemap();
	m_Tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), 16, 8);

	// TODO this and the 'move game entities...' should be done in one go to make sure the programmer doesn't forget to add the GO to the structure
	// create Game Entities 
	std::unique_ptr<GameObject> player = std::make_unique<GameObject>(200, 50);
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
}