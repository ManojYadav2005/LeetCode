class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>st;
    int n=asteroids.size();
    for(int i=0;i<n;i++){
    int curr=asteroids[i];
    while(!st.empty() && st.top()>0 && asteroids[i]<0){
    
    int sm=curr+st.top();
    if(sm<0){ // pos vala km hai usko delete kro
    st.pop();
    }
    else if(sm>0){ // pos vala jada hai,ab neg ko nhi daalna hai
    curr=0;      // ye current vala element stack mein nhi jaayega
    break;
    }
    else{ // sm=0, ab dono ko delete kr do
    curr=0;
    st.pop();
    break;
    }
    }
    if(curr!=0) st.push(curr);
    }
    int size=st.size();
    vector<int>v(size);
    
    while(!st.empty()){
    size--;
    v[size]=st.top();
    st.pop();
    }
    return v;
    }
};