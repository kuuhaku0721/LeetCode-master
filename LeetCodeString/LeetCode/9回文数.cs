using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class Solution
    {
        public bool IsPalindrome(int x)
        {
            string oristr = x.ToString();
            char[] chars = oristr.ToCharArray();
            Array.Reverse(chars);
            string resstr = new string(chars);
            Console.WriteLine(oristr);
            Console.WriteLine(resstr);

            return oristr == resstr;
        }
    }
    internal class _9回文数
    {
        static void Main()
        {
            Console.WriteLine("Hello World");
            /// 在此键入您的代码 ///
            Solution solution = new Solution();
            int x = 12345;
            Console.WriteLine(solution.IsPalindrome(x).ToString());


            Console.WriteLine("按任意键继续...");
            Console.ReadKey();
        }

    }
}
