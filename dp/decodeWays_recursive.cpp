class Solution {
public:
    int numDecodings(string s) {
      
      int decode_ptr = 0;
      int hist[s.length()]=0;
      int ans = 0;
      getDecodeWays(s,decode_ptr,hist,ans);
        
    }
  
    void getDecodeWays(string s, int decode_ptr, int[] hist, int& ans)
    {
      if (decode_ptr > s.length()-1){
        ans=ans+1;
        return;
      }
      
      if(hist[decode_ptr]!=-0)
      {
        ans = ans + hist[decode_ptr];
        return;
      }
      // if one split is possible
      if isValid(s[decode_ptr])
      {
        int temp_ans = ans;
        getDecodeWays(s, decode_ptr+1, hist, ans)
        hist[decode_ptr+1] = ans-temp_ans;
       }
      
      if (isValid(s.substr(decode_str,decode_str+1)))
      {
        int temp_ans = ans;
        getDecodeWays(s, decode_ptr+2, hist, ans)
        hist[decode_ptr+2] = ans-temp_ans;
      }
    }
};
