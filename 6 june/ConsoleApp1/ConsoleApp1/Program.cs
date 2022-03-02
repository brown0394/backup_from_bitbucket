using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{

    
    class Program
    {
        public enum E_RPS
        {
            Draw = 0,
            Win ,
            Lose
        }

        public const int MAXMONSTERCOUNT = 10; //#define 사용 불가하므로. 

        public E_RPS ISRPS()
        {



            return E_RPS.Draw;
        }

        static void Main(string[] args)
        {

            Program tempprog = new Program();//static은 클래스 외부에 존재하는 것이기 때문에 이와 같이 접근해야 하는 것이다.   Random rand = Random(); int val = reand.Next() %  3;
            //ConsoleApp1.Player myplayer;
            Player myplayer = new Player();
            Monster mob = new Monster();

            for (int i = 0; i < Program.MAXMONSTERCOUNT; ++i)
            {

                while (true)
                {
                    E_RPS result = tempprog.ISRPS();

                }
                               
            }



            myplayer = null;
            mob = null;
            tempprog = null;
        }
    }
}
