class PluginUsersClient : PluginUsersBase
{
    ref CRDTN_UserClient m_User;

    string GetPlayerName()
    {
        return m_User.PlayerName;
    }

    int GetPlayerId()
    {
        return m_User.Id;
    }

    override void LoginUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param1<CRDTN_UserClient> data;
        if (!ctx.Read(data))
        {
            return;
        }


        Print(CRDTN_MOD_PREFIX + " LoginUser() called!" + " Target: " + target);
        Print(CRDTN_MOD_PREFIX + " LoginUser() called!" + " Sender: " + sender);
        Print(CRDTN_MOD_PREFIX + " LoginUser() called!" + " Data: " + data.param1);
        if(data.param1)
        {
            m_User = new CRDTN_UserClient();
            m_User.Id = data.param1.Id;
            m_User.PlayerName = data.param1.PlayerName;
        }
        else
        {
            Print(CRDTN_MOD_PREFIX + " User not logged in!");
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "RegisterUser", new Param1<bool>(false), true, sender);
        }
       
    }
}