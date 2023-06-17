class PluginPPE : PluginBase
{

    private CRDTN_PP_PSIRequester m_PSIRequester;

    override void OnInit()
    {
        super.OnInit();
        m_PSIRequester = CRDTN_PP_PSIRequester.Cast(PPERequesterBank.GetRequester(CRDTN_PP_PSIRequester));
    }

    void PluginPPE()
    {
        Print("PluginPPE::PluginPPE()");
    }

    void SetPPEFromTriggerType(CRDTN_ETriggerType triggerType, bool state)
    {
        if(!m_PSIRequester)
        {
            return;
        }
        
        
    }
}