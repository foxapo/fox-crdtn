// Main plugion for initializing the mod folder
// Runs on CLIENT + SERVER
class PluginCRDTN : PluginBase
{
    void PluginCRDTN()
    {
        
        if (!FileExist("$profile:\\" + PROFILE_FOLDER))
        {
            MakeDirectory("$profile:\\" + PROFILE_FOLDER);
        }

        if (!FileExist("$profile:\\" + PROFILE_FOLDER + "\\" + MOD_FOLDER))
        {
            MakeDirectory("$profile:\\" + PROFILE_FOLDER + "\\" + MOD_FOLDER);
        }

    }
}