#include "WoCConfig.h"

WoCConfig::WoCConfig()
{
    Enable = false;
}

WoCConfig* WoCConfig::GetInstance()
{
    if (!instance)
    {
        instance = new WoCConfig();
    }

    return instance;
}
