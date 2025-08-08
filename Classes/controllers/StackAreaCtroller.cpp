#include"StackAreaCtroller.h"
#include"views/CardView.h"
#include"configs/GameConfig.h"
#include"services/UndoService.h"
using namespace std::placeholders;
using namespace cocos2d;
void StackAreaCtroller::setUp(StackAreaModel* model, cocos2d::Layer* view) {
	_model = model;
	_view = view;
	_moveManager = new StackMoveManager{ model ,view };
	_rollbackManager = new StackRollbackManager{ model ,view };

}

void StackAreaCtroller::init(const std::string& kfilePath) {
	//初始化初始化_model的_stackCardModels
	GameConfig conf(kfilePath);
	for (size_t i = 0; i < conf._stackCardsData.size(); i++) {
		CardConfig cardConf = conf._stackCardsData.at(i);
		_model->_stackCardModels.emplace_back(_autoIncrement++,cardConf.getFace(), cardConf.getSuit(), cardConf.getPos());
	}
	
	//使用stackModel初始化卡牌并且将CardView放入_model->_stackCards
	for (int i = 0; i < _model->_stackCardModels.size(); i++) {
		CARD_FACE_TYPE num = _model->_stackCardModels[i]._cardFace;
		CARD_SUIT_TYPE suit = _model->_stackCardModels[i]._cardSuit;
		CardView* cardView = CardView::create(num, suit);
		_model->_stackCards.push_back(cardView);
		CARD_POSITION_TYPE pos = _model->_stackCardModels[i]._cardPos;
		cardView->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
		cardView->setPosition(pos);

		_view->addChild(cardView);
	}
	if (_model->_stackCards.size() < 2)_model->_topIndex = 0;
	else _model->_topIndex = _model->_stackCards.size() - 2;
	if (_model->_stackCards.size() == 0)_model->_topTopIndex = 0;
	else _model->_topTopIndex = _model->_stackCards.size() - 1;
	_model->_stackVecSize = _model->_stackCardModels.size();
	
}


void StackAreaCtroller::cardMoveShift(cocos2d::Node* card) {
	_moveManager->cardMoveShift(card);
}
void StackAreaCtroller::setListener() {
	for (int i = 0; i < _model->_stackCards.size() - 1; i++) {
		((CardView*)_model->_stackCards[i])->setCallback(std::bind(&StackAreaCtroller::cardMoveShift, this, _1));
		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);

		listener->onTouchBegan = [=](Touch* touch, Event* event) {
			auto card = static_cast<Node*>(event->getCurrentTarget());
			if (!_moveManager->isTopCard(card)) {
				return false; 
			}

			Point localPos = card->convertTouchToNodeSpace(touch);
			Rect rect(0, 0, card->getContentSize().width, card->getContentSize().height);

			if (rect.containsPoint(localPos)) {
				return true; 
			}
			return false;
		};
		listener->onTouchEnded = [=](Touch* touch, Event* event) {
			auto card = static_cast<Node*>(event->getCurrentTarget());
			//this->cardMoveShift();
			((CardView*)_model->_stackCards[i])->invokCallback();

		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, _model->_stackCards[i]);
	}
		
}

void StackAreaCtroller::undo(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition) {
	_rollbackManager->stackAreaRollback(cardView, originalPosition);
}
