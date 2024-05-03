class Solution {
    vector<string> result;

    void backtracking(string& s, int start_idx, int point_num) {
        if (point_num == 3) {
            if (isValid(s, start_idx, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = start_idx; i < s.size(); ++i) {
            if (isValid(s, start_idx, i)) {
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                backtracking(s, i + 2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
        }
    }

    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }

        if (s[start] == '0' && start != end) {
            return false;
        }

        int num = 0;
        for (int i = start; i <= end; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};
