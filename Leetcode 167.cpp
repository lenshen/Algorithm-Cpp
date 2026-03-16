class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = n-1,r = 0;
        while(l > r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){return {r+1,l+1};}
            else if(sum > target){l--;}
            else {r++;}
        }
        return {};
    }
};
