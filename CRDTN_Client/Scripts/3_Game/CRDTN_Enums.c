enum CRDTN_EFaction
{
    _NONE,
    Zone,
    Loner,
    Bandit, 
    Mercenaries,
    Military,
    Duty,
    Freedom,
    Ecologists,
    ClearSky,
    Renegades,
    Monolith,
    _COUNT
};

enum CRDTN_ERank
{
    _NONE,
    Rookie,
    Experienced,
    Veteran,
    Expert,
    Elite,
    Master,
    Legendary,
    Godlike,
    _COUNT
};

enum CRDTN_EQuestType
{
    _NONE,
    Explore,
    Kill,
    Trigger,
    Trade,
    _COUNT
};

/// @brief Used for in the combat to determine which kind of combat situation happened
enum CRDTN_ECombatEvent
{
    _NONE,
    PSI_HIT,
    PSI_EXPLOSION,
    PSI_KILLED,
    _COUNT
};

enum CRDTN_EEffectAreaType
{
    PSI
};

enum CRDTN_ETriggerType
{
    PSI
};