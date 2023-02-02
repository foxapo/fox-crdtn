
class CfgPatches
{
    class CRDTN_Sounds
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Scripts"};
    };
};

class CfgSoundSets
{
    class SoundSet_Inv_Base
    {
        volumeFactor = 0.2;
        frequencyFactor = 1;
        spatial = 0;
    };

    class SoundSet_InvOpen : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvOpen"};
    };

    class SoundSet_InvClose : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvClose"};
    };

    class SoundSet_InvMove_Generic : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Generic"};
    };

    class SoundSet_InvMove_Action : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Action"};
    };

    class SoundSet_InvMove_BigItem : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_BigItem"};
    };

    // -------------------------------------------------
    // Resources section - parts, materials etc...
    // -------------------------------------------------

    class SoundSet_InvMove_Cloth : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Cloth"};
    };

    class SoundSet_InvMove_Parts : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Parts"};
    };

    class SoundSet_InvMove_Key : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Key"};
    };

    class SoundSet_InvMove_Coin : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Coin"};
    };

    class SoundSet_InvMove_Paper : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Paper"};
    };

    // -------------------------------------------------
    // Meds & Food section
    // -------------------------------------------------

    class SoundSet_InvMove_Pills : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Pills"};
    };

    class SoundSet_InvMove_Bottle : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Bottle"};
    };

    // -------------------------------------------------
    // Weaponry section
    // -------------------------------------------------

    class SoundSet_InvMove_Wpn : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Wpn"};
    };

    class SoundSet_InvMove_Grenade : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_Grenade"};
    };

    class SoundSet_InvMove_AmmoSound : SoundSet_Inv_Base
    {
        soundShaders[] = {"SoundShader_InvMove_AmmoSound"};
    };
};

class CfgSoundShaders
{
    class SoundShader_Inv_Base
    {
        volume = 0.5;
    };

    class SoundShader_InvOpen : SoundShader_Inv_Base
    {
        samples[] = {{"CRDTN_Client\Data\sounds\inv_open", 1}};
    };

    class SoundShader_InvClose : SoundShader_Inv_Base
    {
        samples[] = {{"CRDTN_Client\Data\sounds\inv_close", 1}};
    };

    class SoundShader_InvMove_Generic : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_generic_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_generic_2", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_generic_3", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_generic_4", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_generic_5", 1},
        };
    };

    class SoundShader_InvMove_Action : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_take_all", 1},
        };
    };

    class SoundShader_InvMove_Cloth : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_cloth_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_cloth_2", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_cloth_3", 1},
        };
    };

    class SoundShader_InvMove_BigItem : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_wpnbig_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_wpnbig_2", 1},
        };
    };

    // -------------------------------------------------
    // Resources section - parts, materials etc...
    // -------------------------------------------------

    class SoundShader_InvMove_Parts : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_parts_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_parts_2", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_parts_3", 1},
        };
    };

    class SoundShader_InvMove_Key : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_key_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_key_2", 1},
        };
    };

    class SoundShader_InvMove_Coin : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_money_coin_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_money_coin_2", 1},
        };
    };

    class SoundShader_InvMove_Paper : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_money_paper", 1},
        };
    };

    // -------------------------------------------------
    // Meds & Food section
    // -------------------------------------------------

    class SoundShader_InvMove_Pills : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_pills_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_pills_2", 1},
        };
    };

    class SoundShader_InvMove_Bottle : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_bottle_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_bottle_2", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_bottle_3", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_bottle_4", 1},
        };
    };

    // -------------------------------------------------
    // Weaponry section
    // -------------------------------------------------

    class SoundShader_InvMove_Wpn : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_wpn_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_wpn_2", 1},
        };
    };

    class SoundShader_InvMove_Grenade : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_grenade_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_grenade_2", 1},
        };
    };

    class SoundShader_InvMove_AmmoSound : SoundShader_Inv_Base
    {
        samples[] = {
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_1", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_2", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_3", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_4", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_5", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_6", 1},
            {"CRDTN_Client\Data\sounds\Items\inv_items_ammo_7", 1}};
    };
};
