#include "BattleScene.hpp"

USING_NS_CC;

#if 0
表示する要素

背景

プレイヤーキャラ
　HP
　攻撃
　防御
　命中
　回避

エネミーキャラ
　HP
　攻撃
　防御
　命中
　回避

キャラコマンド
　プレイヤーコマンド1
　プレイヤーコマンド2
　プレイヤーコマンド3
　プレイヤーコマンド4
　エネミーコマンド1
　エネミーコマンド2
　エネミーコマンド3
　エネミーコマンド4

コマンド詳細
　名前
　行動タイプ
　速度
　対象
　日本語説明
　命中
　回避

#endif

Scene* BattleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BattleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BattleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    return true;
}
