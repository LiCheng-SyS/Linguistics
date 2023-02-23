using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        static ActionExecutor executor = new ActionExecutor();
        static void Main(string[] args)
        {


        }
        static void MemoryRun()
        {
            executor.AddAction(() => Console.WriteLine("Action 1"));
            executor.AddAction(() => Console.WriteLine("Action 2"));
            executor.AddAction(() => Console.WriteLine("Action 3"));
            executor.AddAction(() => Console.WriteLine("Action 4"));
            executor.AddAction(() => throw new Exception());
            executor.AddAction(() => Console.WriteLine("Action 5"));

            while (true)
            {
                executor.ExecuteActions();
                Thread.Sleep(1000); // 休眠1秒
            }
        }
    }
}
