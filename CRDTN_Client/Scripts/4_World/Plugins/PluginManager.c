modded class PluginManager
{

	override void Init()
	{
		Print("PluginManager::Init()");
		if (GetGame().IsClient())
		{
			RegisterPlugin("PluginUsersClient", true, false);
			RegisterPlugin("PluginFactionsClient", true, false);
			RegisterPlugin("PluginPdaClient", true, false);
		}
		super.Init();
	}
}