#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:

    bool static find(std::vector<char> v, char s){
        
        for(int i = 0; i < v.size(); i++){
            if(v[i] == s)
                return true;
        }
        return false;

    }
    int static lengthOfLongestSubstring(std::string s) {
        
        std::vector<char> charvector;
        int sol = 0;

        for(int i = 0; i < s.length(); i++){
            while(Solution::find(charvector, s[i]) == true){
                charvector.erase(charvector.begin());
            }

            charvector.push_back(s[i]);
            
            sol = (sol < charvector.size())? charvector.size(): sol; 
            
        }
        return sol;
    }

    int static pritnss(std::vector<char> s){
        
        for(int i = 0; i < s.size(); i++){
            std::cout << s[i];
        }
        
    }
};

int main(){
    std::cout << Solution::lengthOfLongestSubstring("pwwkew");
    
}