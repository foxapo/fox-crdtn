modded class Inventory
{

    private ImageWidget m_VicinityPhoto;
    private MultilineTextWidget m_VicinityName;
    private MultilineTextWidget m_VicinityFaction;
    private MultilineTextWidget m_VicinityRank;

    private ImageWidget m_CharacterPhoto;
    private MultilineTextWidget m_CharacterName;
    private MultilineTextWidget m_CharacterFaction;
    private MultilineTextWidget m_CharacterRank;

    private PluginUsersClient m_PluginUserClient;
    private PluginFactionsClient m_PluginFactionsClient;

    override void Init()
    {
        super.Init();

        Class.CastTo(m_PluginFactionsClient, GetPlugin(PluginFactionsClient));
        Class.CastTo(m_PluginUserClient, GetPlugin(PluginUsersClient));

        m_VicinityName = MultilineTextWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_VICINITY_NAME_W));
        m_VicinityPhoto = ImageWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_VICINITY_PHOTO_W));
        m_VicinityFaction = MultilineTextWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_VICINITY_FACTION_W));
        m_VicinityRank = MultilineTextWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_VICINITY_RANK_W));

        m_CharacterName = MultilineTextWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_CHARACTER_NAME_W));
        m_CharacterPhoto = ImageWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_CHARACTER_PHOTO_W));
        m_CharacterFaction = MultilineTextWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_CHARACTER_FACTION_W));
        m_CharacterRank = MultilineTextWidget.Cast(m_RootWidget.FindAnyWidget(CRDTN_UI_LAYOUT_CHARACTER_RANK_W));
    }

    override void OnHide()
    {
        super.OnHide();
        if (GetGame().IsClient())
        {
            PlaySound(CRDTN_SOUND_INV_CLOSE);
        }
    }


    override void OnShow()
    {
        super.OnShow();
        if (GetGame().IsClient())
        {
            InitCharacterPanel();
            InitVicinityPanel();
            PlaySound(CRDTN_SOUND_INV_CLOSE);
        }
    }

    void InitCharacterPanel()
    {
        if(m_PluginUserClient && m_PluginUserClient.IsInitialized())
        {
            m_CharacterName.SetText(m_PluginUserClient.GetPlayerName());
        }

        if(m_PluginFactionsClient && m_PluginFactionsClient.IsInitialized())
        {
            m_CharacterFaction.SetText(m_PluginFactionsClient.GetFactionNameById(m_PluginFactionsClient.GetUserFaction().Faction_ID));
            m_CharacterRank.SetText(m_PluginFactionsClient.GetRankNameById(m_PluginFactionsClient.GetUserFaction().Rank));
            m_CharacterPhoto.LoadImageFile(1, m_PluginFactionsClient.GetMyFactionIcon());
            m_CharacterPhoto.SetImage(1);
            m_CharacterPhoto.Show(true);
        }
    }

    void InitVicinityPanel()
    {
        VicinityItemManager vicinity_manager = VicinityItemManager.GetInstance();
        if(!vicinity_manager)
        {
            return;
        }
        
        ref array<EntityAI> objects = vicinity_manager.GetVicinityItems();
        if(!objects)
        {
            return;
        }

        foreach(EntityAI ent : objects)
        {
            if(!ent.IsMan() && !ent.IsDayZCreature())
            {
                continue;
            }

            SetInitVicinityPanel(ent);
            return;
        }
        
        UnsetVicinityPanel();
    }

    void SetInitVicinityPanel(EntityAI ent)
    {
        if(ent.IsMan())
        {
            PlayerBase player = PlayerBase.Cast(ent);
            if(player)
            {
                if(player.GetIdentity() != NULL)
                {
                    m_VicinityName.SetText(player.GetIdentity().GetName());
                    m_VicinityFaction.SetText(m_PluginFactionsClient.GetFactionNameById(player.GetFactionId()));
                    m_VicinityRank.SetText(m_PluginFactionsClient.GetRankNameById(player.GetFactionRank()));
                    m_VicinityPhoto.LoadImageFile(1, GUIUtils.GetFactionImageByType(player.GetFactionId()));
                    m_VicinityPhoto.SetImage(1);
                    m_VicinityPhoto.Show(true);
                }
                else
                {
                    m_VicinityName.SetText(player.GetDisplayName());
                    m_VicinityFaction.SetText("");
                    m_VicinityRank.SetText("");
                    m_VicinityPhoto.Show(false);
                }
            }
        }

        if(ent.IsDayZCreature())
        {
            DayZCreature creature = DayZCreature.Cast(ent);
            if(creature)
            {
                m_VicinityName.SetText(creature.GetDisplayName());
                m_VicinityFaction.SetText("");
                m_VicinityRank.SetText("");
                m_VicinityPhoto.Show(false);
                // m_VicinityFaction.SetText(m_PluginFactionsClient.GetUserFaction().GetFactionNameById(creature.GetFactionId()));
                // m_VicinityRank.SetText(m_PluginFactionsClient.GetUserFaction().GetRankNameById(creature.GetFactionRank()));
                // m_VicinityPhoto.LoadImageFile(1, GUIUtils.GetFactionImageByType(creature.GetFactionId()));
                // m_VicinityPhoto.SetImage(1);
                // m_VicinityPhoto.Show(true);
            }
        }
    }

    void UnsetVicinityPanel()
    {
        m_VicinityName.SetText("");
        m_VicinityFaction.SetText("");
        m_VicinityRank.SetText("");
        m_VicinityPhoto.Show(false);
    }
    
    void PlaySound(string soundset)
    {
        // Check the mission
        Mission mission = GetGame().GetMission();
        if (!mission)
        {
            return;
        }

        // Check the hud
        IngameHud thishud = IngameHud.Cast(mission.GetHud());
        if (!thishud)
        {
            return;
        }

        // Create a sound
        EffectSound sound = SEffectManager.CreateSound(soundset, GetGame().GetPlayer().GetPosition());
        if (!sound)
        {
            return;
        }

        sound.SetSoundAutodestroy(true);
        sound.SoundPlay();
    }
};