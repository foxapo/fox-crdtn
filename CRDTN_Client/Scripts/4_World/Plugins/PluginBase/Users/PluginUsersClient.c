class PluginUsersClient : PluginUsersBase
{

    override void LoginUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Client)
        {
            return;
        }

        Param1<bool> data;
        if (!ctx.Read(data))
        {
            return;
        }

        if (data.param1)
        {
            Print(CRDTN_MOD_PREFIX + " User logged in!");
        }
        else
        {
            Print(CRDTN_MOD_PREFIX + " User not logged in!");
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "RegisterUser", new Param1<bool>(false), true, sender);
        }
    }

    override void RegisterUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Client)
        {
            return;
        }

        Param1<bool> data;
        if (!ctx.Read(data))
        {
            return;
        }

        if (data.param1)
        {
            Print(CRDTN_MOD_PREFIX + " User registered!");
        }
        else
        {
            Print(CRDTN_MOD_PREFIX + " User not registered!");
        }
    }
}