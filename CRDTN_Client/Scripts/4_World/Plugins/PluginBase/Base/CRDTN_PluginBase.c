class CRDTN_PluginBase : PluginBase
{

    override void OnInit()
    {
        super.OnInit();
        InitRPCs();
        InitData();
        ParseData();
    }

    void InitRPCs();
    
    void InitData();
    
    void ParseData();
};