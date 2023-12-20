#include <iostream>
#include "raylib.h"
#include <memory>
#include <GE3D/Game.h>

int main()
{
	try
	{
		//Game* gameInstance = new Game();

		Game gameInstance;

		gameInstance.Run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}