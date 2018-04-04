using System;
using System.Collections.Generic;
using CryEngine;
using Game.Framework;

namespace Game.Manager
{
    public class ModuleManager
    {
        private static Dictionary<int, BaseModule> _dModule;
        public static Dictionary<int, BaseModule> DModule
        {
            get
            {
                if (_dModule == null)
                {
                    _dModule = new Dictionary<int, BaseModule>();
                }
                return _dModule;
            }
        }
        
        public static void CreateModule<T>(int id) where T : BaseModule
        {
            T temp = null;
            if (!ModuleManager.DModule.ContainsKey(id))
            {
                temp = Activator.CreateInstance<T>();
                ModuleManager.DModule.Add(id, temp);
            }
            else
            {
                Log.Error("module is exit!!!!");
            }
        }

        public static void RemoveModule(int id)
        {
            if (ModuleManager.DModule.ContainsKey(id))
            {
                ModuleManager.DModule.Remove(id);
            }
        }
    }
}