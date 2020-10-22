using NETCONLib;
using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Threading;
using System.Runtime.InteropServices;

namespace GitSetup
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
           
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            // if (Steuer_Taste.IsEnabled)
            //     netsh.set_hostednetwork(Name_Textbox.Text, Passwort_Pbox.Visibility == Visibility.Visible ? Passwort_Pbox.Password : Passwort_Tbox.Text);
        }
    }
}
