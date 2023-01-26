class CfgPatches
{
    class CRDTN_Client
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};

class CfgMods
{

    class CRDTN_Client
    {
        name = "FOX Coradiation ClientMod";
        credits = "Big Kudos to guys from the Renegade Stalker Server for providing valuable information";
        author = "foxapo/freeman/greyfox";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        dir = "CRDTN_Client";

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"CRDTN_Client/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"CRDTN_Client/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"CRDTN_Client/Scripts/5_Mission"};
            };
        };
    };
};

class CfgSlots
{
   
};

class CfgVehicles
{
   
};