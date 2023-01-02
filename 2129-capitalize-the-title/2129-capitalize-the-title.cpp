class Solution {
public:
    string capitalizeTitle(string title) {
        
        title += " ";
        int i = 0 , n = title.length();
        
        while(i<n)
        {
            int prev = i;
            while(i<n && title[i] != ' ')
            {
                title[i] = tolower(title[i]);
                i++;
            }
            
            if(i-prev > 2)
            {
                title[prev] = toupper(title[prev]);
            }
            
            i++;
        }
        
        
        title.pop_back();       
        
        return title;
        
    }
};