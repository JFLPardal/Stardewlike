#include "pch.h"
#include "Window.h"

#include "GameApp.h"
#include "DrawableEntity.h"
#include "GameObject.h"

Window::Window()
	:m_isOpen(true)
	,m_Window(sf::VideoMode(1024, 768), "Nice Window :')")
{
	m_Window.setVerticalSyncEnabled(true);
}

bool Window::PollEvent(sf::Event& aEvent)
{
	return m_Window.pollEvent(aEvent);
}

void Window::ProcessEvent(sf::Event & aEvent)
{
	if (aEvent.type == sf::Event::Closed)
	{
		m_isOpen = false;
	}
	if (aEvent.type == sf::Event::KeyPressed)
	{
		//printf("key pressed: %d\n", aEvent.key.code);
	}
	if (aEvent.type == sf::Event::MouseButtonPressed)
	{
		//printf("mouse pressed: %d %d %d\n", aEvent.mouseButton.x, aEvent.mouseButton.y, aEvent.mouseButton.button);
	}
	if (aEvent.type == sf::Event::MouseMoved)
	{
		printf("mouse moved: %d %d\n", aEvent.mouseMove.x, aEvent.mouseMove.y);
	}
}

void Window::Draw(const std::vector<std::unique_ptr<GameObject>>& aGameObjects)
{
	m_Window.clear();
	for (auto& gameObject : aGameObjects)
		m_Window.draw(gameObject->GetRenderer());
		//if(gameObject->IsDrawable())
	m_Window.display();
}