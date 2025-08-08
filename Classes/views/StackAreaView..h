#pragma once
#include"cocos2d.h"
#include "ui/UIButton.h"
#include"CardView.h"
#include<functional>

/*@class StackAreaView
* @brief 手牌区场景视图
*功能：
* -显示手牌区游戏场景
* -播放手牌区 点击移动/回滚 动画
*职责：
* -控制手牌区 点击移动/回滚 动画的播放流程
* -展示手牌区游戏视图
*使用场景：
* -用户点击手牌区卡牌，播放相应的动画，用户点击手牌区“回退”按钮播放回滚动画
*/
class StackAreaView:public cocos2d::Layer{
public:
    /*
     *@brief 初始化函数
     * @return scenePointer 骨架创建成功，nullptr 手牌区视图创建失败
    */
    static cocos2d::Layer* createStackView();
    /*
     *@brief 卡牌 点击移动 动画播放
     *@param cardView 具体被点击的卡牌
     *@param targetPosition 卡牌动画要移动到的位置
    */
    void animateMove(cocos2d::Node* cardView, const cocos2d::Vec2& targetPosition);
    /*
     *@brief 卡牌 回滚 动画播放
     *@param cardView 具体被点击的卡牌
     *@param originalPosition 卡牌动画要移动到的位置
    */
    void animateMoveBack(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition);

    cocos2d::ui::Button* _backButton;//手牌区回退按钮控件

    /*
     *@brief 设置回退按钮的回调函数
     *@param func 回调函数
    */
    void setBtnClickedCallback(std::function<void()> func) {
        _btnClickedCallback = func;
    }
    /*
     *@brief 调用回退按钮的回调函数
    */
    void btnClickedCallback() {
        _btnClickedCallback();
    }
    
private:
    virtual bool init();

    CREATE_FUNC(StackAreaView);

    std::function<void()> _btnClickedCallback;//存储回调函数
    
};