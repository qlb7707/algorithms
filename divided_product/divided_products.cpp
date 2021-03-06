#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int vals;
    int sum;
    int product;
};

int main()
{
    int n,m;
    cin>>n>>m;
    node init;
    int cnt = 0;
    init.vals=0;
    init.product = 1;
    init.sum = 0;
    vector<node> layer;
    vector<node> next;
    layer.push_back(init);
    while(!layer.empty())
    {
        int sz = layer.size();
        for(int i = 0;i < sz;i++)
        {
            int min = layer[i].vals;
            for(int j = min+1;j <= n-layer[i].sum;j++)
            {
                if(j + layer[i].sum > n)
                    break;
                if(j + layer[i].sum == n)
                {
                    if((j*layer[i].product)%m == 0)
                        cnt++;
                    break;
                }
                node new_node=layer[i];
                new_node.vals=j;
                new_node.sum += j;
                new_node.product = new_node.product*j%m;
                next.push_back(new_node);
            }
        }
        layer=next;
        next.clear();
    }
    cout<<cnt<<endl;


    return 0;
}
