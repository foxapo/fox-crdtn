
class CfgPatches
{
	class CRDTN_SoundsWeapons
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Sounds_Effects"};
	};
};

class CfgSoundSets
{
	class SoundSet_CRDTN_AK_Base
	{
		volumeFactor = 0.2;
		frequencyFactor = 1;
		spatial = 0;
	};
};

class CfgSoundShaders
{

	class base_closeShot_SoundShader
	{
		volume = 1;
		range = 3500;
		rangeCurve = "closeShotAttenuationCurve";
	};

	class closeShotRifle_SoundShader : base_closeShot_SoundShader
	{
		rangeCurve = "closeShotRifleCurve";
		range = 3000;
	};

	class base_midShot_SoundShader
	{
		volume = 1;
		range = 3500;
		rangeCurve = "midShotAttenuationCurve";
	};

	class midShotRifle_SoundShader : base_midShot_SoundShader
	{
		rangeCurve = "midShotRifleCurve";
		range = 3000;
	};

	class base_distShot_SoundShader
	{
		volume = 1;
		range = 3500;
		rangeCurve = "distShotAttenuationCurve";
	};

	class distShotRifle_SoundShader : base_distShot_SoundShader
	{
		rangeCurve = "distShotRifleCurve";
		range = 3000;
	};

	class base_ProfessionalSilenced_closeShot_SoundShader
	{
		volume = 1;
		range = 150;
		rangeCurve = "closeShotProfessionalSilencedAttenuationCurve";
	};

	// GLOCK

	class closeShotPistol_SoundShader: base_closeShot_SoundShader
	{
		rangeCurve = "closeShotPistolCurve";
		range = 1000;
	};

	class Glock19_closeShot_SoundShader : closeShotPistol_SoundShader
	{
		samples[] = {
			{"CRDTN_Client\Data\sounds\weapons\GLOCK\glock_shoot", 1},
			{"CRDTN_Client\Data\sounds\weapons\GLOCK\glock_shoot1", 1},
			{"CRDTN_Client\Data\sounds\weapons\GLOCK\glock_shoot2", 1}
			};
	};
	class Glock19_silencerCloseShot_SoundShader : base_ProfessionalSilenced_closeShot_SoundShader
	{
		samples[] = {
			{"CRDTN_Client\Data\sounds\weapons\GLOCK\glock_shot_sil", 1}
		};
	};

	// AK

	class AK_closeShot_SoundShader : closeShotRifle_SoundShader
	{
		samples[] = {
			{"CRDTN_Client\Data\sounds\weapons\ak103\ak103_shoot", 1},
			{"CRDTN_Client\Data\sounds\weapons\ak103\ak103_shoot1", 1},
			{"CRDTN_Client\Data\sounds\weapons\ak103\ak103_shoot2", 1},
			{"CRDTN_Client\Data\sounds\weapons\ak103\ak103_shoot3", 1},
			{"CRDTN_Client\Data\sounds\weapons\ak103\ak103_shoot4", 1},
			{"CRDTN_Client\Data\sounds\weapons\ak103\ak103_shoot5", 1},
		};
		volume = 0.70794576;
	};

	class AK_silencerCloseShot_SoundShader : base_ProfessionalSilenced_closeShot_SoundShader
	{
		samples[] = {{"CRDTN_Client\Data\sounds\weapons\ak\ak_shot_sil", 1}};
		volume = 1.0;
	};

	class AK_midShot_SoundShader : midShotRifle_SoundShader
	{
		samples[] = {{"CRDTN_Client\Data\sounds\weapons\_distance_shooting_mid\ak_distant", 1}};
		volume = 0.3548134;
	};

	class AK_distShot_SoundShader : distShotRifle_SoundShader
	{
		samples[] = {{"CRDTN_Client\Data\sounds\weapons\_distance_shooting_far\ak_distant", 1}};
		volume = 0.3548134;
	};

	// M4

	class M4_closeShot_SoundShader : closeShotRifle_SoundShader
	{
		samples[] = {
			{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shoot", 1},
			{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shoot1", 1},
			{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shoot2", 1},
			{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shoot3", 1},
			{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shoot4", 1},
			{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shoot5", 1},
		};
		volume = 1.0;
	};

	class M4_silencerCloseShot_SoundShader : base_ProfessionalSilenced_closeShot_SoundShader
	{
		samples[] = {{"CRDTN_Client\Data\sounds\weapons\M4A1\m4a1_shot_sil", 1}};
		volume = 1.0;
	};

	class M4_midShot_SoundShader : midShotRifle_SoundShader
	{
		samples[] = {{"CRDTN_Client\Data\sounds\weapons\_distance_shooting_mid\scar_distant", 1}};
		volume = 0.56234133;
	};
	class M4_distShot_SoundShader : distShotRifle_SoundShader
	{
		samples[] = {{"CRDTN_Client\Data\sounds\weapons\_distance_shooting_far\scar_distant", 1}};
		volume = 1.0;
	};
};
