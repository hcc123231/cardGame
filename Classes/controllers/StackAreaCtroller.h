#pragma once
#include"views/StackAreaView..h"
#include"models/StackAreaModel.h"
#include"utils/common.h"
#include"models/UndoModel .h"
#include<vector>
#include"managers/StackMoveManager.h"
#include"managers/StackRollbackManager.h"

/*@class StackAreaCtroller
* @brief ������������
*���ܣ�
* -���������������¼��Ļص�����
* -ʵ���������������߼�
*ְ��
* -��ʼ�������������������
* -�����������¼���Ӧ�Ļص�����
*ʹ�ó�����
* -���û������������н���ʱ�������߼���������StackAreaCtroller�ṩ�Ļص�������ʵ��
*/
class StackAreaCtroller {
private:
	StackAreaModel* _model;//��������������ģ��
	cocos2d::Layer* _view;//��������ͼ
	size_t _autoIncrement = 0;//���������Ƶ�����id

	StackMoveManager* _moveManager;//�������Ŀ��Ƶ���ƶ�����������
	StackRollbackManager* _rollbackManager;//�������Ŀ��ƻع�������
public:
	/*
	*@brief �����������������Ŀ�������ģ�ͺ���ͼ
	*@param model ��������ģ��
	*@param view ��ͼ
   */
	void setUp(StackAreaModel* model, cocos2d::Layer* view);
	/*
	*@brief ��ʼ����������������ģ��
	*@param kfilePath json�ļ�·��
   */
	void init(const std::string& kfilePath);
	/*
	*@brief Ϊÿһ�ſ��������¼�������
   */
	void setListener();
	/*
	*@brief ���������ƻع������ص�����
	*@param cardView ����
	*@param originalPosition ����ԭʼλ��
   */
	void undo(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);
public:
	StackAreaCtroller()=default;
	
public:
	/*
	*@brief ���������Ƶ���ƶ������ص�����
	*@param card ����
   */
	void cardMoveShift(cocos2d::Node* card);
};