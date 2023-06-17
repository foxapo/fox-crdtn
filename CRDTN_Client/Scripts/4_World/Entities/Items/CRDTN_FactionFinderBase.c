class CRDTN_FactionFinderBase extends PoweredOptic_Base
{
    static const float FACTIONFINDER_MAX_DISTANCE = 400.0;

    protected ref Timer m_Timer;
    protected ref WidgetFadeTimer m_FadeTimer;
    protected PluginFactionsClient m_PluginFactionsClient;

    protected Widget m_FactionFinderWidgetRoot;
    protected Widget m_FactionFinderWidget;
    protected TextWidget m_FactionFinderTargetName;
    protected TextWidget m_FactionFinderTargetRank;
    protected ImageWidget m_FactionFinderFactionIcon;
    protected ImageWidget m_FactionFinderRankIcon;

    private bool m_IsFactionFinderActive = false;

    void ~CRDTN_FactionFinderBase()
    {
        delete m_Timer;
        delete m_FadeTimer;
    }

    // How frequently the measurement should be taken
    float GetMeasurementUpdateInterval()
    {
        return 0.5;
    }

    override void OnWorkStart()
    {
        if (!GetGame().IsDedicatedServer())
        {
            PlayerBase player_this = PlayerBase.Cast(GetGame().GetPlayer());
            PlayerBase player_owner = PlayerBase.Cast(GetHierarchyRootPlayer());

            if (!m_FactionFinderWidgetRoot)
            {
                m_FactionFinderWidgetRoot = GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_FACTION_FINDER_L);
                if (!m_FactionFinderWidgetRoot)
                {
                    return;
                }
                m_FactionFinderWidget = m_FactionFinderWidgetRoot.FindAnyWidget(CRDTN_UI_LAYOUT_FACTION_FINDER_W);
                if (!m_FactionFinderWidget)
                {
                    return;
                }
                m_FactionFinderWidgetRoot.Show(true);
                m_FactionFinderWidget.Show(false);
            }

            if (!m_IsFactionFinderActive)
            {
                if (!PreInit())
                {
                    return;
                }
            }

            if (player_this == player_owner)
            {
                StartPeriodicMeasurement();
            }
        }
    }

    override void OnWorkStop()
    {
        if (!GetGame().IsDedicatedServer())
        {
            PlayerBase player_this = PlayerBase.Cast(GetGame().GetPlayer());
            PlayerBase player_owner = PlayerBase.Cast(GetHierarchyRootPlayer());
            if (player_this == player_owner)
            {
                StopPeriodicMeasurement();
                HideFactionFinder();
            }
        }
    }

    void StartPeriodicMeasurement()
    {
        if (!m_Timer)
        {
            m_Timer = new Timer(CALL_CATEGORY_GAMEPLAY);
        }

        m_Timer.Run(GetMeasurementUpdateInterval(), this, "DoMeasurement", null, true);
    }

    void StopPeriodicMeasurement()
    {
        if (m_Timer)
        {
            m_Timer.Stop();
        }
    }

    void HideFactionFinder()
    {
        if (m_FactionFinderWidget)
        {
            m_FactionFinderWidget.Show(false);
        }
    }

    // Measures the distance and returns result in formated string
    void DoMeasurement()
    {
        PlayerBase player = GetPlayer();
        if (player)
        {
            // Raycast from
            vector from = GetGame().GetCurrentCameraPosition() + GetGame().GetCurrentCameraDirection().Normalized() * 2.0;
            // Raycast to
            vector to = from + (GetGame().GetCurrentCameraDirection() * FACTIONFINDER_MAX_DISTANCE);
            // Raycast out parameter
            vector contact_pos;
            vector contact_dir;
            int contact_component;
            set<Object> objects = new set<Object>;
            bool selected = false;

            if (DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, objects))
            {
                Print(CRDTN_MOD_PREFIX + "Factionfinder: Raycast hit something! (" + objects.Count() + " objects");

                for (int i = 0; i < objects.Count(); ++i)
                {
                    Object obj = objects.Get(i);
                    if (!obj.IsInherited(EntityAI))
                    {
                        continue;
                    }
                    EntityAI entity = EntityAI.Cast(obj);
                    Print(CRDTN_MOD_PREFIX + "Factionfinder: Object " + i + ": " + entity.GetDisplayName());

                    float dist = vector.Distance(from, contact_pos);
                    dist = Math.Round(dist);
                    if (dist > FACTIONFINDER_MAX_DISTANCE)
                    {
                        continue;
                    }

                    PlayerBase targetPlayer = PlayerBase.Cast(entity);
                    if (!targetPlayer)
                    {
                        continue;
                    }
                    RenderFactionFinder(targetPlayer);
                    return;
                }
                HideFactionFinder();
            }
            else
            {
                HideFactionFinder();
            }
        }
    }

    bool PreInit()
    {

        if (m_FadeTimer == null)
        {
            m_FadeTimer = new WidgetFadeTimer();
        }

        if (m_IsFactionFinderActive)
        {
            return true;
        }

        if (!m_PluginFactionsClient)
        {
            Print(CRDTN_MOD_PREFIX + "Factionfinder: getting PluginFactionsClient");
            m_PluginFactionsClient = PluginFactionsClient.Cast(GetPlugin(PluginFactionsClient));
        }

        if (!m_PluginFactionsClient)
        {
            Print(CRDTN_MOD_PREFIX + "Factionfinder: PluginFactionsClient not found!");
            return false;
        }

        m_FactionFinderTargetName = TextWidget.Cast(m_FactionFinderWidgetRoot.FindAnyWidget(CRDTN_UI_LAYOUT_FACTION_FINDER_CHAR_NAME));
        if (!m_FactionFinderTargetName)
        {
            Print(CRDTN_MOD_PREFIX + "Factionfinder: m_FactionFinderTargetName not found!");
            return false;
        }

        m_FactionFinderTargetRank = TextWidget.Cast(m_FactionFinderWidgetRoot.FindAnyWidget(CRDTN_UI_LAYOUT_FACTION_FINDER_CHAR_RANK));
        if (!m_FactionFinderTargetRank)
        {
            Print(CRDTN_MOD_PREFIX + "Factionfinder: m_FactionFinderTargetRank not found!");
            return false;
        }

        m_FactionFinderFactionIcon = ImageWidget.Cast(m_FactionFinderWidgetRoot.FindAnyWidget(CRDTN_UI_LAYOUT_FACTION_FINDER_FACTION_ICON));
        if (!m_FactionFinderFactionIcon)
        {
            Print(CRDTN_MOD_PREFIX + "Factionfinder: m_FactionFinderFactionIcon not found!");
            return false;
        }

        m_FactionFinderRankIcon = ImageWidget.Cast(m_FactionFinderWidgetRoot.FindAnyWidget(CRDTN_UI_LAYOUT_FACTION_FINDER_RANK_ICON));
        if (!m_FactionFinderRankIcon)
        {
            Print(CRDTN_MOD_PREFIX + "Factionfinder: m_FactionFinderRankIcon not found!");
            return false;
        }

        m_IsFactionFinderActive = true;
        return true;
    }

    void RenderFactionFinder(PlayerBase player)
    {
        Print(CRDTN_MOD_PREFIX + "Factionfinder: Render! " + player.GetDisplayName());
        if (player.GetIdentity())
        {
            m_FactionFinderTargetName.SetText(player.GetIdentity().GetName());
            m_FactionFinderTargetRank.SetText(m_PluginFactionsClient.GetRankNameById(player.GetFactionRank()));
            m_FactionFinderFactionIcon.LoadImageFile(1, GUIUtils.GetFactionImageByType(player.GetFactionId()));
            m_FactionFinderFactionIcon.SetImage(1);
            m_FactionFinderFactionIcon.Show(true);
            m_FactionFinderRankIcon.LoadImageFile(1, GUIUtils.GetRankImageByType(player.GetFactionRank()));
            m_FactionFinderFactionIcon.SetImage(1);
            m_FactionFinderFactionIcon.Show(true);
            m_FactionFinderWidget.Show(true);
        }
        else
        {
            m_FactionFinderTargetName.SetText(player.GetDisplayName());
            m_FactionFinderTargetRank.SetText("");
            m_FactionFinderFactionIcon.Show(false);
            m_FactionFinderRankIcon.Show(false);
            m_FactionFinderWidget.Show(true);
        }
    }

    override void SetActions()
    {
        super.SetActions();

        RemoveAction(ActionViewOptics);
        AddAction(ActionViewBinoculars);
    }

    override void OnDebugSpawn()
    {
        GetInventory().CreateInInventory("Battery9V");
    }
};