using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace keepfiles
{
    class Program
    {
        static string g_sDirReadFrom = "";
        static string g_sDirCopyTo = "";

        static void Main(string[] args)
        {
            g_sDirReadFrom = args[0];
            g_sDirCopyTo = args[1];

            DirSearch(g_sDirReadFrom);
        }

        static void DirSearch(string sDirectory)
        {
            string sFileCopyTo = "";

            try
            {
                foreach (string d in Directory.GetDirectories(sDirectory))
                {
                    foreach (string f in Directory.GetFiles(d))
                    {
                        FileInfo iFile = new FileInfo(f);
                        string sDateTime = iFile.LastWriteTime.ToString("dd-MM-yyyy HH:mm:ss", CultureInfo.CreateSpecificCulture("en-AR"));

                        if (sDateTime.Substring(0, 10) == "03-08-2016" && (
                                (Int32.Parse(sDateTime.Substring(11, 2)) >= 14 && Int32.Parse(sDateTime.Substring(14, 2)) >= 45) ||
                                (Int32.Parse(sDateTime.Substring(11, 2)) >= 15 && Int32.Parse(sDateTime.Substring(14, 2)) >= 0)
                            )) {

                            sFileCopyTo = g_sDirCopyTo + f.Replace(g_sDirReadFrom, "");
                            DirCreate(sFileCopyTo.Substring(0, sFileCopyTo.LastIndexOf(@"\")));
                            File.Copy(f, sFileCopyTo);
                        }
                        iFile = null;                     
                    }
                    DirSearch(d);
                }
            }
            catch (System.Exception eException)
            {
                Console.WriteLine(eException.Message);
            }
        }

        static void DirCreate(string sDirectory)
        {
            try
            {
                char c = '\\';
                string[] sParts = sDirectory.Split(c);
                string sPath = "";

                foreach (string sPart in sParts) {
                    sPath += sPart + @"\";
                    if (!Directory.Exists(sPath)) Directory.CreateDirectory(sPath);
                }
            }
            catch (System.Exception eException)
            {
                Console.WriteLine(eException.Message);
            }
        }
    }
}
