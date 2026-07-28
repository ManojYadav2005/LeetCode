class Solution {
public:
    string smallestPalindrome(string s) {
    map<char,int>mpp;

    for(auto it:s){
    mpp[it]++;
    }

    string left="";
    string middle="";

    
    for(auto it:mpp){
    char ch=it.first;
    int freq=it.second;
    
    left.append(freq/2,ch);
    if(freq%2==1){
    middle=ch;
    }
    
    }
    string rght=left;
    reverse(rght.begin(),rght.end());
    return left+middle+rght;

    }
};