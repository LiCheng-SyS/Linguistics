using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {

            double d = -2.345;
            int i = (int)Convert.ChangeType(d, typeof(int));
            var xx=  Convert.ChangeType(d, typeof(int));
            Console.WriteLine("The double value {0} when converted to an int becomes {1}", d, i);




            //ActionExecutor executor = new ActionExecutor();
            //executor.AddAction(() => Console.WriteLine("Action 1"));
            //executor.AddAction(() => Console.WriteLine("Action 2"));
            //executor.AddAction(() => Console.WriteLine("Action 3"));
            //executor.AddAction(() => Console.WriteLine("Action 4"));
            //executor.AddAction(() => throw new Exception());
            //executor.AddAction(() => Console.WriteLine("Action 5"));

            //while (true)
            //{
            //    executor.ExecuteActions();
            //    Thread.Sleep(1000); // 休眠1秒
            //}
        }
    }
}
