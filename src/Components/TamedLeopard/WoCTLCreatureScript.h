#ifndef MODULE_WOC_TL_CREATURESCRIPT_H
#define MODULE_WOC_TL_CREATURESCRIPT_H

#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

#include <AI/ScriptedAI/ScriptedGossip.h>

class WoCTLCreatureScript : public CreatureScript
{
public:
    WoCTLCreatureScript() : CreatureScript("WoCTLCreatureScript") { }

private:
    enum ItemComposerGossip
    {
        GOSSIP_TAMED_LEOPARD_MOUNT = 1000,
        GOSSIP_TAMED_LEOPARD_PET = 1001,
        GOSSIP_TAMED_LEOPARD_GOODBYE = 1500
    };

    enum ItemComposerEntries
    {
        ENTRY_TAMED_LEOPARD_GOSSIPTEXT_GREET = 411001,
        ENTRY_TAMED_LEOPARD_MOUNT_SPELLID = 10788
    };

    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;
    void MountPlayer(Player* /*player*/, Creature* /*creature*/);
    void ReceivePet(Player* /*player*/, Creature* /*creature*/);
};

#endif //MODULE_WOC_TL_CREATURESCRIPT_H
