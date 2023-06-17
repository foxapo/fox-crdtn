class CRDTN_PSIArea : CRDTN_EffectArea
{
    
    void CRDTN_PSIArea()
    {
        Print("CRDTN_PSIArea::CRDTN_PSIArea() on " + GetPosition());
        m_AreaType = CRDTN_EEffectAreaType.PSI;
        m_Name = "Psi Area";                        // The user defined name of the area
        m_Type = eZoneType.DYNAMIC;                 // If the zone is static or dynamic
        m_TriggerType = "CRDTN_PSIEffectTrigger";   // The trigger class used by this zone
        m_Radius = 5;                               // Radius of the Contaminated Area
        m_PositiveHeight = 25;                      // Distance between center and maximum height
        m_NegativeHeight = 10;                      // Distance between center and minimum height
        m_ParticleID = ParticleList.SPOOKY_MIST;
        m_AroundParticleID = ParticleList.CONTAMINATED_AREA_GAS_GROUND;
        m_TinyParticleID = ParticleList.CONTAMINATED_AREA_GAS_TINY;
        m_PPERequesterIdx = PPERequesterBank.GetRequesterID(CRDTN_PP_PSIRequester);
    }

    override void CreateTrigger(vector pos, int radius)
    {
        super.CreateTrigger(pos, radius);
        // PSI TRIGGER CREATION
        CRDTN_PSIEffectTrigger psiTrigger = CRDTN_PSIEffectTrigger.Cast(m_Trigger);
        if (psiTrigger)
        {
            psiTrigger.SetLocalEffects(m_AroundParticleID, m_TinyParticleID, m_PPERequesterIdx);
        }
    }
};