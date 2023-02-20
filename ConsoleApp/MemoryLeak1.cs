using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp
{
    public partial class MemoryLeak1
    {
        public static void Demo3()
        {
            while (true)
            {
                Console.ReadLine();
                Thread t = new Thread(new ThreadStart(ThreadProc));
                t.Start();
            }

        }



        static void ThreadProc()
        {
            Thread.CurrentThread.Join();
        }

    }
}
