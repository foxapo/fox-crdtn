modded class IngameHud
{

    private PluginFactionsClient m_PluginFactionsClient;
    private PluginPdaClient m_PluginPdaClient;

    private ImageWidget m_FactionWidget;
    private ImageWidget m_RankWidget;

    private Widget m_PDAPanel;
    

    override void Init(Widget hud_panel_widget)
    {
        super.Init(hud_panel_widget);
        m_FactionWidget = ImageWidget.Cast(hud_panel_widget.FindAnyWidget(CRDTN_UI_LAYOUT_FACTION_PATCH_W));
        m_RankWidget = ImageWidget.Cast(hud_panel_widget.FindAnyWidget(CRDTN_UI_LAYOUT_RANK_PATCH_W));
        m_PDAPanel = Widget.Cast(hud_panel_widget.FindAnyWidget(CRDTN_UI_LAYOUT_PDA_PANEL_W));

        Class.CastTo(m_PluginFactionsClient, GetPlugin(PluginFactionsClient));
        Class.CastTo(m_PluginPdaClient, GetPlugin(PluginPdaClient));

        if(m_PluginFactionsClient)
        {
            GetDayZGame().CRDTNGetEventHandler().GetEventInvoker(CRDTN_EVT_PLAYER_FACTION_SYNC).Insert(InitFactionBadges);
        }

        if(m_PluginPdaClient)
        {
            m_PluginPdaClient.SetHudWidget(m_PDAPanel);
            m_PluginPdaClient.InitPdaWidget();
        }
    }

    ImageWidget GetFactionWidget()
    {
        return m_FactionWidget;
    }

    
    /// @brief Custom CRDTN ui init
    void InitFactionBadges()
    {
        Print("InitFactionBadge");
        Print(m_PluginFactionsClient);
        
        if (!m_PluginFactionsClient)
        {
            return;
        }
        string imgPath = m_PluginFactionsClient.GetMyFactionIcon();
        m_FactionWidget.LoadImageFile(1, imgPath);
        m_FactionWidget.SetImage(1);
        m_FactionWidget.Show(true);

        imgPath = m_PluginFactionsClient.GetMyRankIcon();
        m_RankWidget.LoadImageFile(1, imgPath);
        m_RankWidget.SetImage(1);
        m_RankWidget.Show(true);
    }
    
};