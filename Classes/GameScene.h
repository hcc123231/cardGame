#pragma once
#include<cocos2d.h>
#include"views/GameView.h"
#include"controllers/GameController .h"
#include"models/GameModel .h"
/*@class GameScene
* @brief ��Ϸ�����ܿ�ܣ���Ϸ���
*���ܣ�
* -��Ϸ�������س���
* -��ʼ����Ϸ����������Ϸ��ͼ�㣬��Ϸ����ģ��
* -������Ϸ
*ְ��
* -������Ϸ����������Ϸ��ͼ�㣬��Ϸ����ģ��
* -������Ϸ��������
*ʹ�ó�����
* -AppDelegate��ʼ��Ϸ����GameScene scene��runWithScene(scene)
*/
class GameScene :public cocos2d::Scene {
public:
    /*
     *@brief ��ʼ������
     * @return scenePointer �Ǽܴ����ɹ���nullptr �Ǽܴ���ʧ��
    */
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

private:
    
    cocos2d::Layer* _gameView;//��Ϸ����ͼ��λ��GameScene֮�ϵ�һ��layer
    GameCtroller* _gameCtroller;//��Ϸ���̿�����
    GameModel* _gameModel;//��Ϸ����ģ��
};