class Solution {
public:
    void add_helper(string num, int target, vector<string>& ans, string expr, long long prev, long long curr, int index) {
        if (index == num.length()) {
            if (curr == target)
                ans.push_back(expr);
            return;
        }

        for (int i = index; i < num.length(); i++) {
            // Handle leading zero case
            if (i != index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long long val = stoll(part);

            if (index == 0) {
                add_helper(num, target, ans, part, val, val, i + 1);
            } else {
                add_helper(num, target, ans, expr + '+' + part, val, curr + val, i + 1);
                add_helper(num, target, ans, expr + '-' + part, -val, curr - val, i + 1);
                add_helper(num, target, ans, expr + '*' + part, prev * val, curr - prev + prev * val, i + 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string expr = "";
        add_helper(num, target, ans, expr, 0, 0, 0);
        return ans;
    }
};
