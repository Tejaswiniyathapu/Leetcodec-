class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
      if(n==0){
        return " ";
      }
      int start=0;
      int maxlen=1;
      auto expand = [&](int left,int right){
        while(left>=0 && right<n &&s[left]==s[right] ){
            if(right-left+1>maxlen){
                maxlen=right-left+1;
                start=left;
            }
            left--;
            right++;
        }

      };
      for (int i=0;i<n;i++){
        expand(i,i);


        expand(i,i+1);
      }
      
 return s.substr(start, maxlen);

    }
};