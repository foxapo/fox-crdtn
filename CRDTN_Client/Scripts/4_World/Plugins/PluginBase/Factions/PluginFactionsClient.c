class PluginFactionsClient : PluginFactionsBase
{

    private ref map<int, ref CRDTN_Faction> Factions;
    private ref CRDTN_UserFaction UserFaction;

    // RPCs
    override void GetAllFactions(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param1<array<CRDTN_Faction>> data;
        if (!ctx.Read(data))
        {
            return;
        }

        Factions = new map<int, ref CRDTN_Faction>();
        foreach (CRDTN_Faction faction : data.param1)
        {
            Factions.Insert(faction.Id, faction);
        }
        Print("Factions received!");
    }

    override void GetFactionById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param1<CRDTN_Faction> data;
        if (!ctx.Read(data))
        {
            return;
        }

        CRDTN_Faction Faction = data.param1;
        PlayerBase player = PlayerBase.Cast(target);
        player.SetFactionId(Faction.Id);
        Print(Faction.PrintData());
    }

    override void GetFactionUserById(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }

        Param1<CRDTN_UserFaction> data;
        if (!ctx.Read(data))
        {
            return;
        }

        CRDTN_UserFaction UserFaction = data.param1;
        Print(UserFaction.PrintData());
    }
};
