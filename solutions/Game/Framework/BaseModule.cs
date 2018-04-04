using System;
using Game.System;

namespace Game.Framework
{
    public class BaseModule : IDisposable
    {
        public BaseModule()
        {
            Initialize();
        }
        protected virtual void DoRegister<T1,T2>() where T1 : BaseView  where T2 : BaseMediator
        {
            GameConfig.mediatorMap.Map<T1>().ToMediator<T2>();
        }

        protected virtual void UnRegister<T1>()
        {
            GameConfig.mediatorMap.Unmap<T1>().FromAll();
        }

        public virtual void Initialize()
        {
            
        }
        
        public virtual void Show()
        {

        }

        public virtual void Hide()
        {

        }

        public virtual void Dispose()
        {
            Dispose();
        }
    }
}