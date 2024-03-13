#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 用一个整数表示，值为从 1970 年 1 月 1 日 00 : 00 : 00到当前时刻经过的毫秒数
*  输出时分秒表示的当前时间，格式形如 HH :MM:SS，
* 其中HH 表示时，值为 0到 23，MM 表示分，值为 0 到 59，SS 表示秒，值为 0 到 59。时、分、秒不足两位时补前导0。
* 【测试用例】
* Input：
* 46800999
* Output：
* 13:00:00
*/
/*
* 虽然只要时分秒，但是考虑到闰年和2月的时间差，还是得减，捡到这一天为止
* 先从年份开始减，一直减到不够一年，从月分开始减，不够一月从天开始减，减到不够一天，就是最终结果了
* 最后不够一天的那个毫秒数，就是这一天从00：00开始过去了多少毫秒
* 然后再减小时，直到不够一小时，再减分，直到不够一分钟，再减秒，直到不够一秒
* 
* 喵个咪的看错题了，只要一天就行，我还在傻傻判断年月日...
* 从1970年数到现在......
*/

typedef long long LL;

vector<int> months{ 31,28,31,30,31,30,31,31,30,31,30,31 };
LL YEAR_NORMAL = 31536000000;
LL YEAR_RUN = 31622400000;
LL DAY = 86400000;
LL HOUR = 3600000;
LL MINUTE = 60000;

bool isRun(int year)
{
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	return true;
}

void DateChange()
{
	LL date;
	cin >> date;
	cout << "初始值: " << date << endl;
	int year = 1970;
	while (date > YEAR_NORMAL || year > YEAR_RUN)
	{
		if (isRun(year))
		{
			date -= YEAR_RUN;
			cout << "当次date = " << date << endl;
		}
		else
		{
			date -= YEAR_NORMAL;
			cout << "当次date = " << date << endl;
		}
		year++;
	}
	cout << "剩下的不够一年: " << date << endl;
	int i = 0;
	while (date > months[i] * DAY)
	{
		if(i == 1)
			if (isRun(year))
				date -= (months[i] + 1) * DAY;
		else
			date -= months[i] * DAY;
		i++;
	}
	cout << "剩下的不够一个月: " << date << endl;
	// 且i就是马上要进入的那个月
	while (date > DAY)
	{
		date -= DAY;
	}
	// 剩下的不够一天，从这里开始转换格式,把这个毫秒数变成 HH : MM : SS 的形式
	cout << "剩下的：" << date << endl;
	int h = 0;
	while (date > HOUR)
	{
		date -= HOUR;
		h++;
	}
	// 剩下的不够一小时
	int m = 0;
	while (date > MINUTE)
	{
		date -= MINUTE;
		m++;
	}
	// 剩下的不够一分钟
	int s = 0;
	while (date > 1000)
	{
		date -= 1000;
		s++;
	}
	// 剩下的不足一秒
	// 结束
	cout << "时: " << h << "，分: " << m << "，秒: " << s << endl;
	string res = "";
	if (h < 10)
	{
		res += "0";
		res += to_string(h);
	}
	else
		res += to_string(h);
	res += ":";
	if (m < 10)
	{
		res += "0";
		res += to_string(m);
	}
	else
		res += to_string(m);
	res += ":";
	if (s < 10)
	{
		res += "0";
		res += to_string(s);
	}
	else
		res += to_string(s);
	cout << res << endl;
}

int main()
{
	cout << "hello world" << endl;
	DateChange();

	system("pause");
	return 0;
}

