#include"StackRollbackManager.h"
#include"views/StackAreaView..h"
void StackRollbackManager::stackAreaRollback(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition) {
	//�������ݺ󲥷Ŷ���
	if (_stackAreaModel->_topTopIndex <= _stackAreaModel->_stackCards.size())_stackAreaModel->_topTopIndex += 1;//�ȸ���_topTopIndex
	if (_stackAreaModel->_topIndex < 0)_stackAreaModel->_topIndex += 1;
	else {
		if ((size_t)(_stackAreaModel->_topIndex) <= _stackAreaModel->_stackCards.size())_stackAreaModel->_topIndex += 1;//����stack����Ķ�����Ϊ��ǰ�����Ƶ���һ��
	}

	((StackAreaView*)_stackAreaView)->animateMoveBack(cardView, originalPosition);
}