#pragma once
#include"cocos2d.h"

/*@class MasterAreaView
* @brief ������������ͼ
*���ܣ�
* -��ʾ��������Ϸ����
*ְ��
* -չʾ��������Ϸ��ͼ
*ʹ�ó�����
* -��ʾ������
*/
class MasterAreaView:public cocos2d::Layer{
public:
    /*
     *@brief ��ʼ������
     * @return scenePointer �Ǽܴ����ɹ���nullptr ��������ͼ����ʧ��
    */
    static cocos2d::Layer* createMasterView();
private:
    CREATE_FUNC(MasterAreaView);
    virtual bool init();
};