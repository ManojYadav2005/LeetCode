class Solution {
public:

    vector<vector<string>> ans;


    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path) {

        if(word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }


        for(auto p : parent[word]) {

            path.push_back(p);

            dfs(p, beginWord, parent, path);

            path.pop_back();
        }
    }


    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {


        unordered_set<string> st(wordList.begin(), wordList.end());


        if(st.find(endWord) == st.end())
            return {};


        unordered_map<string, vector<string>> parent;


        queue<string> q;
        q.push(beginWord);


        unordered_set<string> visited;
        visited.insert(beginWord);


        bool found = false;


        while(!q.empty() && !found) {


            unordered_set<string> levelVisited;


            int size = q.size();


            while(size--) {


                string word = q.front();
                q.pop();


                string temp = word;


                for(int i=0;i<word.size();i++) {


                    char original = word[i];


                    for(char c='a'; c<='z'; c++) {


                        word[i]=c;


                        if(st.count(word)) {


                            if(!visited.count(word)) {

                                if(!levelVisited.count(word)) {
                                    q.push(word);
                                    levelVisited.insert(word);
                                }


                                parent[word].push_back(temp);
                            }


                            if(word == endWord)
                                found=true;
                        }
                    }


                    word[i]=original;
                }
            }


            for(auto w:levelVisited)
                visited.insert(w);
        }


        if(found) {

            vector<string> path={endWord};

            dfs(endWord, beginWord, parent, path);
        }


        return ans;
    }
};