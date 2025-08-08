#include"MasterMoveManager.h"
#include"services/UndoService.h"
#include"views/GameView.h"
void MasterMoveManager::cardMoveShift(cocos2d::Node* card) {
	CCLOG("master card be clicked");
	size_t index = 0;
	for (size_t i = 0; i < _gameModel->_masterModel->_masterCards.size(); i++) {
		if (_gameModel->_masterModel->_masterCards[i] == card) {
			index = i;
		}
	}
	//检查卡牌是否合规
	CARD_FACE_TYPE targetNumber = _gameModel->_stackModel->_stackCardModels[_gameModel->_stackModel->_topTopIndex]._cardFace;
	CARD_FACE_TYPE curNumber = _gameModel->_masterModel->_masterCardModels[index]._cardFace;
	if ((targetNumber > curNumber && targetNumber == curNumber + 1) || (targetNumber < curNumber && targetNumber + 1 == curNumber)) {
		//记录undo logs
		CardView* cardV = (CardView*)_gameModel->_masterModel->_masterCards[index];
		cocos2d::Vec2 oringinPos = cardV->getPosition();
		cocos2d::Vec2 targetPos = cocos2d::Vec2(600, 300);
		recordAction(MASTER_CARD_ACTION, oringinPos, targetPos, cardV);
		//动画
		((GameView*)_gameView)->animateMove(_gameModel->_masterModel->_masterCards[index], cocos2d::Vec2(600, 300));
		//动画播放完以后就将masterArea的卡牌push_back到stackArea中
		_gameModel->_stackModel->_stackCards.push_back(_gameModel->_masterModel->_masterCards[index]);
		_gameModel->_stackModel->_stackCardModels.push_back(_gameModel->_masterModel->_masterCardModels[index]);

		_gameModel->_masterModel->_masterCards.erase(_gameModel->_masterModel->_masterCards.begin() + index);
		_gameModel->_masterModel->_masterCardModels.erase(_gameModel->_masterModel->_masterCardModels.begin() + index);
		//更新stack的_topTopIndex
		_gameModel->_stackModel->_topTopIndex = _gameModel->_stackModel->_stackCards.size() - 1;

	}
}

void MasterMoveManager::recordAction(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card) {
	UndoService::getInstance()->insertRecords(type, oringinPos, targetPos, card, UndoModel::getInstance());
}