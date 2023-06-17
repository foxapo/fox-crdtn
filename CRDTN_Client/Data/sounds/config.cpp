///-----------------------------------------------------------------------------------------------------------------
/// CORADIATION CLIENTMOD
/// @brief This is the clientmod for the Coradiation mod
/// FoxApoGames All Rights Resreved (c) 2023
/// www.foxapo.com
/// If you want to use this mod in your mod, please contact me first @freeman
///-----------------------------------------------------------------------------------------------------------------
/// @brief Big thanks to the creator of CSO - Complete sound overhaul
/// Also thanks to the guys from the Renegade Stalker Server for providing valuable information
class CfgPatches
{
    class CRDTN_SoundMod
    {
        units[] = {""};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
            {
                "DZ_Data",
                "DZ_Scripts",
                "DZ_Sounds_Effects"};
    };
};

class CfgSoundSets
{
    #include "inventory\inventory_sound_sets.hpp"
    #include "creatures\creatures_sound_sets.hpp"
    #include "fx\fx_sound_sets.hpp"
};

class CfgSoundShaders
{
    #include "inventory\inventory_sound_shaders.hpp"
    #include "creatures\creatures_sound_shaders.hpp"
    #include "fx\fx_sound_shaders.hpp"
};

class CfgSounds
{
    #include "creatures\creatures_sounds.hpp"
};