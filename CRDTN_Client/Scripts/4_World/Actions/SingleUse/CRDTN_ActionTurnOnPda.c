class CRDTN_ActionTurnOnPdaCB : ActionSingleUseBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUseTurnOnPlugged();
	}
}

class CRDTN_ActionTurnOnPda : ActionTurnOnWhileInHands
{
	void CRDTN_ActionTurnOnPda()
	{
		m_CallbackClass = CRDTN_ActionTurnOnPdaCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_ON;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_ITEM_ON;
		m_Text = "#turn_on";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item.IsPdaDevice())
		{

			PluginPdaClient pluginPDA;
			if (Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient)))
			{
				return !pluginPDA.IsOpen();
			}

			return item.HasEnergyManager() && !item.GetCompEM().IsWorking();
		}

		return false;
	}

	override void OnExecuteClient(ActionData action_data)
	{
		super.OnExecuteClient(action_data);

		PluginPdaClient pluginPDA;
		if (Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient)))
		{
			pluginPDA.Open();
		}
	}

	override void OnExecuteServer(ActionData action_data)
	{
		action_data.m_MainItem.GetCompEM().SwitchOn();
	}
}
