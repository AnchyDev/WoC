#include "WoCConfig.h"

WoCConfig* WoCConfig::instance = nullptr;

WoCConfig* WoCConfig::GetInstance()
{
    if (!instance)
    {
        instance = new WoCConfig();
    }

    return instance;
}
