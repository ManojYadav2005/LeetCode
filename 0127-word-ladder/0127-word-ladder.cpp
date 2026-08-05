// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//      queue<pair<string,int>>q;
//      q.push({beginWord,1});
//      unordered_set<string> st(wordList.begin(),wordList.end());
    
//      st.erase(beginWord);

//      while(!q.empty()){
//         string word=q.front().first;
//         int steps=q.front().second;

//         q.pop();

//         if(word==endWord) return steps;

//         for(int i=0;i<word.size();i++){
//         char original=word[i]; // maan lo i=1. pr hit= ka original=i=1=i hoga word[1]=i

//         for(char ch='a';ch<='z';ch++){
//         word[i]=ch; // word[1]=a,b,c,,d,e,f,g,...
//         if(st.find(word) !=st.end()){
//         st.erase(word);
//         q.push({word,steps+1}); }
//         }
//         word[i]=original; // original ko store kr lo,kyuki word change hua hoga ...
//         } 

//      }
//      return 0;

//     }
// };




























class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    unordered_set<string>st(wordList.begin(),wordList.end());
    
    st.erase(beginWord);
    
    while(!q.empty()){
    string word=q.front().first;
    int steps=q.front().second;
    
    q.pop();

    if(word==endWord) return steps;

    for(int i=0;i<word.size();i++){
      
    int original=word[i];
    for(char ch='a';ch<='z';ch++){
    
    word[i]=ch;
    if(st.find(word)!=st.end()){
    st.erase(word);
    q.push({word,steps+1});}
    }
    word[i]=original;
    }
    }
    return 0;
    }
};