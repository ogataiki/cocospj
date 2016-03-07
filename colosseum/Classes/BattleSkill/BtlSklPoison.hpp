#ifndef BtlSklPoison_hpp
#define BtlSklPoison_hpp

#include "cocos2d.h"

class BtlSklPoison : public cocos2d::Ref
{
public:
    
    uint64_t    power;
    uint64_t    power_ratio;
    // power_ratioが0の場合はpower分の固定値変化
    
    uint64_t    turn;
    // turnが0の場合は永続（基本使わない）
    // 継続している間は、毎ターン改めて効果を発揮する

    enum TARGET
    {
        TARGET_NON = 0,

        TARGET_HP,
        TARGET_ATK,
        TARGET_DEF,
        TARGET_HIT,
        TARGET_AVD,
    };
    TARGET target;
    
    BtlSklPoison();
    ~BtlSklPoison();
};

#endif /* BtlSklPoison_hpp */
