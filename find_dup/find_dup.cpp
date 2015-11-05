#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int find_dup(vector<int> &array)
{
    int n = array.size();
    vector<int> tmp = array;
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<n-1;i++)
    {
        if(tmp[i]==tmp[i+1])
            return tmp[i];
    }
    return 0;
}

int find_dup_binary_search(vector<int> &array)
{
    int low = 1;
    int n = array.size();
    int high = array.size()-1;
    int mid;
    int ans = 0;
    while(low<high)
    {
        mid = (low + high)/2;
        int cnt = 0;
        for(int i = 0;i < n; i++)
        {
            if(array[i]<=mid)
                cnt++;
        }
        if(cnt > mid)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    if(high==low)
        ans=low;
    return ans;
    
}



int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++)
    {
        cin>>v[i];
    }

    cout<<find_dup_binary_search(v)<<endl;
    return 0;

}
