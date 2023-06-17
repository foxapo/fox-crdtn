class CRDTN_EffectArea extends EffectArea
{

    protected int m_AreaId;
    protected CRDTN_EEffectAreaType m_AreaType;

    void CRDTN_EffectArea()
    {
    }

    void ~CRDTN_EffectArea()
    {
    }

    override void InitZoneClient()
    {
        // you can implement client logic here
        super.InitZoneClient();
        // Use for placing particles
        // PlaceParticles(GetWorldPosition(), m_Radius, m_InnerRings, m_InnerSpacing, m_OuterRingToggle, m_OuterSpacing, m_OuterRingOffset, m_ParticleID);
    }

    override void InitZoneServer()
    {
        // you can implement server logic here
    }

    override void Tick()
    {
        super.Tick();
    }

    override void CreateTrigger(vector pos, int radius)
    {
        super.CreateTrigger(pos, radius);
    }

    override void EEDelete(EntityAI parent)
    {
        super.EEDelete(parent);
    }
};