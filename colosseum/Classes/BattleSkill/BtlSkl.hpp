#ifndef BtlSkl_hpp
#define BtlSkl_hpp

#include "cocos2d.h"

#include "BtlSklDamage.hpp"
#include "BtlSklProtect.hpp"
#include "BtlSklStsChange.hpp"
#include "BtlSklPoison.hpp"
#include "BtlSklTrap.hpp"

class BtlSkl
{
public:
    enum TYPE
    {
        TYPE_NON = 0,
        
        TYPE_ATK,
        TYPE_DEF,
        TYPE_SPC,
        TYPE_ENH,
    };
    
    enum SOURCE_SPEC
    {
        SOURCE_SPEC_NON = 0,
        
        SOURCE_SPEC_HP,
        SOURCE_SPEC_ATK,
        SOURCE_SPEC_DEF,
        SOURCE_SPEC_HIT,
        SOURCE_SPEC_AVD,
        
        SOURCE_SPEC_MAXHP,
        SOURCE_SPEC_BASEATK,
        SOURCE_SPEC_BASEDEF,
        SOURCE_SPEC_BASEHIT,
        SOURCE_SPEC_BASEAVD,
    };
    
    enum ABILITY_TYPE
    {
        ABILITY_TYPE_NON = 0,
        
        ABILITY_TYPE_DAMAGE,
        ABILITY_TYPE_PROTECT,
        ABILITY_TYPE_STSCHANGE,
        ABILITY_TYPE_POISON,
        ABILITY_TYPE_TRAP,
    };
    struct ABILITY
    {
        // 各効果のどのクラスに値を持っているか
        ABILITY_TYPE    type;
        
        // 各効果のpowerの元となる値
        SOURCE_SPEC     sourceSpec;
        
        // どれか一つだけ持っている
        BtlSklDamage    *damage;
        BtlSklProtect   *protect;
        BtlSklStsChange *stsChange;
        BtlSklPoison    *poison;
        BtlSklTrap      *trap;
    };
    
    uint64_t        probability;

    std::string name;
    
    std::string detail;
    
    TYPE type;
    
    uint64_t speed;
    
    std::vector<ABILITY>    abilitys;
    
    uint64_t hit;
    uint64_t avoid;
    
    bool        self;
    
    std::vector<std::string>    speechBefor;
    std::vector<std::string>    speechAfter;
    
    
    
    BtlSkl();
    ~BtlSkl();
};

#endif /* BtlSkl_hpp */
