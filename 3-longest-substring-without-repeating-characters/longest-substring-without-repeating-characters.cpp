class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int hashlen= 256;
       int hash[hashlen];
       int maxlen=0;
       for (int i = 0 ;i< hashlen;i++){
        hash[i]=-1;
       }
       int l=0,r=0;
       while(r<n){
       if (hash[s[r]]!=-1){
        l = max(hash[s[r]]+1,l);

       }
       int len = r-l +1;
       maxlen=max(len,maxlen);
       hash[s[r]]=r;
       r++;

       }
       return maxlen;

    }
};