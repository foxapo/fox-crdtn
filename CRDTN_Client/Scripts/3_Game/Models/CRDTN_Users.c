// Users
class CRDTN_Users
{
    ref array<ref CRDTN_User> Users;
};

class CRDTN_User
{
    int Id; // tied to the factions i.e. FASU_PlayerDefinitionFaction
    string SteamId;
    string PlayerName;
    string Password;
    string Description;
    string RegistrationDate;
};

class CRDTN_UserFaction
{
    int Player_ID;
    CRDTN_EFaction Faction_ID;
    CRDTN_ERank Rank;
    ref array<ref CRDTN_UserReputation> Reputations;

    string PrintData()
    {
        return "Faction: " + Faction_ID + " (" + Rank + ")";
    }
};

class CRDTN_UserReputation
{
    CRDTN_EFaction Faction_ID;
    int Reputation;
};