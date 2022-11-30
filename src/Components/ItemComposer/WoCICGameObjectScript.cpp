#include "WoCICGameObjectScript.h"

bool WoCICGameObjectScript::OnGossipHello(Player* player, GameObject* go)
{
    ClearGossipMenuFor(player);

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I would like to compose an item.", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_COMPOSE);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Goodbye.", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_GOODBYE);

    SendGossipMenuFor(player, ENTRY_ITEM_COMPOSER_GOSSIPTEXT_GREET, go->GetGUID());

    return true;
}

bool WoCICGameObjectScript::OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
    {
        return false;
    }

    switch (action)
    {
    case GOSSIP_ITEM_COMPOSER_COMPOSE:
        StartCompose(player, go);
        break;

    case GOSSIP_ITEM_COMPOSER_GOODBYE:
        CloseGossipMenuFor(player);
        break;

    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HEAD:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_NECK:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_SHOULDERS:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BACK:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_CHEST:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_WRISTS:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HANDS:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BELT:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_LEGS:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_FEET:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING1:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING2:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET1:
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET2:
        ListItems(player, go, action);
        break;
    }

    if (action > GOSSIP_ITEM_COMPOSTER_STARTCOMPOSE_ITEMPOS_START &&
        action < GOSSIP_ITEM_COMPOSTER_STARTCOMPOSE_ITEMPOS_END)
    {
        uint32 itemPos = action - GOSSIP_ITEM_COMPOSTER_STARTCOMPOSE_ITEMPOS_START;
        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, itemPos);

        if (item)
        {
            LOG_INFO("module", "Found item: {}", item->GetTemplate()->Name1);
        }
    }

    return true;
}

void WoCICGameObjectScript::StartCompose(Player* player, GameObject* go)
{
    ClearGossipMenuFor(player);

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Head", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HEAD);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Neck", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_NECK);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Shoulders", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_SHOULDERS);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Back", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BACK);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Chest", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_CHEST);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Wrists", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_WRISTS);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Hands", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HANDS);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Belt", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BELT);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Legs", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_LEGS);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Feet", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_FEET);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Ring 1", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING1);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Ring 2", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING2);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Trinket 1", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET1);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Trinket 2", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET2);
    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Goodbye.", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_GOODBYE);

    SendGossipMenuFor(player, ENTRY_ITEM_COMPOSER_GOSSIPTEXT_STARTCOMPOSE, go->GetGUID());
}

void WoCICGameObjectScript::ListItems(Player* player, GameObject* go, uint32 action)
{
    ClearGossipMenuFor(player);

    uint32 itemType = GetItemTypeFromAction(action);

    for (uint32 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);

        if (!item)
        {
            continue;
        }

        LOG_INFO("module", "ItemId: {}, Type: {}, Slot: {}", item->GetTemplate()->ItemId, item->GetTemplate()->InventoryType, i);

        if (item->GetTemplate()->HasWoCFlag(WOC_FLAGS_ITEM) &&
            item->GetTemplate()->InventoryType == itemType)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, item->GetTemplate()->Name1, GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSTER_STARTCOMPOSE_ITEMPOS_START + i);
        }
    }

    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Goodbye.", GOSSIP_SENDER_MAIN, GOSSIP_ITEM_COMPOSER_GOODBYE);

    SendGossipMenuFor(player, ENTRY_ITEM_COMPOSER_GOSSIPTEXT_STARTCOMPOSE_LISTITEMS, go->GetGUID());
}

uint32 WoCICGameObjectScript::GetItemTypeFromAction(uint32 action)
{
    switch (action)
    {
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HEAD:
        return 1;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_NECK:
        return 2;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_SHOULDERS:
        return 3;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BACK:
        return 16;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_CHEST:
        return 5;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_WRISTS:
        return 9;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_HANDS:
        return 10;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_BELT:
        return 6;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_LEGS:
        return 7;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_FEET:
        return 8;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING1:
        return 11;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_RING2:
        return 11;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET1:
        return 12;
    case GOSSIP_ITEM_COMPOSER_STARTCOMPOSE_TRINKET2:
        return 12;
    }

    return 0;
}
