#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "user_code.h"

using namespace std;

// int problem1(string inputPath, string outputPath){
//     vector<vector<int> > denseMatrix;
//     vector<int> values;
//     vector<int> columnIndices;
//     vector<int> rowPointers;

//     ifstream inputFile(inputPath);
//     ofstream outputFile(outputPath);
//     int N;
//     inputFile >> N;
//     // read dense matrix from input file
//     for(int i = 0; i < N; i++){
//         vector<int> temp;
//         for(int j = 0; j < N; j++){
//             int x;
//             inputFile >> x;
//             temp.push_back(x);
//         }
//         denseMatrix.push_back(temp);
//     }

//     //add input size matrix (N*N )log here
//     // measure time taken in nanoseconds
//     cout<< "input_size_n:" << denseMatrix.size() << endl;
//     clock_t start = clock();
//     denseToSparse(denseMatrix, values, columnIndices, rowPointers);
//     clock_t end = clock();
//     // time diff in nanoseconds
//     double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
//     cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;

//     // write values to output file
//     for(int i = 0; i < values.size(); i++){
//         outputFile << values[i] << " ";
//     }
//     outputFile << endl;
//     for (int i = 0; i < columnIndices.size(); i++){
//         outputFile << columnIndices[i] << " ";
//     }
//     outputFile << endl;
//     for (int i = 0; i < rowPointers.size(); i++){
//         outputFile << rowPointers[i] << " ";
//     }
//     outputFile << endl;
    
//     inputFile.close();
//     outputFile.close();
//     return 0;
// }

// int problem2a(string inputPath, string outputPath){
//     vector<vector<int> > denseMatrix1;
//     vector<vector<int> > denseMatrix2;
//     vector<vector<int> > denseMatrixResult;
//     ifstream inputFile(inputPath);
//     ofstream outputFile(outputPath);
//     int N;
//     inputFile >> N;
//     // read dense matrix from input file
//     for(int i = 0; i < N; i++){
//         vector<int> temp;
//         for(int j = 0; j < N; j++){
//             int x;
//             inputFile >> x;
//             temp.push_back(x);
//         }
//         denseMatrix1.push_back(temp);
//     }
//     // read dense matrix 2 from input file
//     for(int i = 0; i < N; i++){
//         vector<int> temp;
//         for(int j = 0; j < N; j++){
//             int x;
//             inputFile >> x;
//             temp.push_back(x);
//         }
//         denseMatrix2.push_back(temp);
//     }

//     // initialize resultant matrix
//     denseMatrixResult.resize(N, vector<int>(N,0));


//     // measure time taken in nanoseconds
//     cout<< "input_size_n:" << denseMatrix1.size() << endl;
//     clock_t start = clock();
    
//     denseMatrixMultiplication(denseMatrix1, denseMatrix2, N, denseMatrixResult);
//     clock_t end = clock();
//     // time diff in nanoseconds
//     double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
//     cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;


//     // write values to output file
//     for(int i = 0; i < denseMatrixResult.size(); i++){
//         for(int j = 0; j < denseMatrixResult[i].size(); j++){
//             outputFile << denseMatrixResult[i][j] << " ";
//         }
//         outputFile << endl;
//     }
    
//     return 0;
// }

int problem2b(string inputPath, string outputPath){
    vector<vector<int> > denseMatrix1;
    vector<vector<int> > denseMatrix2;
    vector<vector<int> > denseMatrixResult;
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);
    int N;
    int B;
    inputFile >>N>>B;
    // read dense matrix 1 from input file
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix1.push_back(temp);
    }

    // read dense matrix 2 from input file
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix2.push_back(temp);
    }

    // initialize resultant matrix
    denseMatrixResult.resize(N, vector<int>(N,0));

    cout<< "input_size_n:" << denseMatrix1.size() << endl;
    clock_t start = clock();

    blockMatrixMultiplication(denseMatrix1, denseMatrix2, N, B, denseMatrixResult);
    clock_t end = clock();
    // time diff in nanoseconds
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;
    for (int i = 0; i < denseMatrixResult.size(); i++){
        for (int j = 0; j < denseMatrixResult[i].size(); j++){
            outputFile << denseMatrixResult[i][j] << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}


int main(int argc, char** argv) {
    // string problem1InputPath = argv[1];
    // string problem1OutputPath = argv[2];
    // string problem2aInputPath = argv[1];
    // string problem2aOutputPath = argv[2];
    string problem2bInputPath = argv[1];
    string problem2bOutputPath = argv[2];
    // Calling user code for Problem 1
    int p1Ret, p2aRet,p2bRet,p2cRet, p3Ret;

    // p1Ret = problem1(problem1InputPath, problem1OutputPath);
    // if(p1Ret != 0){

    //     cout << "Error in problem 1" << endl;
    // }
    
//    p2aRet = problem2a(problem2aInputPath, problem2aOutputPath);
//     if(p2aRet != 0){
//       cout << "Error in problem 2a" << endl;
//     }

   p2bRet = problem2b(problem2bInputPath, problem2bOutputPath);
    if(p2bRet != 0){
      cout << "Error in problem 2b" << endl;
    }

}