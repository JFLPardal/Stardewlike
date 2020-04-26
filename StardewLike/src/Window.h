#pragma once

/*
	Window is a wrapper around the function calls to the SFML library needed to create and 
	draw to a window. Additionally, it is responsible for forwarding Window events to a class 
	where they should be treated. This events include mouse movement and clicks, keyboard input,
	window moved, resized, etc...
*/

class GameObject;
class WindowEventHandler;

class Window
{
public:
	Window();
	~Window();

	bool IsOpen() const { return m_isOpen; }
	bool PollEvent(sf::Event& aEvent);
	void ProcessEvent(sf::Event& aEvent);

	void Draw(const sf::Drawable* const aDrawble);								// used to draw generic sf::Drawable
	void Draw(const std::vector<std::unique_ptr<GameObject>>& aGameObjects);	// used to draw GameObjects

	WindowEventHandler* GetWindowEventHandler() const { return m_windowEventHandler; }
private:
	bool m_isOpen = false;
	sf::RenderWindow m_window;
	WindowEventHandler* m_windowEventHandler{ nullptr };
};

