#include "Person.hpp"

Person::Person()
:   isPlayer(false)
,   displayName("")

{
    specInit(1000, 100, 50, 100, 20);
}
Person::~Person()
{
    for (int i=0; i<btlsklTable.size(); ++i) {
        BtlSkl &skl = btlsklTable[i];
        for (int j=0; j<ABILITY_OVERLAP; ++j) {
            BtlSkl::ABILITY &in_ability = skl.abilitys[j];
            switch (in_ability.type)
            {
            case BtlSkl::ABILITY_TYPE_DAMAGE:
                if(in_ability.damage != NULL)
                {
                    delete in_ability.damage;
                }
                break;
            case BtlSkl::ABILITY_TYPE_PROTECT:
                if(in_ability.protect != NULL)
                {
                    delete in_ability.protect;
                }
                break;
            case BtlSkl::ABILITY_TYPE_STSCHANGE:
                if(in_ability.stsChange != NULL)
                {
                    delete in_ability.stsChange;
                }
                break;
            case BtlSkl::ABILITY_TYPE_POISON:
                if(in_ability.poison != NULL)
                {
                    delete in_ability.poison;
                }
                break;
            case BtlSkl::ABILITY_TYPE_TRAP:
                if(in_ability.trap != NULL)
                {
                    delete in_ability.trap;
                }
                break;
            default:
                break;
            }
        }
    }
}

void Person::initBtlSklTable(BTLSKL_ABILITY *abilitys, BTLSKL *btlskls)
{
    for (int i=0;; ++i)
    {
        if(btlskls[i].probability == 0) {
            return;
        }
        BTLSKL &in = btlskls[i];
        BtlSkl skl;
        skl.probability = in.probability;
        skl.type        = (BtlSkl::TYPE)in.type;
        skl.speed       = in.speed;
        skl.hit         = in.hit;
        skl.avoid       = in.avoid;
        skl.self        = in.self;
        skl.name        = in.name;
        skl.detail      = in.detail;
        for (int j=0; j<ABILITY_OVERLAP; ++j) {
            
            if (in.abilityIndexs[j] >=0) {
                
                BTLSKL_ABILITY &in_ability = abilitys[in.abilityIndexs[j]];
                
                BtlSkl::ABILITY ability;
                ability.damage = NULL;
                ability.protect = NULL;
                ability.stsChange = NULL;
                ability.poison = NULL;
                ability.trap = NULL;
                
                switch ((BtlSkl::ABILITY_TYPE)in.abilityIndexs[j]) {
                    case BtlSkl::ABILITY_TYPE_DAMAGE:
                    {
                        ability.type = (BtlSkl::ABILITY_TYPE)in_ability.type;
                        ability.damage = new BtlSklDamage();
                        ability.damage->power = in_ability.power;
                        ability.damage->power_ratio = in_ability.power_ratio;
                    }
                        break;

                    case BtlSkl::ABILITY_TYPE_PROTECT:
                        ability.type = (BtlSkl::ABILITY_TYPE)in_ability.type;
                        ability.protect = new BtlSklProtect();
                        ability.protect->power = in_ability.power;
                        ability.protect->power_ratio = in_ability.power_ratio;
                        ability.protect->turn = in_ability.turn;
                        break;

                    case BtlSkl::ABILITY_TYPE_STSCHANGE:
                        ability.type = (BtlSkl::ABILITY_TYPE)in_ability.type;
                        ability.stsChange = new BtlSklStsChange();
                        ability.stsChange->power = in_ability.power;
                        ability.stsChange->power_ratio = in_ability.power_ratio;
                        ability.stsChange->turn = in_ability.turn;
                        ability.stsChange->target = (BtlSklStsChange::TARGET)in_ability.target;
                        break;

                    case BtlSkl::ABILITY_TYPE_POISON:
                        ability.type = (BtlSkl::ABILITY_TYPE)in_ability.type;
                        ability.poison = new BtlSklPoison();
                        ability.poison->power = in_ability.power;
                        ability.poison->power_ratio = in_ability.power_ratio;
                        ability.poison->turn = in_ability.turn;
                        ability.poison->target = (BtlSklPoison::TARGET)in_ability.target;
                        break;

                    case BtlSkl::ABILITY_TYPE_TRAP:
                        ability.type = (BtlSkl::ABILITY_TYPE)in_ability.type;
                        ability.trap = new BtlSklTrap();
                        ability.trap->power = in_ability.power;
                        ability.trap->power_ratio = in_ability.power_ratio;
                        ability.trap->turn = in_ability.turn;
                        ability.trap->target = (BtlSklTrap::TARGET)in_ability.target;
                        ability.trap->hit_loss = in_ability.hit_loss;
                        break;

                    default:
                        ability.type = BtlSkl::ABILITY_TYPE_NON;
                        break;
                }
                
                skl.abilitys.push_back(ability);
            }
        }
        btlsklTable.push_back(skl);
    }
}

