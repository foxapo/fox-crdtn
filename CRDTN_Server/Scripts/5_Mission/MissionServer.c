modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        Print(CRDTN_MOD_PREFIX + " Initializing Mission");
    }

    

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        Print(CRDTN_MOD_PREFIX + " Player connected: " + identity.GetName());
        if(identity == NULL)
        {
            return;
        }

        PluginUsersServer plugin = PluginUsersServer.Cast(GetPlugin(PluginUsersServer));
        if(plugin)
        {
            plugin.LoginUser(CallType.Server, null, identity, player);
        }

        PluginFactionsServer pluginFactions = PluginFactionsServer.Cast(GetPlugin(PluginFactionsServer));
        if(pluginFactions)
        {
            pluginFactions.GetAllFactions(CallType.Server, null, identity, player);
            pluginFactions.GetFactionUserById(CallType.Server, null, identity, player);
        }
    }



}