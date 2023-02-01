class CRDTN_PluginBase : PluginBase
{
    protected bool m_IsInitialized = false;

    override void OnInit()
    {
        super.OnInit();
        InitRPCs();
        InitData();
        ParseData();
    }

    bool IsInitialized()
    {
        return m_IsInitialized;
    }

    void InitRPCs();
    
    void InitData();
    
    void ParseData();
};