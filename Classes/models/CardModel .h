#ifndef __CARDMODEL_H__
#define __CARDMODEL_H__
#include"../utils/define.h"
/*@class CardModel
* @brief ���Ʊ���Ԫ���ݽṹ
*���ܣ�
* -���忨�Ʊ���Ԫ���ݽṹ
*ְ��
* -���忨�Ʊ���Ԫ���ݽṹ
*ʹ�ó�����
* -��ʼ������ʱ�����Ƶ�Ԫ����ʹ��CardModel���ݽṹ����
*/
struct CardModel {
	size_t _cardId;//Ψһ�����������������������Զ���
	CARD_FACE_TYPE _cardFace;//��������
	CARD_SUIT_TYPE _cardSuit;//��ɫ����
	CARD_POSITION_TYPE _cardPos;//����λ����Ϣ

	explicit CardModel(size_t cardId, CARD_FACE_TYPE face, CARD_SUIT_TYPE suit, CARD_POSITION_TYPE num) :_cardId{cardId}, _cardFace { face }\
		, _cardSuit{suit}, _cardPos{num}{}
};


#endif