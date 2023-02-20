using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    public partial class MemoryLeak
    {
        /// <summary>
        /// 当前为会泄露
        /// </summary>
        public static void List()
        {
            List<string> asd = new List<string>();
            while (true)
            {
                ///String它存放的并不是普通的堆
                ///.NET有一个叫做内存驻地的东西---->字符串池--->字符串驻留池
                ///你的这些String会存放起来并不会"完全"遵照GC走
                asd.Add(Guid.NewGuid().ToString());
                if (asd.Count > 10000)
                {
                    asd.Clear();
                    Console.WriteLine("asdasdasdasd" + 1);
                    Console.WriteLine("Error info");
                    Console.WriteLine("Error  info");
                    Console.WriteLine("error");
                    Console.WriteLine("erorr");
                }
            }
        }
        /// <summary>
        /// 泄露版
        /// </summary>
        public static void MemoryLeakList()
        {
            List<int[]> asd = new List<int[]>();
            while (true)
            {
                asd.Add(new int[85001]);
            }


           
        }



        public static void MemoryList()
        {

            List<int[]> asd = new List<int[]>();
            while (true)
            {
                asd.Add(new int[85001]);
                Task.Delay(1000).Wait();
            
            }
            Console.WriteLine(asd[0].Length);
        }
    }
}
