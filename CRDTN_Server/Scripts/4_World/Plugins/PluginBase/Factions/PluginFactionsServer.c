class PluginFactionsServer : PluginFactionsBase
{

    ref CRDTN_Factions cfg_Factions;
    // Maps
    ref map<CRDTN_EFaction, ref CRDTN_Faction> Factions;
    ref map<int, ref CRDTN_UserFaction> UserFactions;
    ref map<CRDTN_ERank, ref CRDTN_Rank> Ranks;

    override void InitData()
    {
        if (FileExist(MOD_PATH + CONFIG_FACTIONS))
        {
            JsonFileLoader<ref CRDTN_Factions>.JsonLoadFile(MOD_PATH + CONFIG_FACTIONS, cfg_Factions);
        }
        else
        {
            Print(CRDTN_MOD_PREFIX + " Factions config not found!");
            return;
        }
    }

    override void ParseData()
    {
        Factions = new map<CRDTN_EFaction, ref CRDTN_Faction>();
        foreach (CRDTN_Faction faction : cfg_Factions.Factions)
        {
            Factions.Insert(faction.Id, faction);
        }
        UserFactions = new map<int, ref CRDTN_UserFaction>();
        foreach (CRDTN_UserFaction userFaction : cfg_Factions.UserFactions)
        {
            UserFactions.Insert(userFaction.Player_ID, userFaction);
        }

        Ranks = new map<CRDTN_ERank, ref CRDTN_Rank>();
        foreach (CRDTN_Rank rank : cfg_Factions.Ranks)
        {
            Ranks.Insert(rank.Id, rank);
        }
        Print(CRDTN_MOD_PREFIX + " Total factions loaded: " + Factions.Count());
        Print(CRDTN_MOD_PREFIX + " Total user factions loaded: " + UserFactions.Count());
        Print(CRDTN_MOD_PREFIX + " Total ranks loaded: " + Ranks.Count());
    }

    // Retrieving of all factions - Param<array<CRDTN_Faction>>
    override void GetAllFactions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }

        array<CRDTN_Faction> factions = new array<CRDTN_Faction>();
        array<CRDTN_Rank> ranks = new array<CRDTN_Rank>();
        foreach (CRDTN_Faction faction : cfg_Factions.Factions)
        {
            factions.Insert(faction);
        }

        foreach (CRDTN_Rank rank : cfg_Factions.Ranks)
        {
            ranks.Insert(rank);
        }

        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "GetAllFactions", new Param2<array<CRDTN_Faction>, array<CRDTN_Rank>>(factions, ranks), true, sender);
        Print(CRDTN_MOD_PREFIX + " Sent all factions and ranks to " + sender.GetName());
    }

    // Retrieving of faction data by given id - Param<int>
    override void GetFactionById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }

        Param1<int> data;
        if (!ctx.Read(data))
        {
            return;
        }

        CRDTN_Faction faction = Factions.Get(data.param1);
        if(!faction)
        {
            Print("Could not find faction with id " + data.param1 + "");
            return;
        }

        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "GetFactionById", new Param1<CRDTN_Faction>(faction), true, sender);
        Print(CRDTN_MOD_PREFIX + " Sent faction " + faction.FactionName + " to " + sender.GetName());
    }

    // Retrieving of faction user data by given id - Param<int>
    override void GetFactionUserById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }

        int userId = -1;
        if(ctx != null)
        {
            Param1<int> data;
            if (!ctx.Read(data))
            {
                return;
            }
            userId = data.param1;
        }else
        {
            userId = CRDTN_GlobalUtils.ParseID(sender.GetPlainId());
        }

        CRDTN_UserFaction userFaction = UserFactions.Get(userId);
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "GetFactionUserById", new Param1<CRDTN_UserFaction>(userFaction), true, sender);
        Print(CRDTN_MOD_PREFIX + " Sent faction user " + userFaction.Faction_ID + " to " + sender.GetName());
    }
};