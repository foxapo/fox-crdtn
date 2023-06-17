class CRDTN_PSIEffectTrigger : CRDTN_EffectTrigger
{
    static const float CAMERASHAKE_STRENGTH = 0.1;
    static const float CAMERASHAKE_RADIUS = 1.0;
    static const float CAMERASHAKE_SMOOTHNESS = 1.5;
    static const float CAMERASHAKE_RADIUS_DECAY_SPEED = 1.4;

    void CRDTN_PSIEffectTrigger()
    {
        RegisterNetSyncVariableInt("m_TriggerType");
    }

    override string GetAmbientSoundsetName()
    {
        return "CRDTN_SoundSet_Psi_Voices_1";
    }

    override void Virtual_OnEnterClientEvent(PlayerBase insider)
    {
        SetupClientEffects(true, insider);
        insider.GetCurrentCamera().SpawnCameraShake(CAMERASHAKE_STRENGTH, CAMERASHAKE_RADIUS, CAMERASHAKE_SMOOTHNESS, CAMERASHAKE_RADIUS_DECAY_SPEED);
    }

    override void Virtual_OnLeaveClientEvent(PlayerBase insider)
    {
        SetupClientEffects(false, insider);
    }

    override void Virtual_OnEnterServerEvent(PlayerBase insider);
    override void Virtual_OnLeaveServerEvent(PlayerBase insider);
};