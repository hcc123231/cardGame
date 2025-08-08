#pragma once
#include"views/MaterAreaView.h"
#include"models/MaterAreaModel.h"
/*@class MasterAreaCtroller
* @brief 桌面区控制器
*功能：
* -初始化桌面区卡牌数据模型
*职责：
* -初始化桌面区卡牌数据模型
*使用场景：
* -当MasterAreaCtroller被init时，MasterAreaCtroller会初始化它的数据模型
*/
class MasterAreaCtroller {
private:
	MasterAreaModel* _model;//桌面区卡牌数据模型
	cocos2d::Layer* _view;//桌面区视图
	size_t _autoIncrement = 0;//手牌区卡牌的自增id
public:
	/*
	*@brief 设置桌面区管理器的卡牌数据模型和视图
	*@param model 卡牌数据模型
	*@param view 视图
   */
	void setUp(MasterAreaModel* model, cocos2d::Layer* view);
	/*
	*@brief 初始化桌面区卡牌数据模型
	*@param kfilePath json文件路径
   */
	void init(const std::string& kfilePath);
public:
	MasterAreaCtroller()=default;
};