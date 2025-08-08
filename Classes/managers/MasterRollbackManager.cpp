#include"MasterRollbackManager.h"
#include"models/UndoModel .h"
#include"views/GameView.h"
void MasterRollbackManager::undo(StackAreaCtroller* stackAreaCtroller) {
	//先取出一条undo记录
	if (UndoModel::getInstance()->_undoRecords.empty())return;
	UndoData undoData = UndoModel::getInstance()->_undoRecords.back();
	UndoModel::getInstance()->_undoRecords.pop_back();
	cocos2d::Node* cardView = undoData._cardView;
	cocos2d::Vec2 originalPosition = undoData._originPos;
	ActionType type = undoData._type;
	//如果是STACK_CARD_ACTION,丢给_stackAreaCtroller去做
	if (type == STACK_CARD_ACTION) {
		stackAreaCtroller->undo(cardView, originalPosition);
	}

	//如果是MASTER_CARD_ACTION，则处理数据再播放动画


	else if (type == MASTER_CARD_ACTION) {
		_gameModel->_masterModel->_masterCards.push_back(cardView);
		size_t index = 0;
		for (size_t i = 0; i < _gameModel->_stackModel->_stackCards.size(); i++) {
			if (cardView == _gameModel->_stackModel->_stackCards[i])index = i;
		}
		_gameModel->_masterModel->_masterCardModels.push_back(_gameModel->_stackModel->_stackCardModels[index]);

		_gameModel->_stackModel->_stackCards.erase(_gameModel->_stackModel->_stackCards.begin() + index);
		_gameModel->_stackModel->_stackCardModels.erase(_gameModel->_stackModel->_stackCardModels.begin() + index);

		//如果_topTopIndex超过了stack的vecSize，那么_topTopIndex直接-1，如果没有超过，那_topTopIndex=_topIndex+1
		if (_gameModel->_stackModel->_topTopIndex > _gameModel->_stackModel->_stackVecSize) {
			_gameModel->_stackModel->_topTopIndex -= 1;
		}
		else {
			_gameModel->_stackModel->_topTopIndex = _gameModel->_stackModel->_topIndex + 1;
		}
		((GameView*)_gameView)->animateMoveBack(cardView, originalPosition);
	}
}