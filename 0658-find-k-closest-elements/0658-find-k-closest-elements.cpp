class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;

        int n = arr.size();
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty()){
            int closest = pq.top().second;
            result.push_back(closest);
            pq.pop();
        }

        sort(result.begin(),result.end());

        return result;
    }
};