class PluginUsersServer : PluginUsersBase
{

    ref CRDTN_Users cfg_Users;
    ref map<int, ref CRDTN_User> Users;

    override void InitRPCs()
    {
        super.InitRPCs();
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "LoginUser", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "RegisterUser", this, SingleplayerExecutionType.Both);
    }

    override void InitData()
    {
        super.InitData();
        cfg_Users = new CRDTN_Users();
        JsonFileLoader<ref CRDTN_Users>.JsonLoadFile(MOD_PATH + CONFIG_USERS, cfg_Users);
    }

    override void ParseData()
    {
        Print(CRDTN_MOD_PREFIX + " Parsing users...");
        Users = new map<int, ref CRDTN_User>();
        foreach (CRDTN_User user : cfg_Users.Users)
        {
            Users.Insert(user.Id, user);
        }
        Print(CRDTN_MOD_PREFIX + " Users parsed!");
    }

    override void LoginUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }
        Print(CRDTN_MOD_PREFIX + " Logging in user " + sender.GetName());
        int id = CRDTN_GlobalUtils.ParseID(sender.GetPlainId());
        CRDTN_User user = Users.Get(id);
        if (user)
        {

            CRDTN_UserClient userClient = new CRDTN_UserClient();
            userClient.Id = user.Id;
            userClient.PlayerName = user.PlayerName;

            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "LoginUser", new Param1<CRDTN_UserClient>(userClient), true, sender);
        }
        else
        {
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "LoginUser", new Param1<bool>(false), true, sender);
        }
    }

    override void RegisterUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }
        Print(CRDTN_MOD_PREFIX + " Registering user " + sender.GetName());
        int id = CRDTN_GlobalUtils.ParseID(sender.GetPlainId());
        CRDTN_User user = Users.Get(id);
        AddUser(sender);
    }

    private void AddUser(ref PlayerIdentity identity)
    {
        Print(CRDTN_MOD_PREFIX + " Registering user " + identity.GetName() + "...");
        CRDTN_User user = new CRDTN_User();
        user.Id = CRDTN_GlobalUtils.ParseID(identity.GetPlainId());
        user.PlayerName = identity.GetName();
        user.SteamId = identity.GetPlainId();
        user.RegistrationDate = CRDTN_GlobalUtils.GetDate();
        cfg_Users.Users.Insert(user);
        JsonFileLoader<ref CRDTN_Users>.JsonSaveFile(MOD_PATH + CONFIG_USERS, cfg_Users);
    }
};