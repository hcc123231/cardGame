#pragma once
#include"utils/common.h"
#include"views/CardView.h"
#include"models/UndoModel .h"
//单例模式，处理插入undorecords


/*@class UndoService
* @brief 记录回滚操作
*功能：
* -对回滚数据模型进行insert操作
*职责：
* -insert一条回滚数据到回滚模型中
*使用场景：
* -用户点击操作时的回滚操作记录
*/
class UndoService {
public:
    /*
     *@brief 插入一条操作信息到回滚数据模型中
     *@param type 回滚操作类型
     *@param originPos 卡牌原位置
     *@param curPos 卡牌即将移动到的位置
     *@param cardView 具体卡牌
     *@param model 回滚模型
    */
	void insertRecords(ActionType type, cocos2d::Vec2 originPos, cocos2d::Vec2 curPos, CardView* cardView,UndoModel* model) {
        model->_undoRecords.emplace_back(type, originPos, curPos, cardView);
        CCLOG("insert");
	}
    /*
     *@brief 获取单例模式下的UndoService一个实例
    */
    static UndoService* getInstance() {
        if (!_undoService) {
            _undoService = new UndoService();
            return _undoService;
        }
        else {
            return _undoService;
        }
    }
private:
	UndoService() = default;
    static UndoService* _undoService;//UndoService单例
};
