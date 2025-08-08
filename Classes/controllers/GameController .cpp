#include"GameController .h"
#include"views/CardView.h"
#include"views/GameView.h"
#include"services/UndoService.h"
using namespace cocos2d;
using namespace std::placeholders;
//显示页面
void GameCtroller::init(std::string filePath) {
	_moveManager = new MasterMoveManager{ _gameView ,_gameModel };
	_rollbackManager = new MasterRollbackManager{ _gameView ,_gameModel };
	//创建两个控制器
	_masterAreaCtroller = new MasterAreaCtroller();
	_stackAreaCtroller = new StackAreaCtroller();
	//设置控制器
	_masterAreaCtroller->setUp(_gameModel->_masterModel, ((GameView*)_gameView)->_areaMaterCard);
	_stackAreaCtroller->setUp(_gameModel->_stackModel, ((GameView*)_gameView)->_areaStackCard);
	//初始化控制器
	_masterAreaCtroller->init(filePath);
	_stackAreaCtroller->init(filePath);
	
	
}

void GameCtroller::buttonSetListener() {
	auto* button = ((StackAreaView*)((GameView*)_gameView)->_areaStackCard)->_backButton;

	button->addClickEventListener([=](Ref* sender) {
		_rollbackManager->undo(_stackAreaCtroller);
	});
	
}
void GameCtroller::startGame() {
	_stackAreaCtroller->setListener();
	this->setListener();
	this->buttonSetListener();
}
void GameCtroller::cardMoveShift(cocos2d::Node* card) {
	_moveManager->cardMoveShift(card);
}
void GameCtroller::setListener() {
	for (int i = 0; i < _gameModel->_masterModel->_masterCards.size(); i++) {
		((CardView*)_gameModel->_masterModel->_masterCards[i])->setCallback(std::bind(&GameCtroller::cardMoveShift, this, _1));
		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);

		listener->onTouchBegan = [=](Touch* touch, Event* event) {
			auto card = static_cast<Node*>(event->getCurrentTarget());
			Point localPos = card->convertTouchToNodeSpace(touch);
			Rect rect(0, 0, card->getContentSize().width, card->getContentSize().height);
			if (rect.containsPoint(localPos)) {
				return true; 
			}
			return false;
			};
		listener->onTouchEnded = [=](Touch* touch, Event* event) {
			auto card = static_cast<Node*>(event->getCurrentTarget());
			((CardView*)card)->invokCallback();

		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, _gameModel->_masterModel->_masterCards[i]);
	}
}

