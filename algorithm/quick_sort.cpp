 #include<iostream>
 using namespace std;
 void quick_sort(int a[],int l,int r)
 {
    if(l >= r)
    {
        return;
    }
     int mid = a[(l+r)>>1];
     int i=l,j=r;
     while(i<j)
    {
        while(a[i]<mid)i++;
        while(a[j]>mid)j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    quick_sort(a,l,j);
    quick_sort(a,i,r);
 }
 
 int main()
 {
     int num;
    const int N = 100004;
    int a[N];
     cin>>num;
     for(int i = 0;i<num;i++)
     {
         cin>>a[i];
     }
     quick_sort(a,0,num-1);
     for(int i = 0;i<num;i++)
     {
         cout<<a[i]<<" ";
     }
     cout<<endl;
     return 0;
 }
