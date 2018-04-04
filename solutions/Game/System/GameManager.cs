using CryEngine;
using FairyGUI;
using Robotlegs.Bender.Bundles.MVCS;
using Robotlegs.Bender.Framework.API;
using Robotlegs.Bender.Framework.Impl;

namespace Game.System
{
    public class GameManager
    {
        private static GameManager _instance;     
        public static GameManager GetInstance()
        {
            if(_instance == null)
            {
                _instance = new GameManager();
            }
            return _instance;
        }
        private IContext context;
        
        //初始化
        public void Initialize()
        {
            context = new Context();
            context.Install<MVCSBundle>().Configure<GameConfig>();
            context.Initialize();
        }
    }
}