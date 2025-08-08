#pragma once
#include"cocos2d.h"
//#include"views/GameView.h"
#include"models/GameModel .h"
/*@class MasterMoveManager
* @brief 桌面区点击卡牌移动管理
*功能：
* -对桌面区卡牌的点击事件的回调函数进行定义
*职责：
* -管理桌面区卡牌点击事件触发的移动
*使用场景：
* -当桌面区的卡牌被点击时，触发回调函数，这个回调函数就是由cardMoveShift来定义的
*/
class MasterMoveManager {
private:
	cocos2d::Layer* _gameView;//桌面区视图引用
	GameModel* _gameModel; //桌面区卡牌数据模型

public:
	MasterMoveManager(cocos2d::Layer* gameView, GameModel* gameModel) :_gameView{ gameView }, _gameModel{ gameModel } {};
	/*
	*@brief 桌面区卡牌点击事件回调函数具体实现
	*@param card 卡牌
   */
	void cardMoveShift(cocos2d::Node* card);
	/*
	*@brief 记录一条回滚数据
	*@param type 回滚操作类型
	*@param oringinPos 卡牌原位置
	*@param targetPos 卡牌目标位置
	*@param card 卡牌
   */
	void recordAction(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card);
};