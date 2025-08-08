#include"MasterRollbackManager.h"
#include"models/UndoModel .h"
#include"views/GameView.h"
void MasterRollbackManager::undo(StackAreaCtroller* stackAreaCtroller) {
	//��ȡ��һ��undo��¼
	if (UndoModel::getInstance()->_undoRecords.empty())return;
	UndoData undoData = UndoModel::getInstance()->_undoRecords.back();
	UndoModel::getInstance()->_undoRecords.pop_back();
	cocos2d::Node* cardView = undoData._cardView;
	cocos2d::Vec2 originalPosition = undoData._originPos;
	ActionType type = undoData._type;
	//�����STACK_CARD_ACTION,����_stackAreaCtrollerȥ��
	if (type == STACK_CARD_ACTION) {
		stackAreaCtroller->undo(cardView, originalPosition);
	}

	//�����MASTER_CARD_ACTION�����������ٲ��Ŷ���


	else if (type == MASTER_CARD_ACTION) {
		_gameModel->_masterModel->_masterCards.push_back(cardView);
		size_t index = 0;
		for (size_t i = 0; i < _gameModel->_stackModel->_stackCards.size(); i++) {
			if (cardView == _gameModel->_stackModel->_stackCards[i])index = i;
		}
		_gameModel->_masterModel->_masterCardModels.push_back(_gameModel->_stackModel->_stackCardModels[index]);

		_gameModel->_stackModel->_stackCards.erase(_gameModel->_stackModel->_stackCards.begin() + index);
		_gameModel->_stackModel->_stackCardModels.erase(_gameModel->_stackModel->_stackCardModels.begin() + index);

		//���_topTopIndex������stack��vecSize����ô_topTopIndexֱ��-1�����û�г�������_topTopIndex=_topIndex+1
		if (_gameModel->_stackModel->_topTopIndex > _gameModel->_stackModel->_stackVecSize) {
			_gameModel->_stackModel->_topTopIndex -= 1;
		}
		else {
			_gameModel->_stackModel->_topTopIndex = _gameModel->_stackModel->_topIndex + 1;
		}
		((GameView*)_gameView)->animateMoveBack(cardView, originalPosition);
	}
}