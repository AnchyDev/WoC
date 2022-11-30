#ifndef MODULE_WOC_IC_GAMEOBJECTSCRIPT_H
#define MODULE_WOC_IC_GAMEOBJECTSCRIPT_H

#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

#include <AI/ScriptedAI/ScriptedGossip.h>

class WoCICGameObjectScript : public GameObjectScript
{
public:
    WoCICGameObjectScript() : GameObjectScript("WoCICGameObjectScript") { }
private:
    enum ItemComposerGossip
    {
        GOSSIP_ITEM_COMPOSER_COMPOSE = 1000,

        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HEAD = 1101,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_NECK = 1102,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_SHOULDERS = 1103,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BACK = 1104,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_CHEST = 1105,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_WRISTS = 1106,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HANDS = 1107,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BELT = 1108,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_LEGS = 1109,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_FEET = 1110,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING1 = 1111,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING2 = 1112,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET1 = 1113,
        GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET2 = 1114,

        GOSSIP_ITEM_COMPOSTER_STARTCOMPOSE_ITEMPOS_START = 5000,
        GOSSIP_ITEM_COMPOSTER_STARTCOMPOSE_ITEMPOS_END = 6000,

        GOSSIP_ITEM_COMPOSER_GOODBYE = 1500
    };

    enum ItemComposerEntries
    {
        ENTRY_ITEM_COMPOSER_GOSSIPTEXT_GREET = 410001,
        ENTRY_ITEM_COMPOSER_GOSSIPTEXT_STARTCOMPOSE = 410002,
        ENTRY_ITEM_COMPOSER_GOSSIPTEXT_STARTCOMPOSE_LISTITEMS = 410003
    };

    bool OnGossipHello(Player* /*player*/, GameObject* /*go*/) override;
    bool OnGossipSelect(Player* /*player*/, GameObject* /*go*/, uint32 /*sender*/, uint32 /*action*/) override;

    void StartCompose(Player* /*player*/, GameObject* /*go*/);
    void ListItems(Player* /*player*/, GameObject* /*go*/, uint32 /*action*/);
    uint32 GetItemTypeFromAction(uint32 /*action*/);
};

#endif //MODULE_WOC_IC_GAMEOBJECTSCRIPT_H
