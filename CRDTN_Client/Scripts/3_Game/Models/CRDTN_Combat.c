class CRDTN_Combat
{
    ref array<ref CRDTN_UserCombatStat> UserCombatStats;
};

class CRDTN_UserCombatStat
{
    int UserId;
    ref map<string, int> Kills;

    void CRDTN_UserCombatStat(int userId)
    {
        UserId = userId;
        Kills = new map<string, int>();
    }

    void RegisterKill(string victimClassName)
    {
        if (!Kills.Contains(victimClassName))
        {
            Kills.Insert(victimClassName, 1);
            return;
        }
        Kills.Set(victimClassName, Kills.Get(victimClassName) + 1);
    }
};