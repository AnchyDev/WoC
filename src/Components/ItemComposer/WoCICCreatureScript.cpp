#include "WoCICCreatureScript.h"

bool WoCICCreatureScript::OnGossipHello(Player* player, Creature* creature)
{
    ClearGossipMenuFor(player);

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I would like to compose an item.", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_COMPOSE);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Goodbye.", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_GOODBYE);

    SendGossipMenuFor(player, ENTRY_ITEM_COMPOSER_GOSSIPTEXT, creature->GetGUID());

    return true;
}

bool WoCICCreatureScript::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
    {
        return false;
    }

    switch (action)
    {
    case GOSSIP_ITEM_COMPOSER_COMPOSE:
        ChatHandler(player->GetSession()).SendSysMessage("Compose");
        break;

    case GOSSIP_ITEM_COMPOSER_GOODBYE:
        CloseGossipMenuFor(player);
        break;
    }

    return true;
}
