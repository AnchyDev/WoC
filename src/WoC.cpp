#include "WoC.h"

void WoCWorld::OnAfterConfigLoad(bool /*reload*/)
{
    WoCConfigMgr->Enable = sConfigMgr->GetOption<bool>("WoC.Enable", false);
}

void AddSCWoCScripts()
{
    new WoCWorld();

    if (WoCConfigMgr->Enable)
    {
        new WoCIGPlayerScript();
    }
}
