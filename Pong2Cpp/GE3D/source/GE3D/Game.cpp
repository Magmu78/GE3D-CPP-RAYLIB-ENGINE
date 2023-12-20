#include <GE3D/Game.h>
#include <GE3D/GameManager.h>
#include <memory>
#include <cassert>
#include <iostream>

void Game::Run()
{
	//GameManager* mainGameManager = new GameManager();

	GameManager mainGameManager;

	//assert(mainGameManager == nullptr && "Maingamemanager is null");
	
	SetTargetFPS(60);

	mainGameManager.InitAppWindow(1366, 768, "Garjine Engine 3D");
	mainGameManager.Loop();
	mainGameManager.Cleanup();
}