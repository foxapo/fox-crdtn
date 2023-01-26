class PluginMainServer : CRDTN_PluginBase
{
    ref CRDTN_Main cfg_Main;

    override void InitData()
    {
        if (FileExist(MOD_PATH + CONFIG_MAIN))
        {
            JsonFileLoader<ref CRDTN_Main>.JsonLoadFile(MOD_PATH + CONFIG_MAIN, cfg_Main);
        }
        else
        {
            Print(CRDTN_MOD_PREFIX + " Main config not found!");
            return;
        }

        Print(CRDTN_MOD_PREFIX + " Main config loaded!");
    }

    override void ParseData()
    {
        Print("---------------CRDTN-------------------");
        Print(CRDTN_MOD_PREFIX + " World name: " + cfg_Main.WorldName);
        Print(CRDTN_MOD_PREFIX + " Faction checker enabled: " + cfg_Main.FactionCheckerEnabled);
        Print(CRDTN_MOD_PREFIX + " Reputation enabled: " + cfg_Main.ReputationEnabled);
        Print(CRDTN_MOD_PREFIX + " Ranks enabled: " + cfg_Main.RanksEnabled);
        Print(CRDTN_MOD_PREFIX + " Default faction: " + cfg_Main.DefaultFaction);
        Print(CRDTN_MOD_PREFIX + " Default rank: " + cfg_Main.DefaultRank);
        Print(CRDTN_MOD_PREFIX + " Main config parsed!");
        Print("----------------------------------------");
    }

    string GetWorldName()
    {
        return cfg_Main.WorldName;
    }
    bool IsFactionCheckerEnabled()
    {
        return cfg_Main.FactionCheckerEnabled;
    }
    bool IsReputationEnabled()
    {
        return cfg_Main.ReputationEnabled;
    }
    bool IsRanksEnabled()
    {
        return cfg_Main.RanksEnabled;
    }
    CRDTN_EFaction GetDefaultFaction()
    {
        return cfg_Main.DefaultFaction;
    }
    CRDTN_ERank GetDefaultRank()
    {
        return cfg_Main.DefaultRank;
    }
}