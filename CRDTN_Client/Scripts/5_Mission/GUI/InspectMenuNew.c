modded class InspectMenuNew
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_INSPECT_NEW);
		return layoutRoot;
	}
}