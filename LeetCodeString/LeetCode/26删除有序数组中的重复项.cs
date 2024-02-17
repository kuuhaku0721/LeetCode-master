using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class Solution
    {
        public int RemoveDuplicates(int[] nums)
        {
            if(nums.Length <= 1) return nums.Length;
            int pre= 1, ind = 0, tmp = nums[ind];
            while(pre <= nums.Length)
            {
                if (nums[pre] != tmp)
                {
                    ind++;
                    nums[ind] = nums[pre];
                    tmp = nums[ind];
                    pre++;
                }
                else
                {
                    pre++;
                }
            }

            return ind+1;
        }
    }
    internal class _26删除有序数组中的重复项
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
