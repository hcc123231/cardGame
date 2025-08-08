#pragma once
#include"cocos2d.h"
#include "ui/UIButton.h"
#include"CardView.h"
#include<functional>

/*@class StackAreaView
* @brief ������������ͼ
*���ܣ�
* -��ʾ��������Ϸ����
* -���������� ����ƶ�/�ع� ����
*ְ��
* -���������� ����ƶ�/�ع� �����Ĳ�������
* -չʾ��������Ϸ��ͼ
*ʹ�ó�����
* -�û�������������ƣ�������Ӧ�Ķ������û���������������ˡ���ť���Żع�����
*/
class StackAreaView:public cocos2d::Layer{
public:
    /*
     *@brief ��ʼ������
     * @return scenePointer �Ǽܴ����ɹ���nullptr ��������ͼ����ʧ��
    */
    static cocos2d::Layer* createStackView();
    /*
     *@brief ���� ����ƶ� ��������
     *@param cardView ���屻����Ŀ���
     *@param targetPosition ���ƶ���Ҫ�ƶ�����λ��
    */
    void animateMove(cocos2d::Node* cardView, const cocos2d::Vec2& targetPosition);
    /*
     *@brief ���� �ع� ��������
     *@param cardView ���屻����Ŀ���
     *@param originalPosition ���ƶ���Ҫ�ƶ�����λ��
    */
    void animateMoveBack(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);

    cocos2d::ui::Button* _backButton;//���������˰�ť�ؼ�

    /*
     *@brief ���û��˰�ť�Ļص�����
     *@param func �ص�����
    */
    void setBtnClickedCallback(std::function<void()> func) {
        _btnClickedCallback = func;
    }
    /*
     *@brief ���û��˰�ť�Ļص�����
    */
    void btnClickedCallback() {
        _btnClickedCallback();
    }
    
private:
    virtual bool init();

    CREATE_FUNC(StackAreaView);

    std::function<void()> _btnClickedCallback;//�洢�ص�����
    
};