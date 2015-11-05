#include<iostream>
#include<vector>
using namespace std;


vector<int> compute_pi(const string pattern);

//class KMP
//{
//    public:
//        explicit KMP(const string str):pattern(str){init_pi();}
//        int matchn(const string str);
//        void display_pi();
//    private:
//        void init_pi();
//        const string pattern;
//        vector<int> pi;
//};
//
//
//int KMP::matchn(const string str)
//{
//    int n = str.size();
//    int m = pattern.size();
//    init_pi();
//    int q = -1;
//    int cnt = 0;
//    for(int i = 0; i < n; i++)
//    {
//        while(q >= 0 && pattern[q+1] != str[i])
//        {
//            q = pi[q];
//        }
//        if(pattern[q+1] == str[i])
//        {
//            q++;
//        }
//        if(q == m-1)
//        {
//            cnt++;
//            q = pi[q];
//        }
//    }
//
//    return cnt;
//
//}
//
//void KMP::display_pi()
//{
//    if(pi.empty())
//    {
//        cout<<"next array empty!"<<endl;
//        return;
//    }
//    int n = pi.size();
//    for(int i = 0;i < n;i++)
//    {
//        cout<<pi[i]<<" ";
//    }
//    cout<<endl;
//    return;
//}
////pattern[0]-pattern[pi[i]] is the longest prefix of pattern which is also a suffix
////of pattern[0]-pattern[i].
////the case pi[i] = i is exclusive.
//void KMP::init_pi()
//{
//    int n = pattern.size();
//    pi = vector<int> (n);
//    pi[0] = -1;
//    int k = -1;
//    for(int q = 1;q < n;q++)
//    {
//        while(k >= 0 && pattern[k+1] != pattern[q])
//        {
//            k = pi[k];
//        }
//        if(pattern[k+1] == pattern[q])
//        {
//            k++;
//        }
//        pi[q] = k;
//    }
//}

int KMP_match_count(const string str, const string pattern)
{
    
    int n = str.size();
    int m = pattern.size();
    vector<int> pi;
    pi = compute_pi(pattern);
    int q = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        while(q >= 0 && pattern[q+1] != str[i])
        {
            q = pi[q];
        }
        if(pattern[q+1] == str[i])
        {
            q++;
        }
        if(q == m-1)
        {
            cnt++;
            q = pi[q];
        }
    }

    return cnt;
}

vector<int> compute_pi(const string pattern)
{
    int n = pattern.size();
    vector<int> pi(n);
    pi[0] = -1;
    int k = -1;
    for(int q = 1;q < n;q++)
    {
        while(k >= 0 && pattern[k+1] != pattern[q])
        {
            k = pi[k];
        }
        if(pattern[k+1] == pattern[q])
        {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

int main()
{
   /* KMP k1("HA");
    KMP k2("WQN");
    KMP k3("ADA");
    cout<<k1.matchn("HAHAHA")<<endl
        <<k2.matchn("WQN")<<endl
        <<k3.matchn("ADADADA")<<endl;*/
    int cases;
    string s,p;
    cin>>cases;
    vector<int> ans;
    for(int i = 0;i < cases;i++)
    {
        cin>>p>>s;
        ans.push_back(KMP_match_count(s,p));
    }

    int n = ans.size();
    for(int i=0; i < n;i++)
    {
        cout<<ans[i]<<endl;
    }


    return 0;
}
