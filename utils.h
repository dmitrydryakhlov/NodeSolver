#pragma once
#include <iostream>
#include <random>
void printMatrix(float** a, int N);
void printVectorF(float* b, int N);
void printVectorI(int* b, int N);
void mallocVectorF(float** b, int N);
void mallocVectorI(int** b, int N);
void randVector(int* b, int N);
void mallocMatrixCCS(float** AVal, int** ARow, int** AIndx, int nz, int N);
void makeBlock6x6Low(float** a, int N);
void makeBlock6x6Up(float** a, int N);
void makeBlock6x6LowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx, int NzL, int N);
void makeBlock6x6UpCCS(float *MatrixUpVal, int *MatrixUpRow, int *MatrixUpIndx, int NzU, int N);

void randMatrix(float** a, int N);
void FreeMem(float **A, int n);

void randMatrixLow(float** a, int N);
void randMatrixUp(float** a, int N);
void CalcSuperNodesLow(float** A, int** SNodes, int N, int &NodesN);
void CalcSuperNodesUp(float** A, int** SNodes, int N, int &NodesN);
void changeBLow(float** Matrix, int indexX, int N, float* x, float* b);
void changeBUp(float** Matrix, int indexX, int N, float* x, float* b);
void blockSolverLow(float** MatrixLow, int* SNodesLow, int NodesNLow, float* xLow, float* bLow, int N);
void blockSolverUp(float** MatrixUp, int* SNodesUp, int NodesNUp, float* xUp, float* bUp, int N);

void CalcSuperNodesLowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx,
	int **SNodesLow, int &NodesNLow, int N, int NzL);

void CalcSuperNodesUpCCS(float *MatrixUpVal, int *MatrixUpRow, int *MatrixUpIndx,
	int **SNodesUp, int &NodesNUp, int N, int NzU);

void changeBLowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx,
	 int indexX, int N, float* x, float* b, int NzL);
void changeBUpCCS(float *MatrixUpVal, int *MatrixUpRow, int *MatrixUpIndx,
	int indexX, int N, float* x, float* b);

void blockSolverLowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx,
	int* SNodesLow, int NodesNLow, float* xLow, float* bLow, int N);
void blockSolverUpCCS(float *MatrixUpVal, int *MatrixUpRow, int *MatrixUpIndx,
	int* SNodesUp, int NodesNUp, float* xUp, float* bUp, int N);