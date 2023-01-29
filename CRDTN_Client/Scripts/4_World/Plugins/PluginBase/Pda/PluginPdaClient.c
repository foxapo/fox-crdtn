class PluginPdaClient : PluginPdaBase
{

    private Widget m_PDAPanelRoot;
    private ref CRDTN_PDA_Widget m_PDAWidget;
    private bool m_IsOpen = false;

    private Widget m_PDAInstanceWidget;

    void PluginPdaClient()
    {
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::PluginPdaClient()");
    }

    void SetHudWidget(Widget parent)
    {
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::SetHudWidget()");
        m_PDAPanelRoot = parent;
    }

    void InitPdaWidget()
    {
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::InitPdaWidget()");
        m_PDAWidget = new CRDTN_PDA_Widget();
        m_PDAWidget.SetParent(m_PDAPanelRoot);
        m_PDAInstanceWidget = m_PDAWidget.Init();
        m_PDAInstanceWidget.Show(false);
        // Event subscription
    }

    void Open()
    {
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::OpenPda()");
        m_PDAInstanceWidget.Show(true);
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::OpenPda() - m_PDAInstanceWidget.Show(true)" + m_PDAInstanceWidget.GetName());
        m_IsOpen = true;
    }

    void Close()
    {
        Print(CRDTN_MOD_PREFIX + " PluginPdaClient::ClosePda()");
        if (m_PDAWidget != null)
        {
            m_PDAInstanceWidget.Show(false);
            Print(CRDTN_MOD_PREFIX + " PluginPdaClient::OpenPda() - m_PDAInstanceWidget.Show(false)" + m_PDAInstanceWidget.GetName());
        }
        m_IsOpen = false;
    }

    bool IsOpen()
    {
        return m_IsOpen;
    }
};