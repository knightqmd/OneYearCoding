#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    int size = nums.size();
        //首先确定k的值
        int k;
        int fi = 0,fj =size;
        while(fi!=fj)
        {
            if(nums[(fi+fj)>>1]<=nums[fi])
            {
                fj = (fi+fj)>>1;
            }
            else{
                fi = (fi+fj)>>1;
            }
        }
        //进行2分查找
        int bias = fi+1;
        int i = bias;
        int j = size+bias-1;
        while(i<j)
        {
            if(i == j-1&&nums[i%size]!=target&&nums[j%size]!=target)
            {
                return -1;
            }
            if(i == j-1&&nums[i%size]==target)
            {
                return i%size;
            }
            if(i == j-1&&nums[j%size]==target)
            {
                return j%size;
            }
            
            if(nums[((i+j)>>1)%size]>target)
            {
                j=(i+j)>>1 ;
            }
            if(nums[((i+j)>>1)%size]<target)
            {
                i = (i+j)>>1;
            }
            if(nums[((i+j)>>1)%size]==target)
            {
                return ((i+j)>>1)%size;
            }

        }
        if(nums.size()==1&&nums[0] == target)
        {
            return 0;
        }
        return -1;
    }
};

    int main()
    {
        vector<int> nums = {1,3};
        cout<<search(nums,1)<<endl;
        return 0;

    }