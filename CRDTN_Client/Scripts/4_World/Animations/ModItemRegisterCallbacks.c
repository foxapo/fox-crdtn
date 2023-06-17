
modded class ModItemRegisterCallbacks
{

    override void RegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
	{
        super.RegisterOneHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("CRDTN_FactionFinder", "dz/anims/workspaces/player/player_main/props/player_main_1h_binocular.asi", pBehavior, "dz/anims/anm/player/ik/gear/binoculars.anm");
    }

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("CRDTN_PDA", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, /*"CRDTN_Client/Data/Animations/PDA.anm"*/ "dz/anims/anm/player/ik/two_handed/CookingPot.anm");
    }

};

