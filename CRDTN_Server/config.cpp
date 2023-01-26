class CfgPatches
{
    class CRDTN_Server
    {
        units[] = {};
        requiredAddons[] = {"DZ_Data", "DZ_Scripts", "CRDTN_Client"};
    };
};

class CfgMods
{

    class CRDTN_Server
    {
        name = "FOX Coradiation ServerMod";
        credits = "Big Kudos to guys from the Renegade Stalker Server for providing valuable information";
        author = "foxapo/freeman/greyfox";
        type = "mod";
        dependencies[] = {"World", "Mission"};
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"CRDTN_Server/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"CRDTN_Server/Scripts/5_Mission"};
            };
        };
    };
};
