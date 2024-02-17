using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class Solution
    {
        public int RemoveElement(int[] nums, int val)
        {
            int ind = 0, len = 0;
            while(ind < nums.Length) 
            {
                if (nums[ind] == val)
                {
                    ind++;
                }
                else
                {
                    nums[len] = nums[ind];
                    len++;
                    ind++;
                }
            }

            return len+1;
        }
    }
    internal class _27移除元素
    {

        static void Main()
        {
            Console.WriteLine("Hello World");
            /// 在此键入您的代码 ///



            Console.WriteLine("按任意键继续...");
            Console.ReadKey();
        }

    }
}
