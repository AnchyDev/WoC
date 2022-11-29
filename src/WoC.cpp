#include "WoC.h"

void WoCWorld::OnAfterConfigLoad(bool /*reload*/)
{
    WoCConfigMgr->Enable = sConfigMgr->GetOption<bool>("WoC.Enable", false);
}

void AddWoCScripts()
{
    new WoCWorld();

    if (WoCConfigMgr->Enable)
    {
        new WoCIGPlayerScript();
    }
}
