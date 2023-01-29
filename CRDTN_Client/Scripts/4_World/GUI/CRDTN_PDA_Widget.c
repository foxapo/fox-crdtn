class CRDTN_PDA_Widget : UIScriptedMenu
{

    private Widget m_Parent;

    bool m_IsActive = false;

    void SetParent(Widget parent)
    {
        m_Parent = parent;
    }

    override Widget Init()
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::Init()");
        layoutRoot = GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_PDA_MAIN, m_Parent);
        return layoutRoot;
    }

    void ~CRDTN_PDA_Widget()
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::~CRDTN_PDA_Widget()");
    }

    override void OnShow()
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::OnShow()");
        super.OnShow();
        GetGame().GetInput().ChangeGameFocus(1);
        SetFocus(layoutRoot);
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        player.GetInputController().SetDisabled(true);
        player.GetActionManager().EnableActions(false);
    }

    override void OnHide()
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::OnHide()");
        super.OnHide();
        GetGame().GetInput().ResetGameFocus();
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        player.GetInputController().SetDisabled(false);
        player.GetActionManager().EnableActions(true);
        Close();
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        Print(CRDTN_MOD_PREFIX + " CRDTN_PDA_Widget::OnClick()");
        return super.OnClick(w, x, y, button);
    }
};