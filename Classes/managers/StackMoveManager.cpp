#include"StackMoveManager.h"
#include"views/StackAreaView..h"
#include"services/UndoService.h"
bool StackMoveManager::isTopCard(cocos2d::Node* card) {
	if (_model->_topIndex < 0)return true;
	if (card == _model->_stackCards[_model->_topIndex]) {
		return true;
	}
	return false;
}
void StackMoveManager::recordAction(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card) {
	UndoService::getInstance()->insertRecords(type, oringinPos, targetPos, card, UndoModel::getInstance());
}

void StackMoveManager::cardMoveShift(cocos2d::Node* card) {
	StackAreaView* view = ((StackAreaView*)_view);
	CardView* cardV = (CardView*)_model->_stackCards[_model->_topIndex];
	//�ȼ�¼stackAction
	cocos2d::Vec2 oringinPos = cardV->getPosition();
	cocos2d::Vec2 targetPos = cocos2d::Vec2(600, 300);
	recordAction(STACK_CARD_ACTION, oringinPos, targetPos, cardV);

	_model->_topTopIndex = _model->_topIndex;//�ȸ���_topTopIndex
	_model->_topIndex -= 1;//����stack����Ķ�����Ϊ��ǰ�����Ƶ���һ��
	view->animateMove(cardV, targetPos);
}