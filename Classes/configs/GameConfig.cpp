#include"GameConfig.h"
#include<fstream>
#include"cocos2d.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
using namespace cocos2d;

GameConfig::GameConfig(const std::string& kfilePath) {
    //CCLOG("%s", kfilePath.c_str());
	std::string jsonString = FileUtils::getInstance()->getStringFromFile(kfilePath);
    //CCLOG("%s", jsonString.c_str());
	if (jsonString.empty()) {
        CCLOG("json string is empty!");
		return;
	}
	_document.Parse<rapidjson::kParseDefaultFlags>(jsonString.c_str());
	if (!_document.IsObject()) {
        CCLOG("json parse failed");
		return;
	}
    parseCardsData("Playfield", MASTER_CARDS_DATA);
    parseCardsData("Stack", STACK_CARDS_DATA);

}

void GameConfig::parseCardsData(const std::string& kobjName, VectorType vecType) {
    if (_document.HasMember(kobjName.c_str()) && _document[kobjName.c_str()].IsArray()) {
        const rapidjson::Value& playfieldArray = _document[kobjName.c_str()];
        for (rapidjson::SizeType i = 0; i < playfieldArray.Size(); i++) {
            const rapidjson::Value& card = playfieldArray[i];
            if (card.IsObject()) {
                CARD_FACE_TYPE face;
                CARD_SUIT_TYPE suit;
                CARD_POSITION_TYPE pos;
                // ½âÎöface
                if (card.HasMember("CardFace") && card["CardFace"].IsInt()) {
                    face = card["CardFace"].GetInt();
                }
                // ½âÎösuit
                if (card.HasMember("CardSuit") && card["CardSuit"].IsInt()) {
                    suit = card["CardSuit"].GetInt();
                }
                // ½âÎöpos
                if (card.HasMember("Position") && card["Position"].IsObject()) {
                    const rapidjson::Value& position = card["Position"];
                    if (position.HasMember("x") && position["x"].IsNumber()) {
                        pos.x = position["x"].GetInt();
                    }
                    if (position.HasMember("y") && position["y"].IsNumber()) {
                        pos.y = position["y"].GetInt();
                    }
                }
                if (vecType == MASTER_CARDS_DATA) {
                    _masterCardsData.emplace_back(face, suit, pos);
             
                }
                else if(vecType == STACK_CARDS_DATA)_stackCardsData.emplace_back(face, suit, pos);

            }
        }
    }
}


CARD_FACE_TYPE CardConfig::getFace()const noexcept {
    return _face;
}
CARD_SUIT_TYPE CardConfig::getSuit()const noexcept {
    return _suit;
}
CARD_POSITION_TYPE CardConfig::getPos()const noexcept {
    return _pos;
}
