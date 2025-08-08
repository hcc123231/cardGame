#pragma once
#include"cocos2d.h"
#include"models/GameModel .h"
#include"controllers/StackAreaCtroller.h"
/*@class MasterRollbackManager
* @brief �����������ع�����
*���ܣ�
* -ʵ���������ع�����
*ְ��
* -�����������ع�����
*ʹ�ó�����
* -�������������ع�����ʱMasterRollbackManager���ûع���������
*/
class MasterRollbackManager {
private:
	cocos2d::Layer* _gameView;//��������ͼ����
	GameModel* _gameModel;//��������������ģ��
public:
	MasterRollbackManager(cocos2d::Layer* gameView, GameModel* gameModel) :_gameView{ gameView }, _gameModel{ gameModel } {};
	/*
	 *@brief �������ع�����
	 *@param stackAreaCtroller ������������
	*/
	void undo(StackAreaCtroller* stackAreaCtroller);
};