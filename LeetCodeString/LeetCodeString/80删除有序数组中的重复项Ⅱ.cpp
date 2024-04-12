#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
* 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
        // 数组中的一号和二号元素肯定不用删除
        int count = 2;
        for (int i = 2; i < nums.size(); i++) 
        {
            if (nums[i] != nums[count - 2]) 
            {
                nums[count++] = nums[i];
            }
        }
        return count;
	}

    // 最简写法
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i - 2])
                nums[i++] = n;
        return i;
    }
};

int main()
{
	cout << "hello world" << endl;

	system("pause");
	return 0;
}

