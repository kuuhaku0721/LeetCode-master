using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    internal class _20有效括号
    {
        public class Solution
        {
            public bool IsValid(string s)
            {
                if(s.Length == 0) return false;
                string[] strs = { "()", "[]", "{}" };
                Stack<char> stack = new Stack<char>();
                for (int i = 0; i < s.Length; i++)
                {
                    if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    {
                        stack.Push(s[i]);
                    }
                    else
                    {
                        if (stack.Count == 0) return false;
                        string tmp = stack.Pop().ToString() + s[i];
                        //Console.WriteLine(tmp);
                        if (!strs.Contains(tmp))
                            return false;
                    }
                }
                if (stack.Count == 0) return true;
                else return false;
            }
        }

        static void Main()
        {
            Console.WriteLine("Hello World");
            /// 在此键入您的代码 ///
            Solution solution = new Solution();
            string s = "{[{(})]}";
            Console.WriteLine(solution.IsValid(s).ToString());


            Console.WriteLine("按任意键继续...");
            Console.ReadKey();
        }

    }
}
