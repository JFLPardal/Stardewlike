#include "GameApp.h"

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Tilemap.h"
#include "DrawableEntity.h"
#include "GameObject.h"
#include "Components/Transform.h"

GameApp::GameApp(Window& aWindow)
	:m_GameWindow(aWindow)
{
	// map
	m_Tilemap = new Tilemap();
	// original map
	/*const int map[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};*/
	const int map[] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
	m_Tilemap->Load("assets\\tileset.png", sf::Vector2u(32,32), map, 16, 8);
	//m_Drawables.push_back(m_Tilemap);
	
	//create cherry object
	std::shared_ptr<DrawableEntity> cherry01 = std::make_shared<DrawableEntity>("assets\\cherry.png");

	// create Game Entities
	std::unique_ptr<GameObject> player = std::make_unique<GameObject>();
	player->AddComponent<Transform>(); // TODO move add transform to the GO constructor
	if(player->GetComponent<Transform>())
		printf("x: %d\n", player->GetComponent<Transform>()->X());
	//m_GameObjects.push_back(std::move(player));

	m_Drawables.push_back(cherry01);
}

GameApp::~GameApp()
{
	delete m_Tilemap;
}

void GameApp::Update()
{
	for (auto& drawable : m_Drawables)
	{
		drawable->update();
	}
}

void GameApp::Draw() const
{
	//m_GameWindow.Draw(m_Tilemap);
	m_GameWindow.Draw(m_Drawables);
}