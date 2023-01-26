/// @brief Template plugin class for defining all the abstract methods
class PluginFactionsBase : CRDTN_PluginBase
{
    /// @brief Just a wrapper function for setup of all the RPCs.
    override void InitRPCs()
    {
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "GetAllFactions", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "GetFactionById", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "GetFactionUserById", this, SingleplayerExecutionType.Both);
    }

    // Retrieving of all factions - Param<array<CRDTN_Faction>>
    void GetAllFactions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target);
    // Retrieving of faction data by given id - Param<int>
    void GetFactionById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target);
    // Retrieving of faction user data by given id - Param<int>
    void GetFactionUserById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target);
};