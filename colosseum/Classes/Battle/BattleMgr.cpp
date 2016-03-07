#include "BattleMgr.hpp"

BattleMgr* BattleMgr::mBattleMgr = NULL;

BattleMgr::BattleMgr()
{
    
}

BattleMgr* BattleMgr::getInstance()
{
    if(mBattleMgr == NULL)
    {
        mBattleMgr = new BattleMgr();
        mBattleMgr->initialize();
    }
    
    return mBattleMgr;
}

// 値の初期化
void BattleMgr::initialize()
{
    
}
