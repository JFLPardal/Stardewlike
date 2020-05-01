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
	printf("----------detruction and removal of events---------");
	return 0;
}