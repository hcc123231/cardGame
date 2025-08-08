#pragma once
#include"cocos2d.h"
#include"models/StackAreaModel.h"
/*@class StackRollbackManager
* @brief �����������ع�����
*���ܣ�
* -ʵ���������ع�����
*ְ��
* -�����������ع�����
*ʹ�ó�����
* -�������������ع�����ʱStackRollbackManager���ûع���������
*/
class StackRollbackManager {
private:
	StackAreaModel* _stackAreaModel;//��������������ģ��
	cocos2d::Layer* _stackAreaView;//��������ͼ����
public:
	StackRollbackManager(StackAreaModel* stackAreaModel, cocos2d::Layer* stackAreaView) :_stackAreaModel{ stackAreaModel }\
		, _stackAreaView{ stackAreaView }{}

    /*
     *@brief �������ع�����
     *@param cardView ��������
     *@param originalPosition ����ԭλ��
    */
	void stackAreaRollback(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);
};