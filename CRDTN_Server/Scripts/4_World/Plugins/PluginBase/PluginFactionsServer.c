class PluginFactionsServer : PluginFactionsBase
{

    ref CRDTN_Factions cfg_Factions;
    // Maps
    ref map<CRDTN_EFaction, ref CRDTN_Faction> Factions;
    ref map<int, ref CRDTN_UserFaction> UserFactions;

    void PluginFactionsServer()
    {
        if (!FileExist("$profile:\\" + PROFILE_FOLDER + "\\" + MOD_FOLDER + "\\" + CONFIG_FACTIONS))
        {
            MakeDirectory("$profile:\\" + PROFILE_FOLDER + "\\" + MOD_FOLDER + "\\" + CONFIG_FACTIONS);
        }
    }

    override void InitData()
    {
        Print(CRDTN_MOD_PREFIX + " Loading Factions...");
        if (FileExist(MOD_PATH + CONFIG_FACTIONS))
        {
            JsonFileLoader<ref CRDTN_Factions>.JsonLoadFile(MOD_PATH + CONFIG_FACTIONS, cfg_Factions);
        }
        else
        {
            Print(CRDTN_MOD_PREFIX + " Factions config not found!");
            return;
        }

        Print(CRDTN_MOD_PREFIX + " Total factions loaded: " + cfg_Factions.Factions.Count());
    }

    override void ParseData()
    {
        Print(CRDTN_MOD_PREFIX + " Parsing factions...");
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
        Print(CRDTN_MOD_PREFIX + " Total factions parsed: " + Factions.Count());
        Print(CRDTN_MOD_PREFIX + " Total user factions parsed: " + UserFactions.Count());
    }

    
     // Retrieving of all factions - Param<array<CRDTN_Faction>>
    override void GetAllFactions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }

        array<CRDTN_Faction> factions = new array<CRDTN_Faction>();
        foreach (CRDTN_Faction faction : cfg_Factions.Factions)
        {
            factions.Insert(faction);
        }
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "GetAllFactions", new Param1<array<CRDTN_Faction>>(factions), true, sender);
        Print(CRDTN_MOD_PREFIX + " Sent all factions to " + sender.GetName());
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

        Param1<int> data;
        if (!ctx.Read(data))
        {
            return;
        }

        CRDTN_UserFaction userFaction = UserFactions.Get(data.param1);
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "GetFactionUserById", new Param1<CRDTN_UserFaction>(userFaction), true, sender);
        Print(CRDTN_MOD_PREFIX + " Sent faction user " + userFaction.Faction_ID + " to " + sender.GetName());
    }



};