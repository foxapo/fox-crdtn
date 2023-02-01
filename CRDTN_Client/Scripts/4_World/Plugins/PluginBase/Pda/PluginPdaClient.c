class PluginPdaClient : PluginPdaBase
{

    private Widget m_PDAPanelRoot;
    private ref CRDTN_PDA_Widget m_PDAWidget;
    private bool m_IsOpen = false;

    void PluginPdaClient()
    {
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::PluginPdaClient()");
    }

    void SetHudWidget(Widget parent)
    {
        m_PDAPanelRoot = parent;
    }

    void InitPdaWidget()
    {
        m_PDAPanelRoot.Show(true);
    }

    void Open()
    {
        m_PDAWidget = new CRDTN_PDA_Widget();
        m_PDAWidget.SetParent(m_PDAPanelRoot);
        m_PDAWidget.Init();
        GetGame().GetUIManager().ShowScriptedMenu(m_PDAWidget, NULL);
        m_IsOpen = true;
    }

    void Close()
    {
        m_PDAWidget.OnHide();
        m_IsOpen = false;
    }

    bool IsOpen()
    {
        return m_IsOpen;
    }
};