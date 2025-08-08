#include"MasterAreaCtroller.h"
#include"views/CardView.h"
#include"configs/GameConfig.h"

void MasterAreaCtroller::setUp(MasterAreaModel* model, cocos2d::Layer* view) {
	_model = model;
	_view = view;
}
void MasterAreaCtroller::init(const std::string& kfilePath) {
	//首先初始化_masterCardModels
	GameConfig conf(kfilePath);
	for (size_t i = 0; i < conf._masterCardsData.size(); i++) {
		CardConfig cardConf = conf._masterCardsData.at(i);
		_model->_masterCardModels.emplace_back(_autoIncrement++,cardConf.getFace(), cardConf.getSuit(), cardConf.getPos());
	}

	//然后通过_masterCardModels数据创建Cardview，再将Cardview放入_masterCards；
	for (int i = 0; i < _model->_masterCardModels.size(); i++) {
		CARD_FACE_TYPE num = _model->_masterCardModels[i]._cardFace;
		CARD_SUIT_TYPE suit = _model->_masterCardModels[i]._cardSuit;
		CardView* cardView = CardView::create(num, suit);
		_model->_masterCards.push_back(cardView);
		CARD_POSITION_TYPE pos = _model->_masterCardModels[i]._cardPos;
		cardView->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
		cardView->setPosition(pos);
	
		_view->addChild(cardView);

	}
}
