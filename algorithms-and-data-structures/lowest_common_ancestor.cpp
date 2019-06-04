#include <vector>
#include <iostream>
using namespace std;


class LCA
{
public:
    LCA(int root, const vector<int> &tree, const vector<int> &level)
        : root(root),level(level), tree(tree)
    {
        initialize();
        preprocess();
    }

    LCA(int root, const vector<int> &tree)
        : root(root), tree(tree)
    {
        initialize();
        compute_levels();
        preprocess();
    }
    
    size_t query(int p, int q)
    {
        size_t log;
        if(level[p] < level[q])
            swap(p,q);

        for(log = 0; (1 << log) <= level[p]; log++);

        for(int i = log; i >= 0; i--)
        {
            if(level[p] - (1 << i) >= level[q])
            {
                p = lca_pre[p][i];
            }
        }

        if(p == q)
            return p;

        for(int i = log; i >= 0; i--)
        {
            if(lca_pre[p][i] != lca_pre[q][i])
            {
                p = lca_pre[p][i];
                q = lca_pre[q][i];
            }
        }
        return tree[p];
    }

private:
    void initialize()
    {
        size_t logn = 1;
        size_t p = 1;

        tree[root] = -1;

        while(p <= tree.size())
        {
            p *= 2;
            logn++;
        }

        lca_pre.resize(tree.size());

        for(size_t i = 0; i < lca_pre.size(); i++)
        {
            lca_pre[i].resize(logn, root);
        }
    }

    void preprocess()
    {
        for(size_t i = 0; i < lca_pre.size(); i++)
        {
            lca_pre[i][0] = tree[i];
        }
        size_t logn = lca_pre[0].size();
        for(size_t p = 1; p < logn; p++)
            for(size_t i = 0; i < lca_pre.size(); i++)
            {
                if(lca_pre[i][p-1] >= 0)
                {
                    lca_pre[i][p] = lca_pre[lca_pre[i][p-1]][p-1];
                }
                else
                {
                    lca_pre[i][p] = root;
                }
            }
    }

    //Careful!, this might cause stack overflows
    void compute_levels()
    {
        level.resize(tree.size(),0);
        level[root] = 1;
        for(size_t i = 0; i < tree.size(); i++)
            if(level[i] == 0)
                dfs(i);
    }

    void dfs(int v)
    {
        if(v < 0 || level[v] > 0)
            return;
        if(level[v] == 0)
            dfs(tree[v]);
        level[v] = level[tree[v]]+1;
    }

    int root;
    vector<int> level; //level[i] = length of path from root to i
    vector<int> tree; //tree[i] = father of node i
    vector<vector<int> > lca_pre;
};


int main()
{
    vector<int> tree(9,0);
    tree[0] = 0;
    tree[1] = 0;
    tree[2] = 1;
    tree[3] = 2;
    tree[4] = 2;
    tree[5] = 1;
    tree[6] = 5;
    tree[7] = 5;
    tree[8] = 5;
    LCA lca(0, tree);

    cout << lca.query(2,5) << endl;
    cout << lca.query(1,2) << endl;
    cout << lca.query(6,7) << endl;
    cout << lca.query(6,8) << endl;
    cout << lca.query(1,1) << endl;
}

