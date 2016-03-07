#ifndef BtlSklStsChange_hpp
#define BtlSklStsChange_hpp

#include "cocos2d.h"

class BtlSklStsChange : public cocos2d::Ref
{
public:
    
    int64_t     power;
    // powerがプラス値の場合は強化、マイナス値の場合は弱化
    uint64_t    power_ratio;
    // power_ratioが0の場合はpower分の固定値変化
    
    uint64_t    turn;
    // turnが0の場合は永続（基本使わない）
    
    enum TARGET
    {
        TARGET_NON = 0,

        TARGET_ATK,
        TARGET_DEF,
        TARGET_HIT,
        TARGET_AVD,
    };
    TARGET target;
    
    BtlSklStsChange();
    ~BtlSklStsChange();
};

#endif /* BtlSklStsChange_hpp */
