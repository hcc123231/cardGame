#include"StackRollbackManager.h"
#include"views/StackAreaView..h"
void StackRollbackManager::stackAreaRollback(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition) {
	//处理数据后播放动画
	if (_stackAreaModel->_topTopIndex <= _stackAreaModel->_stackCards.size())_stackAreaModel->_topTopIndex += 1;//先更新_topTopIndex
	if (_stackAreaModel->_topIndex < 0)_stackAreaModel->_topIndex += 1;
	else {
		if ((size_t)(_stackAreaModel->_topIndex) <= _stackAreaModel->_stackCards.size())_stackAreaModel->_topIndex += 1;//更新stack区域的顶部牌为当前顶部牌的上一张
	}

	((StackAreaView*)_stackAreaView)->animateMoveBack(cardView, originalPosition);
}