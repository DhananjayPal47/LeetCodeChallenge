class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m));
        
        int freshCount = 0;

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else visited[i][j] = 0;

                if(grid[i][j]==1)
                    freshCount++;
            }
        }

        int time = 0;
        int cnt=0;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;

            time = max(time,t);

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 
                   && grid[nrow][ncol]==1){
                   q.push({{nrow,ncol},t+1});
                   visited[nrow][ncol] = 1;
                   cnt++;
                }
            }


        }
        if(cnt!=freshCount) return -1;
        else return time;
        
    }
};