using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        /// <summary>
        /// 테스트 함수임
        /// </summary>
        /// <param name="a">이값은 out 테스트용</param>
        /// <param name="b">이 값은 ref 테스트용</param>
        /// <returns></returns>
        public int TestFunc(int a, ref int b) // out>?
        {
            int c = a + b;

            b = 1;
            return c;
        }
        //함수 바로 위에 작성해야지 이게 나오네.
        public int TestFunc2(out int a, ref int b) // object 타입이 void와 유사함.
        {
            int c = 15 + b;

            a = 35;
            b = 1;
            return c;
            
        }
        static void Main(string[] args)
        {


            int[] i_tempintarray = new int[20];

            i_tempintarray[0] = 10;


            for (int i = 0; i < 10; i++)
            {
                Console.Write("abc");
            }

            foreach (int item in i_tempintarray)
            {


            }

            Program testp = new Program();
            int c = 15;

            int a = testp.TestFunc(5, ref c);

            int b = testp.TestFunc2(out a , ref c);
        }
    }
}
