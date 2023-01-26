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

    void LoginUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }
        
        int id = CRDTN_GlobalUtils.ParseID(sender.GetPlainId());
        CRDTN_User user = Users.Get(id);
        if (user)
        {
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "LoginUser", new Param1<bool>(true), true, sender);
        }
        else
        {
            GetRPCManager().SendRPC(CRDTN_MOD_PREFIX, "LoginUser", new Param1<bool>(false), true, sender);
        }
    }

    void RegisterUser(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (!sender || type != CallType.Server)
        {
            return;
        }

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