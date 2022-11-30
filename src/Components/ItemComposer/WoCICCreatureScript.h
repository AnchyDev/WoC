#ifndef MODULE_WOC_IC_CREATURESCRIPT_H
#define MODULE_WOC_IC_CREATURESCRIPT_H

#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

#include <AI/ScriptedAI/ScriptedGossip.h>

class WoCICCreatureScript : public CreatureScript
{
public:
    WoCICCreatureScript() : CreatureScript("WoCICCreatureScript") { }
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

    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;
};

#endif //MODULE_WOC_IC_CREATURESCRIPT_H
