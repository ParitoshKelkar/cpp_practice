class Solution {
public:
    string decodeAtIndex(string S, int K) {
        
        std::vector<char> decoded_string;
        // loop through input S 
        for  (char c : S)
        {
            // check ascii codes- if digit 
            if (int(c) > 49 && int(c) < 58)
            {
                std::vector<char> current_vec = decoded_string;
                int reps = int(c) - int('0') -1;
                while (reps > 0)
                {
                    decoded_string.insert(decoded_string.end(), current_vec.begin(), current_vec.end());
                    reps--;
                }
                
            }
            
            // if letter, lowercase 
            else if (int(c) > 96 && int(c) < 123)
                decoded_string.push_back(c);
            else
            {
                cout<<"Invalid char; <char, ascii> = <"<<c<<","<<int(c)<<">\n";
                exit(1);
            }
            
        }
        string temp_s(1,decoded_string[K-1]);
        
        return temp_s;
        
    }
};
