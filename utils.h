#pragma once
#include <iostream>
#include <random>
void printMatrix(float** a, int N);
void printVectorF(float* b, int N);
void printVectorI(int* b, int N);
void mallocVectorF(float** b, int N);
void mallocVectorI(int** b, int N);
void randVector(int* b, int N);
void mallocMatrix(float*** a, int N);
void makeBlock6x6Low(float** a, int N);
void makeBlock6x6Up(float** a, int N);
void randMatrix(float** a, int N);
void CalcSuperNodesLow(float** A, int** SNodes, int N, int &NodesN);
void CalcSuperNodesUp(float** A, int** SNodes, int N, int &NodesN);
void changeBLow(float** Matrix, int indexX, int N, float* x, float* b);
void changeBUp(float** Matrix, int indexX, int N, float* x, float* b);
void blockSolverLow(float** MatrixLow, int* SNodesLow, int NodesNLow, float* xLow, float* bLow, int N);
void blockSolverUp(float** MatrixUp, int* SNodesUp, int NodesNUp, float* xUp, float* bUp, int N);
void FreeMem(float **A, int n);