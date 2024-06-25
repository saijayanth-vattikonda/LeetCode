class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // int left= 0;
        // unordered_set<char> st;
        // int maxLen = 0;
        // for(int right=0;right<n;right++){
        //     if(st.find(s[right]) != st.end()){
        //         while(left<right && st.count(s[right])){
        //             st.erase(s[left]);
        //             left++;
        //         }
        //     }
        //     st.insert(s[right]);
        //     maxLen = max(maxLen,right-left+1);
        // }
        // return maxLen;

        vector<int> mp(256,-1);
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while(right<n){
            if(mp[s[right]] != -1){
                left = max(left,mp[s[right]]+1);
            }   
            mp[s[right]] = right;
            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};