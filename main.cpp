#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "user_code.h"

using namespace std;

int problem1(){
    vector<vector<int> > denseMatrix;
    vector<int> values;
    vector<int> columnIndices;
    vector<int> rowPointers;
    string inputPath = "dense_to_sparse_tests/input1.txt";
    string outputPath = "dense_to_sparse_tests/userOutput1.txt";

    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);
    
    // read dense matrix from input file
    for(int i = 0; i < 10; i++){
        vector<int> temp;
        for(int j = 0; j < 10; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix.push_back(temp);
    }

    denseToSparse(denseMatrix, values, columnIndices, rowPointers);

    for(int i = 0; i < values.size(); i++){
        cout << values[i] << endl;
    }

    return 0;
}

int problem2(){

    return 0;
}

int problem3(){

    return 0;
}

int problem4(){

    return 0;
}

int main() {
    // Calling user code for Problem 1
    int p1Ret, p2Ret, p3Ret, p4Ret;

    p1Ret = problem1();
    if(p1Ret != 0){
        cout << "Error in problem 1" << endl;
    }
    p2Ret = problem2();
    if(p2Ret != 0){
      cout << "Error in problem 2" << endl;
    }
    p3Ret = problem3();
    if(p3Ret != 0){
      cout << "Error in problem 3" << endl;
    }
    p4Ret = problem4();
    if(p4Ret != 0){
        cout << "Error in problem 4" << endl;
    }
}
