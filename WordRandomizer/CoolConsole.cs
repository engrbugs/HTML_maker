using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WordRandomizer
{
    internal class CoolConsole
    {
        public static void WriteLine(string message)
        {
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine(message);
            Console.ResetColor();
            System.Threading.Thread.Sleep(300);
        }

        public static void Write(string message)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write(message);
            Console.ResetColor();
            System.Threading.Thread.Sleep(300);
        }
    }
}
