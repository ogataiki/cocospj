#ifndef BtlSklDamage_hpp
#define BtlSklDamage_hpp

#include "cocos2d.h"

class BtlSklDamage : public cocos2d::Ref
{
public:
    
    uint64_t    power;
    uint64_t    power_ratio;
    // power_ratioが0の場合はpower分の固定ダメージ
    
    BtlSklDamage();
    ~BtlSklDamage();
};

#endif /* BtlSklDamage_hpp */
