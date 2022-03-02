using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Monster
    {

        public int HP = 100;
        public void SetDamage(int p_damage)
        {
            HP -= p_damage;
        }
    }
}
