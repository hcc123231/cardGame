#pragma once
#include"cocos2d.h"
#include"views/CardView.h"
#include"utils/common.h"
//undorecordsҲ���ɵ���ģʽ


/*@class UndoData
* @brief �ع�����
*���ܣ�
* -�ع����ݽṹ
*ְ��
* -����ع����ݽṹ
*ʹ�ó�����
* -����һ���ع���¼
*/
struct UndoData {
	cocos2d::Vec2 _originPos;
	cocos2d::Vec2 _curPos;//�ƶ���λ��Ҳ���ǵ�ǰλ��
	CardView* _cardView;
	ActionType _type;
	UndoData(ActionType type, cocos2d::Vec2 oringinPos, cocos2d::Vec2 targetPos, CardView* card) :_type{type}, \
	_originPos{ oringinPos }, _curPos{ targetPos }, _cardView{ card }{}
};
/*@class UndoModel
* @brief ��¼�ع�����
*���ܣ�
* -�洢�ع�������¼
*ְ��
* -��¼�ع�����
*ʹ�ó�����
* -�û��������ʱ����һ���ع���¼��UndoModel
*/
struct UndoModel {
	
	std::vector<UndoData> _undoRecords;//�ع�������¼ջ
	static UndoModel* getInstance() {
		if (!_undoModel) {
			_undoModel = new UndoModel();
			return _undoModel;
		}
		else {
			return _undoModel;
		}
	}
private:
	UndoModel() = default;
	static UndoModel* _undoModel;//�ع���¼����
};
