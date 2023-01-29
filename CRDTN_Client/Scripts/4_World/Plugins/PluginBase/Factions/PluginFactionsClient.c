class PluginFactionsClient : PluginFactionsBase
{

    private ref map<int, ref CRDTN_Faction> m_Factions;
    private ref CRDTN_UserFaction m_UserFaction;
    private ref map<int, ref CRDTN_Rank> m_Ranks;

    CRDTN_UserFaction GetUserFaction()
    {
        return m_UserFaction;
    }

    int GetMyFactionId()
    {
        if(m_UserFaction != null)
        {
            return m_UserFaction.Faction_ID;
        }

        return -1;
    }

    string GetFactionNameById(int id)
    {
        if(m_Factions.Get(id) != null)
        {
            return m_Factions.Get(id).FactionName;
        }

        return "";
    }

    string GetRankNameById(int id)
    {
        if(m_Ranks.Get(id) != null)
        {
            return m_Ranks.Get(id).RankName;
        }

        return "";
    }

    string GetRankIconById(int id)
    {
        if(m_Ranks.Get(id) != null)
        {
            return m_Ranks.Get(id).RankIconPath;
        }

        return "";
    }

    string GetFactionIconById(int id)
    {
        if(m_Factions.Get(id) != null)
        {
            return m_Factions.Get(id).FactionIconPath;
        }

        return "";
    }

    string GetMyFactionIcon()
    {
        if(m_UserFaction != null)
        {
            return GetFactionIconById(m_UserFaction.Faction_ID);
        }

        return "";
    }

    string GetMyRankIcon()
    {
        if(m_UserFaction != null)
        {
            return GetRankIconById(m_UserFaction.Rank);
        }

        return "";
    }

    bool IsFactionInitialized()
    {
        return m_Factions != null;
    }


    // RPCs
    override void GetAllFactions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param2<array<CRDTN_Faction>, array<CRDTN_Rank>> data;
        if (!ctx.Read(data))
        {
            return;
        }

        m_Factions = new map<int, ref CRDTN_Faction>();
        foreach (CRDTN_Faction faction : data.param1)
        {
            m_Factions.Insert(faction.Id, faction);
        }
        m_Ranks = new map<int, ref CRDTN_Rank>();
        foreach (CRDTN_Rank rank : data.param2)
        {
            m_Ranks.Insert(rank.Id, rank);
        }
        Print("Factions received!");
    }

    override void GetFactionById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param1<CRDTN_Faction> data;
        if (!ctx.Read(data))
        {
            return;
        }
    }

    override void GetFactionUserById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param1<CRDTN_UserFaction> data;
        if (!ctx.Read(data))
        {
            return;
        }

        if(!data.param1)
        {
            Print("Received null user faction data from the server!");
            return;
        }

        Print("User faction received!");
        m_UserFaction = data.param1;
        Print(m_UserFaction.PrintData());
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        player.SetFactionId(m_UserFaction.Faction_ID);
        player.SetFactionRank(m_UserFaction.Rank);
    }
};
