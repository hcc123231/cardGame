#pragma once
#include"views/MaterAreaView.h"
#include"models/MaterAreaModel.h"
/*@class MasterAreaCtroller
* @brief ������������
*���ܣ�
* -��ʼ����������������ģ��
*ְ��
* -��ʼ����������������ģ��
*ʹ�ó�����
* -��MasterAreaCtroller��initʱ��MasterAreaCtroller���ʼ����������ģ��
*/
class MasterAreaCtroller {
private:
	MasterAreaModel* _model;//��������������ģ��
	cocos2d::Layer* _view;//��������ͼ
	size_t _autoIncrement = 0;//���������Ƶ�����id
public:
	/*
	*@brief �����������������Ŀ�������ģ�ͺ���ͼ
	*@param model ��������ģ��
	*@param view ��ͼ
   */
	void setUp(MasterAreaModel* model, cocos2d::Layer* view);
	/*
	*@brief ��ʼ����������������ģ��
	*@param kfilePath json�ļ�·��
   */
	void init(const std::string& kfilePath);
public:
	MasterAreaCtroller()=default;
};