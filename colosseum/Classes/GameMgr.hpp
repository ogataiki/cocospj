#ifndef GameMgr_hpp
#define GameMgr_hpp

#include <stdio.h>

class GameMgr
{
private:
    GameMgr();
    static GameMgr* mGameMgr;
    
public:
    static GameMgr* getInstance();
    
    // 値の初期化
    void initialize();
    
};

#endif /* GameMgr_hpp */
