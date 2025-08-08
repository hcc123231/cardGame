#ifndef __GAMECTROLLER_H__
#define __GAMECTROLLER_H__
#include"views/GameView.h"
#include"models/GameModel .h"
#include"MasterAreaCtroller.h"
#include"StackAreaCtroller.h"
#include<vector>
#include"managers/MasterMoveManager.h"
#include"managers/MasterRollbackManager.h"
/*@class GameCtroller
* @brief ��Ϸ���̿�����
*���ܣ�
* -��ʼ����������������������������
* -Ϊ���������������¼�����
* -�������������Ƶĵ���ƶ�����
* -Ϊ�������İ�ť���ûص�������
* -Ϊ��Ϸ���߼������ṩ���
*ְ��
* -����������Ϸ����ת
*ʹ�ó�����
* -������GameCtroller֮�󣬵�����startGame��ʽ��ʼ��Ϸ
*/
class GameCtroller {
private:
	cocos2d::Layer* _gameView;//��Ϸ����ͼ����
	GameModel* _gameModel;//��Ϸ����ģ��

private:
	MasterMoveManager* _moveManager;//���������Ƶ���ƶ�������
	MasterRollbackManager* _rollbackManager;//�������ع�����������
	MasterAreaCtroller* _masterAreaCtroller;//������������
	StackAreaCtroller* _stackAreaCtroller;//������������
private:
	/*
	*@brief ��ʼ��GameCtroller�еĳ�Ա����
	*@param filePath json�ļ�·��
   */
	void init(std::string filePath);

	/*
	*@brief Ϊ�������������ü���
   */
	void setListener();

	/*
	*@brief �������������Ƶĵ���ƶ�����
	*@param card ���ƶ�������
   */
	void cardMoveShift(cocos2d::Node* card);

	/*
	*@brief Ϊ��ť�����¼�����
   */
	void buttonSetListener();

public:
	GameCtroller() = delete;
	GameCtroller(cocos2d::Layer* view, GameModel* model, std::string filePath) :_gameView{ view }, _gameModel{ model }{ init(filePath); };

	/*
	*@brief �߼��Ͽ�ʼ��Ϸ
   */
	void startGame();

};

#endif