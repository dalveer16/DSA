class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(), m=land[0].size();
        vector<vector<int>> vis(n, vector<int>(m)), ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==1 || land[i][j]==0)continue;
                int a=i, b=j,c=i,d=j;
                while(d<m && land[a][d]==1)d++;
                d--;
                while(c<n && land[c][b]==1)c++;
                c--;
                ans.push_back({a,b,c,d});
                for(int x=a; x<=c; x++){
                    for(int y=b; y<=d; y++)vis[x][y]=1;
                }
                j=d;
            }
        }
        return ans;
    }
};
