using FairyGUI;
using Game.Framework;
using Game.Manager;

namespace Game.UI.TestProject
{
    public class testView : BaseView
    {
       private GComponent _mainView;
       private GObject _backBtn;

		public testView()
			: base()
		{
			int a = 0;
		}

		public override void Initialize()
       {
            UIPackage.AddPackage("UI/Login");
            _mainView = UIPackage.CreateObject("Login", "Login").asCom;
			_mainView.MakeFullScreen();
			_mainView.AddRelation(GRoot.inst, RelationType.Size);
			GRoot.inst.AddChild(_mainView);
            _backBtn = _mainView.GetChild("n22");
            _backBtn.onClick.Add(onClickBack);
       }  
       public override void Show()
       {
           base.Show();
       }   
       public override void Hide()
       {
            base.Hide(); 
       } 
       public override void dispose()
       {
            base.Dispose();
       }
       	private void onClickBack()
		{
            UIManager.GetInstance().OnDestroy(10000);
            GRoot.inst.RemoveChild(_mainView);
		}
    }
}