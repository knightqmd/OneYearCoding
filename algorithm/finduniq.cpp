#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<vector<char>> lines;
vector<int> result;

bool match(vector<char> fir,vector<char> sec)
{
    for(int i =0;i<32;i++)
    {
        if(fir[i] != sec[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream f;
    f.open("data.txt",ios::in);
    if(!f.is_open())
    {
        cout<<"fail"<<endl;
        return 0;
    }
    char temp[64];
    while(f.getline(temp,sizeof(temp)))
    {
        vector<char> temp2;
        for(int i =0;i<32;i++)
        {
            temp2.push_back(temp[i]);
        }
        lines.push_back(temp2);
    }
    for(auto i =0;i<lines.size();i++)
    {
        int count = 0;
        for(int j = 0;j<lines.size();j++)
        {
            if(match(lines[i],lines[j]))
            {
               count++;
            }
        }
        result.push_back(count);
    }
    for(int i = 0;i<result.size();i++ )
    {
        if(result[i] == 1)
        {
            for(auto j =0;j<32;j++)
            {
                cout<<lines[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}