class CRDTN_CreatureData
{
    string Combatant;
    bool IsAlive = true;
    bool IsPlayerInRange = false;
    ref CRDTN_CombatResult CombatResults;
    ref CRDTNCombatPPEDefinition PostProcessingEffects;
    int CombatLevel = 0;
    CRDTN_ECombatEvent CombatEvent = CRDTN_ECombatEvent._NONE;
};

class CRDTN_CombatResult
{
    int NumOfHits;
    ref array<string> Loot;
    bool IsPPEDirty;
};

class CRDTNCombatPPEDefinition
{
    float Blur;
    float ChromaticAberration;
};