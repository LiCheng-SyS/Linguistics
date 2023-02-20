using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;


/// <summary>
/// 异常处理
/// 如在多线程编程中，可以使用类似的代码来管理多个委托的执行，避免出现一些潜在的问题，比如内存泄漏、异常处理
/// 在一些需要异步处理的场景下，也可以使用类似的代码来管理回调委托的执行。
/// </summary>
public class ActionWrapper
{
    public Action Action { get; set; }
    public int ErrorCount { get; set; }
    public bool IsEnabled { get; set; } = true;
    public int WaitTimeToLive { get; set; } = 1000 * 10; // 单位为毫秒
}

public class ActionExecutor
{
    public Action ActionToExecute { get; set; }

    private readonly List<ActionWrapper> _actionList = new List<ActionWrapper>();

    public ActionExecutor()
    {
        Task.Factory.StartNew(() =>
        {
            while (true)
            {
                _actionList.ForEach(action =>
                {
                    action.WaitTimeToLive -= 1;
                });
                Thread.Sleep(1); // 降低 CPU 占用率
            }
        }, TaskCreationOptions.LongRunning);
    }

    public void AddAction(Action action)
    {
        _actionList.Add(new ActionWrapper
        {
            Action = action,
            IsEnabled = true,
            ErrorCount = 0
        });
    }

    public void ExecuteActions()
    {
        _actionList.ForEach(action =>
        {
            if (!action.IsEnabled)  {
                return;
            }
            try
            {
                action.Action.Invoke();
            }
            catch (Exception)
            {
                Console.WriteLine("这孙子错了,把他给我删了");
                action.IsEnabled = (++action.ErrorCount > 3);
            }
        });
    }
}
