#include "WoCIGPlayerScript.h"

void WoCIGPlayerScript::OnStoreNewItem(Player* player, Item* item, uint32 /*count*/)
{
    auto itemTemplate = item->GetTemplate();

    if (!itemTemplate->HasWoCFlag(WOC_FLAGS_ITEM))
    {
        return;
    }

    double roll = rand_chance();

    if (roll > 50.0)
    {

        if (itemTemplate->HasWoCFlag(WOC_FLAGS_ITEM_PHYS))
        {
            item->SetItemRandomProperties(-urand(100, 108));
        }

        EnchantItem(player, item, PRISMATIC_ENCHANTMENT_SLOT, 3884, true);
    }
}

void WoCIGPlayerScript::EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId, bool overwrite)
{
    if (item->GetEnchantmentId(slot) && !overwrite)
    {
        return;
    }

    player->ApplyEnchantment(item, false);
    item->SetEnchantment(EnchantmentSlot(slot), enchantId, 0, 0);
    player->ApplyEnchantment(item, true);

    return;
}
