using EditorV4.Controls.TreeViewControl;
using EditorV4.Forms;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EditorV4
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(String[] args)
        {

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            var mapEditorForm = new MapEditor();
            if (args.Length > 0)
            {
                mapEditorForm.OpenFile(args[0]);
            }
            Application.Run(mapEditorForm);
            //Application.Run(new TestForm(10, 10, 16, null));
        }
    }
}
