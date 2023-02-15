class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        map<int,int> cou;
        vector<int> ret;
        for(int i:nums){
            cou[i]++;
        }
        for(int i = 0;i < nums.size();i++){
            if(cou[nums[i]] == 1){
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};