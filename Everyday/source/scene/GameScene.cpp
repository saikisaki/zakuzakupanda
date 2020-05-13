#include "GameScene.h"
#include "../unit/Player.h"
#include "../Mng/SceneMng.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::Init(void)
{

}

Unique_Base GameScene::UpDate(Unique_Base own)
{
	_objList.emplace_back(std::make_shared<Player>(VECTOR2(lpSceneMng.GetScreenSize().x / 2 - 15, 350), 10));


	return std::move(own);
}
