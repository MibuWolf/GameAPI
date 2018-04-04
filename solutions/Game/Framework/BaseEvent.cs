using System;
using Robotlegs.Bender.Extensions.EventManagement.API;

namespace Game.Framework
{
    public class BaseEvent : IEvent
    {
        public BaseEvent(Enum type)
        {
            this.type = type;
        }
        public Enum type
        {
            get;
        }
    }
}