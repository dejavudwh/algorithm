class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        vector<bool> flag(128, true);

        for (int i = 0; i < t.size(); i++) {
            flag[t[i]] = true;
            ++chars[t[i]];
        }

        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        bool found = false;
        for (int r = 0; r < s.size(); ++r) {
            // 往右移动
            if (flag[s[r]]) {
                if (--chars[s[r]] >= 0) {
                    cnt++;
                }
            }

            // 满足条件下，将l右移，看是否能找出更优结果
            while (cnt == t.size()) {
                if (r - l + 1 < min_size) {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[s[l]] && ++chars[s[l]] > 0) {
                    --cnt;
                }
                ++l;
            }
        }
    
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};