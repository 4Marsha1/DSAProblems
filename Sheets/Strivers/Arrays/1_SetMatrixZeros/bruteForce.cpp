#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> coord;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    coord.push_back({i,j});
                }
            }
        }
        for(int l=0;l<coord.size();l++){
            for(int k=0;k<n;k++){
                matrix[k][coord[l][1]]=0;
            }
            for(int k=0;k<m;k++){
                matrix[coord[l][0]][k]=0;
            }
        }
    }
};