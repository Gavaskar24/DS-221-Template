#ifndef USER_CODE_H
#define USER_CODE_H

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <stdio.h>
#include<iostream>
using namespace std;


// Problem 1
// Convert a dense matrix to compressed sparse row format
// where each rowpointer is the index of the first non-zero element in previous row of that element
//  and is offset by 0 at the beginning, value represents the value of element and 
// columnIndice represents column index of that element

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

// Pesudo code of problem 1
// Initiate size variables
// Iterate through rows
// Set current rowpointer to count
// Iterate through columns of current row
// If element is non-zero
// Add value to values vector
// Add column index to columnIndices vector
// Increment count
// End column loop
// End row loop
// Return vectors
// Big O complexity is O(N*M) where N is number of rows and M is number of columns
// Omega (N*M) in best case if matrix is completely dense
// Theta (N*Nnz) if matrix is sparse where Nnz is number of non-zero elements



// ###############################################################################################  //


// Problem 2(a)

//  Given two square dense matrices of sizes N, Find their matrix multiplication and store it in denseMatrix
//  Input: denseMatrix1 - a 2D array of integers
//         denseMatrix2 - a 2D array of integers
//         N - size of the matrices
//  Output: denseMatrix - a 2D array of integers
//         (see the assignment description for details)

void denseMatrixMultiplication(const std::vector<std::vector<int> >& denseMatrix1,
								const std::vector<std::vector<int> >& denseMatrix2,
                                int squareMatrixSize,
                                std::vector<std::vector<int> >& denseMatrix_result){
                                int n=squareMatrixSize;
                                denseMatrix_result.resize(n, std::vector<int>(n, 0));
                                
                                for(int i=0;i<n;i++){
                                    for(int j=0;j<n;j++){
                                        long long temp=0;
                                        for(int k=0;k<n;k++){
                                            temp+=denseMatrix1[i][k]*denseMatrix2[k][j];
                                            
                                        }
                                        // cout<<temp<<endl;
                                        denseMatrix_result[i][j]=temp;
                                    }
                                }
                                return;
    
                                }

//  Writing pseudo code for problem 2(a)
// Initialize size of result matrix and result matrix to all zeros
// Iterate through rows of first matrix
// Iterate through columns of second matrix
// Iterate through common elements (columns of first and rows of second)
// Add product of elements to running sum
// End inner loop
// Store running sum in result matrix
// End column loop
// End row loop
// Asymptotic Analysis
// Big O complexity is O(N^3) as there are three nested loops iterating from 0 to N
// Omega(N^3) in best case
// Theta(N^3) as all elements are multiplied

// ###############################################################################################  //

// problem 2(b)
//Function to perform dense matrix multiplication using block matrix multiplication
void blockMatrixMultiplication(const std::vector<std::vector<int>>& denseMatrix1,
                               const std::vector<std::vector<int>>& denseMatrix2,
                               int N, int B,
                               std::vector<std::vector<int>>& denseMatrix_result) {
    for (int i = 0; i < N; i += B) {
        for (int j = 0; j < N; j += B) {
            for (int k = 0; k < N; k += B) {
                for (int i1 = i; i1 < i + B; i1++) {
                    for (int j1 = j; j1 < j + B; j1++) {
                        for (int k1 = k; k1 < k + B; k1++) {
                            denseMatrix_result[i1][j1] += denseMatrix1[i1][k1] * denseMatrix2[k1][j1];
                        }
                    }
                }
            }
        }
    }
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

                                int n=N;
                                int count=0;

                                for(int i=0;i<n;i++){
                                    rowPointersResult.push_back(count);
                                    
                                    for(int j=0;j<n;j++){
                                        int sum=0;
                                       for(int k=rowPointers1[i]; k<rowPointers1[i+1]; k++)
                                                {
                                                int col1 = columnIndices1[k];
  
                                                for(int l=rowPointers2[col1]; l<rowPointers2[col1+1]; l++) 
                                                    {
                                                
                                                         if(columnIndices2[l] == j) 
                                                        {
                                                        // Column indices match 
                                                        sum += values1[k] * values2[l]; 
                                                    }
                                                }
                                            }    
                                                                                      
                                        
                                        if(sum!=0){
                                             
                                            valuesResult.push_back(sum);
                                            columnIndicesResult.push_back(j);
                                            count++;

                                            // check if valuesResult and columnIndicesResult are appending correct elements
                                            
                                            
                                        }
                                        
                                    }
                                    
                                }
                                rowPointersResult.push_back(count);
                                return;
                            

}


// Function to find directed 3-cycles in graphs using a map
void findTrianglesAsMap(const std::vector<std::vector<int>>& adjMat, int N, std::map<std::vector<int>, int>& outputMap) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Check if edge (i, j) exists
            if (adjMat[i][j] == 0) continue;

            for (int k = j + 1; k < N; k++) {
                // Check if k forms a triangle with i and j
                if (adjMat[i][k] != 0 && adjMat[j][k] != 0) {
                    // Found a triangle, increment count
                    std::vector<int> pattern = { adjMat[i][j], adjMat[j][k], adjMat[k][i] };
                    outputMap[pattern]++;
                }
            }
        }
    }
}
// Function to find directed 3-cycles in graphs using a vector
void findTrianglesAsVec(const std::vector<std::vector<int>>& adjMat, int N, std::vector<std::vector<int>>& outputVec) {
    std::vector<std::vector<int>> patterns;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (adjMat[i][j] == 0) continue;

            std::unordered_set<int> visited;
            visited.insert(i);
            visited.insert(j);

            for (int k = 0; k < N; k++) {

                if (adjMat[j][k] != 0 && adjMat[k][i] != 0 && visited.count(k) == 0) {

                    std::vector<int> pattern = { adjMat[i][j], adjMat[j][k], adjMat[k][i], 1 };
                    patterns.push_back(pattern);

                    visited.insert(k);
                }
            }
        }
    }

    // Sort patterns and combine duplicates
    std::sort(patterns.begin(), patterns.end());

    for (int i = 0; i < patterns.size(); i++) {
        if (i == 0 || patterns[i] != patterns[i - 1]) {
            outputVec.push_back(patterns[i]);
        }
        else {
            outputVec.back()[3]++;
        }
    }
}


#endif // USER_CODE_H