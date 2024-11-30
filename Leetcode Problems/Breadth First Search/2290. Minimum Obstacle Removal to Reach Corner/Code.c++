class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        set<vector<int>>st;
        if(grid[0][0]==1)
            st.insert({1,0,0});
        else
            st.insert({0,0,0});
        vis[0][0]=true;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        while(!st.empty())
        {
            vector<int>temp=*(st.begin());
            st.erase(temp);
            if(temp[1]==m-1 and temp[2]==n-1)
                return temp[0];
            
            for(int i=0;i<dir.size();i++)
            {
                int r=temp[1]+dir[i][0];
                int c=temp[2]+dir[i][1];
                int obs=temp[0];
                if(r>=0 and c>=0 and r<m and c<n)
                {
                    if(vis[r][c]==false)
                    {
                        vis[r][c]=true;
                        if(grid[r][c]==1)
                        {
                            st.insert({r,c,obs+1});
                        }
                        else
                        {
                            st.insert({r,c,obs});
                        }
                    }
                }
            }
        }
    }
};
