class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        //mp will stoe the sorted str and all the corresposing str that matches the str
        unordered_map<string,vector<string>>mp;

        for(auto w : strs)
        {
            string word = w;
            sort(word.begin(),word.end());

            mp[word].push_back(w);
        }

        //now put all the grouped anangram to arr
        for(auto word: mp)
        {
            ans.push_back(word.second);
        }

        return ans;


    }
};