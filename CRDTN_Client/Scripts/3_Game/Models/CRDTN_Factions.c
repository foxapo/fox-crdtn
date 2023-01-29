// Factions
class CRDTN_Factions
{
    ref array<ref CRDTN_Faction> Factions;
    ref array<ref CRDTN_UserFaction> UserFactions;
    ref array<ref CRDTN_Rank> Ranks;
};

class CRDTN_Faction
{
    CRDTN_EFaction Id;
    string FactionName;
    string FactionDescription;
    string FactionIconPath;
    string FactionLangName;
    string FactionLangDescription;

    string PrintData()
    {
        return "Faction: " + FactionName + " (" + FactionDescription + ")";
    }
};

class CRDTN_Rank
{
    CRDTN_ERank Id;
    string RankName;
    string RankDescription;
    string RankIconPath;
    string RankLangName;
    string RankLangDescription;
};