// Factions
class CRDTN_Factions
{
    ref array<ref CRDTN_Faction> Factions;
    ref array<ref CRDTN_UserFaction> UserFactions;
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