#ifndef __CARDMODEL_H__
#define __CARDMODEL_H__
#include"../utils/define.h"
/*@class CardModel
* @brief 卡牌本身元数据结构
*功能：
* -定义卡牌本身元数据结构
*职责：
* -定义卡牌本身元数据结构
*使用场景：
* -初始化卡牌时将卡牌的元数据使用CardModel数据结构定义
*/
struct CardModel {
	size_t _cardId;//唯一索引，手牌区和桌面区各自独立
	CARD_FACE_TYPE _cardFace;//卡牌数字
	CARD_SUIT_TYPE _cardSuit;//花色代码
	CARD_POSITION_TYPE _cardPos;//卡牌位置信息

	explicit CardModel(size_t cardId, CARD_FACE_TYPE face, CARD_SUIT_TYPE suit, CARD_POSITION_TYPE num) :_cardId{cardId}, _cardFace { face }\
		, _cardSuit{suit}, _cardPos{num}{}
};


#endif