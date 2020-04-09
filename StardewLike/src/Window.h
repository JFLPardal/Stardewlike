#pragma once
#include <SFML/Graphics.hpp>
#include "GameApp.h"

class DrawableEntity;

class Window
{
public:
	Window();

	bool IsOpen() const { return m_isOpen; }
	bool PollEvent(sf::Event& aEvent);
	void ProcessEvent(sf::Event& aEvent);

	//void Draw(const std::vector<sf::Drawable*>& aDrawableEntities);
	void Draw(const std::vector<std::shared_ptr<DrawableEntity>>& aDrawableEntities);
private:
	bool m_isOpen = false;
	sf::RenderWindow m_Window;
};

