#include "pch.h"
#include "Window.h"

#include "GameObject.h"
#include "WindowEventHandler.h"

Window::Window()
	:m_isOpen(true)
	,m_window(sf::VideoMode(1024, 768), "Nice Window :')")
	,m_windowEventHandler(new WindowEventHandler())
{
	m_window.setVerticalSyncEnabled(true);
}

bool Window::PollEvent(sf::Event& aEvent)
{
	return m_window.pollEvent(aEvent);
}

void Window::ProcessEvent(sf::Event& aEvent)
{
	if (!m_windowEventHandler->ProcessEvent(aEvent))
		m_isOpen = false;
}

void Window::Draw(const sf::Drawable* const aDrawble)
{
	m_window.clear();
		m_window.draw(*aDrawble);
	//m_window.display();
}

void Window::Draw(const std::vector<std::unique_ptr<GameObject>>& aGameObjects)
{
	//m_window.clear();
	for (auto& gameObject : aGameObjects)
		m_window.draw(gameObject->GetRenderer());
	m_window.display();
}

Window::~Window()
{
	delete m_windowEventHandler;
}