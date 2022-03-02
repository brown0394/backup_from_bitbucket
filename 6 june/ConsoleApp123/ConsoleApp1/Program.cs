using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{

    public class Stage
    {
  //      public class Stage2
  //      {
  //
  //        }
  //      public static Stage2 stagecls = new Stage2();



    }

    public class Actor
    {
        public enum E_ClassType
        {
            player = 0,
            monster,
            middlemon
        }


        public int HP = 100;
        public float Defense = 1f;

        public void SetHp(int p_hp)
        {
            HP = p_hp;
        }

        protected virtual void SetEXDamage(int p_damage)
        {

        }

        public virtual void SetDamage(int p_damage)
        {
            HP -= (int)((float)p_damage / Defense);
            if (HP < 0)
            {
                HP = 0;
            }

            SetEXDamage(p_damage);
        }

        public virtual void Move()
        {

        }

        public Actor TargetActor = null;
        public virtual void Attack()
        {
            TargetActor.SetDamage(10);

        }

    }

    public class Player : Actor
    {
        public float MagDef = 1f;


        protected override void SetEXDamage(int p_damage)
        {

        }
        //  public new void SetEXDamage(int p_damage) 완전히 새롭게 하는 것. 고로 부모 클래스의 원 함수에 접근 불가. 즉 분리. sealed. public sealed void SetHp(); 상속을 막는 키워드;
        //  {
        //
        //  }
        public override void Move()
        {

        }

        public override void Attack()
        {
            base.Attack();


        }


        public override void SetDamage(int p_damage)
        {
            p_damage -= (int)((float)p_damage / Defense);
           
            base.SetDamage(p_damage); //부모클래스 함수 사용. 상속없이.
        }
    }

    public class Monster : Actor
    {
        public override void Move()
        {

        }
    }

    class InGame
    {
        Player playcls = new Player();
        Monster monstercls = new Monster();

        Actor[] ActorArray = new Actor[2];

        public bool IsLoop()
        {
            ConsoleKeyInfo info = Console.ReadKey();
            if (info.Key == ConsoleKey.Q)
            {
                return false;
            }
            return true;

        }


        Random rand = new System.Random();
        void InGameLogic()
        {
            int result = rand.Next() % 2;


            for (int i = 0; i < ActorArray.Length; ++i)
            {
                ActorArray[i].Move();

                ActorArray[i].Attack();

                Player playercls2 = ActorArray[i] as Player; //   is 키워드 공부할 것??
                if (playercls2 == null)
                {
                    if (playercls2.TargetActor.HP <= 0)
                    {

                    }
                }
            }

            if (0 == result)
            {
                ActorArray[0].SetDamage(10);
                playcls.SetDamage(10);

            }
            else
            {
                ActorArray[1].SetDamage(10);
                monstercls.SetDamage(10);
            }
        }

        public void GameStart()
        {
            bool isloop = false;
            Initialization();


            while (true)
            {


                isloop = IsLoop();
                if (isloop == false)
                {


                    break;
                }
            }
            Release();

        }
        void Release()//Destroy
        {
            playcls = null;
            monstercls = null;
        }


        void Initialization()
        {
   
            ActorArray[2] = new Monster();


            ActorArray[0] = playcls;
            ActorArray[1] = monstercls;
            ActorArray[2] = new Monster();

            ActorArray[0].TargetActor = ActorArray[1];
            ActorArray[1].TargetActor = ActorArray[0];
            ActorArray[2].TargetActor = ActorArray[0];

         //   playcls.SetHp(100);
         //   monstercls.SetHp(100);

        }

    }

    class Program
    {


        //Stage.Stage2 stage2cls = new Stage.Stage2();
        static void Main(string[] args)
        {

            InGame gamecls = new InGame();
            gamecls.GameStart();

        }
    }
}
