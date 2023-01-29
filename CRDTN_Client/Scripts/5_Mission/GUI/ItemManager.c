modded class ItemManager
{
    void ItemManager(Widget root)
    {
        m_Instance					= this;
		m_RootWidget				= root;
		m_DefautOpenStates			= new map<string, bool>;
		m_DefautHeaderOpenStates	= new map<string, bool>;
		m_SlotInfoShown				= false;
		
		#ifdef PLATFORM_CONSOLE
			m_TooltipWidget			= GetGame().GetWorkspace().CreateWidgets("gui/layouts/inventory_new/day_z_inventory_new_tooltip_xbox.layout", root );
			m_TooltipSlotWidget		= GetGame().GetWorkspace().CreateWidgets("gui/layouts/inventory_new/day_z_inventory_new_tooltip_slot_xbox.layout", root );
		#else
			m_TooltipWidget			= GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_TOOLTIP, root );
			m_TooltipSlotWidget		= GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_TOOLTIP_SLOT, root );
		#endif
		m_TooltipWidget.Show( false );
		m_TooltipSlotWidget.Show( false );
    }
}