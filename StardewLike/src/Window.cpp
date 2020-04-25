#include "pch.h"
#include "Window.h"

#include "GameApp.h"
#include "DrawableEntity.h"
#include "GameObject.h"
#include "WindowEventHandler.h"

Window::Window()
	:m_isOpen(true)
	,m_Window(sf::VideoMode(1024, 768), "Nice Window :')")
	,m_windowEventHandler(new WindowEventHandler())
{
	m_Window.setVerticalSyncEnabled(true);
}

bool Window::PollEvent(sf::Event& aEvent)
{
	return m_Window.pollEvent(aEvent);
}

void Window::ProcessEvent(sf::Event& aEvent)
{
	if (!m_windowEventHandler->ProcessEvent(aEvent))
		m_isOpen = false;
}

void Window::Draw(const std::vector<std::unique_ptr<GameObject>>& aGameObjects)
{
	m_Window.clear();
	for (auto& gameObject : aGameObjects)
		m_Window.draw(gameObject->GetRenderer());
	m_Window.display();
}

void Window::Draw(const std::vector<sf::Drawable*>& aDrawableEntities)
{
	m_Window.clear();
	for (auto& gameObject : aDrawableEntities)
		m_Window.draw(*gameObject);
	m_Window.display();
}

Window::~Window()
{
	delete m_windowEventHandler;
}