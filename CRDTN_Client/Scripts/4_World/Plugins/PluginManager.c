modded class PluginManager
{

	override void Init()
	{
		super.Init();

		if (GetGame().IsClient())
		{
			RegisterPlugin("PluginFactionsClient", true, false);
			RegisterPlugin("PluginUsersClient", true, false);
		}
	}
}