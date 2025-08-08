#pragma once
#include"utils/common.h"
#include"views/CardView.h"
#include"models/UndoModel .h"
//����ģʽ���������undorecords


/*@class UndoService
* @brief ��¼�ع�����
*���ܣ�
* -�Իع�����ģ�ͽ���insert����
*ְ��
* -insertһ���ع����ݵ��ع�ģ����
*ʹ�ó�����
* -�û��������ʱ�Ļع�������¼
*/
class UndoService {
public:
    /*
     *@brief ����һ��������Ϣ���ع�����ģ����
     *@param type �ع���������
     *@param originPos ����ԭλ��
     *@param curPos ���Ƽ����ƶ�����λ��
     *@param cardView ���忨��
     *@param model �ع�ģ��
    */
	void insertRecords(ActionType type, cocos2d::Vec2 originPos, cocos2d::Vec2 curPos, CardView* cardView,UndoModel* model) {
        model->_undoRecords.emplace_back(type, originPos, curPos, cardView);
        CCLOG("insert");
	}
    /*
     *@brief ��ȡ����ģʽ�µ�UndoServiceһ��ʵ��
    */
    static UndoService* getInstance() {
        if (!_undoService) {
            _undoService = new UndoService();
            return _undoService;
        }
        else {
            return _undoService;
        }
    }
private:
	UndoService() = default;
    static UndoService* _undoService;//UndoService����
};
