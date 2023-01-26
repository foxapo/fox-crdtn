class PluginUsersBase : CRDTN_PluginBase
{
    /// @brief Just a wrapper function for setup of all the RPCs.
    override void InitRPCs()
    {
        // Users
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "LoginUser", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "RegisterUser", this, SingleplayerExecutionType.Both);
    }
    
    // Retrieving of user data by given id - Param<int>
    void LoginUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target);
    // Retrieving of user data by given id - Param<int>
    void RegisterUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target);

};
