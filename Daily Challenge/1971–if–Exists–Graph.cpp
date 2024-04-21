class DisjointSet
{
    vector<int> parent;
    vector<int> size;

    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);

        if(ulp_u==ulp_v)
        {
            return;
        }

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        DisjointSet ds(n);

        for(auto i: edges)
        {
            int u=i[0];
            int v=i[1];

            ds.unionBySize(u, v);
        }

        if(ds.findUParent(source)==ds.findUParent(destination))
        {
            return true;
        }

        return false;
    }
};
