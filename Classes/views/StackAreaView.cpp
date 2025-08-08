#include"StackAreaView..h"
#include"cocos2d.h"
using namespace cocos2d;
cocos2d::Layer* StackAreaView::createStackView() {
	return StackAreaView::create();
}

bool StackAreaView::init()
{
    if (!Layer::init())return false;
    _backButton = cocos2d::ui::Button::create();
    _backButton->setTitleText(u8"»ØÍË");
    _backButton->setTitleColor(Color3B::WHITE);
    _backButton->setTitleFontSize(75);
    _backButton->setContentSize(_backButton->getContentSize() + Size(100, 0));
    _backButton->setPosition(Vec2(900, 300));
    this->addChild(_backButton);

    return true;


}

void StackAreaView::animateMove(cocos2d::Node* cardView, const cocos2d::Vec2& targetPosition) {
    cocos2d::Node* targetParent = cardView->getParent();
    targetParent->reorderChild(cardView, targetParent->getChildren().size() - 1);
    auto moveAction = MoveTo::create(1.0f, targetPosition);
    auto easeAction = EaseBackOut::create(moveAction);
    auto scaleUp = cocos2d::ScaleTo::create(0.2f, 1.1f);
    auto scaleDown = cocos2d::ScaleTo::create(0.3f, 1.0f);
    auto scaleSequence = cocos2d::Sequence::create(scaleUp, scaleDown, nullptr);
    auto spawn = cocos2d::Spawn::create(easeAction, scaleSequence, nullptr);
    cardView->runAction(spawn);
}
void StackAreaView::animateMoveBack(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition) {
    auto moveAction = MoveTo::create(1.0f, originalPosition);
    auto easeAction = EaseBackIn::create(moveAction); 
    auto scaleDown = ScaleTo::create(0.2f, 0.9f);
    auto scaleUp = ScaleTo::create(0.3f, 1.0f); 
    auto scaleSequence = Sequence::create(scaleDown, scaleUp, nullptr);
    auto spawn = Spawn::create(easeAction, scaleSequence, nullptr);

    auto callback = CallFunc::create([cardView]() {
        if (auto parent = cardView->getParent()) {
            parent->reorderChild(cardView, 0); 
        }
        });
    auto sequence = Sequence::create(spawn, callback, nullptr);
    cardView->runAction(sequence);
}