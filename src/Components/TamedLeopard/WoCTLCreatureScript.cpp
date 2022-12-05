#include "WoCTLCreatureScript.h"

bool WoCTLCreatureScript::OnGossipHello(Player* player, Creature* creature)
{
    ClearGossipMenuFor(player);

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Mount the Leopard>", GOSSIP_SENDER_MAIN, GOSSIP_TAMED_LEOPARD_MOUNT);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Pet the Leopard>", GOSSIP_SENDER_MAIN, GOSSIP_TAMED_LEOPARD_PET);

    SendGossipMenuFor(player, ENTRY_TAMED_LEOPARD_GOSSIPTEXT_GREET, creature->GetGUID());

    return true;
}

bool WoCTLCreatureScript::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
    {
        return false;
    }

    switch (action)
    {
    case GOSSIP_TAMED_LEOPARD_MOUNT:
        MountPlayer(player, creature);
        break;

    case GOSSIP_TAMED_LEOPARD_PET:
        ReceivePet(player, creature);
        break;
    }

    return true;
}

void WoCTLCreatureScript::MountPlayer(Player* player, Creature* creature)
{
    if (!player || !creature)
    {
        return;
    }

    if (player->HasAura(ENTRY_TAMED_LEOPARD_MOUNT_SPELLID))
    {
        return;
    }

    if (player->IsMounted())
    {
        player->Dismount();
    }

    creature->AddAura(ENTRY_TAMED_LEOPARD_MOUNT_SPELLID, player);
}

void WoCTLCreatureScript::ReceivePet(Player* player, Creature* creature)
{
    creature->TextEmote("Tamed Leopard purrs.");

    CloseGossipMenuFor(player);
}
