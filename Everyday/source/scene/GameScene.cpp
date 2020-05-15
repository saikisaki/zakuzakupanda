#include "GameScene.h"
#include "../unit/Player.h"
#include "../unit/Enemy.h"
#include "../Mng/SceneMng.h"

GameScene::GameScene()
{
	Init();
}

GameScene::~GameScene()
{
}

void GameScene::Init(void)
{
	_objList.emplace_back(std::make_shared<Player>(VECTOR2(lpSceneMng.GetScreenSize().x / 2 - 15, 350), 20));
	_objList.emplace_back(std::make_shared<Enemy>(VECTOR2(lpSceneMng.GetScreenSize().x / 2 - 15, -20), 20));
}

Unique_Base GameScene::UpDate(Unique_Base own)
{
	for (auto &obj : _objList)
	{
		obj->SetMove();
		obj->Draw();
	}

	return std::move(own);
}
