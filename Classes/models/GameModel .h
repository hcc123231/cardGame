#ifndef __GAMEMODEL_H__
#define __GAMEMODEL_H__
#include<vector>
#include"CardModel .h"
#include"MaterAreaModel.h"
#include"StackAreaModel.h"
#include<string>
/*@class GameModel
* @brief 存储手牌区和桌面区相关模型数据
*功能：
* -存储手牌区和桌面区相关模型数据
*职责：
* -存储手牌区和桌面区相关模型数据
*使用场景：
* -游戏流程控制器可以通过GameModel访问所有卡牌数据
*/
class GameModel {
public:
	MasterAreaModel* _masterModel;//桌面区卡牌数据模型
	StackAreaModel* _stackModel;//手牌区卡牌数据模型
public:
	GameModel() {
		_masterModel = new MasterAreaModel();
		_stackModel = new StackAreaModel();
	}
};


#endif
