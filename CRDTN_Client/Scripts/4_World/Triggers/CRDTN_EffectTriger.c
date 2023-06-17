class CRDTN_EffectTrigger : EffectTrigger
{
    // CLIENT

    override void OnEnterClientEvent(TriggerInsider insider)
    {
        super.OnEnterClientEvent(insider);
        if (insider.GetObject().IsInherited(PlayerBase))
        {
            PlayerBase playerInsider = PlayerBase.Cast(insider.GetObject());

            // We will only handle the controlled player, as effects are only relevant to this player instance
            if (playerInsider.IsControlledPlayer())
            {
                // If it is first entrance, we fire the following
                if (!m_Manager.IsPlayerInTriggerType(playerInsider, this))
                {
                    Virtual_OnEnterClientEvent(playerInsider);
                }
                // We then handle the update of player trigger state in manager
                m_Manager.OnPlayerEnter(playerInsider, this);
            }
        }
    }

    override void OnLeaveClientEvent(TriggerInsider insider)
    {
        super.OnLeaveClientEvent(insider);
        if (insider.GetObject().IsInherited(PlayerBase))
        {
            PlayerBase playerInsider = PlayerBase.Cast(insider.GetObject());

            // We will only handle the controlled player, as effects are only relevant to this player instance
            if (playerInsider.IsControlledPlayer())
            {
                // If it is last exit, we fire the following
                if (m_Manager.IsPlayerInTriggerType(playerInsider, this))
                {
                    Virtual_OnLeaveClientEvent(playerInsider);
                }
                // We then handle the update of player trigger state in manager
                m_Manager.OnPlayerExit(playerInsider, this);
            }
        }
    }

    override void OnEnterServerEvent(TriggerInsider insider)
    {
        super.OnEnterServerEvent(insider);
        if (insider.GetObject().IsInherited(PlayerBase))
        {
            PlayerBase playerInsider = PlayerBase.Cast(insider.GetObject());

            // We don't need to test the trigger count as Modifiers handle such cases already
            if (playerInsider)
            {
                // If it is first entrance, we fire the following
                if (!m_Manager.IsPlayerInTriggerType(playerInsider, this))
                {
                    Virtual_OnEnterServerEvent(playerInsider);
                }
                // We then handle the update of player trigger state in manager
                m_Manager.OnPlayerEnter(playerInsider, this);
            }
        }
    }

    override void OnLeaveServerEvent(TriggerInsider insider)
    {
        super.OnLeaveServerEvent(insider);
        if (insider.GetObject().IsInherited(PlayerBase))
        {
            PlayerBase playerInsider = PlayerBase.Cast(insider.GetObject());

            if (playerInsider)
            {
                // If it is last exit, we fire the following
                if (m_Manager.IsPlayerInTriggerType(playerInsider, this))
                {
                    Virtual_OnLeaveServerEvent(playerInsider);
                }
                // We then handle the update of player trigger state in manager
                m_Manager.OnPlayerExit(playerInsider, this);
            }
        }
    }

    /// Abstract method to be implemented by child classes
    void Virtual_OnEnterClientEvent(PlayerBase insider);
    /// Abstract method to be implemented by child classes
    void Virtual_OnLeaveClientEvent(PlayerBase insider);
    /// Abstract method to be implemented by child classes
    void Virtual_OnEnterServerEvent(PlayerBase insider);
    /// Abstract method to be implemented by child classes
    void Virtual_OnLeaveServerEvent(PlayerBase insider);
};