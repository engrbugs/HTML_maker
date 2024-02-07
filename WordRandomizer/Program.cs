using Microsoft.Office.Interop.Word;
using System;
using System.Diagnostics;
using System.Reflection;
using WordRandomizer;
using Word = Microsoft.Office.Interop.Word;

class Program
{

    static void Main()
    {
        string version = "v1.0a";
        string rulesPath = @"C:\Users\engrb\OneDrive\bugs\Don Juan\Cyrano-Read-The-Screenplay.docx";
        //string tweetIntent = "https://twitter.com/intent/tweet";
        //string chatGPT = "https://chat.openai.com/";
        //string journalPath = @"C:\Users\engrb\OneDrive\bugs\Geek\csharp\Journal\Journal\bin\Release\net5.0\Journal.exe";


        CoolConsole.WriteLine("Hello, Quantum Bug Squasher! " + version);
        CoolConsole.WriteLine("Initializing the Quantum Bug Squasher...");
        System.Threading.Thread.Sleep(1000);

        // Initialize Word application
        Word.Application wordApp = new Word.Application();
        Word.Document doc = null;

        try
        {
            object missing = System.Reflection.Missing.Value;

            doc = wordApp.Documents.Open(rulesPath, System.Reflection.Missing.Value, true);

            // Get the total number of pages
            int totalPages = doc.ComputeStatistics(Word.WdStatistic.wdStatisticPages, ref missing);

            CoolConsole.WriteLine($"Total pages in the document: {totalPages}");
            CoolConsole.WriteLine("Generating cosmic randomness:");
            ShowCoolProgressBar(8);
            System.Threading.Thread.Sleep(1200);

            CoolConsole.WriteLine("Scouring the document's quantum fields...");
            System.Threading.Thread.Sleep(500);

            CoolConsole.WriteLine("Teleporting cursor to the focal point...");
            System.Threading.Thread.Sleep(500);

            CoolConsole.WriteLine("Activating the invisibility cloak...");
            

            int randomNumber = GenerateRandomNumber(1, 100);
            System.Threading.Thread.Sleep(600);
            // Navigate to the calculated position
            Word.Range range = doc.GoTo(Word.WdGoToItem.wdGoToPercent, Word.WdGoToDirection.wdGoToAbsolute, randomNumber);

            // Scroll into view
            range.Select();

            wordApp.Visible = true; // Make Word application visible
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
        finally
        {
            // Close the opened document if needed
            // doc.Close();
            // You can also choose to release the doc object if it's no longer needed:
            // if (doc != null)
            // {
            //     System.Runtime.InteropServices.Marshal.ReleaseComObject(doc);
            // }

            // Keep the Word application open
        }

        // open twitter for tweeting.
        //OpenWebsite.Open(tweetIntent);
        //System.Threading.Thread.Sleep(800);
        //OpenWebsite.Open(chatGPT);
        //System.Threading.Thread.Sleep(1200);
        //OpenWebsite.Open(journalPath);

        //// open doc1 in Word for a scratch.
        //System.Threading.Thread.Sleep(1200);
        //Word.Document NewDoc1 = wordApp.Documents.Add();
    }

    static void ShowCoolProgressBar(int segments)
    {
        for (int i = 0; i < segments; i++)
        {
            CoolConsole.Write("▓");
            System.Threading.Thread.Sleep(150);
        }
        Console.WriteLine();
    }

    static int GenerateRandomNumber(int minValue, int maxValue)
    {
        Random random = new Random();
        return random.Next(minValue, maxValue + 1); // '+1' is used to include maxValue in the range
    }
}
