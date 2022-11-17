class Solution {
public:
    int maximum69Number (int num) {


        string curr = to_string(num);

        for(auto &it:curr)
        {
            if(it == '6')
            {
                it = '9';
                break;
            }
        }

        num = stoi(curr);


        return num;
        
    }
};