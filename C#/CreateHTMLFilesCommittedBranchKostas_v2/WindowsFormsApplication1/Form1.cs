using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        List<String> g_lines = new List<String>();
        List<String> g_files = new List<String>();
        String g_rootpath = @"P:\Users\conde\Documents\Programs\C#\CreateHTMLFilesCommittedBranchKostas_v2\Files-AddsOn\";

        public Form1()
        {
            InitializeComponent();
        }

        private String getLink(List<String> files, List<String> urls, String filename)
        {
            //TODO
            return "";
        }

        private void readFile(String filename)
        {
            String line;

            using (StreamReader sr = new StreamReader(filename))
            {
                while ((line = sr.ReadLine()) != null)
                {
                    g_lines.Add(line);
                }

                List<String> distinct = g_lines.Distinct().ToList();

                foreach (String l in distinct)
                {
                    g_files.Add(l);
                }
            }
        }

        private void btnCreateFilesList_Click(object sender, EventArgs e)
        {
            List<String> files = new List<String>(new String[] {
                g_rootpath + "cafcb8c371a.txt"
            ,   g_rootpath + "16436b4bc9b.txt"
            ,   g_rootpath + "8e6a9cdca29.txt"
            ,   g_rootpath + "808eed2b3fa.txt"
            ,   g_rootpath + "50581beffa0.txt"
            ,   g_rootpath + "3e316fb9ad4.txt"
            ,   g_rootpath + "d9479d823c4.txt"
            ,   g_rootpath + "7cb5d63bbd4.txt"
            ,   g_rootpath + "754bf2cdb9a.txt"
            ,   g_rootpath + "7ec1419c6be.txt"
            ,   g_rootpath + "82f39a9bacc.txt"
            });

            List<String> commits_id = new List<String>(new String[] {
                "cafcb8c371a"
            ,    "16436b4bc9b"
            ,    "8e6a9cdca29"
            ,    "808eed2b3fa"
            ,    "50581beffa0"
            ,    "3e316fb9ad4"
            ,    "d9479d823c4"
            ,    "7cb5d63bbd4"
            ,    "754bf2cdb9a"
            ,    "7ec1419c6be"
            ,    "82f39a9bacc"
            });

            List<String> commits_url = new List<String>(new String[] {
                //cafcb8c371a
                "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/cafcb8c371a6e72bb1184fe3825d483336a7e003"
                //16436b4bc9b
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/16436b4bc9b43403e238a0b2cdb503f83957084b"
                //8e6a9cdca29
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/8e6a9cdca290fdb418deb2c46749dbe3c2ea8eb6"
                //808eed2b3fa
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/808eed2b3fa16b6f419c8ec1b9cf785a2e7bfc5f"
                //50581beffa0
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/50581beffa0b64e5c0ca05a29cfd279853a8f163"
                //3e316fb9ad4
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/3e316fb9ad4fccef1a45a15dbfdeb8afd9f150b4"
                //d9479d823c4
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/d9479d823c4539950eb92ddbe19c815a0522573a"
                //7cb5d63bbd4
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/7cb5d63bbd4309f1483b8220375ab7bf57b918a7"
                //754bf2cdb9a
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/754bf2cdb9a70c355b006b1bce0b0a2f1b173994"
                //7ec1419c6be
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/7ec1419c6be0f4f78ee36dbb67816be7ea505e4d"
                //82f39a9bacc
            ,   "https://stash.intralot.com/users/panagopoulou/repos/chile/commits/82f39a9bacc5de0b3f2445ee80e44a9f6be60d02"
            });

            g_files.Clear();

            foreach (String filename in files)
            {
                readFile(filename);
            }

            List<String> ff = g_files.Distinct().ToList();
            List<String> f = new List<String>();

            int total = 0;
            int page_size = 0;
            int n = 0;
            String line = "";


            using (StreamReader sr = new StreamReader(g_rootpath + "loto3.clean.txt"))
            {
                while ((line = sr.ReadLine()) != null)
                {
                    foreach (String l in ff)
                    {
                        if (line == l)
                        {
                            f.Add(l);
                            break;
                        }
                    }
                }
            }

            f.Sort();

            List<String> ext = new List<String>();

            foreach (String l in f)
            {
                ext.Add(l.Substring(l.LastIndexOf(".") + 1));
            }

            List<String> d_ext = ext.Distinct().ToList();

            using (StreamWriter sr = new StreamWriter(g_rootpath + "kostas.loto3.txt"))
            {
                foreach (String filename in f)
                {
                    sr.WriteLine(filename);
                }
            }

            using (StreamWriter sr = new StreamWriter(g_rootpath + "kostas.loto3.html"))
            {
                sr.WriteLine("<html>");
                sr.WriteLine("<title>Files</title>");
                sr.WriteLine("<style>");
                sr.WriteLine("\tbody { ");
                sr.WriteLine("\t\tfont: .8em Tahoma normal;");
                sr.WriteLine("\t}");
                sr.WriteLine("");
                sr.WriteLine("\tdl {");
                sr.WriteLine("\t\tfloat: left;");
                sr.WriteLine("\t\tdisplay: block;");
                sr.WriteLine("\t\twidth: 100%;");
                sr.WriteLine("\t\tmargin: 0;");
                sr.WriteLine("\t\tfont: .919em Tahoma normal;");
                sr.WriteLine("\t}");
                sr.WriteLine("");
                sr.WriteLine("\tdl > dl {");
                sr.WriteLine("\t\twidth: 60.5em;");
                sr.WriteLine("\t\tmargin-right: 1em;");
                sr.WriteLine("\t}");
                sr.WriteLine("");
                sr.WriteLine("\tdl dd {");
                sr.WriteLine("\t\tfloat: left;");
                sr.WriteLine("\t\tmargin-left: .5em;");
                sr.WriteLine("\t\tmargin-top: .5em;");
                sr.WriteLine("\t\twidth: 60em;");
                sr.WriteLine("\t\theight: 2.5em;");
                sr.WriteLine("\t\tborder: 1px solid #777777;");
                sr.WriteLine("\t\tpadding: .25em;");
                sr.WriteLine("\t\tposition: relative;");
                sr.WriteLine("\t\tdisplay: block;");
                sr.WriteLine("\t}");
                sr.WriteLine("</style>");
                sr.WriteLine("<body>");

                sr.WriteLine("<script>");
                sr.WriteLine("function selectExtension(ob) {");
                sr.WriteLine("\tvar elem = document.getElementsByClassName(ob.value);");
                sr.WriteLine("\tfor (var n = 0; n < elem.length; n ++) {");
                sr.WriteLine("\t\tif (ob.checked) elem[n].style.display=\"inline\";");
                sr.WriteLine("\t\tif (!ob.checked) elem[n].style.display=\"none\";");
                sr.WriteLine("\t}");
                sr.WriteLine("}");
                sr.WriteLine("</script>");

                sr.WriteLine("Los siguientes ID commits, son los que Kostas ha hecho para el Loto 3:<br/>");
                sr.WriteLine("<strong>");

                foreach (String l in commits_id)
                {
                    sr.WriteLine(l + "<br/>");
                }

                sr.WriteLine("</strong>");
                sr.WriteLine("<br/>");

                total = d_ext.Count();
                page_size = (int)Math.Ceiling((double)total / 2);
                n = 1;

                foreach (String l in d_ext)
                {
                    if (n == page_size)
                        sr.WriteLine("<br/>");

                    sr.WriteLine("<input type=\"checkbox\" value=\"" + l + "\" onclick=\"selectExtension(this)\" checked=\"checked\"/>" + l + "&nbsp;&nbsp;");
                    n++;
                }

                total = f.Count();
                page_size = (int)Math.Ceiling((double)total / 2) + 1;
                n = 1;

                sr.WriteLine("<br/>");
                sr.WriteLine("<br/>");

                sr.WriteLine("<dl>");

                foreach (String filename in f)
                {
                    if (n == 1 || n == page_size)
                    {
                        if (n == page_size)
                            sr.WriteLine("\t</dl>");

                        sr.WriteLine("\t<dl>");
                    }

                    sr.WriteLine("\t\t<dd class=\"" + filename.Substring(filename.LastIndexOf(".") + 1) + "\">" + filename + "</dd>");

                    if (n == total)
                        sr.WriteLine("\t</dl>");

                    n++;
                }

                sr.WriteLine("</dl>");
                sr.WriteLine("<br/>");
                sr.WriteLine("<br/>");

                sr.WriteLine("&nbsp;");

                sr.WriteLine("</body>");
                sr.WriteLine("</html>");

                MessageBox.Show("Done.", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }      
}
