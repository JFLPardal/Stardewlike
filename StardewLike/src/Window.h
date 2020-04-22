#pragma once

/*
	Window is a wrapper around the function calls to the SFML library needed to create and 
	draw to a window.

	// TODO extract this from this class
	Additionally it is responsible for polling the events that happen on the window like mouse movement,
	keys pressed or windows resizing.
*/

class GameApp;
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
	void Draw(const std::vector<std::unique_ptr<GameObject>>& aGameObjects);
private:
	bool m_isOpen = false;
	sf::RenderWindow m_Window;
};

