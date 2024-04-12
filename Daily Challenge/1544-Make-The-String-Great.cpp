//Approach 1
class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;
        
        for (char c : s) {
            if (!stack.empty() && abs(c - stack.top()) == 32) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        
        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};

//Approach 2
class Solution {
public:
    string makeGood(string s) 
    {
        string res;
        for (char c : s) {
            if (!res.empty() && (toupper(c) == toupper(res.back())) && (c - res.back() != 0)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};
