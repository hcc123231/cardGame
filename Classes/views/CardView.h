#ifndef __CARDVIEW_H__
#define __CARDVIEW_H__

#include "cocos2d.h"
#include"models/CardModel .h"
#include"utils/define.h"
#include<functional>
/*@class CardView
* @brief ������ͼչʾ
*���ܣ�
* -��ʾ������ͼ
*ְ��
* -չʾ������ͼ
* -���Ʊ����ʱ���ûص����������¼�
*ʹ�ó�����
* -��ʼ��������ͼ
*/
class CardView : public cocos2d::Node
{
public:
    /*
     *@brief ��ʼ��������ͼ
     *@param num ���Ʊ�������
     *@param suit ���Ʊ��滨ɫ
     *@return CardView* �����ɹ��� nullptr ����ʧ��
    */
    static CardView* create(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit);
    /*
    *@brief ���ÿ��ƻص�����
    *@param func �ص�����
   */
    void setCallback(const std::function<void(cocos2d::Node*)>& func) {
        _funcCallback = func;
    }
    /*
    *@brief ִ�лص�����
   */
    void invokCallback() {
        if (_funcCallback)_funcCallback(this);
    }

private:
    bool init(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit);
private:
    std::function<void(cocos2d::Node*)> _funcCallback=nullptr;//�洢�ص�����
};

#endif 