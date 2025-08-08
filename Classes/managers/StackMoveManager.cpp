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
	//先记录stackAction
	cocos2d::Vec2 oringinPos = cardV->getPosition();
	cocos2d::Vec2 targetPos = cocos2d::Vec2(600, 300);
	recordAction(STACK_CARD_ACTION, oringinPos, targetPos, cardV);

	_model->_topTopIndex = _model->_topIndex;//先更新_topTopIndex
	_model->_topIndex -= 1;//更新stack区域的顶部牌为当前顶部牌的上一张
	view->animateMove(cardV, targetPos);
}