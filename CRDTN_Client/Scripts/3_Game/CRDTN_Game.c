modded class DayZGame
{
    private ref CRDTN_EventHandler m_CRDTN_EventHandler;

    void DayZGame()
    {
        Print(CRDTN_MOD_PREFIX + " DayZGame");
        m_CRDTN_EventHandler = new CRDTN_EventHandler();
    }

    CRDTN_EventHandler CRDTNGetEventHandler()
    {
        return m_CRDTN_EventHandler;
    }
}
