// Generate sparse matrix of size N x N with density D
// output the matrix in CSR format
// where first row gives the size of square matrix
// second row gives the values of non zero elements
// third row gives the column indices of non zero elements
// fourth row gives the row pointers which represent the number of non zero elements upto the previous row
// output the file into a txt with rows seperated by line breaks and elements seperated by spaces

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

void generate_sparsematrix(int N, double D, string filename){
    // N is size of matrix
    // D is density of matrix
    // filename is name of file to be outputted
    // Initiate variables
    int n = N;
    int m = N;
    double d = D;
    
    // Initiate vectors
    vector<vector<int>> denseMatrix;
    vector<int> values;
    vector<int> columnIndices;
    vector<int> rowPointers;

    // Generate random matrix
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            double r = (double)rand() / RAND_MAX;
            if(r < d){
                row.push_back(rand() % 100);
            }
            else{
                row.push_back(0);
            }
        }
        denseMatrix.push_back(row);
    }

    // Convert to CSR format
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

    // Output to file
    ofstream myfile;
    myfile.open(filename);
    myfile << n << endl;
    for(int i = 0; i < values.size(); i++){
        myfile << values[i] << " ";
    }
    myfile << endl;
    for(int i = 0; i < columnIndices.size(); i++){
        myfile << columnIndices[i] << " ";
    }
    myfile << endl;
    for(int i = 0; i < rowPointers.size(); i++){
        myfile << rowPointers[i] << " ";
    }
    myfile << endl;
    myfile.close();
}

int main(){
    generate_sparsematrix(10, 1, "sparsematrix10.txt");
    return 0;
}   

// Density here is the ratio of non-zero elements to total elements
