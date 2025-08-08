#include "GameView.h"
#include "SimpleAudioEngine.h"
#include "CardView.h"
#include"MaterAreaView.h"
#include"StackAreaView..h"
USING_NS_CC;

Layer* GameView::createLayer()
{
    return GameView::create();
}
bool GameView::init()
{
    if (!Layer::init())return false;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _areaStackCard = StackAreaView::createStackView();
    _areaStackCard->setAnchorPoint(cocos2d::Vec2(0, 0));
    _areaStackCard->setPosition(Vec2(0, 0));
    _areaStackCard->setContentSize(Size(visibleSize.width, 580)); 
    this->addChild(_areaStackCard);

    _areaMaterCard = MasterAreaView::createMasterView();
    _areaMaterCard->setAnchorPoint(cocos2d::Vec2(0, 0));
    _areaMaterCard->setPosition(Vec2(0, 580));
    _areaMaterCard->setContentSize(Size(visibleSize.width, 1500)); 
    this->addChild(_areaMaterCard);
    auto layerMasterColor = LayerColor::create(Color4B(204, 153, 128, 255), visibleSize.width, 1500);
    _areaMaterCard->addChild(layerMasterColor);
    auto layerStackColor = LayerColor::create(Color4B(204, 0, 204, 128), visibleSize.width, 580);
    _areaStackCard->addChild(layerStackColor);
    return true;
}
void GameView::animateMove(cocos2d::Node* cardView, const cocos2d::Vec2& targetPosition) {
    const Size stackSize = _areaStackCard->getContentSize();
    Vec2 globalTarget = _areaStackCard->convertToWorldSpace(targetPosition);
    Vec2 targetInMaster = _areaMaterCard->convertToNodeSpace(globalTarget);
    auto moveAction = MoveTo::create(1.0f, targetInMaster);
    auto easeAction = EaseBackOut::create(moveAction);
    auto callback = CallFunc::create([=]() {
        Vec2 currentWorldPos = cardView->getParent()->convertToWorldSpace(cardView->getPosition());
        cardView->retain(); 
        cardView->removeFromParent();
        _areaStackCard->addChild(cardView);
        _areaStackCard->reorderChild(cardView, _areaStackCard->getChildren().size() - 1);
        cardView->setPosition(_areaStackCard->convertToNodeSpace(currentWorldPos));
        cardView->release();
        });
    cardView->runAction(Sequence::create(easeAction, callback, nullptr));
}

void GameView::animateMoveBack(cocos2d::Node* cardView, const cocos2d::Vec2& originalPosition) {
    Vec2 currentWorldPos = cardView->getParent()->convertToWorldSpace(cardView->getPosition());

    cardView->retain();
    cardView->removeFromParent();
    this->addChild(cardView, 1000); 
    cardView->setPosition(this->convertToNodeSpace(currentWorldPos));
    cardView->release();

    Vec2 globalTarget = _areaMaterCard->convertToWorldSpace(originalPosition);
    Vec2 targetInView = this->convertToNodeSpace(globalTarget);
    auto moveAction = MoveTo::create(1.0f, targetInView);
    auto easeAction = EaseBackIn::create(moveAction); 

    auto callback = CallFunc::create([=]() {
        Vec2 currentWorldPos = cardView->getParent()->convertToWorldSpace(cardView->getPosition());
        cardView->retain();
        cardView->removeFromParent();
        _areaMaterCard->addChild(cardView);
        _areaMaterCard->reorderChild(cardView, _areaMaterCard->getChildren().size() - 1);
        cardView->setPosition(_areaMaterCard->convertToNodeSpace(currentWorldPos));
        cardView->setPosition(originalPosition);
        cardView->release();
        });
    cardView->runAction(Sequence::create(easeAction, callback, nullptr));
}
