#include "GameMgr.hpp"

GameMgr* GameMgr::mGameMgr = NULL;

GameMgr::GameMgr()
{
    
}

GameMgr* GameMgr::getInstance()
{
    if(mGameMgr == NULL)
    {
        mGameMgr = new GameMgr();
        mGameMgr->initialize();
    }
    
    return mGameMgr;
}

// 値の初期化
void GameMgr::initialize()
{
    
}
