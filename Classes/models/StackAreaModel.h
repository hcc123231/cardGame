#pragma once
#include<vector>
#include"cocos2d.h"
#include"CardModel .h"
#include"UndoModel .h"
/*@class StackAreaModel
* @brief 存储手牌区卡牌元数据，卡牌本身视图
*功能：
* -存储手牌区卡牌相关数据
*职责：
* -存储手牌区卡牌相关数据
*使用场景：
* -游戏初始化时将手牌区卡牌数据存入到StackAreaModel模型中
*/
struct StackAreaModel {
	std::vector<CardModel> _stackCardModels;//手牌区卡牌元数据容器
	std::vector<cocos2d::Node*> _stackCards;//手牌区卡牌视图对象容器
	size_t _stackVecSize;//存储手牌区视图对象初始化时容器中元素个数
	int _topIndex;//存储手牌区栈顶元素下标
	size_t _topTopIndex;//存储手牌区目标位置元素下标
};