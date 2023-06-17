class PluginCombatServer : CRDTN_PluginBase
{
    ref CRDTN_Combat cfg_Combat;
    ref map<int, ref CRDTN_UserCombatStat> UserCombatStats;

    override bool IsInitialized()
    {
        return m_IsInitialized;
    }

    override void InitRPCs()
    {
        return;
    }
    
    override void InitData()
    {
        super.InitData();
        cfg_Combat = new CRDTN_Combat();
        JsonFileLoader<ref CRDTN_Combat>.JsonLoadFile(MOD_PATH + CONFIG_COMBAT, cfg_Combat);
    }
    
    override void ParseData()
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
        // TODO - Add support for registering kills by the player
        // TODO - Also need to read data from the config about PPE and so on
        UserCombatStats.Get(killerId).RegisterKill(victimClassName);
        CRDTN_CreatureData combatData = new CRDTN_CreatureData();
        combatData.IsAlive = false;
        combatData.Combatant = victimClassName;
        combatData.CombatEvent = CRDTN_ECombatEvent.PSI_KILLED;

        Param1<CRDTN_CreatureData> param = new Param1<CRDTN_CreatureData>(combatData);
        Print("Phantom Animal EEKilled - RPC" + combatData.IsAlive + " " + combatData.IsPlayerInRange + " " + combatData.CombatEvent);
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "OnCombatDataReceived", new Param1<CRDTN_CreatureData>(combatData), true, killer);
    }

    /// @brief Called from the actual AI creature when it is hit/triggered by the player
    /// @param player 
    /// @param combatData 
    void SendCombatDataToPlayer(PlayerIdentity player, CRDTN_CreatureData combatData)
    {
        int playerId = CRDTN_GlobalUtils.ParseID(player.GetPlainId());
        Print("Sending combat data to player: " + playerId + " " + combatData.IsAlive + " " + combatData.Combatant + " " + combatData.CombatEvent);
        GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "OnCombatDataReceived", new Param1<CRDTN_CreatureData>(combatData), true, player);
    }

};