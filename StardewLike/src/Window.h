#pragma once
#include <SFML/Graphics.hpp>
#include "GameApp.h"

class DrawableEntity;
class GameObject;

class Window
{
public:
	Window();

	bool IsOpen() const { return m_isOpen; }
	bool PollEvent(sf::Event& aEvent);
	void ProcessEvent(sf::Event& aEvent);

	void Draw(const std::vector<std::shared_ptr<DrawableEntity>>& aDrawableEntities);
	//void Draw(const std::vector<std::unique_ptr<GameObject>>& aGameObjects);
private:
	bool m_isOpen = false;
	sf::RenderWindow m_Window;
};

