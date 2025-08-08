#ifndef __CARDVIEW_H__
#define __CARDVIEW_H__

#include "cocos2d.h"
#include"models/CardModel .h"
#include"utils/define.h"
#include<functional>
/*@class CardView
* @brief 卡牌视图展示
*功能：
* -显示卡牌视图
*职责：
* -展示卡牌视图
* -卡牌被点击时调用回调函数处理事件
*使用场景：
* -初始化卡牌视图
*/
class CardView : public cocos2d::Node
{
public:
    /*
     *@brief 初始化卡牌视图
     *@param num 卡牌表面数字
     *@param suit 卡牌表面花色
     *@return CardView* 创建成功， nullptr 创建失败
    */
    static CardView* create(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit);
    /*
    *@brief 设置卡牌回调函数
    *@param func 回调函数
   */
    void setCallback(const std::function<void(cocos2d::Node*)>& func) {
        _funcCallback = func;
    }
    /*
    *@brief 执行回调函数
   */
    void invokCallback() {
        if (_funcCallback)_funcCallback(this);
    }

private:
    bool init(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit);
private:
    std::function<void(cocos2d::Node*)> _funcCallback=nullptr;//存储回调函数
};

#endif 