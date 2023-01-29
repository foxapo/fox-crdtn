modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(CRDTN_ActionTurnOnPda);
        actions.Insert(CRDTN_ActionTurnOffPda);
      
    };
};