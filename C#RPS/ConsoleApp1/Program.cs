using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{

    
    class Program
    {
        public enum E_RPSDWL
        {
            Draw = 10,
            Win ,
            Lose
        }
        public enum E_RPS
            {
            Rock = 0,
            Scissor,
            Paper
             }


        public const int MAXMONSTERCOUNT = 10; //#define 사용 불가하므로. 

        public E_RPSDWL ISRPS()
        {
            Random rand = Random();
            int val = rand.Next() % 3;

            int input = -1;
            scanf_s("%d", &input, sizeof(int));

            if(input == val)
           {
            return E_RPSDWL.Draw;
            }
            else if(input == (val - 1) || (E_RPS.Sicssor == input && E_RPS.Paper == val))
            {
                return E_RPSDWL.Win;
            }

            return E_RPSDWL.Lose;
        }

        static void Main()
        {

            Program tempprog = new Program();//static은 클래스 외부에 존재하는 것이기 때문에 이와 같이 접근해야 하는 것이다.   Random rand = Random(); int val = reand.Next() %  3;
            //ConsoleApp1.Player myplayer;
            Player myplayer = new Player();
            int monstercount = 0;

            for (int i = 0; i < Program.MAXMONSTERCOUNT; ++i)
            {
             Monster mob = new Monster();
                while (true)
                {
                    E_RPS result = tempprog.ISRPS();
                    if(result == E_RPSDWL.Win)
                   {
                        mob.SetDamage(10);
                        printf("YOU WON\n");
                        if(mob.HP <= 0)
                        {
                            ++monstercount;
                            printf("YOU WON\nMONSTERS YOU DEFEATED %d\n", monstercount);
                        }
                    }
                    else if(result == E_RPSDWL.Lose)
                    {
                        myplayer.SetDamage(10);
                        printf("YOU LOSE\n");
                        if(myplayer.HP <= 0)
                        {
                            printf("YOU LOST ALL YOUR ENERGY\n\n\t\tGAME OVER\n");
                            i == MAXMONSTERCOUNT;
                            break;
                        }
                    }
                    else
                    {
                        printf("DRAW\n");
                    }


                }
                               
            }

            if(mob.HP <= 0)
            {
                printf("YOU WON\n");
            }

            myplayer = null;
            mob = null;
            tempprog = null;
        }
    }
}
