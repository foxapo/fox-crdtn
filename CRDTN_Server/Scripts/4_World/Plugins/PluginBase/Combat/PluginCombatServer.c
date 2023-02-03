class PluginCombatServer : CRDTN_PluginBase
{
    ref CRDTN_Combat cfg_Combat;
    ref map<int, ref CRDTN_UserCombatStat> UserCombatStats;

    bool IsInitialized()
    {
        return m_IsInitialized;
    }

    void InitRPCs()
    {
        return;
    }
    
    void InitData()
    {
        super.InitData();
        cfg_Combat = new CRDTN_Combat();
        JsonFileLoader<ref CRDTN_Combat>.JsonLoadFile(MOD_PATH + CONFIG_COMBAT, cfg_Combat);
    }
    
    void ParseData()
    {
        UserCombatStats = new map<int, ref CRDTN_UserCombatStat>();
        foreach (CRDTN_UserCombatStat userCombatStat : cfg_Combat.UserCombatStats)
        {
            UserCombatStats.Insert(userCombatStat.UserId, userCombatStat);
        }
        Print(CRDTN_MOD_PREFIX + " Total user combat stats loaded: " + UserCombatStats.Count());
    }

    /// @brief Called from the AI creature when it is killed by a player
    /// @param killer 
    /// @param victimClassName 
    void RegisterKillByPlayer(PlayerIdentity killer, string victimClassName)
    {
        int killerId = CRDTN_GlobalUtils.ParseID(killer.GetPlainId());
        if (!UserCombatStats.Contains(killerId))
        {
            UserCombatStats.Insert(killerId, new CRDTN_UserCombatStat(killerId));
        }

        UserCombatStats.Get(killerId).RegisterKill(victimClassName);
        CRDTN_CreatureData combatData = new CRDTN_CreatureData();
        combatData.IsAlive = false;
        Param1<CRDTN_CreatureData> param = new Param1<CRDTN_CreatureData>(combatData);
        Print("Phantom Animal EEKilled - RPC" + combatData.IsAlive + " " + combatData.IsPlayerInRange + " " + combatData.CombatLevel);
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "OnCombatDataReceived", new Param1<CRDTN_CreatureData>(combatData), true, killer);
    }

    /// @brief Called from the actual AI creature when it is hit/triggered by the player
    /// @param player 
    /// @param combatData 
    void SendCombatDataToPlayer(PlayerIdentity player, CRDTN_CreatureData combatData)
    {
        int playerId = CRDTN_GlobalUtils.ParseID(player.GetPlainId());
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "OnCombatDataReceived", new Param1<CRDTN_CreatureData>(combatData), true, player);
    }

};