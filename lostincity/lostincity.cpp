#include<iostream>
#include<vector>
using namespace std;


vector<vector<char> > rotate(vector<vector<char> > &ori)
{
    vector<vector<char> > ans = ori;
    int n = ori.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-1-i] = ori[i][j];
        }
    }
    return ans;

}

bool match(vector<vector<char> > &map,vector<vector<char> > &sur,int x,int y)
{
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(map[x+i][y+j]!=sur[i+1][j+1])
                return false;
        }
    }
    return true;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char> > map(m,vector<char>(n));
    vector<vector<char> > sur(3,vector<char>(3));

    vector<vector<char> > r90;
    vector<vector<char> > r180;
    vector<vector<char> > r270;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>sur[i][j];
        }
    }
    r90=rotate(sur);
    r180=rotate(r90);
    r270=rotate(r180);
    char c = sur[1][1];
    vector<pair<int,int> > potential;
    for(int i=1;i<m-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(map[i][j]==c)
                potential.push_back(pair<int,int>(i,j));
        }
    }
   // vector<pair<int,int> > ans;
    int sz=potential.size();
    for(int i=0;i<sz;i++)
    {
        if(match(map,sur,potential[i].first,potential[i].second)||
            match(map,r90,potential[i].first,potential[i].second)||
            match(map,r180,potential[i].first,potential[i].second)||
            match(map,r270,potential[i].first,potential[i].second)
            )
            cout<<potential[i].first+1<<" "<<potential[i].second+1<<endl;
    }


    return 0;

}
