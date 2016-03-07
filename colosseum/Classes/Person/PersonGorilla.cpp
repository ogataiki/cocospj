#include "PersonGorilla.hpp"

namespace {
    
    Person::BTLSKL_ABILITY ability_table[] = {
#if 0
        // type, power, power_ratio, turn, target, hit_loss
#endif
        /* 0    */ {BtlSkl::ABILITY_TYPE_DAMAGE, 1, 1, 0, 0, 0},
        /* 1    */ {BtlSkl::ABILITY_TYPE_PROTECT, 1, 1, 3, 0, 0},
        /* 2    */ {BtlSkl::ABILITY_TYPE_STSCHANGE, 20, 0, 3, BtlSklStsChange::TARGET_ATK, 0},
        /* 3    */ {BtlSkl::ABILITY_TYPE_STSCHANGE, -50, 100, 3, BtlSklStsChange::TARGET_ATK, 0},
        /* 4    */ {BtlSkl::ABILITY_TYPE_POISON, 50, 100, 3, BtlSklPoison::TARGET_HP, 0},
        /* 5    */ {BtlSkl::ABILITY_TYPE_TRAP, 200, 100, 3, BtlSklTrap::TARGET_DEF, 20},
    };
    
    Person::BTLSKL btlskl_table[] = {
#if 0
        // probability, type, abilityIndexs1, abilityIndexs2, speed, hit, avoid, self, name
#endif
        {20, BtlSkl::TYPE_ATK, 0, -1, 100, 100, 0, false, "ウホッ", "全力の攻撃"},
        {10, BtlSkl::TYPE_DEF, 1, -1, 100, 100, 0, true, "ウホッホ", "3ターンの守り"},
        {10, BtlSkl::TYPE_SPC, 4, -1, 100, 100, 0, false, "ウッウホッ", "3ターンの毒"},
        {10, BtlSkl::TYPE_ENH, 2, -1, 100, 100, 0, true, "ウホ〜", "3ターン攻撃がちょっと強化"},
        {0, 0, 0, 0, 0, 0, 0, ""}
    };
}

PersonGorilla::PersonGorilla()
:   name("gorilla")
{
    // 性能設定
    specInit(500, 10, 5, 100, 20);
    
    // 行動設定
    initBtlSklTable(ability_table, btlskl_table);
}
PersonGorilla::~PersonGorilla()
{
    
}

std::string PersonGorilla::getImageName()
{
    return "person_enemy_gorilla.png";
}
std::string PersonGorilla::getDisplayName()
{
    return "練習用ゴリラさん";
}
