#include "PersonNeetLv1.hpp"

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
        {20, BtlSkl::TYPE_ATK, 0, -1, 100, 100, 0, false, "とりあえず叩く", "全力の攻撃"},
        {10, BtlSkl::TYPE_DEF, 1, -1, 100, 100, 0, true, "身を守る", "3ターンの守り"},
        {10, BtlSkl::TYPE_SPC, 4, -1, 100, 100, 0, false, "腐った魚を投げつける", "3ターンの毒"},
        {10, BtlSkl::TYPE_ENH, 2, -1, 100, 100, 0, true, "サプリメント摂取", "3ターン攻撃をちょっと強化"},
        {5, BtlSkl::TYPE_SPC, 5, -1, 100, 100, 0, false, "ネットで知った罠を使う", "3ターン防御に対してトラップ"},
        {10, BtlSkl::TYPE_ATK, 3, -1, 100, 60, 10, false, "威嚇する", "3ターン攻撃をちょっと弱化"},
        {0, 0, 0, 0, 0, 0, 0, ""}
    };
}

PersonNeetLv1::PersonNeetLv1()
:   name("neet_lv_1")
{
    // 性能設定
    specInit(1000, 100, 50, 100, 20);
    
    // 行動設定
    initBtlSklTable(ability_table, btlskl_table);
}
PersonNeetLv1::~PersonNeetLv1()
{
    
}

std::string PersonNeetLv1::getImageName()
{
    return "person_neet1.png";
}
std::string PersonNeetLv1::getDisplayName()
{
    return "ニートLv1";
}
