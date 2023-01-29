class CRDTN_PDA_Base : ItemBase
{

	private int m_OwnerId = -1;

	void CRDTN_PDA()
	{
		RegisterNetSyncVariableInt("m_OwnerId", int.MIN, int.MAX);
	}

	override bool IsPdaDevice()
	{
		return true;
	}

    override void SetActions()
	{
		super.SetActions();
		
		AddAction(CRDTN_ActionTurnOnPda);
		AddAction(CRDTN_ActionTurnOffPda);
	}
};