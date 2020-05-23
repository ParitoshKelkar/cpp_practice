class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans_string(num.size() - k,'0');
        int orig_string_iter1 = 0;
        int orig_string_iter2 = 1;
        int new_string_iter = 0;
        while (k !=0)
        {
            int curr_char = int(num[orig_string_iter1])-int('0'); int next_char = int(num[orig_string_iter2]) - int('0');
            std::cout<<"Curr string int:"<<curr_char<<"; Next string int="<<next_char<<"\n";
            if (curr_char <= next_char)
            {
                ans_string[new_string_iter]=char(curr_char+48);
                new_string_iter++;
                orig_string_iter2+=1;
            }
            else
            {
                ans_string[new_string_iter]=char(curr_char+48);
                orig_string_iter1+=1;
                new_string_iter++;
            }
            std::cout<<"Curr char:"<<char(curr_char+48)<<"; Next char="<<char(next_char+48)<<"\n";
            std::cout<<"Curr orig iter:"<<orig_string_iter2<<"\n";
            k--;
        }
        return ans_string;
    }
};
