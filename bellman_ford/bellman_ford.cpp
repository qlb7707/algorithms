/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :bellman_ford.cpp
*   author       :qinlibin
*   create date  :2016/06/09
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "bellman_ford.h"
#include<iostream>
#include<vector>
#define INF 999999
#define NIL -1
using namespace std;

struct vetex
{
    int d;
    int pi;
};

void init_single_source(vector<vetex> &V,int s)
{
    int n = V.size();
    for(int i = 0; i < n; i++)
    {
        V[i].d = INF;
        V[i].pi = NIL;
    }
    V[s].d = 0;

}

void relax(vector<vetex> &V,int u,int v,vector<vector<int> > &w)
{
    if(V[v].d > V[u].d + w[u][v])
    {
        V[v].d = V[u].d + w[u][v];
        V[v].pi = u;
    }
}

bool bellman_ford(vector<vetex> &V,vector<vector<int> > &w, int s)
{
    init_single_source(V,s);
    int n = V.size();
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(w[j][k] < INF)
                {
                    relax(V,j,k,w);
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(V[j].d > V[i].d + w[i][j])
            {
                return false;
            }
        }
    }

    return true;

}

int main()
{
    int nv,ne;
    int src,dst,w;
    int s,d;
    cout<<"input vetex number & eage number"<<endl;
    cin>>nv>>ne;
    vector<vector<int> > adj_mat(nv,vector<int>(nv,INF));
    vector<vetex> vetexes(nv);
    cout<<"input "<<ne<<" eages"<<endl;
    for(int i = 0; i < ne; i++)
    {
        cin>>src>>dst>>w;
        adj_mat[src][dst] = w;
    }
    cout<<"source & destination"<<endl;
    cin>>s>>d;
    int st = d;
    if(bellman_ford(vetexes,adj_mat,s))
    {
        cout<<"shortest path from "<<s<<" to "<<d<<" has length of "<< vetexes[d].d<<endl;
        cout<<"the reversed path is:"<<endl;
        do
        {
            cout<<st<<"<--";
            st = vetexes[st].pi;

        }while(st != NIL);
        cout<<"NIL"<<endl;
        
    }
    else
    {
        cout<<"There is a negative wight cycle!"<<endl;
        return -1;
    }

    return 0;
}
