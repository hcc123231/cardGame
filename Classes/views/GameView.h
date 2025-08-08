#ifndef __GAMEVIEW_H__
#define __GAMEVIEW_H__

#include "cocos2d.h"
#include "ui/UIButton.h"

#include"controllers/GameController .h"

#include"CardView.h"

/*@class GameView
* @brief ����Ϸ����չʾ
*���ܣ�
* -��ʾ����Ϸ����
* -�������������������������ƽ�������
*ְ��
* -�������������������������� ����ƶ�/�ع� �����Ĳ�������
* -չʾ����Ϸ��ͼ
*ʹ�ó�����
* -�û�������������ƣ�������Ӧ�Ķ������û���������������ˡ���ť���Żع�����
* -չʾ��Ϸ�ܳ���
*/
class GameView : public cocos2d::Layer
{
public:
    /*
     *@brief ��ʼ������
     * @return layerPointer �Ǽܴ����ɹ���nullptr ��������ͼ����ʧ��
    */
    static cocos2d::Layer* createLayer();//��ʼ���õ�������Ϸ����

    virtual bool init();

    CREATE_FUNC(GameView);
    /*
     *@brief ���������� ����ƶ� ��������
     *@param cardView ���屻����Ŀ���
     *@param targetPosition ���ƶ���Ҫ�ƶ�����λ��
    */
    void animateMove(cocos2d::Node* cardView, const cocos2d::Vec2& targetPosition);
    /*
     *@brief ���������� �ع� ��������
     *@param cardView ���屻����Ŀ���
     *@param originalPosition ���ƶ���Ҫ�ƶ�����λ��
    */
    void animateMoveBack(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);
public:
    cocos2d::Layer* _areaMaterCard;//��������Ϸ��ͼ
    cocos2d::Layer* _areaStackCard;//��������Ϸ��ͼ

};

#endif 