#include <iostream>
#include <string>
using namespace std;

/*
* 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
*/

//原来，string有back和pop_back、push_back这些操作啊........
//string本身就像是一个栈一样可以操作，毕竟，string也是模板类啊...

class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) 
        {
            if (!stk.empty() && stk.back() == ch) 
            {
                stk.pop_back();
            }
            else 
            {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};

int main()
{
	cout << "hello world" << endl;

	string s = "ssssssa";
	s = Solution().removeDuplicates(s);
	cout << s << endl;


	system("pause");
	return 0;
}

