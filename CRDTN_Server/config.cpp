class CfgPatches
{
    class CRDTN_Server
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "CRDTN_Client" };
    };
};

class CfgMods
{

    class CRDTN_Server
    {
        name = "FOX Coradiation ClientMod";
        credits = "Renegade Server";
        author = "freeman";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        dir = "CRDTN_Server";

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"CRDTN_Server/Scripts/3_Game"};
            };
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

class CfgSlots
{
   
};

class CfgVehicles
{
   
};