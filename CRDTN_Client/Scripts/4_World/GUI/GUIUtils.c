class GUIUtils
{

    static const string ERROR_IMAGE = "CRDTN_Client/Data/error.edds";
    static const string FACTION_IMAGES = "CRDTN_Client/Data/factions";
    static const string RANK_IMAGES = "CRDTN_Client/Data/ranks";

    static string GetFactionImageByType(CRDTN_EFaction faction)
    {
        string imgPath = ERROR_IMAGE;
        switch (faction)
        {
        case CRDTN_EFaction.Loner:
            imgPath = FACTION_IMAGES + "/loner.edds";
            break;
        case CRDTN_EFaction.Bandit:
            imgPath = FACTION_IMAGES + "/bandit.edds";
            break;
        case CRDTN_EFaction.Mercenaries:
            imgPath = FACTION_IMAGES + "/merk.edds";
            break;
        case CRDTN_EFaction.Military:
            imgPath = FACTION_IMAGES + "/mil.edds";
            break;
        default:
            imgPath = FACTION_IMAGES + "/cs.edds";
            break;
        }
        Print("GetFactionImageByType: " + faction + " on " + imgPath);
        return imgPath;
    }

    static string GetRankImageByType(CRDTN_ERank rank)
    {
        string imgPath = ERROR_IMAGE;
        switch (rank)
        {
        case CRDTN_ERank.Rookie:
            imgPath = RANK_IMAGES + "/rookie.edds";
            break;
        case CRDTN_ERank.Experienced:
            imgPath = RANK_IMAGES + "/experienced.edds";
            break;
        case CRDTN_ERank.Veteran:
            imgPath = RANK_IMAGES + "/veteran.edds";
            break;
        case CRDTN_ERank.Expert:
            imgPath = RANK_IMAGES + "/expert.edds";
            break;
        default:
            imgPath = RANK_IMAGES + "/rookie.edds";
            break;
        }
        Print("GetRankImageByType: " + rank + " on " + imgPath);
        return imgPath;
    }
};
