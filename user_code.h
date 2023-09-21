// Problem 1
// Convert a dense matrix to compressed sparse row format
// where each rowpointer is the index of the first non-zero element in that row and is offset by 0 at the beginning
#ifndef USER_CODE_H
#define USER_CODE_H

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <stdio.h>

void denseToSparse(const std::vector<std::vector<int>>& denseMatrix,
                   std::vector<int>& values,
                   std::vector<int>& columnIndices,
                   std::vector<int>& rowPointers){
    int n = denseMatrix.size();
    int m = denseMatrix[0].size();
    int count = 0;
    
    for(int i = 0; i < n; i++){
      
        rowPointers.push_back(count);
        for(int j = 0; j < m; j++){
            if(denseMatrix[i][j] != 0){
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

void denseMatrixMultiplication(const std::vector<std::vector<int> >& denseMatrix1,
                               const std::vector<std::vector<int> >& denseMatrix2,
                               int N,
                              const std::vector<std::vector<int> >& denseMatrix_result){

                                

                                for(int i=0;i<N;i++){
                                    for(int j=0;j<N;j++){
                                       
                                        for(int k=0;k<N;k++){
                                            denseMatrix_result[i][j]+=denseMatrix1[i][k]*denseMatrix2[k][j];
                                            
                                           
                                        }
                                        
                                      
                                    }
                                   
                                }
                                return;
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
								 std::vector<std::vector<int>>& denseMatrixResult){
                                    std::vector<std::vector<int>> temp(N, std::vector<int>(N, 0));
                                    int n = N/B;
                                    for(int i = 0; i < n; i++){
                                        for(int j = 0; j < n; j++){
                                            for(int k = 0; k < n; k++){
                                                for(int i1 = i*B; i1 < (i+1)*B; i1++){
                                                    for(int j1 = j*B; j1 < (j+1)*B; j1++){
                                                        for(int k1 = k*B; k1 < (k+1)*B; k1++){
                                                            temp[i1][j1] += denseMatrix1[i1][k1] * denseMatrix2[k1][j1];
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    denseMatrixResult=temp;
                                }
                                

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
void findTrianglesAsMap(const std::vector<std::vector<int> >& adjMat, int N, std::map<std::vector<int>, int> outputMap){
    // Write your code here
    return;
}


//function For finding patterns in graphs using a vector

void findTrianglesAsVec(const std::vector<std::vector<int> >& adjMat, int N,  std::vector<std::vector<int> >& outputVec){
    // Write your code here
    return;
}


            


