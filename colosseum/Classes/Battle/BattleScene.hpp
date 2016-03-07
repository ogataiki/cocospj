#ifndef BattleScene_hpp
#define BattleScene_hpp

#include "cocos2d.h"

class BattleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(BattleScene);
};


#endif /* BattleScene_hpp */
