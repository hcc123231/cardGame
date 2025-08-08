#pragma once
#include"cocos2d.h"
#include"models/GameModel .h"
#include"controllers/StackAreaCtroller.h"
/*@class MasterRollbackManager
* @brief 管理桌面区回滚操作
*功能：
* -实现桌面区回滚操作
*职责：
* -定义桌面区回滚操作
*使用场景：
* -当桌面区发生回滚操作时MasterRollbackManager调用回滚操作函数
*/
class MasterRollbackManager {
private:
	cocos2d::Layer* _gameView;//桌面区视图引用
	GameModel* _gameModel;//桌面区卡牌数据模型
public:
	MasterRollbackManager(cocos2d::Layer* gameView, GameModel* gameModel) :_gameView{ gameView }, _gameModel{ gameModel } {};
	/*
	 *@brief 桌面区回滚操作
	 *@param stackAreaCtroller 手牌区控制器
	*/
	void undo(StackAreaCtroller* stackAreaCtroller);
};