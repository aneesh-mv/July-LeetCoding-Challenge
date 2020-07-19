.
/*
Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

*/
class Solution {
public:
    string reverseWords(string s) {
       int write_idx = 0;
       int space_count = 1; // for the case when space is present in the begining of the string
       // Moving all the extra space to the end of string
       for (int i = 0; i< s.size(); ++i){
           if (s[i] != ' '){
               s[write_idx++] = s[i];
               space_count = 0;
           }// only single space need to be added in the result
           else if (!space_count){
                s[write_idx++] = s[i];
                ++space_count;
           }
       }      
       // specail case when one space is left  
       if (write_idx && s[write_idx - 1] == ' ') --write_idx;
        
	  // removing all the extra space moved to the end of string	
       s.erase(s.begin() + write_idx, s.end()); 
        
       reverse(s.begin(), s.end());
       int  start = 0,end;
        
       while((end = s.find(" ", start)) != string::npos){
            reverse(s.begin()+ start, s.begin()+end);
            start = end + 1;
       }
       reverse(s.begin() + start, s.end());
       return s;
     }
};
