using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)     //TODO:优化：换双指针，一次遍历
        {
            int[] arr = new int[2];
            for (int i = 0; i < nums.Length; i++)
            {
                for(int j = 0; j < nums.Length; j++)
                {
                    if(i != j && (nums[i] + nums[j] == target))
                    {
                        arr[0] = i;
                        arr[1] = j;
                    }
                }
            }
            return arr;
        }
    }
    internal class _1两数之和
    {
        static void Main(string[] args)
        {
            int[] nums = { 2, 7, 11, 15 };
            int target = 9;
            Solution solution = new Solution();
            int[] arr = solution.TwoSum(nums, target);
            foreach(int i in arr)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("按任意键继续...");
            Console.ReadKey();
        }
    }
}
