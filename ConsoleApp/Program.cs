using System;
using System.Threading;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            //MemoryLeak.TheadJion();

            ActionExecutor executor = new ActionExecutor();

            executor.AddAction(() => Console.WriteLine("Action 1"));
            executor.AddAction(() => Console.WriteLine("Action 2"));
            executor.AddAction(() => Console.WriteLine("Action 3"));
            executor.AddAction(() => Console.WriteLine("Action 4"));
            executor.AddAction(() => throw new Exception() ) ;
            executor.AddAction(() => Console.WriteLine("Action 5"));


            while (true)
            {
                executor.ExecuteActions();
                Thread.Sleep(1000); // 休眠1秒
            }
        }
    }
}
