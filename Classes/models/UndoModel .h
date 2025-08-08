#pragma once
#include"cocos2d.h"
#include"views/CardView.h"
#include"utils/common.h"
//undorecords也做成单例模式


/*@class UndoData
* @brief 回滚数据
*功能：
* -回滚数据结构
*职责：
* -定义回滚数据结构
*使用场景：
* -插入一条回滚记录
*/
struct UndoData {
	cocos2d::Vec2 _originPos;
	cocos2d::Vec2 _curPos;//移动后位置也就是当前位置
	CardView* _cardView;
	ActionType _type;
	UndoData(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card) :_type{type}, \
	_originPos{ oringinPos }, _curPos{ targetPos }, _cardView{ card }{}
};
/*@class UndoModel
* @brief 记录回滚操作
*功能：
* -存储回滚操作记录
*职责：
* -记录回滚操作
*使用场景：
* -用户点击卡牌时插入一条回滚记录到UndoModel
*/
struct UndoModel {
	
	std::vector<UndoData> _undoRecords;//回滚操作记录栈
	static UndoModel* getInstance() {
		if (!_undoModel) {
			_undoModel = new UndoModel();
			return _undoModel;
		}
		else {
			return _undoModel;
		}
	}
private:
	UndoModel() = default;
	static UndoModel* _undoModel;//回滚记录单例
};
