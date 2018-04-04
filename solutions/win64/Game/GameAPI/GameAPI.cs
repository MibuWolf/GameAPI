using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Game
{
	class GameAPI
	{
		[DllImport("GameAPI.dll", EntryPoint = "Add", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
		extern static int Add(int x, int y);

	}
}
