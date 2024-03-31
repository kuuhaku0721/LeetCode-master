#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++) 
        {
            ret[i] = number;
            if (number * 10 <= n) 
            {
                number *= 10;
            }
            else 
            {
                while (number % 10 == 9 || number + 1 > n) 
                {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }

    // 快排
    void quickSort(std::vector<int>& arr, int left, int right) 
    {
        if (left >= right) 
        {
            return;
        }

        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) 
            {
                i++;
            }
            while (arr[j] > pivot) 
            {
                j--;
            }
            if (i <= j) 
            {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
};


int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

