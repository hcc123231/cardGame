#pragma once
#include"cocos2d.h"
//#include"views/GameView.h"
#include"models/GameModel .h"
/*@class MasterMoveManager
* @brief ��������������ƶ�����
*���ܣ�
* -�����������Ƶĵ���¼��Ļص��������ж���
*ְ��
* -�������������Ƶ���¼��������ƶ�
*ʹ�ó�����
* -���������Ŀ��Ʊ����ʱ�������ص�����������ص�����������cardMoveShift�������
*/
class MasterMoveManager {
private:
	cocos2d::Layer* _gameView;//��������ͼ����
	GameModel* _gameModel; //��������������ģ��

public:
	MasterMoveManager(cocos2d::Layer* gameView, GameModel* gameModel) :_gameView{ gameView }, _gameModel{ gameModel } {};
	/*
	*@brief ���������Ƶ���¼��ص���������ʵ��
	*@param card ����
   */
	void cardMoveShift(cocos2d::Node* card);
	/*
	*@brief ��¼һ���ع�����
	*@param type �ع���������
	*@param oringinPos ����ԭλ��
	*@param targetPos ����Ŀ��λ��
	*@param card ����
   */
	void recordAction(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card);
};