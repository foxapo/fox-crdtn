class PluginCombatClient : CRDTN_PluginBase
{

    #ifdef S_VISUAL 
    private CRDTN_S_FX_PsiHitAnim psiHitEffect; 
    #endif
    #ifndef S_VISUAL
    ref PPERequester_Creatures m_PPERequester;
    #endif

    private int m_CurrentCombatLevel = 0;

    void PluginCombatClient()
    {
        #ifndef S_VISUAL
            m_PPERequester = PPERequester_Creatures.Cast(PPERequesterBank.GetRequester(PPERequester_Creatures));
        #endif
    }

    /// @brief Just a wrapper function for setup of all the RPCs.
    override void InitRPCs()
    {
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "OnCombatDataReceived", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CRDTN_MOD_PREFIX, "OnCombatTargetKilled", this, SingleplayerExecutionType.Both);
    }

    void OnCombatDataReceived(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }
        Print("OnCombatDataReceived");
        Param1<CRDTN_CreatureData> data;
        if (!ctx.Read(data))
        {
            return;
        }
        Print("OnCombatDataReceived: " + data.param1.Combatant + " " + data.param1.IsAlive + " " + data.param1.IsPlayerInRange + " " + data.param1.CombatLevel);
        ValidateCombat(data.param1);
    }

    void OnCombatTargetKilled(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
        {
            return;
        }
        Print("OnCombatTargetKilled");
    }

    private void ValidateCombat(CRDTN_CreatureData data)
    {
        if(data.IsAlive)
        {
            HandleInCombat(data);
        }
        else
        {
            HandleEndOfCombat(data);
        }
    }

    private void HandleInCombat(CRDTN_CreatureData data)
    {     
        // Send notification that you hit the combatant
        Print("You hit " + data.Combatant + " with " + data.CombatResults.NumOfHits + " hits.");
        HandlePostProcessingEffects(data);
    }

    private void HandleEndOfCombat(CRDTN_CreatureData data)
    {
        // Send notification that you killed the combatant
        Print("You killed " + data.Combatant + " with " + data.CombatResults.NumOfHits + " hits.");
        HandlePostProcessingEffects(data);
    }

    private void HandlePostProcessingEffects(CRDTN_CreatureData data)
    {
        if(!data)
        {
            Print("Data is null");
            return;
        }

        // SVisual usage
        #ifdef S_VISUAL
            HandleSVisualPPE(data.CombatEvent);
        #endif
        // Vanilla usage
        #ifndef S_VISUAL
            HandlePPEffects(data.CombatEvent);
        #endif
    }

 // SVISUAL
#ifdef S_VISUAL
    private void HandleSVisualPPE(CRDTN_ECombatEvent combatEvent)
    {
        
        switch(combatEvent)
            {
                case CRDTN_ECombatEvent._NONE:
                    Print("No combat event");
                    break;
                case CRDTN_ECombatEvent.PSI_HIT:
                    Print("PSI_HIT");
                    
                    if(!psiHitEffect)
                    {
                        psiHitEffect = new CRDTN_S_FX_PsiHitAnim(1);
                    }


                    if(psiHitEffect.isPlaying())
                    {
                        psiHitEffect.ChangeLevel(1);
                    }
                    else
                    {
                        PPEManager.activate(psiHitEffect);
                    }
                    break;
                case CRDTN_ECombatEvent.PSI_EXPLOSION:
                    Print("PSI_EXPLOSION");
                    break;
                case CRDTN_ECombatEvent.PSI_KILLED:
                    Print("PSI_KILLED");
                    if(!psiHitEffect)
                    {
                        psiHitEffect = new CRDTN_S_FX_PsiHitAnim(0);
                    }
                    psiHitEffect.stop();
                    break;
                default:
                    Print("Unknown combat event");
                    if(!psiHitEffect)
                    {
                        psiHitEffect = new CRDTN_S_FX_PsiHitAnim(0);
                    }
                    psiHitEffect.stop();
                    break;
            }
        }
#endif

    private void HandlePPEffects(CRDTN_ECombatEvent combatEvent)
    {
        switch(combatEvent)
        {
            case CRDTN_ECombatEvent._NONE:
                Print("No combat event");
                break;
            case CRDTN_ECombatEvent.PSI_HIT:
                Print("PSI_HIT");
                if(m_PPERequester)
                {
                    m_PPERequester.SetGausBlur(0.1);
                    m_PPERequester.SetChromAbr(0.1);
                }
                break;
            case CRDTN_ECombatEvent.PSI_EXPLOSION:
                Print("PSI_EXPLOSION");
                break;
            case CRDTN_ECombatEvent.PSI_KILLED:
                Print("PPEF Unknown combat event");
                if(m_PPERequester)
                {
                    m_PPERequester.ResetToDefault();
                }   
            default:
                Print("Unknown combat event");
                if(m_PPERequester)
                {
                    m_PPERequester.ResetToDefault();
                }
                break;
        }
    }

};