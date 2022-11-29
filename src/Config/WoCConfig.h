#ifndef MODULE_WOC_CONFIG_H
#define MODULE_WOC_CONFIG_H

class WoCConfig
{
public:
    bool Enable;

    static WoCConfig* GetInstance();
private:
    WoCConfig();
    static WoCConfig* instance;
};

#define WoCConfigMgr WoCConfig::GetInstance()

#endif //MODULE_WOC_CONFIG_H
