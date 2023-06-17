modded class PlayerBase
{

    private PluginFactionsClient m_PluginFactionsClient;
    private PluginUsersClient m_PluginUsersClient;
    private PluginPPE m_PluginPPE;
    private int m_FactionId = -1;
    private int m_FactionRank = -1;

    void PlayerBase()
    {
        RegisterNetSyncVariableInt("m_FactionId", int.MIN, int.MAX);
        RegisterNetSyncVariableInt("m_FactionRank", int.MIN, int.MAX);

        Class.CastTo(m_PluginFactionsClient, GetPlugin(PluginFactionsClient));
        Class.CastTo(m_PluginUsersClient, GetPlugin(PluginUsersClient));
        Class.CastTo(m_PluginPPE, GetPlugin(PluginPPE));
    }

    void SetFactionId(int factionId)
    {
        m_FactionId = factionId;
        SetSynchDirty();
    }

    void SetFactionRank(int factionRank)
    {
        m_FactionRank = factionRank;
        SetSynchDirty();
    }

    override void OnPlayerLoaded()
    {
        super.OnPlayerLoaded();
        if (IsControlledPlayer())//true only on client for the controlled character
		{
            GetDayZGame().CRDTNGetEventHandler().GetEventInvoker(CRDTN_EVT_PLAYER_FACTION_SYNC).Invoke();
        }
    }

    int GetFactionId()
    {
        return m_FactionId;
    }

    int GetFactionRank()
    {
        return m_FactionRank;
    }

    void SetTriggerEffectPPE(CRDTN_ETriggerType triggerType, bool state)
    {
        if(!m_PluginPPE)
        {
            return;
        }
        
    }
};

