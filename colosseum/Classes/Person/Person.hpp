#ifndef Person_hpp
#define Person_hpp

#include "cocos2d.h"

#include "BattleSkill/BtlSkl.hpp"

#define ABILITY_OVERLAP     2

class Person : public cocos2d::Sprite
{
public:
    
    Person();
    ~Person();
    
    bool isPlayer;
    void setPlayer(bool v = true);
    
    std::string displayName;
    
    // エンカウント時のセリフ
    std::vector<std::string> speech_battlePre;
    std::vector<std::string> speech_battleEnd_win;
    std::vector<std::string> speech_battleEnd_lose;
    
    // 配列は各ターンを示す[0]は1ターン目のコマンド選択時に喋る
    std::vector< std::vector<std::string> > speech_battleStart;
    std::vector< std::vector<std::string> > speech_battleTacticalStart;

    // speechは、勝手にしゃべる内容だけ入れる
    // 会話はtalkマネージャ作ってそっちで管理
    
    struct SPEC
    {
        int64_t hp;
        int64_t atk;
        int64_t def;
        int64_t hit;
        int64_t avd;
    };
    SPEC spec_base;
    SPEC spec;
    
    void specInit(SPEC &spec);
    void specInit(int64_t hp, int64_t atk, int64_t def, int64_t hit, int64_t avd);
    
    cocos2d::Point position_base;
    void positionUpdate(cocos2d::Point pos);

    bool isDead();
    
    
    
    // バトルスキル効果を付与
    void recvBtlSkl(BtlSkl &bs, Person &subject);
    
    // ダメージを付与
    void recvBtlSklDamage(int64_t sourcePower, BtlSklDamage &in);

    // カウンター
    void recvBtlSklCounter(BtlSklDamage &in);
    
    // シールドを付与
    struct PROTECT
    {
        uint64_t value;
        uint64_t turn;
    };
    std::vector<PROTECT> protects;
    void recvBtlSklProtect(int64_t sourcePower, BtlSklProtect &in);
    uint64_t getProtectValue();
    // シールド更新
    // ターン終了時に呼び出す
    void updateProtect();

    
    // ステータス変化を付与
    struct STSCHANGE
    {
        int64_t chgATK;
        int64_t chgDEF;
        int64_t chgHIT;
        int64_t chgAVD;
        uint64_t turn;
    };
    std::vector<STSCHANGE> stschanges;
    void recvBtlSklStsChange(int64_t sourcePower, BtlSklStsChange &in);
    // ステータス変化更新
    // ターン終了時に呼び出す
    void updateStsChange();

    
    // 毒を付与
    struct POISON
    {
        int64_t chgHP;
        int64_t chgATK;
        int64_t chgDEF;
        int64_t chgHIT;
        int64_t chgAVD;
        uint64_t turn;
    };
    std::vector<POISON> poisons;
    void recvBtlSklPoison(int64_t sourcePower, BtlSklPoison &in);
    // 毒更新
    // ターン終了時の毒演出で呼び出すこと
    void updatePoison();
    
    
    // トラップを付与
    struct TRAP
    {
        BtlSklTrap::TARGET target;
        int64_t damage;
        int64_t hitloss;
        uint64_t turn;
    };
    std::vector<TRAP> traps;
    void recvBtlSklTrap(int64_t sourcePower, BtlSklTrap &in);
    // トラップ更新
    // ターン終了時に呼び出す
    void updateTrap();
    
    struct BTLSKL_ABILITY
    {
        int         type;
        
        int64_t     power;
        uint64_t    power_ratio;
        
        uint64_t    turn;
        
        int         target;
        
        // BtlSklTrap用
        uint64_t    hit_loss;
    };
    struct BTLSKL
    {
        uint64_t        probability;
        
        int             type;

        // BTLSKL_ABILITYのインデックスリスト
        int             abilityIndexs[ABILITY_OVERLAP];

        uint64_t        speed;
        
        uint64_t        hit;
        uint64_t        avoid;
        
        bool            self;
        
        std::string     name;
        
        std::string     detail;
    };
    
    std::vector<BtlSkl> btlsklTable;
    virtual void initBtlSklTable(BTLSKL_ABILITY *abilitys, BTLSKL *btlskls);
};

#endif /* Person_hpp */
