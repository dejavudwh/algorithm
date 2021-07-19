class Solution {
public:
    // 贪心问题：每次都放置一个正确的位置
    // 根据hi进行降序排序，相同则按ki升序
    // 遍历，根据ki插入指定位置，这个位置有人即往后退
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
      
        vector<vector<int>> ans;
        for (const vector<int>& person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};