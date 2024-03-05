#include <iostream>
#include <cmath>
using namespace std;

const int total = 23333333;
const double H = 11625907.5798;

/*
* 如果碰到类似的数学计算式，那就放弃吧
* 说实话，这几个log计算式让我手算我都不一定算得出来，代码更不会了
*/

void shion()
{
    for (int i = 0; i < total / 2; i++) 
    {
        double ans = 0;
        ans -= 1.0 * i * i / total * log2(1.0 * i / total);
        ans -= 1.0 * (total - i) * (total - i) / total * log2(1.0 * (total - i) / total);
        if (abs(ans - H) < 1e-4) {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

