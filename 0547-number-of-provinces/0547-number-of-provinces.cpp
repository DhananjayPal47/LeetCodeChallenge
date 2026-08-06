class Solution {
    private:
        void dfs(int node, vector<vector<int>> &adjLs, vector<int> &visited){
            visited[node] = 1;
            for(auto it : adjLs[node]){
                if(!visited[it])
                    dfs(it, adjLs, visited);
            }
        }
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);

        //to change adjacent matrix to list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i, adjLs, visited);
            }
        }
        return count;
}
        
    
};