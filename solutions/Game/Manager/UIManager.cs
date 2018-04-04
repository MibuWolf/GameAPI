using System.Collections.Generic;
using CryEngine;
using FairyGUI;
using Game.Framework;
using Game.UI.TestProject;
using Robotlegs.Bender.Extensions.Mediation.API;
using Robotlegs.Bender.Extensions.Mediation.DSL;
using Robotlegs.Bender.Extensions.ViewManagement.API;
using static FairyGUI.UIPackage;

namespace Game.Manager
{
    public enum Layer
    {
        //默认
        DEFAULT = -1,
        //背景层
        BG = 0,
        //游戏信息层
        HUD = 1,
        //系统层
        SYS = 2,
        //普通UI
        BASE = 3,
        //弹框
        POPUP = 4,
    }
    
    public class UIManager
    {
        private static UIManager _instance;     
        public static UIManager GetInstance()
        {
            if(_instance == null)
            {
                _instance = new UIManager();
            }
            return _instance;
        }

        //初始化UI
        public void Initialize()
        {   
            ModuleManager.CreateModule<testModule>(10000);
            Show(10000);
        }

        public void Show(int moduleID)
        {
            if(ModuleManager.DModule.ContainsKey(moduleID))
            {
                ModuleManager.DModule[moduleID].Show();     
            }
            else
            {
                Log.Error("ID not is exit"); 
            }
        }

        public void Hide(int moduleID)
        {
           if (ModuleManager.DModule.ContainsKey(moduleID))
           {
               ModuleManager.DModule[moduleID].Hide();  
           }
        }

        public void OnDestroy(int moduleID)
        {
           if (ModuleManager.DModule.ContainsKey(moduleID))
           {
              ModuleManager.DModule[moduleID].Dispose();
              ModuleManager.DModule.Remove(moduleID);
           }
        }


        //---------------------------------UI扩展函数---------------------------------//    


        ///<param name="PPath">包的路径</param>
        public void AddPackage(string PPath)
        {
            UIPackage.AddPackage(PPath);
        }

        ///<param name="pkgName">包名</param>
        ///<param name="resName">资源名</param>
        public GObject CreateObject(string pkgName, string resName)
        {
            var g_object = UIPackage.CreateObject(pkgName,resName);
            if(g_object == null)
            {
                Log.Error("not find!!!");
            }
            return g_object;
        }
    }
}