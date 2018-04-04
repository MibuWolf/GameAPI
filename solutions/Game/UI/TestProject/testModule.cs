using CryEngine;
using Game.Framework;

namespace Game.UI.TestProject
{
    public class testModule : BaseModule
    {
        testView view = null;
        public override void Initialize()
        {
            DoRegister<testView,testMediator>();
        }

        public override void Show()
        {
            view = new testView();
            view.Show();
        }

        public override void Hide()
        {
            view.Hide();
        }

        public override void Dispose()
        {
            view.dispose();        
        }
    }
}