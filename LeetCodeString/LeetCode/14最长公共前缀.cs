using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class Solution
    {
        public string LongestCommonPrefix(string[] strs)
        {
            int Len = int.MaxValue;
            foreach (var s in strs)
            {
                if(s.Length < Len)
                    Len = s.Length;
            }
            int ind;
            string prefix = "";
            bool flag = true;
            for (ind = 1; ind <= Len; ind++)
            {
                prefix = strs[0].Substring(0, ind);
                foreach (string s in strs)
                {
                    if(!s.StartsWith(prefix))
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
                return prefix;
            else
                return prefix.Substring(0, prefix.Length - 1);
        }
    }
    internal class _14最长公共前缀
    {

        static void Main()
        {
            Console.WriteLine("Hello World");
            /// 在此键入您的代码 ///
            Solution solution = new Solution();
            string[] strs = { "dog", "racecar", "car" };
            string res = solution.LongestCommonPrefix(strs);
            Console.WriteLine(res);

            


            Console.WriteLine("按任意键继续...");
            Console.ReadKey();
        }

    }
}
