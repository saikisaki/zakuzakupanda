#include "GameScene.h"



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
	return std::move(own);
}
