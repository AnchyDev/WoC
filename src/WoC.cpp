#include "WoC.h"

void WoCWorld::OnAfterConfigLoad(bool /*reload*/)
{
    LOG_INFO("module", "Loading WoC config..");
    WoCConfigMgr->Enable = sConfigMgr->GetOption<bool>("WoC.Enable", false);
    LOG_INFO("module", ">> Config Loaded");
}

void AddSCWoCScripts()
{
    new WoCWorld();
    new WoCIGPlayerScript();
    new WoCICGameObjectScript();
}
