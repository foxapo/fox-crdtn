/// @brief Overrides the vanilla hud to add custom elements
modded class MissionGameplay
{

    override void OnInit()
    {

        Print(CRDTN_MOD_PREFIX + " Initializing MissionGameplay");

        // if (!m_HudRootWidget)
        // {
        //     m_HudRootWidget = GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_MAIN_HUD);
        //     m_HudRootWidget.Show(false);

        //     m_Chat.Init(m_HudRootWidget.FindAnyWidget("ChatFrameWidget"));

        //     m_ActionMenu.Init(m_HudRootWidget.FindAnyWidget("ActionsPanel"), TextWidget.Cast(m_HudRootWidget.FindAnyWidget("DefaultActionWidget")));

        //     m_Hud.Init(m_HudRootWidget.FindAnyWidget("HudPanel"));

        //     // von enabled icon
        //     m_MicrophoneIcon = ImageWidget.Cast(m_HudRootWidget.FindAnyWidget("mic"));
        //     m_MicrophoneIcon.Show(false);

        //     // von voice level
        //     m_VoiceLevels = m_HudRootWidget.FindAnyWidget("VoiceLevelsPanel");
        //     m_VoiceLevelsWidgets = new map<int, ImageWidget>;
        //     m_VoiceLevelTimers = new map<int, ref WidgetFadeTimer>;

        //     if (m_VoiceLevels)
        //     {
        //         m_VoiceLevelsWidgets.Set(VoiceLevelWhisper, ImageWidget.Cast(m_VoiceLevels.FindAnyWidget("Whisper")));
        //         m_VoiceLevelsWidgets.Set(VoiceLevelTalk, ImageWidget.Cast(m_VoiceLevels.FindAnyWidget("Talk")));
        //         m_VoiceLevelsWidgets.Set(VoiceLevelShout, ImageWidget.Cast(m_VoiceLevels.FindAnyWidget("Shout")));

        //         m_VoiceLevelTimers.Set(VoiceLevelWhisper, new WidgetFadeTimer);
        //         m_VoiceLevelTimers.Set(VoiceLevelTalk, new WidgetFadeTimer);
        //         m_VoiceLevelTimers.Set(VoiceLevelShout, new WidgetFadeTimer);
        //     }

        //     HideVoiceLevelWidgets();

        //     // chat channel
        //     m_ChatChannelArea = m_HudRootWidget.FindAnyWidget("ChatChannelPanel");
        //     m_ChatChannelText = TextWidget.Cast(m_HudRootWidget.FindAnyWidget("ChatChannelText"));
        // }
        if ( m_Initialized )
		{
			return;
		}
		
		#ifdef DEVELOPER
		if (!GetGame().IsMultiplayer())//to make it work in single during development
		{
			UndergroundAreaLoader.SpawnAllTriggerCarriers();
		}
		#endif
		
		PPEffects.Init(); //DEPRECATED, left in for legacy purposes only
		MapMarkerTypes.Init();
		
		m_UIManager = GetGame().GetUIManager();
			
		m_Initialized				= true;

		// init hud ui
		if ( !m_HudRootWidget )
		{
			m_HudRootWidget			= GetGame().GetWorkspace().CreateWidgets(CRDTN_UI_LAYOUT_MAIN_HUD);
			
			m_HudRootWidget.Show(false);
			
			m_Chat.Init(m_HudRootWidget.FindAnyWidget("ChatFrameWidget"));
			
			m_ActionMenu.Init( m_HudRootWidget.FindAnyWidget("ActionsPanel"), TextWidget.Cast( m_HudRootWidget.FindAnyWidget("DefaultActionWidget") ) );
			
			m_Hud.Init( m_HudRootWidget.FindAnyWidget("HudPanel") );
			
			// von enabled icon
			m_MicrophoneIcon = ImageWidget.Cast( m_HudRootWidget.FindAnyWidget("mic") );
			m_MicrophoneIcon.Show(false);
			
			// von voice level
			m_VoiceLevels = m_HudRootWidget.FindAnyWidget("VoiceLevelsPanel");
			m_VoiceLevelsWidgets = new map<int, ImageWidget>; // [key] voice level
			m_VoiceLevelTimers = new map<int,ref WidgetFadeTimer>; // [key] voice level
		
			if ( m_VoiceLevels )
			{
				m_VoiceLevelsWidgets.Set(VoiceLevelWhisper, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Whisper") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelTalk, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Talk") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelShout, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Shout") ));
				
				m_VoiceLevelTimers.Set(VoiceLevelWhisper, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelTalk, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelShout, new WidgetFadeTimer);
			}
			
			HideVoiceLevelWidgets();
			
			// chat channel
			m_ChatChannelArea		= m_HudRootWidget.FindAnyWidget("ChatChannelPanel");
			m_ChatChannelText		= TextWidget.Cast( m_HudRootWidget.FindAnyWidget("ChatChannelText") );
		}
		
		// init hud ui
		#ifdef DEVELOPER	
		m_HudDebug				= new HudDebug;
			
		if ( !m_HudDebug.IsInitialized() )
		{
			m_HudDebug.Init( GetGame().GetWorkspace().CreateWidgets("gui/layouts/debug/day_z_hud_debug.layout") );				
			PluginConfigDebugProfile.GetInstance().SetLogsEnabled(LogManager.IsLogsEnable());
		}		
		#endif
    }

    override void OnKeyRelease(int key)
    {
        super.OnKeyRelease(key);
        PluginPdaClient pluginPDA;
        if (key == KeyCode.KC_ESCAPE)
        {
            Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient));
            if (pluginPDA && pluginPDA.IsOpen())
            {
                pluginPDA.Close();
            }
        }

        // if (key == KeyCode.KC_LMENU)
        // {
        //     Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient));
        //     if (pluginPDA && pluginPDA.IsOpen())
        //     {
        //         GetGame().GetMission().PlayerControlEnable(false);
        //     }
        // }
    }

    // override void OnKeyPress(int key)
    // {
    //     super.OnKeyPress(key);
    //     if (key == KeyCode.KC_LMENU)
    //     {
    //         PluginPdaClient pluginPDA;
    //         Class.CastTo(pluginPDA, GetPlugin(PluginPdaClient));
    //         if (pluginPDA && pluginPDA.IsOpen())
    //         {
    //             GetGame().GetMission().PlayerControlEnable(true);
    //         }
    //     }
    // }

}