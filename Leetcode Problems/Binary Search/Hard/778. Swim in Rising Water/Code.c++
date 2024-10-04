class Solution {
public:
    int n,m;
    vector<vector<int>>dir{{-1,0} , {0,1} , {1,0} , {0,-1}}; //{rowOffset , colOffset}
    int swimInWater(vector<vector<int>>& grid) {
         n = grid.size(); m = grid[0].size();

         int ans = INT_MAX;
         int start = 0;
         int end   = INT_MAX;
         while(start <= end){
            int mid = (0LL + start + end)/(1LL * 2);
            if(bfs(mid,grid) == true) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
         }
         return ans;
    }
    bool isValid(int row , int col){
        if(row >= 0 and row < n  and col >=0 and col < m)
        return true;

        return false;
    }
     bool bfs(int &mid , vector<vector<int>>&arr){
         vector<vector<bool>>vis(arr.size(),vector<bool>(arr[0].size(),false));
         queue<pair<int,int>>q;
         if(arr[0][0] <= mid) {
            q.push({0,0});
            vis[0][0] = true;
         }
         while(!q.empty()){
             auto p = q.front(); q.pop();
             int row = p.first;
             int col = p.second;

             if(row == arr.size()-1 and col == arr[0].size()-1) return true;

             for(int i = 0 ; i < dir.size() ; i++){
                   if(isValid(row+dir[i][0] , col+dir[i][1]) == true and vis[row+dir[i][0]][col+dir[i][1]] == false and arr[row+dir[i][0]][col+dir[i][1]] <= mid){
                        q.push({row+dir[i][0],col+dir[i][1]});
                        vis[row+dir[i][0]][col+dir[i][1]] = true;
                   }
             }         
         }
         return false;
    }
};
