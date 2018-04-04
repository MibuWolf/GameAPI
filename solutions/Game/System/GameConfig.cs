using Game.Manager;
using Game.UI.TestProject;
using Robotlegs.Bender.Extensions.EventCommand.API;
using Robotlegs.Bender.Extensions.EventManagement.API;
using Robotlegs.Bender.Extensions.Mediation.API;
using Robotlegs.Bender.Framework.API;

namespace Game.System
{
    public class GameConfig : IConfig
    {
        [Inject] public static IMediatorMap mediatorMap;
		[Inject] public IInjector injector;
	    [Inject] public IContext context;
        [Inject] public IEventCommandMap sysCommandMap; 
        [Inject] public IEventDispatcher sysDispatcher;
        public void Configure()
        { 
            RegisterView();
            RegisterModel();
            RegisterService();
            context.AfterInitializing(StartGame);
        }

        //游戏启动
        private void StartGame()
        {
            UIManager.GetInstance().Initialize();
        }

        //需要游戏启动的时候注册的就注册,一般在view初始化的时候注册
        private void RegisterView()
        {
            
        }
        
        private void RegisterModel() 
        {
            injector.Map<testModel>().ToSingleton<testModel>();      
            




        }
        private void RegisterService()
        {
            injector.Map<testService>().ToSingleton<testService>();      




            
        }
    }
}