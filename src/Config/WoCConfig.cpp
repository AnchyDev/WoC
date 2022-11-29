#include "WoCConfig.h"

WoCConfig* WoCConfig::GetInstance()
{
    if (!WoCConfig::instance)
    {
        WoCConfig::instance = new WoCConfig();
    }

    return WoCConfig::instance;
}
