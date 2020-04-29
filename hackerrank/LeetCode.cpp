#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <list>
#include <set>
#include <map>

#include <fstream>

using namespace std;

typedef unsigned long long int uint64;


class Solution1 {
    int find_odd_number(vector<int>& nums) {
        for (auto a : nums) {
            if (a != 0)
                if (a % 2 == 1)
                    return a;
        }
        return -1;
    }

    long long int calc_sum(vector<int>& nums) {
        long long int sum = 0;
        for (auto a : nums) {
            sum += a;
        }
        return sum;
    }

public:
    int singleNumber(vector<int>& nums) {

        int divider = 1;
        while (true) {
            long long int sum = calc_sum(nums);;
            if (sum % 2 == 1) // the sum is odd, find the odd number;
                return find_odd_number(nums) * divider;

            divider *= 2;
            // the sum is even - remove all odd numbers and divide by 2 the even numbers;
            for (auto& a : nums) {
                if (a % 2 != 0)
                    a = 0;
                else
                    a /= 2;
            }
        }
    }    
};


void test_single_number() {

    int ret;
    vector<int> nums = { 2,2,1 };
    vector<int> nums1 = { 4,1,2,1,2 };
    vector<int> nums2 = { /*2147483648, */ 
        1073741824, 536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608, 4194304, 2097152, 1048576, 524288, 262144, 131072, 65536,
                    536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608, 4194304, 2097152, 1048576, 524288, 262144, 131072, 65536
    };

    vector<int> nums3 = { /*2147483648, */ 1073741824, 536870912, 536870912 };
    

    Solution1 sln;
    ret = sln.singleNumber(nums);
    cout << ret;
    ret = sln.singleNumber(nums1);
    cout << ret;
    ret = sln.singleNumber(nums2);
    cout << ret;
    ret = sln.singleNumber(nums3);
    cout << ret;
}

class Solution {
public:
    bool isHappy(int n) {

    }
};

void test_isHappy() {

}