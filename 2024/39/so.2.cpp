class Solution {
public:
    void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(state);
            return;
        }
        for (int i = start; i < choices.size(); ++i) {
            if (target - choices[i] < 0) {
                break;
            }

            state.push_back(choices[i]);
            backtrack(state, target - choices[i], choices, i, res);
            state.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> state;
        sort(candidates.begin(), candidates.end());
        int start = 0;
        vector<vector<int>> res;
        backtrack(state, target, candidates, start, res);
        return res;
    }
};