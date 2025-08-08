#pragma once
#include<vector>
#include"cocos2d.h"
#include"CardModel .h"
#include"UndoModel .h"
/*@class StackAreaModel
* @brief �洢����������Ԫ���ݣ����Ʊ�����ͼ
*���ܣ�
* -�洢�����������������
*ְ��
* -�洢�����������������
*ʹ�ó�����
* -��Ϸ��ʼ��ʱ���������������ݴ��뵽StackAreaModelģ����
*/
struct StackAreaModel {
	std::vector<CardModel> _stackCardModels;//����������Ԫ��������
	std::vector<cocos2d::Node*> _stackCards;//������������ͼ��������
	size_t _stackVecSize;//�洢��������ͼ�����ʼ��ʱ������Ԫ�ظ���
	int _topIndex;//�洢������ջ��Ԫ���±�
	size_t _topTopIndex;//�洢������Ŀ��λ��Ԫ���±�
};