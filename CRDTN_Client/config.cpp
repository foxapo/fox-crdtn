class CfgPatches
{
    class CRDTN_Client
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "DZ_Data",
            "DZ_Scripts"};
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

class Cfg_sUDE
{
    class Visual
    {
        class PPEffects
        {
            class DefaultValues
            {
                saturation = 5.0;
                // vignette_strength = 0.5;
                // saturation = 1.0;
                // vignette_strength = 0.0;
                // overlay_factor = 0.0;
                // bloom_threshold = 0.01;
                // bloom_steepness = 0.0;
                // bloom_intensity = 0.5;
                // lens_distort = 0.0;
                // lens_center_x = 0.0;
                // lens_center_y = 0.0;
                // lens_chrom_aber = 0.0;
                // motion_blur_power = 0.01;
                // motion_blur_intensity = 0.1;
                // motion_blur_mindepth = 0.8;
                // motion_blur_maxdepth = 0.9;
                // gauss_blur_intensity = 0.0;
                // radial_blur_power_x = 0.0;
                // radial_blur_power_y = 0.0;
                // radial_blur_offset_x = 0.0;
                // radial_blur_offset_y = 0.0;
                // chrom_aber_power_x = 0.0;
                // chrom_aber_power_y = 0.0;
                // film_grain_sharpness = 0.0;
                // film_grain_grain_size = 0.0;
                // godrays_sun_intensity = 0.8;
                // godrays_sun_overburn_intensity = 0.25;
                // godrays_sun_overburn_start = 0.025;
                // godrays_sun_overburn_end = 0.175;
                // godrays_sun_mask = 0.8;
                // godrays_sun_size = 0.15;
                // godrays_sun_v_intensity = 0.75;
                // godrays_sun_d_intensity = 0.60;
                // vignette_color[] = {0.0, 0.0, 0.0, 0.0};
                // overlay_color[] = {0.0, 0.0, 0.0, 0.0};
                colorization[] = {1.0, 1.0, 1.0, 1.0};
            };
        };
    };
};

class CfgVehicles
{

    // FACTION FINDER

    class ItemOptics;
    class CRDTN_FactionFinderBase : ItemOptics
    {
        scope = 0;
        displayName = "Faction Finder";
        descriptionShort = "Faction Finder";
        model = "\dz\gear\optics\Rangefinder.p3d";
        simulation = "itemoptics";
        animClass = "Binoculars";
        itemSize[] = {2, 1};
        weight = 270;
        rotationFlags = 17;
        memoryPointCamera = "eyeScope";
        cameraDir = "cameraDir";
        class OpticsInfo
        {
            memoryPointCamera = "eyeScope";
            cameraDir = "cameraDir";
            modelOptics = "\DZ\gear\optics\binoculars_view.p3d";
            distanceZoomMin = 100;
            distanceZoomMax = 100;
            opticsZoomMin = 0.05;
            opticsZoomMax = 0.05;
            opticsZoomInit = 0.05;
        };
        attachments[] = {"BatteryD"};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 70;
                    healthLevels[] =
                        {{1.0, {"DZ\gear\optics\data\Rangefinder.rvmat"}},
                         {0.7, {"DZ\gear\optics\data\Rangefinder.rvmat"}},
                         {0.5, {"DZ\gear\optics\data\Rangefinder_damage.rvmat"}},
                         {0.3, {"DZ\gear\optics\data\Rangefinder_damage.rvmat"}},
                         {0.0, {"DZ\gear\optics\data\Rangefinder_destruct.rvmat"}}};
                };
            };
        };
        repairableWithKits[] = {7};
        repairCosts[] = {25.0};
        class EnergyManager
        {
            hasIcon = 1;
            energyUsagePerSecond = 0.01;
            plugType = 1;
            attachmentAction = 1;
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeLightBlunt";
                range = 1.0;
            };
            class Heavy
            {
                ammo = "MeleeLightBlunt_Heavy";
                range = 1.0;
            };
            class Sprint
            {
                ammo = "MeleeLightBlunt_Heavy";
                range = 2.8;
            };
        };
        soundImpactType = "plastic";
    };

    class CRDTN_FactionFinder : CRDTN_FactionFinderBase
    {
        scope = 2;
        displayName = "Faction Finder";
        descriptionShort = "Faction Finder";
    };
};