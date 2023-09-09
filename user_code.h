#ifndef USER_CODE_H
#define USER_CODE_H

#include <vector>
#include <string>
#include <utility>

// Function to convert a dense matrix to a sparse matrix representation
void denseToSparse(const std::vector<std::vector<int> >& denseMatrix,
                   std::vector<int>& values,
                   std::vector<int>& columnIndices,
                   std::vector<int>& rowPointers){
                    // Write your code here
                    
                    return;
}


//Function to perform dense matrix multiplication

void denseMatrixMultiplication(const std::vector<std::vector<int>>& denseMatrix1,
                                const std::vector<std::vector<int>>& denseMatrix2,
                                int N,
                                const std::vector<std::vector<int>>& denseMatrix_result){
                                // Write your code here
                                return;
                                }


//Function to perform dense matrix multiplication using block matrix multiplication
void blockMatrixMultiplication(const std::vector<std::vector<int>>& denseMatrix1,
                                const std::vector<std::vector<int>>& denseMatrix2,
                                int N, int B,
                                const std::vector<std::vector<int>>& denseMatrix_result)}
                                // Write your code here
                                return;
                            }

// Function to perform sparse matrix multiplication
void sparseMatrixMultiplication(const std::vector<int>& values1,
                                const std::vector<int>& columnIndices1,
                                const std::vector<int>& rowPointers1,
                                const std::vector<int>& values2,
                                const std::vector<int>& columnIndices2,
                                const std::vector<int>& rowPointers2,
                                int N,
                                std::vector<int>& valuesResult,
                                std::vector<int>& columnIndicesResult,
                                std::vector<int>& rowPointersResult){
                                // Write your code here
                                return;
}


//function For finding patterns in graphs using a map
void findTrianglesAsMap(const std::vector<std::vector<int> >& adjMat, int N, const std::unordered_map<int[], int> outputMap){
    // Write your code here
    return;
}


//function For finding patterns in graphs using a vector

void findTrianglesAsVec(const std::vector<std::vector<int> >& adjMat, int N, const std::vector<int[]>& outputVec){
    // Write your code here
    return;
}

#endif // USER_CODE_H
