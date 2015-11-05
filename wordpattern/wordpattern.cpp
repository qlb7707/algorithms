#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


bool judge(string p,string str)
{
    istringstream is(str);
    string s;
    vector<string> vs;
    map<char,string> mp;
    int n = p.size();
    while(is>>s)
    {
        vs.push_back(s);
    }
    if(vs.size()!=n) return false;
    for(int i=0;i<n;i++)
    {
        mp[p[i]]="";
    }
    for(int i=0;i<n;i++)
    {
        if(mp[p[i]]!=""&&mp[p[i]]!=vs[i])
            return false;
        if(mp[p[i]]==""&&find_if(mp.begin(),mp.end(),[vs,i](pair<char,string> p){return p.second==vs[i];})!=mp.end())
            return false;
        if(mp[p[i]]=="")
            mp[p[i]]=vs[i];
    }
    return true;
}


int main()
{
    string p;
    string str;
    getline(cin,str);
    cin>>p;
    cout<<p<<endl<<str<<endl;
    cout<<judge(p,str)<<endl;
    return 0;
}
