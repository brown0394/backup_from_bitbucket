using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



//https://github.com/magotoolivesource



namespace Tetris
{
    public class MyRandom
    {
        private static Random m_Rand = new Random();

        public static int GetRand()
        {
            return m_Rand.Next();
        }

        public static int GetRandMax(int p_max)
        {
            return m_Rand.Next() % p_max;

        }

        public static int GetRand(int p_min, int p_max)
        {
            int gab = p_max - p_min;
            int rand = m_Rand.Next() % gab;

            return rand * p_min;

        }
    }


    public class BlockTypeData
    {
        public class BlockElementData
        {

            public int[,] BlockData = null;

        }
        public BlockElementData[] AllBlcokData = null;

        public int[,] GetBlockData(int p_rottype)
        {
            return AllBlcokData[p_rottype].BlockData;
        }
        public int GetBlockRotData(int p_rot, int p_x, int p_y)
        {
            return AllBlcokData[p_rot].BlockData[p_y, p_x];
        }
    //       public int[, ,] BlockArray = new int[4, 4, 4]
    //       {
    //         { 
    //          { 0, 0, 0, 0 },
    //          { 1, 1, 1, 1 },
    //          { 0, 0, 0, 0 },
    //          { 0, 0, 0, 0 },
    //         },
    //         {
    //          { 0, 0, 1, 0 },
    //          { 0, 0, 1, 0 },
    //          { 0, 0, 1, 0 },
    //          { 0, 0, 1, 0 },
    //         },
    //         {
    //          { 0, 0, 0, 0 },
    //          { 0, 0, 0, 0 },
    //          { 1, 1, 1, 1 },
    //          { 0, 0, 0, 0 },
    //         },
    //         {
    //          { 0, 1, 0, 0 },
    //          { 0, 1, 0, 0 },
    //          { 0, 1, 0, 0 },
    //          { 0, 1, 0, 0 },
    //         }
    //       };

}

public class TESTTetris
    {
        const int STAGEHEIGHT = 20;
        const int STAGEWIDTH = 10;
        

        int BlockHeight = 4;
        int BlockWidth = 4;
        int DelayTic = 1000;

        enum E_BLOCKTYPE
        {
            None = 0,
            BLOCK

        }


        public int[,] StageArray = new int[STAGEHEIGHT, STAGEWIDTH];//public int[] StageArray = new int[];


        public BlockTypeData[] AllBlockTypeDataArray = new BlockTypeData[3]
            {
                new BlockTypeData(),
                //{
                //    AllBlcokData = new BlockTypeData.BlockElementData()
                //    {
                //        BlockData = new B
                //    }
                //
                //
                //},
                new BlockTypeData(),
                new BlockTypeData()

            };









        public void StageDraw()
        {
            int len = StageArray.Length;
            int widthsize = StageArray.GetLength(0);
            int heightsize = StageArray.GetLength(1);
            int val = AllBlockTypeDataArray[0].AllBlcokData[0].BlockData[0, 0];


            for (int y = 0; y < STAGEHEIGHT; ++y)
            {
                for (int x = 0; x < STAGEWIDTH; ++x)
                {
                    if (StageArray[y, x] == (int)E_BLOCKTYPE.None)
                    {
                        Console.SetCursorPosition(x * 2, y);
                        Console.Write("·");

                    }
                    //else if (StageArray[y, x] == (int)E_BLOCKTYPE.BLOCK)
                    //{
                    //    Console.SetCursorPosition(x * 2, y);
                    //    Console.Write("■");
                    //
                    //}



                }

            }


        }


        int m_CurrentBlockType = 0;
        int m_BlockPosY = 0;
        int m_BlockPosX = 0;
        int m_RotType = 0;

        public void BlockDraw()
        {
            BlockTypeData blocktypedata = AllBlockTypeDataArray[m_CurrentBlockType];

            int tempy = m_BlockPosY;
            int tempx = m_BlockPosX;
            int widthsize = BlockWidth; //BlockArray.GetLength(2);
            int heightsize = BlockHeight; //BlockArray.GetLength(1);

            int[,] blockdata = blocktypedata.GetBlockData(m_RotType);

            for (int y = 0; y < heightsize; ++y)
            {
                for (int x = 0; x < widthsize; ++x)
                {
                    if (1 == blocktypedata.GetBlockRotData(m_RotType, x, y))
                    {

                        Console.SetCursorPosition((x + tempx) * 2, y + tempy);
                        Console.Write("■");
                    }


                }

            }

        }


        public void Draw()
        {
            StageDraw();
            BlockDraw();
        }

        public void UpdateLogic()
        {
            //    int tick = Environment.TickCount;
            //    while (true)
            //    {
            //        if (Environment.TickCount >= tick + 1000)
            //        { break; }
            //    }


            int currenttick = Environment.TickCount;

            bool isflag = false;
            if (NextTick <= currenttick)
            {
                NextTick = currenttick + DelayTic;
                isflag = true;

            }
            if (isflag == true)
            {
                ++m_BlockPosY;
                if (m_BlockPosY >= 17)
                {
                   CopyBlockData();
                   CreateRandomBlock();
                }

            }
            UpdateInput();
        }

