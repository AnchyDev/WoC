#ifndef MODULE_WOC_H
#define MODULE_WOC_H

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

#include "Config/WoCConfig.h"
#include "Components/Components.h"

class WoCWorld : public WorldScript
{
public:
    WoCWorld() : WorldScript("WoCWorld") { }

private:
    void OnAfterConfigLoad(bool /*reload*/) override;
};

#endif //MODULE_WOC_H
