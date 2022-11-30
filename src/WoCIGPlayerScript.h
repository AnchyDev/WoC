#ifndef MODULE_WOC_IG_PLAYERSCRIPT_H
#define MODULE_WOC_IG_PLAYERSCRIPT_H

#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

class WoCIGPlayerScript : public PlayerScript
{
public:
    WoCIGPlayerScript() : PlayerScript("WoGIGPlayerScript") { }
private:
    void OnStoreNewItem(Player* /*player*/, Item* /*item*/, uint32 /*count*/) override;
    void EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId, bool overwrite);
};

#endif //MODUlE_WOC_IG_PLAYERSCRIPT_H
