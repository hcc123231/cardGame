#include"MaterAreaView.h"
cocos2d::Layer* MasterAreaView::createMasterView() {
	return MasterAreaView::create();
}

bool MasterAreaView::init()
{
    //��ʼ������
    if (!Layer::init())return false;
    return true;
}