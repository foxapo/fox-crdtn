class CRDTN_ActionTurnOffPdaCB : ActionSingleUseBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUse();
	}
}

class CRDTN_ActionTurnOffPda: ActionTurnOffWhileInHands
{
	void CRDTN_ActionTurnOffPda()
	{
		m_CallbackClass 	= CRDTN_ActionTurnOffPdaCB;
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_OFF;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_ITEM_OFF;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 				= "#turn_off";
	}
	
	override bool HasProneException()
	{
		return true;
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item.IsPdaDevice())
		{
            PluginPdaClient pluginPDA;
            if (Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient)))
            {
                return pluginPDA.IsOpen();
            }
			return item.HasEnergyManager() && item.GetCompEM().IsWorking();
		}
		return false;
	}

    override void OnExecuteClient(ActionData action_data)
    {
        super.OnExecuteClient(action_data);
        PluginPdaClient pluginPDA;
        if (Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient)))
        {
            pluginPDA.Close();
        }
    }
		
	override void OnExecuteServer(ActionData action_data)
	{
		action_data.m_MainItem.GetCompEM().SwitchOff();
	}
}