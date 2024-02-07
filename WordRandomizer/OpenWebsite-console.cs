using System.Diagnostics;

namespace WordRandomizer
{
    internal class OpenWebsite
    {
        public static void Open(string site)
        {
            Process.Start(new ProcessStartInfo
            {
                FileName = site,
                UseShellExecute = true
            });
        }
    }
}
