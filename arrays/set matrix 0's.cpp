// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         set<int>rows;
//         set<int>columns;
//         for(int i =0;i<m;i++) {
//             for(int j = 0;j<n;j++) {
//                 if(matrix[i][j] == 0) {
//                     rows.insert(i);
//                     columns.insert(j);
//                 }
//             }
//         }

//         for(int i =0;i<m;i++) {
//             for(int j = 0;j<n;j++) {
//                 if(rows.find(i) != rows.end() || columns.find(j) != columns.end()) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int column0 = 0;
        for(int i =0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                   

                    if(j == 0)
                        column0 = 1;
                    else
                        matrix[0][j] = 0;
                }
            }
        }

        for(int i =1;i<m;i++) {
            for(int j = 1;j<n;j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0] == 0) {
            for(int i = 0;i<n;i++) {
                matrix[0][i] = 0;
            }
        } 

        if(column0) {
            for(int i = 0;i<m;i++) {
                matrix[i][0] = 0;
            }  
        }  

           
    }
};
