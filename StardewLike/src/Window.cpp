#include "pch.h"
#include "Window.h"

#include "GameObject.h"
#include "WindowEventHandler.h"
#include "Constants.h"

Window::Window() noexcept
	:m_isOpen(true)
	,m_window(sf::VideoMode(WINDOW_W, WINDOW_H), WINDOW_NAME)
	,m_windowEventHandler(std::make_unique<WindowEventHandler>())
{
	m_window.setVerticalSyncEnabled(true);
}

bool Window::PollEvent(sf::Event& aEvent)
{
	return m_window.pollEvent(aEvent); 
}

void Window::ProcessEvent(const sf::Event& aEvent)
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

void Window::Draw(const std::vector<std::shared_ptr<GameObject>>& aGameObjects)
{
	//m_window.clear();
	for (auto& gameObject : aGameObjects)
		if(gameObject->IsDrawable())
			m_window.draw(gameObject->GetRenderer());
	//m_window.display();
}

void Window::Draw(const GameObject& aGameObject)
{
	//m_window.clear();
	m_window.draw(aGameObject.GetRenderer());
	m_window.display();
}

Window::~Window()
{
}