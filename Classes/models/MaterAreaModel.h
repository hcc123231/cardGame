#pragma once
#include<vector>
#include"cocos2d.h"
#include"CardModel .h"
/*@class MasterAreaModel
* @brief 存储桌面区卡牌元数据，卡牌本身视图
*功能：
* -存储桌面区卡牌相关数据
*职责：
* -存储桌面区卡牌相关数据
*使用场景：
* -游戏初始化时将桌面区卡牌数据存入到MasterAreaModel模型中
*/
struct MasterAreaModel {
	std::vector<CardModel> _masterCardModels;//桌面区卡牌元数据容器
	std::vector<cocos2d::Node*> _masterCards;//桌面区卡牌视图对象容器
};