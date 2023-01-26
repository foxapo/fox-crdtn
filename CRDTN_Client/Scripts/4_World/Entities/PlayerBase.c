modded class PlayerBase
{

    private PluginFactionsClient m_PluginFactionsClient;
    private PluginUsersClient m_PluginUsersClient;
    private int m_FactionId = -1;
    private int m_FactionRank = -1;

    void PlayerBase()
    {
        RegisterNetSyncVariableInt("m_FactionId", int.MIN, int.MAX);
        RegisterNetSyncVariableInt("m_FactionRank", int.MIN, int.MAX);

        Class.CastTo(m_PluginFactionsClient, GetPlugin(PluginFactionsClient));
        Class.CastTo(m_PluginUsersClient, GetPlugin(PluginUsersClient));
    }

    override void EEInit()
    {
        super.EEInit();
        if (GetGame().IsClient())
        {
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "LoginUser", new Param1<bool>(false), true, GetIdentity());
        }
    }

    override void OnConnect()
    {
        super.OnConnect();

        if (GetGame().IsClient())
        {
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "GetAllFactions", new Param1<bool>(true), true, GetIdentity());
        }
    }

    override void OnSelectPlayer()
    {
        super.OnConnect();
        if (GetGame().IsClient())
        {
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "LoginUser", new Param1<bool>(false), true, GetIdentity());
        }
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



};

