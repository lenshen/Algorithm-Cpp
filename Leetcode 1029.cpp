class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.begin()+n);
        vector<pair<int,int> >re;
        for(int i=0;i<n;i++){
            re.push_back({costs[i][1] - costs[i][0], i});
        }
        sort(re.begin(), re.begin()+n);
        int ans=0;
        for(int i=0;i<n/2;i++) ans += costs[re[i].second][1];
        for(int i=n/2;i<n;i++) ans += costs[re[i].second][0];
        return ans;
    }
};