void Person::setPlayer(bool v)
{
    isPlayer = v;
    if(v)
    {
        // 画像は右向き
        // プレイヤーは画面右に配置で左向き
        setScaleX(-1.0);
    }
    else
    {
        setScaleX(1.0);
    }
}

void Person::specInit(SPEC &spec)
{
    specInit(spec.hp, spec.atk, spec.def, spec.hit, spec.avd);
}
void Person::specInit(int64_t hp, int64_t atk, int64_t def, int64_t hit, int64_t avd)
{
    spec_base.hp = hp;
    spec_base.atk = atk;
    spec_base.def = def;
    spec_base.hit = hit;
    spec_base.avd = avd;
    
    spec.hp = hp;
    spec.atk = atk;
    spec.def = def;
    spec.hit = hit;
    spec.avd = avd;
}

void Person::positionUpdate(cocos2d::Point pos)
{
    _position = pos;
    position_base = pos;
}

bool Person::isDead()
{
    if(spec.hp <= 0)
    {
        return true;
    }
    return false;
}



// バトルスキル効果を付与
void Person::recvBtlSkl(BtlSkl &bs, Person &subject)
{
    for (int i=0; i<bs.abilitys.size(); ++i) {
        BtlSkl::ABILITY &ability = bs.abilitys[i];
        int64_t sourcePower = 0;
        switch (ability.sourceSpec) {
            case BtlSkl::SOURCE_SPEC_HP : sourcePower = subject.spec.hp; break;
            case BtlSkl::SOURCE_SPEC_ATK : sourcePower = subject.spec.atk; break;
            case BtlSkl::SOURCE_SPEC_DEF : sourcePower = subject.spec.def; break;
            case BtlSkl::SOURCE_SPEC_HIT : sourcePower = subject.spec.hit; break;
            case BtlSkl::SOURCE_SPEC_AVD : sourcePower = subject.spec.avd; break;
            case BtlSkl::SOURCE_SPEC_MAXHP : sourcePower = subject.spec_base.hp; break;
            case BtlSkl::SOURCE_SPEC_BASEATK : sourcePower = subject.spec_base.atk; break;
            case BtlSkl::SOURCE_SPEC_BASEDEF : sourcePower = subject.spec_base.def; break;
            case BtlSkl::SOURCE_SPEC_BASEHIT : sourcePower = subject.spec_base.hit; break;
            case BtlSkl::SOURCE_SPEC_BASEAVD : sourcePower = subject.spec_base.avd; break;
            default:
                //そんなもんはねえ。
                return;
        }
        switch (ability.type) {
            case BtlSkl::ABILITY_TYPE_DAMAGE :
                recvBtlSklDamage(sourcePower, *ability.damage);
                break;
                
            case BtlSkl::ABILITY_TYPE_PROTECT :
                recvBtlSklProtect(sourcePower, *ability.protect);
                break;
                
            case BtlSkl::ABILITY_TYPE_STSCHANGE :
                recvBtlSklStsChange(sourcePower, *ability.stsChange);
                break;
                
            case BtlSkl::ABILITY_TYPE_POISON :
                recvBtlSklPoison(sourcePower, *ability.poison);
                break;
                
            case BtlSkl::ABILITY_TYPE_TRAP :
                recvBtlSklTrap(sourcePower, *ability.trap);
                break;
                
            default:
                // そんなもんはねえ。
                break;
        }
    }
}


// ダメージを付与
void Person::recvBtlSklDamage(int64_t sourcePower, BtlSklDamage &in)
{
    uint64_t damage = 0;
    if(in.power_ratio == 0)
    {
        damage = in.power;
    }
    else
    {
        damage = (sourcePower * in.power) / in.power_ratio;
    }
    
    // シールドのダメージ減衰を計算
    damage = damage - getProtectValue();
    damage = (damage < 1) ? 1 : damage;
    
    // 即座に効果を発揮
    spec.hp -= damage;
    spec.hp = (spec.hp < 0) ? 0 : spec.hp;
}

// カウンター
void Person::recvBtlSklCounter(BtlSklDamage &in)
{
    int64_t damage = 0;
    if(in.power_ratio == 0)
    {
        damage = in.power;
    }
    else
    {
        damage = (spec.atk * in.power) / in.power_ratio;
    }
    // カウンターはダメージ2倍
    damage = damage * 2;
    
    // シールドのダメージ減衰を計算
    damage = damage - getProtectValue();
    damage = (damage < 1) ? 1 : damage;
    
    // 即座に効果を発揮
    spec.hp -= damage;
    spec.hp = (spec.hp < 0) ? 0 : spec.hp;
}


