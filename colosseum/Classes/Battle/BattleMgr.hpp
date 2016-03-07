#ifndef BattleMgr_hpp
#define BattleMgr_hpp

#include <stdio.h>

#include "GameMgr.hpp"

class BattleMgr
{
private:
    BattleMgr();
    static BattleMgr* mBattleMgr;
    
public:
    static BattleMgr* getInstance();
    
    // 値の初期化
    void initialize();
    
};

#endif /* BattleMgr_hpp */
