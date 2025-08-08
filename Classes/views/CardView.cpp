#include"CardView.h"
#include"utils/cardType.h"
#include"utils/common.h"
USING_NS_CC;
CardView* CardView::create(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit) {
    auto cardView = new (std::nothrow) CardView();
    if (cardView && cardView->init(num,suit)) {
        cardView->autorelease();
        return cardView;
    }
    CC_SAFE_DELETE(cardView);
    return nullptr;
}

bool CardView::init(CARD_FACE_TYPE num, CARD_SUIT_TYPE suit) {
    if (!Node::init()) {
        return false;
    }
    std::string colorStr{};
    std::string numStr{}, suitStr{};
    if (suit == CST_CLUBS || suit == CST_SPADES)colorStr = "black";
    else if (suit == CST_DIAMONDS || suit == CST_HEARTS)colorStr = "red";
    shift(num, suit, numStr, suitStr);

    this->setContentSize(cocos2d::Size(165, 260));

    auto backgroundSprite = cocos2d::Sprite::create(BACKGROUND_FILE_PATH);
    backgroundSprite->setAnchorPoint(cocos2d::Vec2(0, 0)); // ÉèÖÃÃªµã
    backgroundSprite->setContentSize(cocos2d::Size(165, 260));
    this->addChild(backgroundSprite);

    std::string bigNumFilePath = cocos2d::StringUtils::format("res/number/big_%s_%s.png", colorStr.c_str(), numStr.c_str());
    auto largeNumberSprite = cocos2d::Sprite::create(bigNumFilePath);
    largeNumberSprite->setAnchorPoint(Vec2(0.5, 0.5));
    largeNumberSprite->setPosition(cocos2d::Vec2(82.5, 100));
    largeNumberSprite->setContentSize(Size(75, 120));
    backgroundSprite->addChild(largeNumberSprite);

    std::string smallNumFilePath = cocos2d::StringUtils::format("res/number/small_%s_%s.png", colorStr.c_str(), numStr.c_str());
    auto smallNumberSprite = cocos2d::Sprite::create(smallNumFilePath);
    smallNumberSprite->setAnchorPoint(Vec2(0.5, 0.5));
    smallNumberSprite->setPosition(cocos2d::Vec2(35, 230));
    smallNumberSprite->setContentSize(Size(32.5, 40));
    backgroundSprite->addChild(smallNumberSprite);

    std::string suitSpriteFilePath = cocos2d::StringUtils::format("res/suits/%s.png", suitStr.c_str());
    auto suitSprite = cocos2d::Sprite::create(suitSpriteFilePath);
    suitSprite->setAnchorPoint(Vec2(0.5, 0.5));
    suitSprite->setPosition(cocos2d::Vec2(130, 225)); 
    suitSprite->setContentSize(Size(39, 41));
    backgroundSprite->addChild(suitSprite);
    return true;
}