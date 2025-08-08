#pragma once
#include<cocos2d.h>
#include"views/GameView.h"
#include"controllers/GameController .h"
#include"models/GameModel .h"
/*@class GameScene
* @brief 游戏场景总框架，游戏入口
*功能：
* -游戏启动加载场景
* -初始化游戏控制器，游戏视图层，游戏数据模型
* -启动游戏
*职责：
* -持有游戏控制器，游戏视图层，游戏数据模型
* -决定游戏启动流程
*使用场景：
* -AppDelegate开始游戏创建GameScene scene，runWithScene(scene)
*/
class GameScene :public cocos2d::Scene {
public:
    /*
     *@brief 初始化函数
     * @return scenePointer 骨架创建成功，nullptr 骨架创建失败
    */
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

private:
    
    cocos2d::Layer* _gameView;//游戏总视图，位于GameScene之上的一层layer
    GameCtroller* _gameCtroller;//游戏流程控制器
    GameModel* _gameModel;//游戏数据模型
};