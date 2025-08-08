#ifndef __GAMEMODEL_H__
#define __GAMEMODEL_H__
#include<vector>
#include"CardModel .h"
#include"MaterAreaModel.h"
#include"StackAreaModel.h"
#include<string>
/*@class GameModel
* @brief �洢�����������������ģ������
*���ܣ�
* -�洢�����������������ģ������
*ְ��
* -�洢�����������������ģ������
*ʹ�ó�����
* -��Ϸ���̿���������ͨ��GameModel�������п�������
*/
class GameModel {
public:
	MasterAreaModel* _masterModel;//��������������ģ��
	StackAreaModel* _stackModel;//��������������ģ��
public:
	GameModel() {
		_masterModel = new MasterAreaModel();
		_stackModel = new StackAreaModel();
	}
};


#endif
