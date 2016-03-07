#ifndef BtlSklTrap_hpp
#define BtlSklTrap_hpp

class BtlSklTrap : public cocos2d::Ref
{
public:
    
    // ダメージ
    uint64_t    power;
    uint64_t    power_ratio;
    // power_ratioが0の場合はpower分の固定値変化
    
    // 命中ダウン　固定値
    uint64_t    hit_loss;

    uint64_t    turn;
    // turnが0の場合は永続（基本使わない）
    
    enum TARGET
    {
        TARGET_NON = 0,

        TARGET_ATK,
        TARGET_DEF,
        TARGET_SPC,
        TARGET_ENH,
    };
    TARGET target;
    
    BtlSklTrap();
    ~BtlSklTrap();
};

#endif /* BtlSklTrap_hpp */
