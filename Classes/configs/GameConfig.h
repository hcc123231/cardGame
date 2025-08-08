#pragma once
#include"../utils/define.h"
#include<vector>
#include<string>
#include "json/document.h"

/*@class CardConfig
* @brief ���忨���������ݽṹ
*���ܣ�
* -�����������ݽṹ
*ְ��
* -���忨���������ݽṹ
*ʹ�ó�����
* -����json�ļ������һ������Ԫ���������������ݽṹ
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
* @brief ��¼���������ļ��е�Ԫ����
*���ܣ�
* -��¼���������ļ��е�Ԫ����
*ְ��
* -��¼���������ļ��е�Ԫ����
* -���������ļ���ȡ�����ļ��еĿ���ԭʼ����
*ʹ�ó�����
* -����json�����ļ�����ȡ���ݣ��洢����
*/
struct GameConfig {
	//����std::vector<CardConfig>
	enum VectorType {
		MASTER_CARDS_DATA=0,
		STACK_CARDS_DATA
	};

	std::vector<CardConfig> _masterCardsData;//�洢���������������ļ��е���������
	std::vector<CardConfig> _stackCardsData;//�洢���������������ļ��е���������
	rapidjson::Document _document;//json�������
	/*
	*@brief ��ʼ��GameConfig���ҽ���json�ļ�
	*@param kfilePath json�ļ�·��
   */
	explicit GameConfig(const std::string& kfilePath);
	
private:
	/*
	*@brief ����json���ݴ��뵽������
	*@param vecType ���������������������ݱ�ʶ
	*@param kobjName json�ļ��еĶ��������
   */
	void parseCardsData(const std::string& kobjName,VectorType vecType);
};