        void CopyBlockData()
        {
            BlockTypeData blocktypedata = AllBlockTypeDataArray[m_CurrentBlockType];

            int tempy = m_BlockPosY;
            int tempx = m_BlockPosX;
            int widthsize = BlockWidth; //BlockArray.GetLength(2);
            int heightsize = BlockHeight; //BlockArray.GetLength(1);

            int[,] blockdata = blocktypedata.GetBlockData(m_RotType);

            for (int y = 0; y < heightsize; ++y)
            {
                for (int x = 0; x < widthsize; ++x)
                {
                    if (1 == blocktypedata.GetBlockRotData(m_RotType, x, y))
                    {

                        Console.SetCursorPosition((x + tempx) * 2, y + tempy);
                        Console.Write("■");

                        StageArray[y + tempy, x + tempx] = (int)E_BLOCKTYPE.BLOCK;
                    }


                }

            }

        }


        void CreateRandomBlock()
        {
            //MyRandom rand = new MyRandom();
            //int randval = rand.GetRand(0, 2);

            m_CurrentBlockType = MyRandom.GetRandMax(3);
            m_RotType = 0;
            m_BlockPosY = 0;
        }



        void UpdateInput()
        {


            if (Console.KeyAvailable)
            {

                ConsoleKeyInfo info = Console.ReadKey();
                ConsoleKey keyval = info.Key;

                if (keyval == ConsoleKey.RightArrow || keyval == ConsoleKey.D)
                {
                    ++m_BlockPosX;
                    if (m_BlockPosX >= 6)
                    {
                        m_BlockPosX = 6;

                    }

                }
                else if (keyval == ConsoleKey.LeftArrow || keyval == ConsoleKey.A)
                {
                    --m_BlockPosX;
                    if (m_BlockPosX <= 0)
                    {
                        m_BlockPosX = 0;

                    }


                }
                else if (keyval == ConsoleKey.DownArrow || keyval == ConsoleKey.S)
                {
                    ++m_BlockPosY;
                    if (m_BlockPosY >= 17)
                    {
                        m_BlockPosY = 16;

                    }


                }
                else if (keyval == ConsoleKey.UpArrow || keyval == ConsoleKey.W)
                {
                    m_RotType = (m_RotType + 1) % 4;
                }
            }





        }


        public int GameLogic()
        {
 
            UpdateLogic();
            Draw();
            return 0;

        }

        int NextTick = 0;
        void InitData()
        {
            DelayTic = 200;
            NextTick = Environment.TickCount + DelayTic;
            //StageArray[3, 2] = (int)E_BLOCKTYPE.BLOCK;


            AllBlockTypeDataArray[0].AllBlcokData = new BlockTypeData.BlockElementData[]
                {
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 1, 1, 1, 1 },
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 1, 0, 0 },
                            { 0, 1, 0, 0 },
                            { 0, 1, 0, 0 },
                            { 0, 1, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 },
                            { 1, 1, 1, 1 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 1, 0 },
                            { 0, 0, 1, 0 },
                            { 0, 0, 1, 0 },
                            { 0, 0, 1, 0 }
                        }
                    }
                };

            AllBlockTypeDataArray[1].AllBlcokData = new BlockTypeData.BlockElementData[4]
             {
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 0, 0, 0 }
                        }
                    }
            };
            AllBlockTypeDataArray[2].AllBlcokData = new BlockTypeData.BlockElementData[4]
 {
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 1, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 0, 0, 1, 0 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 1, 1, 0, 0 },
                            { 0, 0, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 1, 0, 0, 0 },
                            { 1, 1, 0, 0 },
                            { 0, 1, 0, 0 }
                        }
                    },
                    new BlockTypeData.BlockElementData()
                    {
                        BlockData = new int[4, 4]
                        {
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 },
                            { 0, 1, 1, 0 },
                            { 1, 1, 0, 0 }
                        }
                    }
};
            //            AllBlockTypeDataArray[0].AllBlcokData[0].BlockData = new int[4, 4]
            //                  {
            //                      { 0, 0, 0, 0 },
            //                      { 1, 1, 1, 1 },
            //                      { 0, 0, 0, 0 },
            //                      { 0, 0, 0, 0 }
            //                  };
            //            AllBlockTypeDataArray[0].AllBlcokData[1].BlockData = new int[4, 4]
            //                  {
            //                      { 0, 1, 0, 0 },
            //                      { 0, 1, 0, 0 },
            //                      { 0, 1, 0, 0 },
            //                      { 0, 1, 0, 0 }
            //                  };
            //            AllBlockTypeDataArray[0].AllBlcokData[2].BlockData = new int[4, 4]
            //                  {
            //                      { 0, 0, 0, 0 },
            //                      { 0, 0, 0, 0 },
            //                      { 1, 1, 1, 1 },
            //                      { 0, 0, 0, 0 }
            //                  };
            //            AllBlockTypeDataArray[0].AllBlcokData[3].BlockData = new int[4, 4]
            //                  {
            //                      { 0, 0, 1, 0 },
            //                      { 0, 0, 1, 0 },
            //                      { 0, 0, 1, 0 },
            //                      { 0, 0, 1, 0 }
            //                  };
        }

        public void InGame()
        {
            int result = 0;
            InitData();
            while (true)
            {
                result = GameLogic();

                if (result <= 0)
                {


                }
            }

        }
    }







    class Program
    {
        static void Main(string[] args)
        {
            Tetris.TESTTetris ingametetris = new Tetris.TESTTetris();

            ingametetris.InGame();
        }
    }
}
