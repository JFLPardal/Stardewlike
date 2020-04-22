#include "pch.h"

#include "GameApp.h"
#include "Window.h"

int main()
{
	Window gameWindow;
	GameApp gameApp(gameWindow);
	
	while(gameWindow.IsOpen())
	{
		sf::Event event;
		while(gameWindow.PollEvent(event))
		{
			gameWindow.ProcessEvent(event);
		}
		gameApp.Update();
		gameApp.Draw();
	}
	return 0;
}