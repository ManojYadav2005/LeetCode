class Solution {
public:
  void trycmbn(int opn,int clse,vector<string>& res,string str){
    if(opn==0 && clse==0){
    res.push_back(str);
    return ; }
    if(opn>0){
    trycmbn(opn-1,clse,res,str+"(");
    }
    if(clse>0 && clse>opn){
    trycmbn(opn,clse-1,res,str+")");  }
  }
    vector<string> generateParenthesis(int n) {
       vector<string> res;
       trycmbn(n,n,res,"");
       return res; 
    }
};