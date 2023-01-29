class CfgPatches
{
	class CRDTN_Pda
	{
		units[] = {"ItemPDA"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Scripts", "CRDTN_Client"};
	};
};

class CfgVehicles
{
	// PDA

	class Inventory_Base;
	class CRDTN_PDA_Base : Inventory_Base
	{
		scope = 0;
		title = "PDA";
		displayName = "PDA";
		descriptionShort = "Personal device";
	};
	class CRDTN_PDA : CRDTN_PDA_Base
	{
		scope = 2;
		model = "CRDTN_Client\Data\items\PDA\pda.p3d";
		hiddenSelections[] = {"body"};
		hiddenSelectionsTextures[] = {"CRDTN_Client\Data\items\PDA\data\pda_co.paa", "CRDTN_Client\Data\items\PDA\data\pda_on_co.paa"};
		itemSize[] = {2, 2};
		weight = 250;
		repairableWithKits[] = {5, 7};
		repairCosts[] = {30, 25};
		oldpower = 0;
		absorbency = 0;
		attachments[] = {"BatteryD"};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.0001;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
		};

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1, {"CRDTN_Client\Data\items\PDA\data\pda.rvmat"}},
									  {0.7, {"CRDTN_Client\Data\items\PDA\data\pda.rvmat"}},
									  {0.5, {"CRDTN_Client\Data\items\PDA\data\pda_damage.rvmat"}},
									  {0.3, {"CRDTN_Client\Data\items\PDA\data\pda_damage.rvmat"}},
									  {0, {"CRDTN_Client\Data\items\PDA\data\pda_destruct.rvmat"}}};
				};
			};
		};
	};
};
