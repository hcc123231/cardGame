#pragma once
#include"views/StackAreaView..h"
#include"models/StackAreaModel.h"
#include"utils/common.h"
#include"models/UndoModel .h"
#include<vector>
#include"managers/StackMoveManager.h"
#include"managers/StackRollbackManager.h"

/*@class StackAreaCtroller
* @brief 手牌区控制器
*功能：
* -定义手牌区各种事件的回调函数
* -实现手牌区操作的逻辑
*职责：
* -初始化手牌区卡牌相关数据
* -设置手牌区事件对应的回调函数
*使用场景：
* -当用户与手牌区进行交互时产生的逻辑操作都由StackAreaCtroller提供的回调函数来实现
*/
class StackAreaCtroller {
private:
	StackAreaModel* _model;//手牌区卡牌数据模型
	cocos2d::Layer* _view;//手牌区视图
	size_t _autoIncrement = 0;//手牌区卡牌的自增id

	StackMoveManager* _moveManager;//手牌区的卡牌点击移动交互管理器
	StackRollbackManager* _rollbackManager;//手牌区的卡牌回滚管理器
public:
	/*
	*@brief 设置手牌区管理器的卡牌数据模型和视图
	*@param model 卡牌数据模型
	*@param view 视图
   */
	void setUp(StackAreaModel* model, cocos2d::Layer* view);
	/*
	*@brief 初始化手牌区卡牌数据模型
	*@param kfilePath json文件路径
   */
	void init(const std::string& kfilePath);
	/*
	*@brief 为每一张卡牌设置事件监听器
   */
	void setListener();
	/*
	*@brief 手牌区卡牌回滚操作回调函数
	*@param cardView 卡牌
	*@param originalPosition 卡牌原始位置
   */
	void undo(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);
public:
	StackAreaCtroller()=default;
	
public:
	/*
	*@brief 手牌区卡牌点击移动操作回调函数
	*@param card 卡牌
   */
	void cardMoveShift(cocos2d::Node* card);
};