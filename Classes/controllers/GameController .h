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
* @brief 游戏流程控制器
*功能：
* -初始化手牌区控制器和桌面区控制器
* -为桌面区卡牌设置事件监听
* -定义桌面区卡牌的点击移动操作
* -为手牌区的按钮设置回调处理函数
* -为游戏的逻辑流程提供入口
*职责：
* -负责整个游戏的运转
*使用场景：
* -创建出GameCtroller之后，调用其startGame正式开始游戏
*/
class GameCtroller {
private:
	cocos2d::Layer* _gameView;//游戏总视图引用
	GameModel* _gameModel;//游戏数据模型

private:
	MasterMoveManager* _moveManager;//桌面区卡牌点击移动管理器
	MasterRollbackManager* _rollbackManager;//桌面区回滚操作管理器
	MasterAreaCtroller* _masterAreaCtroller;//桌面区控制器
	StackAreaCtroller* _stackAreaCtroller;//手牌区控制器
private:
	/*
	*@brief 初始化GameCtroller中的成员函数
	*@param filePath json文件路径
   */
	void init(std::string filePath);

	/*
	*@brief 为桌面区卡牌设置监听
   */
	void setListener();

	/*
	*@brief 定义桌面区卡牌的点击移动操作
	*@param card 卡牌对象引用
   */
	void cardMoveShift(cocos2d::Node* card);

	/*
	*@brief 为按钮设置事件监听
   */
	void buttonSetListener();

public:
	GameCtroller() = delete;
	GameCtroller(cocos2d::Layer* view, GameModel* model, std::string filePath) :_gameView{ view }, _gameModel{ model }{ init(filePath); };

	/*
	*@brief 逻辑上开始游戏
   */
	void startGame();

};

#endif