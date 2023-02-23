using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp
{
    public partial class MemoryLeak
    {

        /// <summary>
        /// Overall, when using Thread.CurrentThread.Join(), 
        /// it's important to ensure that the calling thread is not blocked indefinitely
        /// and that there is a way to gracefully terminate the thread being waited on if necessary.
        /// </summary>
        public static void TheadJion()
        {
            //If the Join() method is called on the main thread, 
            //it will block the entire application and prevent it from responding to user input or events until the current thread completes its execution. 
            //This can lead to a poor user experience or even crash the application if the thread takes too long to complete.
      
            while (true)
            {
                Console.ReadLine();
                Thread t = new Thread(new ThreadStart(ThreadProc));
                t.Start();
            }

        }


        static void ThreadProc()
        {
            //如果在主线程上调用 Join() 方法，它将阻塞整个应用程序并阻止它响应用户输入或事件，直到当前线程完成其执行。这可能会导致糟糕的用户体验，如果线程完成时间过长，甚至会导致应用程序崩溃。
            //方法是一种阻塞方法，它会等待当前线程完成执行，然后再继续执行下一行代码
            //因此，建议仅在必要时使用 Join() 并使用超时值以防止无限期阻塞。此外，确保线程执行的代码经过优化和高效以避免不必要的延迟也很重要
            //因此，应谨慎使用它以避免阻塞主线程或应用程序中的任何其他关键线程
            Thread.CurrentThread.Join();
        }

    }
}
