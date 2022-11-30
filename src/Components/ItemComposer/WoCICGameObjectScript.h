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
        GOSSIP_ITEM_COMPOSER_GOODBYE = 1500
    };

    enum ItemComposerEntries
    {
        ENTRY_ITEM_COMPOSER_GOSSIPTEXT = 410001
    };

    bool OnGossipHello(Player* /*player*/, GameObject* /*go*/) override;
    bool OnGossipSelect(Player* /*player*/, GameObject* /*go*/, uint32 /*sender*/, uint32 /*action*/) override;
};

#endif //MODULE_WOC_IC_GAMEOBJECTSCRIPT_H
