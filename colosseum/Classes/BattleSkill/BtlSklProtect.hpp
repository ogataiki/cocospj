#ifndef BtlSklProtect_hpp
#define BtlSklProtect_hpp

#include "cocos2d.h"

class BtlSklProtect : public cocos2d::Ref
{
public:
    
    uint64_t    power;
    // powerが0の場合は完全シールド
    uint64_t    power_ratio;
    // power_ratioが0の場合はpower分の固定ダメージ減少シールド
    
    uint64_t    turn;
    // turnが0の場合は永続（基本使わない）
    
    BtlSklProtect();
    ~BtlSklProtect();
};


#endif /* BtlSklProtect_hpp */
