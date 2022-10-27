 #include <iostream>
 #include <vector>
 using namespace std;
//  int candy(vector<int>& ratings) {
//         int size = ratings.size();
//         vector<int> nums(size,1);
//         int i = 0,j = 1;
//         for(j;j<size;j++)
//         {
//             if(ratings[j]>ratings[j-1])
//             {
//                 nums[j] = nums[j-1]+1;
//                 int k = j-1;
//                 int start = nums[k];
//                 for( k;k>i;k--)
//                 {
//                     nums[k] = start;
//                     start++;
//                     if(k<size-1&&ratings[k] == ratings[k+1])
//                     {
//                         nums[k] = 1;
//                         start = 2;
//                     }
//                 }
//                 if(nums[i]<start)
//                 {
//                     nums[i] = start;
//                 if(ratings[i] == ratings[i+1])
//                 {
//                     if(i==0)
//                     {
//                         nums[i] = 1;
//                     }
//                     else{
//                         nums[i] = nums[i-1]+1;
//                     }
//                 }
//                 }
//                 i = j;
//             }
//         }
//         if(i<size-1)
//         {
//             int k = size-1;
//             int start = nums[k];
//             for(k;k>i;k--)
//             {
//                 nums[k] = start;
//                 start++;
//                 if(k<size-1&&ratings[k] == ratings[k+1])
//                 {
//                     nums[k] = 1;
//                     start = 2;
//                 }
//             }
//             if(nums[i]<start)
//             {
//                 nums[i] = start;
//                 if(ratings[i] == ratings[i+1])
//                 {
//                     if(i==0)
//                     {
//                         nums[i] = 1;
//                     }
//                     else{
//                         nums[i] = nums[i-1]+1;
//                     }
//                 }
//             }
//         }
//         int sum = 0;
//         for(int t = 0;t<size;t++)
//         {
//             sum+=nums[t];
//         }
//         return sum;
//     }
int candy(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> left(size,1);
    vector<int> right(size,1);
    for(int i = 0;i < size; i++)
    {
        if(i>0&&ratings[i]>ratings[i-1])
        {
            left[i] = left[i-1]+1;
        }else left[i] = 1;
    }
    for(int i = size-1;i>=0;i--)
    {
        if(i<size-1&&ratings[i]>ratings[i+1])
        {
            right[i] = right[i+1]+1;
        }else right[i] = 1;
    }
    int sum = 0;
    for(int i = 0; i<size;i++)
    {
        sum+=max(left[i],right[i]);
    }
    return sum;
}
    int main()
    {
        vector<int> ratings = {1,0,2};
        candy(ratings);
        return 0;
    }