modded class PluginManager
{
	override void Init()
	{
		Print("PluginManager::Init()");
		if (GetGame().IsClient())
		{
			RegisterPlugin("PluginUsersClient", true, false);		// User system
			RegisterPlugin("PluginFactionsClient", true, false);	// Faction system
			RegisterPlugin("PluginPdaClient", true, false);			// PDA
			RegisterPlugin("PluginCombatClient", true, false);		// Combat handler
			RegisterPlugin("PluginPPE", true, false);				// Post Processing Effects
		}
		super.Init();
	}
}