#pragma once
#include"cocos2d.h"
#include"models/StackAreaModel.h"
#include"utils/cardType.h"
/*@class StackMoveManager
* @brief ��������������ƶ�����
*���ܣ�
* -�����������Ƶĵ���¼��Ļص��������ж���
*ְ��
* -�������������Ƶ���¼��������ƶ�
*ʹ�ó�����
* -���������Ŀ��Ʊ����ʱ�������ص�����������ص�����������cardMoveShift�������
*/
class StackMoveManager {
private:
	StackAreaModel* _model;//��������������ģ��
	cocos2d::Layer* _view;//��������ͼ����
public:
	StackMoveManager(StackAreaModel* model, cocos2d::Layer* view):_model{model},_view{view}{}
	/*
	*@brief ��¼һ���ع�����
	*@param type �ع���������
	*@param oringinPos ����ԭλ��
	*@param targetPos ����Ŀ��λ��
	*@param card ����
   */
	void recordAction(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card);

	/*
	*@brief �ж���������ǰ��������Ƿ�Ϊջ������
	*@param card ����
	*@return true ��������ǰ���������ջ�����ƣ� false ��������ǰ������Ʋ���ջ������
   */
	bool isTopCard(cocos2d::Node* card);
	/*
	*@brief ���������Ƶ���¼��ص���������ʵ��
	*@param card ����
   */
	void cardMoveShift(cocos2d::Node* card);
};