using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Spider_Word.Word_IService;
using Spider_Word.Wrod_Service;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Spider_Word
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.SetHighDpiMode(HighDpiMode.SystemAware);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            ServiceCollection service = new ServiceCollection();
            ConfigureServices(service);
           
            var serviceProvider = service.BuildServiceProvider();
            var formMain = serviceProvider.GetRequiredService<FrmMain>();
            Application.Run(formMain);
          //  Application.Run(new Form1());
        }

        private static void ConfigureServices(ServiceCollection services)
        {
            services.AddScoped<FrmMain>();
            services.AddSingleton<IWord_Info, Word_InfoDAL>();
           
            IConfigurationBuilder cfgBuilder = new ConfigurationBuilder()
                .SetBasePath(Directory.GetCurrentDirectory())
                .AddJsonFile("appsettings.json")
                .AddJsonFile($"appsettings.{Environment.GetEnvironmentVariable("DOTNET_ENVIRONMENT")}.json", optional: true, reloadOnChange: false)
                ;
            IConfiguration configuration = cfgBuilder.Build();
            services.AddSingleton<IConfiguration>(configuration);
        }
    }
}
