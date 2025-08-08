#ifndef __GAMEVIEW_H__
#define __GAMEVIEW_H__

#include "cocos2d.h"
#include "ui/UIButton.h"

#include"controllers/GameController .h"

#include"CardView.h"

/*@class GameView
* @brief 总游戏场景展示
*功能：
* -显示总游戏场景
* -播放桌面区卡牌与手牌区卡牌交互动画
*职责：
* -控制桌面区卡牌与手牌区卡牌 点击移动/回滚 动画的播放流程
* -展示总游戏视图
*使用场景：
* -用户点击桌面区卡牌，播放相应的动画，用户点击桌面区“回退”按钮播放回滚动画
* -展示游戏总场景
*/
class GameView : public cocos2d::Layer
{
public:
    /*
     *@brief 初始化函数
     * @return layerPointer 骨架创建成功，nullptr 桌面区视图创建失败
    */
    static cocos2d::Layer* createLayer();//初始化得到整个游戏界面

    virtual bool init();

    CREATE_FUNC(GameView);
    /*
     *@brief 桌面区卡牌 点击移动 动画播放
     *@param cardView 具体被点击的卡牌
     *@param targetPosition 卡牌动画要移动到的位置
    */
    void animateMove(cocos2d::Node* cardView, const cocos2d::Vec2& targetPosition);
    /*
     *@brief 桌面区卡牌 回滚 动画播放
     *@param cardView 具体被点击的卡牌
     *@param originalPosition 卡牌动画要移动到的位置
    */
    void animateMoveBack(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);
public:
    cocos2d::Layer* _areaMaterCard;//桌面区游戏视图
    cocos2d::Layer* _areaStackCard;//手牌区游戏视图

};

#endif 