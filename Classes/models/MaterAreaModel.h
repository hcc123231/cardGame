#pragma once
#include<vector>
#include"cocos2d.h"
#include"CardModel .h"
/*@class MasterAreaModel
* @brief �洢����������Ԫ���ݣ����Ʊ�����ͼ
*���ܣ�
* -�洢�����������������
*ְ��
* -�洢�����������������
*ʹ�ó�����
* -��Ϸ��ʼ��ʱ���������������ݴ��뵽MasterAreaModelģ����
*/
struct MasterAreaModel {
	std::vector<CardModel> _masterCardModels;//����������Ԫ��������
	std::vector<cocos2d::Node*> _masterCards;//������������ͼ��������
};