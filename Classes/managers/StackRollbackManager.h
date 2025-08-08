#pragma once
#include"cocos2d.h"
#include"models/StackAreaModel.h"
/*@class StackRollbackManager
* @brief 管理手牌区回滚操作
*功能：
* -实现手牌区回滚操作
*职责：
* -定义手牌区回滚操作
*使用场景：
* -当手牌区发生回滚操作时StackRollbackManager调用回滚操作函数
*/
class StackRollbackManager {
private:
	StackAreaModel* _stackAreaModel;//手牌区卡牌数据模型
	cocos2d::Layer* _stackAreaView;//手牌区视图引用
public:
	StackRollbackManager(StackAreaModel* stackAreaModel, cocos2d::Layer* stackAreaView) :_stackAreaModel{ stackAreaModel }\
		, _stackAreaView{ stackAreaView }{}

    /*
     *@brief 手牌区回滚操作
     *@param cardView 卡牌引用
     *@param originalPosition 卡牌原位置
    */
	void stackAreaRollback(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);
};