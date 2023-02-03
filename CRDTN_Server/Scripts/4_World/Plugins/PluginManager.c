modded class PluginManager
{

	void PluginManager()
	{
		Print("CRDTN Plugin registering..");
	}

	override void Init()
	{

		Print("PluginManager - Server");

		super.Init();

		if(GetGame().IsServer())
		{
			RegisterPlugin("PluginCRDTN", false, true);
			RegisterPlugin("PluginLogger", false, true);
			RegisterPlugin("PluginMainServer", false, true);
			RegisterPlugin("PluginFactionsServer", false, true);
			RegisterPlugin("PluginUsersServer", false, true);
			RegisterPlugin("PluginCombatServer", false, true);
		}
		
	}
}