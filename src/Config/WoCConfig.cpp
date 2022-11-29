#include "WoCConfig.h"

WoCConfig* WoCConfig::GetInstance()
{
    if (!instance)
    {
        instance = new WoCConfig();
    }

    return instance;
}