// シールドを付与
void Person::recvBtlSklProtect(int64_t sourcePower, BtlSklProtect &in)
{
    PROTECT out;
    if(in.power_ratio == 0)
    {
        out.value = in.power;
    }
    else
    {
        out.value = (sourcePower * in.power) / in.power_ratio;
    }
    out.turn = in.turn;
    protects.push_back(out);
    
    // 攻撃、カウンターのダメージ時に発動
    // ターン終了時に解除判定
}

uint64_t Person::getProtectValue()
{
    uint64_t total = 0;
    for (int i=0; i<protects.size(); ++i)
    {
        PROTECT &protect = protects[i];
        total += protect.value;
    }
    return total;
}

// シールド更新
// ターン終了時に呼び出す
void Person::updateProtect()
{
    for (signed long i=protects.size()-1; i>=0; i--)
    {
        PROTECT &protect = protects[i];
        protect.turn--;
        if (protect.turn == 0)
        {
            protects.erase(protects.begin() + i);
        }
    }
}


// ステータス変化を付与
void Person::recvBtlSklStsChange(int64_t sourcePower, BtlSklStsChange &in)
{
    STSCHANGE out = {0, 0, 0, 0, 0};
    int64_t value = 0;
    if(in.power_ratio == 0)
    {
        value = in.power;
    }
    else
    {
        value = (sourcePower * in.power) / in.power_ratio;
    }
    switch (in.target) {
        case BtlSklStsChange::TARGET_ATK : out.chgATK = value; break;
        case BtlSklStsChange::TARGET_DEF : out.chgDEF = value; break;
        case BtlSklStsChange::TARGET_HIT : out.chgHIT = value; break;
        case BtlSklStsChange::TARGET_AVD : out.chgAVD = value; break;
        default:
            // そんなもんはねえ。
            break;
    }
    out.turn = in.turn;
    stschanges.push_back(out);
    
    // 即座に効果を発揮
    spec.atk += out.chgATK;
    spec.def += out.chgDEF;
    spec.hit += out.chgHIT;
    spec.avd += out.chgAVD;
    
    // ターン終了時に解除判定
}

// ステータス変化更新
// ターン終了時に呼び出す
void Person::updateStsChange()
{
    for (signed long i=stschanges.size()-1; i>=0; i--)
    {
        STSCHANGE &stschange = stschanges[i];
        stschange.turn--;
        if (stschange.turn == 0)
        {
            // 効果を解除
            spec.atk -= stschange.chgATK;
            spec.def -= stschange.chgDEF;
            spec.hit -= stschange.chgHIT;
            spec.avd -= stschange.chgAVD;
            
            stschanges.erase(stschanges.begin() + i);
        }
    }
}


// 毒を付与
void Person::recvBtlSklPoison(int64_t sourcePower, BtlSklPoison &in)
{
    POISON out = {0, 0, 0, 0, 0, 0};
    int64_t value = 0;
    if(in.power_ratio == 0)
    {
        value = in.power;
    }
    else
    {
        value = (sourcePower * in.power) / in.power_ratio;
    }
    switch (in.target) {
        case BtlSklPoison::TARGET_HP : out.chgHP = value; break;
        case BtlSklPoison::TARGET_ATK : out.chgATK = value; break;
        case BtlSklPoison::TARGET_DEF : out.chgDEF = value; break;
        case BtlSklPoison::TARGET_HIT : out.chgHIT = value; break;
        case BtlSklPoison::TARGET_AVD : out.chgAVD = value; break;
        default:
            break;
    }
    out.turn = in.turn;
    poisons.push_back(out);
    
    // ターン終了時に効果を発揮 その後解除判定
}

// 毒更新
// ターン終了時の毒演出で呼び出すこと
void Person::updatePoison()
{
    for (signed long i=poisons.size()-1; i>=0; i--)
    {
        POISON &poison = poisons[i];
        
        //効果を発動
        spec.hp -= poison.chgHP;
        spec.atk -= poison.chgATK;
        spec.def -= poison.chgDEF;
        spec.hit -= poison.chgHIT;
        spec.avd -= poison.chgAVD;
        
        poison.turn--;
        if (poison.turn == 0)
        {
            poisons.erase(poisons.begin() + i);
        }
    }
}



// トラップを付与
void Person::recvBtlSklTrap(int64_t sourcePower, BtlSklTrap &in)
{
    TRAP out;
    if(in.power_ratio == 0)
    {
        out.damage = in.power;
    }
    else
    {
        out.damage = (sourcePower * in.power) / in.power_ratio;
    }
    out.hitloss = in.hit_loss;
    out.target = in.target;
    out.turn = in.turn;
    traps.push_back(out);
    
    // 行動直前に効果を発揮
    // 効果発揮時に解除
}

// トラップ更新
// ターン終了時に呼び出す
void Person::updateTrap()
{
    for (signed long i=traps.size()-1; i>=0; i--)
    {
        TRAP &trap = traps[i];
        trap.turn--;
        if (trap.turn == 0)
        {
            traps.erase(traps.begin() + i);
        }
    }
}
