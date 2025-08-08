#pragma once
#include"../utils/define.h"
#include<vector>
#include<string>
#include "json/document.h"

/*@class CardConfig
* @brief 定义卡牌配置数据结构
*功能：
* -卡牌配置数据结构
*职责：
* -定义卡牌配置数据结构
*使用场景：
* -解析json文件后插入一条卡牌元数据所依赖的数据结构
*/
struct CardConfig {
	CARD_FACE_TYPE _face=0;
	CARD_SUIT_TYPE _suit=-1;
	CARD_POSITION_TYPE _pos = { 0,0 };
	CARD_FACE_TYPE getFace()const noexcept;
	CARD_SUIT_TYPE getSuit()const noexcept;
	CARD_POSITION_TYPE getPos()const noexcept;
	CardConfig()noexcept = default;
	CardConfig(CARD_FACE_TYPE face, CARD_SUIT_TYPE suit, CARD_POSITION_TYPE pos) :_face{ face }, _suit{ suit }, _pos{ pos } {}
};

/*@class GameConfig
* @brief 记录卡牌配置文件中的元数据
*功能：
* -记录卡牌配置文件中的元数据
*职责：
* -记录卡牌配置文件中的元数据
* -解析配置文件获取配置文件中的卡牌原始数据
*使用场景：
* -解析json配置文件，获取数据，存储数据
*/
struct GameConfig {
	//区别std::vector<CardConfig>
	enum VectorType {
		MASTER_CARDS_DATA=0,
		STACK_CARDS_DATA
	};

	std::vector<CardConfig> _masterCardsData;//存储桌面区卡牌配置文件中的数据数组
	std::vector<CardConfig> _stackCardsData;//存储手牌区卡牌配置文件中的数据数组
	rapidjson::Document _document;//json解析结果
	/*
	*@brief 初始化GameConfig并且解析json文件
	*@param kfilePath json文件路径
   */
	explicit GameConfig(const std::string& kfilePath);
	
private:
	/*
	*@brief 解析json数据存入到数组中
	*@param vecType 区分手牌区和桌面区数据标识
	*@param kobjName json文件中的对象具体名
   */
	void parseCardsData(const std::string& kobjName,VectorType vecType);
};

