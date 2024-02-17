#include <iostream>
#include <string>
using namespace std;

/*
TinyURL 是一种 URL 简化服务， 比如：当你输入一个 URL https://leetcode.com/problems/design-tinyurl 时，
它将返回一个简化的URL http://tinyurl.com/4e9iAk 。请你设计一个类来加密与解密 TinyURL 。
加密和解密算法如何设计和运作是没有限制的，你只需要保证一个 URL 可以被加密成一个 TinyURL ，并且这个 TinyURL 可以用解密方法恢复成原本的 URL 。
实现 Solution 类：
Solution() 初始化 TinyURL 系统对象。
String encode(String longUrl) 返回 longUrl 对应的 TinyURL 。
String decode(String shortUrl) 返回 shortUrl 原本的 URL 。题目数据保证给定的 shortUrl 是由同一个系统对象加密的。
*/


/*
* 这题...没有任何要求，也就是说，其实直接return返回也行...但是吧，不道德，真的不道德....233333333
* 那就自己编一个加密方法，从第一个/开始后面的内容，以/当作分割，把前面的部分留下，然后分隔后的每一个字符串的每一个字符，以它的ASCII码%26之后得到的结果为新值
* 运算完毕后结果写回到原位置，解密同理
*/

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int index = longUrl.find("//");
        string res = longUrl.substr(0, index);
        longUrl.replace(0, index + 2, "");
        res += "//";
        index = longUrl.find('/');
        res += longUrl.substr(0, index);
        string remain = longUrl.substr(index, longUrl.size() - index);
        for (int i = 0; i < remain.size(); i++)
        {
            if (remain[i] == '/')
                res += remain[i];
            else
            {
                remain[i] -= 48;
                res += remain[i];
            }
        }
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index = shortUrl.find("//");
        string res = shortUrl.substr(0, index);
        shortUrl.replace(0, index + 2, "");
        res += "//";
        index = shortUrl.find('/');
        res += shortUrl.substr(0, index);
        string remain = shortUrl.substr(index, shortUrl.size() - index);
        for (int i = 0; i < remain.size(); i++)
        {
            if (remain[i] == '/')
                res += remain[i];
            else
            {
                remain[i] += 48;
                res += remain[i];
            }
        }
        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


int main()
{
	cout << "hello world" << endl;

    string longUrl = "http://www.leetcode.com/faq/?id=10";
    longUrl = Solution().encode(longUrl);
    cout << longUrl << endl;
    longUrl = Solution().decode(longUrl);
    cout << longUrl << endl;

	system("pause");
	return 0;
}

