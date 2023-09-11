// Problem 1
// A function to convert a dense matrix to a sparse matrix
//  Input: denseMatrix - a 2D array of integers
//  Output: values - a 1D array of integers
//         columnIndices - a 1D array of integers
//          rowPointers - a 1D array of integers
//         (see the assignment description for details)
void denseToSparse(const std::vector<std::vector<int>>& denseMatrix, std::vector<int>& values, std::vector<int>& columnIndices, std::vector<int>& rowPointers) {
   int n = denseMatrix.size();
   int m = denseMatrix[0].size();
   int count = 0;
   for(int i = 0; i < n; i++) {
       rowPointers.push_back(count);
       for(int j = 0; j < m; j++) {
           if(denseMatrix[i][j] != 0) {
               values.push_back(denseMatrix[i][j]);
               columnIndices.push_back(j);
               count++;
           }
       }
   }
   rowPointers.push_back(count);
}



// Problem 2(a)

//  Given two square dense matrices of sizes N, Find their matrix multiplication and store it in denseMatrix
//  Input: denseMatrix1 - a 2D array of integers
//         denseMatrix2 - a 2D array of integers
//         N - size of the matrices
//  Output: denseMatrix - a 2D array of integers
//         (see the assignment description for details)
void denseMatrixMultiplication(const std::vector<std::vector<int>>& denseMatrix1, const std::vector<std::vector<int>>& denseMatrix2,int N, 
                    std::vector<std::vector<int>>& denseMatrix) 
                    {
                        for(int i = 0; i < N; i++) {
                            std::vector<int> temp;
                            for(int j = 0; j < N; j++) {
                                int sum = 0;
                                for(int k = 0; k < N; k++) {
                                    sum += denseMatrix1[i][k] * denseMatrix2[k][j];
                                }
                                temp.push_back(sum);
                            }
                            denseMatrix.push_back(temp);
                        }

                    }

// Problem 2(b)

// Given two dense square matrices of size N, perform block Matrix-matrix with a block size B and store it in denseMatrix
//  Input: denseMatrix1 - a 2D array of integers
//         denseMatrix2 - a 2D array of integers
//         N - size of the matrices
//         B - size of the block
//  Output: denseMatrix - a 2D array of integers
//         (see the assignment description for details)

void blockMatrixMultiplication(const std::vector<std::vector<int>>& denseMatrix1,
								const std::vector<std::vector<int>>& denseMatrix2,
								int N, int B,
								const std::vector<std::vector<int>>& denseMatrix_result){
                                    int n = N/B;
                                    for(int i = 0; i < n; i++){
                                        for(int j = 0; j < n; j++){
                                            for(int k = 0; k < n; k++){
                                                for(int i1 = i*B; i1 < (i+1)*B; i1++){
                                                    for(int j1 = j*B; j1 < (j+1)*B; j1++){
                                                        for(int k1 = k*B; k1 < (k+1)*B; k1++){
                                                            denseMatrix_result[i1][j1] += denseMatrix1[i1][k1] * denseMatrix2[k1][j1];
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }



            


