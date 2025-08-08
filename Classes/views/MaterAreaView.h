#pragma once
#include"cocos2d.h"

/*@class MasterAreaView
* @brief 桌面区场景视图
*功能：
* -显示桌面区游戏场景
*职责：
* -展示手牌区游戏视图
*使用场景：
* -显示桌面区
*/
class MasterAreaView:public cocos2d::Layer{
public:
    /*
     *@brief 初始化函数
     * @return scenePointer 骨架创建成功，nullptr 桌面区视图创建失败
    */
    static cocos2d::Layer* createMasterView();
private:
    CREATE_FUNC(MasterAreaView);
    virtual bool init();
};