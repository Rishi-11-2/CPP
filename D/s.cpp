#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverse(vector<int> &nums, int low, int high)
    {
        while (low < high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = abs(k - n);
        k = k % n;
        if (k < n)
        {
            reverse(nums, n - k, n - 1);
            reverse(nums, 0, n - k - 1);
            reverse(nums, 0, n - 1);
        }
        else
        {
            int d = (k - n) % n;
            reverse(nums, n - d, n - 1);
            reverse(nums, 0, n - d - 1);
            reverse(nums, 0, n - 1);
        }
    }
};