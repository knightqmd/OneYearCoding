#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// int largestRectangleArea(vector<int>& heights) {
//         int max = 0;
//         for(int i = 0;i<heights.size();i++)
//         {
//             int count = 0;
//             int limit = heights[i];
//             for(int j = i;j>=0;j--)
//             {
//                 count++;
//                 if(heights[j]<limit)
//                 {
//                     limit = heights[j];
//                 }
//                 int size = limit*count;
//                 if(size>max)max=size;
//             }
//         }
//         return max;
//     }
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        stack<pair<int,int>> stk;
        stk.push(make_pair(-1,-1));
        for(int i=0;i<heights.size();i++)
        {

            if(stk.empty())stk.push(make_pair(heights[i],i));
            if(heights[i]>stk.top().first)stk.push(make_pair(heights[i],i));
            if(heights[i]==stk.top().first)
            {
                stk.pop();
                stk.push(make_pair(heights[i],i));
            }
            if(heights[i]<stk.top().first)
            {
                while(!stk.empty()&&heights[i]<stk.top().first)
                {
                    pair<int,int> temp = stk.top();
                    stk.pop();
                    int size = temp.first*(i-stk.top().second-1);
                    if(size>max)max=size;
                }
                if(stk.top().first<heights[i])
                stk.push(make_pair(heights[i],i));
            }
        }

        while(!stk.empty())
        {
            if(stk.size()==1)
            {
                int size = heights.size()*stk.top().first;
                if(size>max)max = size;
                break;
            }
            pair<int,int> temp = stk.top();
            stk.pop();
            int size = temp.first*(heights.size()-stk.top().second-1);
            if(size>max)max=size;
        }
        return max;
    }
int main()
{
    vector<int> height={1,0,0,1,0,1,0,0,0,1};
    int x;
    int max = largestRectangleArea(height);
    cout<<max<<endl;

    system("pause");
    return 0;
}