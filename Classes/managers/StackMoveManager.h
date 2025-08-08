#pragma once
#include"cocos2d.h"
#include"models/StackAreaModel.h"
#include"utils/cardType.h"
/*@class StackMoveManager
* @brief 手牌区点击卡牌移动管理
*功能：
* -对手牌区卡牌的点击事件的回调函数进行定义
*职责：
* -管理手牌区卡牌点击事件触发的移动
*使用场景：
* -当手牌区的卡牌被点击时，触发回调函数，这个回调函数就是由cardMoveShift来定义的
*/
class StackMoveManager {
private:
	StackAreaModel* _model;//手牌区卡牌数据模型
	cocos2d::Layer* _view;//手牌区视图引用
public:
	StackMoveManager(StackAreaModel* model, cocos2d::Layer* view):_model{model},_view{view}{}
	/*
	*@brief 记录一条回滚数据
	*@param type 回滚操作类型
	*@param oringinPos 卡牌原位置
	*@param targetPos 卡牌目标位置
	*@param card 卡牌
   */
	void recordAction(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card);

	/*
	*@brief 判断手牌区当前点击卡牌是否为栈顶卡牌
	*@param card 卡牌
	*@return true 手牌区当前点击卡牌是栈顶卡牌， false 手牌区当前点击卡牌不是栈顶卡牌
   */
	bool isTopCard(cocos2d::Node* card);
	/*
	*@brief 手牌区卡牌点击事件回调函数具体实现
	*@param card 卡牌
   */
	void cardMoveShift(cocos2d::Node* card);
};