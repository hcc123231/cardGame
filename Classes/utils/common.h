#pragma once
#include"define.h"
#include"cardType.h"
/*
     *@brief �����ֺͻ�ɫö��תΪ��Ӧ���ַ���
     *@param num ���Ʊ������֣�������
     *@param suit ���Ʊ��滨ɫ��������
     *@param numStr ���Ʊ��������ַ��� �ַ�����
     *@param suitStr ���Ʊ��滨ɫ�ַ��� �ַ�����
     *@return CardView* �����ɹ��� nullptr ����ʧ��
    */
inline void shift(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit, std::string& numStr, std::string& suitStr) {
    switch (num)
    {
    case CFT_ACE:numStr = "A"; break;
    case CFT_TWO:numStr = "2"; break;
    case CFT_THREE:numStr = "3"; break;
    case CFT_FOUR:numStr = "4"; break;
    case CFT_FIVE:numStr = "5"; break;
    case CFT_SIX:numStr = "6"; break;
    case CFT_SEVEN:numStr = "7"; break;
    case CFT_EIGHT:numStr = "8"; break;
    case CFT_NINE:numStr = "9"; break;
    case CFT_TEN:numStr = "10"; break;
    case CFT_JACK:numStr = "J"; break;
    case CFT_QUEEN:numStr = "Q"; break;
    case CFT_KING:numStr = "K"; break;
    default:break;
    }
    switch (suit)
    {
    case CST_CLUBS:suitStr = "club"; break;
    case CST_DIAMONDS:suitStr = "diamond"; break;
    case CST_HEARTS:suitStr = "heart"; break;
    case CST_SPADES:suitStr = "spade"; break;
    default:break;
    }
}

//undo��������
enum ActionType {
    STACK_CARD_ACTION = 0,
    MASTER_CARD_ACTION
};