using System;
using FairyGUI;
using Robotlegs.Bender.Extensions.Mediation.API;
using Robotlegs.Bender.Extensions.ViewManagement.API;

namespace Game.Framework
{
    public class BaseView : GComponent, IView
    {
        protected bool isDispose;
        protected bool isDestroy;

        public BaseView()
        {
            ViewNotifier.RegisterView(this);
            Initialize();
        }
        private Action<IView> _removeView;
        public event Action<IView> RemoveView
        {
            add
            {
                _removeView += value;
            }
            remove
            {
                _removeView -= value;
            }
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
        
        //避免与GComponent的Dispose冲突
        public virtual void dispose()
        {
            isDispose = true;
            if (!isDestroy)
            {
                if(_removeView != null)
                {
                    _removeView(this);
                }
            }
        }
        
        //加入双向判断，使得OnDestroy || Dispose函数都支持
        public virtual void OnDestroy()
        {
            isDestroy = true; 
            if (!isDispose)
            {
                Dispose();
            }
        }
    }
}