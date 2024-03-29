class PluginLogger : PluginBase
{

    static string s_LogPath = "";

    void PluginLogger()
    {
        s_LogPath = "$profile:\\" + PROFILE_FOLDER + "\\" + MOD_FOLDER + "\\" + LOG_FILE;

        FileHandle file = OpenFile(s_LogPath, FileMode.READ);
        if (file == 0)
        {
            file = OpenFile(s_LogPath, FileMode.WRITE);
        }

        CloseFile(file);
    }

    static void Log(string txt)
    {
        FileHandle logFile = OpenFile(s_LogPath, FileMode.APPEND);
        if (logFile != 0)
        {
            FPrintln(logFile, "[" + GetDate() + "]" + CRDTN_MOD_PREFIX + " " + txt);
            CloseFile(logFile);
        }
    }

    static string GetDate(bool fileFriendly = false)
    {
        int year, month, day, hour, minute, second;

        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        string date = day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(4) + " " + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
        if (fileFriendly)
        {
            date.Replace(" ", "_");
            date.Replace(".", "-");
            date.Replace(":", "-");
        }

        return date;
    }
}