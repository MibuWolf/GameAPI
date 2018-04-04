using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GameAPIBridge;
using CryEngine.UI;
using CryEngine.UI.Components;
using FairyGUI;
using Game.System;

namespace Game
{
    public class Game
    {
		// 初始化游戏
		public static int InitGame(string s)
		{
			bool ret = GameAPI.GetInstance().Initialization();
			GameManager.GetInstance().Initialize();
			GameAPI.GetInstance().GetActorManager().AddMainRole();

			if (ret)
				return 1;

			return 0;
		}

		// 关闭游戏
		public static int CloseGame(string s)
		{
			GameAPI.GetInstance().Destory();
			return 1;
		}
	}
}
