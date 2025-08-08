#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    _gameView = GameView::createLayer();//��ʼ��layer
    _gameView->setAnchorPoint(Vec2(0, 0));
    _gameView->setContentSize(Size(1080, 2080));
    _gameModel = new GameModel();
    _gameCtroller = new GameCtroller{_gameView,_gameModel,"gameconf.json"};
   

    this->addChild(_gameView);
    //��ʼ��Ϸ
    _gameCtroller->startGame();
    return true;
}
