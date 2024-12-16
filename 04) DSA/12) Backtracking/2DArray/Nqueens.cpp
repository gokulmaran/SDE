#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link: https://leetcode.com/problems/n-queens/description/
class Solution {
public:
   vector<vector<string>>ans;
    bool isValid(int size,int k,int i,vector<string>&sol){
        int m=k-1,left=i-1,right=i+1;
        while(m>=0){
            //left diagonal
            if(left>=0 and sol[m][left--]=='Q'){
                return false;
            }
            //right diagonal
            if(right<size and sol[m][right++]=='Q') return false;
            if(sol[m][i]=='Q') return false;
            m--;
        }
        return true;
    }
    void solve(int n,int k,vector<string>&sol){
      if(k==n){
        ans.push_back(sol);
        return;
      }

      for(int i=0;i<n;i++){
        if(isValid(n,k,i,sol)){
             sol[k][i]='Q';
             solve(n,k+1,sol);
             sol[k][i]='.';
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>sol(n,string(n,'.'));
        solve(n,0,sol);
        return ans;
    }
};

int main() {

    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(4);

    cout << "Number of solutions: " << results.size() << endl;
    for (const auto& solution : results) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

