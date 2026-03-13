class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result){
        if(start == s.length()){
            result.push_back(path);
            return;
        }

        for(int end = start; end < s.length(); ++end){
            if(isPalindrome(s, start, end)){
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int low, int high){
        while(low < high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
};
