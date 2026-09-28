import obspython as obs

hotkeyid = obs.OBS_INVALID_HOTKEY_ID

def on_hotkey_pressed(pressed):
    if pressed:
        obs.script_log(obs.LOG_INFO, "start file changes")
        if obs.obs_frontend_recording_active():
            obs.obs_frontend_recording_stop()
            obs.script_log(obs.LOG_INFO, "Recording stopped.")
        else:
            obs.script_log(obs.LOG_INFO, "Recording is not active.")

def script_load(settings):
    global hotkeyid
    hotkeyid = obs.obs_hotkey_register_frontend("unique_hotkey_test_12345", "editing videos", on_hotkey_pressed)
    if hotkeyid == obs.OBS_INVALID_HOTKEY_ID:
        obs.script_log(obs.LOG_WARNING, "Hotkey registration failed.")
    else:
        obs.script_log(obs.LOG_INFO, f"Hotkey registered successfully with ID: {hotkeyid}")
    hotkey_data = obs.obs_data_get_array(settings, "unique_hotkey_test_12345")
    if hotkey_data is None:
        obs.script_log(obs.LOG_WARNING, "No hotkey data loaded.")
    else:
        obs.obs_hotkey_load(hotkeyid, hotkey_data)
    obs.obs_data_array_release(hotkey_data)

def script_save(settings):
    global hotkeyid
    if hotkeyid != obs.OBS_INVALID_HOTKEY_ID:
        hotkey_data = obs.obs_hotkey_save(hotkeyid)
        obs.obs_data_set_array(settings, "unique_hotkey_test_12345", hotkey_data)
        obs.obs_data_array_release(hotkey_data)
    else:
        obs.script_log(obs.LOG_WARNING, "Hotkey is not valid, not saving.")
