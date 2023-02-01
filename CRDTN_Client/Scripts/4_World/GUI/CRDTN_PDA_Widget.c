class CRDTN_PDA_Widget : UIScriptedMenu
{

    private Widget m_Parent;

    private PlayerBase m_PlayerBase;

    bool m_IsActive = false;
    bool m_IsInitialized = false;

    void SetParent(Widget parent)
    {
        m_Parent = parent;
    }

    override Widget Init()
    {
        if(m_IsInitialized)
            return layoutRoot;
        m_PlayerBase = PlayerBase.Cast(GetGame().GetPlayer());
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::Init()");
        layoutRoot = GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_PDA_MAIN, m_Parent);
        m_IsInitialized = true;
        return layoutRoot;
    }

    void ~CRDTN_PDA_Widget()
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::~CRDTN_PDA_Widget()");
    }

    override void OnShow()
    {
        super.OnShow();
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::OnShow()");
	    PPEffects.SetBlurDrunk(0.9);
		GetGame().GetInput().ChangeGameFocus(1);
        GetGame().GetUIManager().ShowUICursor(true);
        m_PlayerBase.GetActionManager().EnableActions(false);
		SetFocus(layoutRoot);
    }

    override void OnHide()
    {
        super.OnHide();
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::OnHide()");
		PPEffects.SetBlurDrunk(0);
        GetGame().GetUIManager().ShowUICursor(false);
		GetGame().GetInput().ResetGameFocus();
        m_PlayerBase.GetActionManager().EnableActions(true);
        Close();
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::OnClick()");
        return super.OnClick(w, x, y, button);
    }
};