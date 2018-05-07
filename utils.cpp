#include "utils.h"
using namespace std;

void printMatrix(float** a, int N) {
	printf("Matrix:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%.1f   ", a[i][j]);
		}
		printf("\n\n");
	}
}

void printVectorF(float* b, int N) {
	printf("Vector flt:\n");
	for (int i = 0; i < N; i++) {
		printf("%.1f   ", b[i]);
	}
	printf("\n");
}

void printVectorI(int* b, int N) {
	printf("Vector int:\n");
	for (int i = 0; i < N; i++) {
		printf("%d   ", b[i]);
	}
	printf("\n");
}

void mallocVectorF(float** b, int N) {
	(*b) = new float[N];
}

void mallocVectorI(int** b, int N) {
	(*b) = new int[N];
}

void randVector(int* b, int N) {
	for (int i = 0; i < N; i++) {
		b[i] = (rand() % 100) / 3.0;
	}
}

void mallocMatrix(float*** a, int N) {
	(*a) = new float *[N];
	for (int i = 0; i < N; i++) {
		(*a)[i] = new float[N];
	}
}

void makeBlock6x6Low(float** a, int N) {
	a[0][0] = 1; a[0][1] = 0; a[0][2] = 0; a[0][3] = 0; a[0][4] = 0; a[0][5] = 0;
	a[1][0] = 1; a[1][1] = 1; a[1][2] = 0; a[1][3] = 0; a[1][4] = 0; a[1][5] = 0;
	a[2][0] = 0; a[2][1] = 0; a[2][2] = 1; a[2][3] = 0; a[2][4] = 0; a[2][5] = 0;
	a[3][0] = 0; a[3][1] = 0; a[3][2] = 1; a[3][3] = 1; a[3][4] = 0; a[3][5] = 0;
	a[4][0] = 1; a[4][1] = 1; a[4][2] = 0; a[4][3] = 0; a[4][4] = 1; a[4][5] = 0;
	a[5][0] = 1; a[5][1] = 1; a[5][2] = 1; a[5][3] = 1; a[5][4] = 1; a[5][5] = 1;
}

void makeBlock6x6Up(float** a, int N) {
	a[0][0] = 1; a[0][1] = 1; a[0][2] = 0; a[0][3] = 0; a[0][4] = 1; a[0][5] = 1;
	a[1][0] = 0; a[1][1] = 1; a[1][2] = 0; a[1][3] = 0; a[1][4] = 1; a[1][5] = 1;
	a[2][0] = 0; a[2][1] = 0; a[2][2] = 1; a[2][3] = 1; a[2][4] = 0; a[2][5] = 1;
	a[3][0] = 0; a[3][1] = 0; a[3][2] = 0; a[3][3] = 1; a[3][4] = 0; a[3][5] = 1;
	a[4][0] = 0; a[4][1] = 0; a[4][2] = 0; a[4][3] = 0; a[4][4] = 1; a[4][5] = 1;
	a[5][0] = 0; a[5][1] = 0; a[5][2] = 0; a[5][3] = 0; a[5][4] = 0; a[5][5] = 1;
}

void randMatrix(float** a, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i >= j) && (rand() / 100000.0f < 0.13f)) {
				a[i][j] = rand() % 100;
			}
			else {
				a[i][j] = 0.0;
			}
		}
	}
}

void CalcSuperNodesLow(float** A, int** SNodes, int N, int &NodesN) {
	int *TmpNodes = new int[N];
	TmpNodes[0] = 0;
	NodesN = 1;

	for (int j = 0; j < N - 1; j++) {
		for (int i = j + 1; i < N; i++) {
			if (A[i][j]) {
				if (!A[i][j + 1]) {
					TmpNodes[NodesN] = j + 1;
					NodesN++;
					break;
				}
			}
			else {
				if (A[i][j + 1]) {
					TmpNodes[NodesN] = j + 1;
					NodesN++;
					break;
				}
			}
		}
	}
	NodesN++;//for last = arr.length
	(*SNodes) = new int[NodesN];
	for (int i = 0; i < NodesN - 1; i++) {
		(*SNodes)[i] = TmpNodes[i];
	}
	(*SNodes)[NodesN - 1] = N;
}

void CalcSuperNodesUp(float** A, int** SNodes, int N, int &NodesN) {
	int *TmpNodes = new int[N];
	TmpNodes[0] = N - 1;
	NodesN = 1;

	for (int j = N - 1; j >= 0; j--) {
		for (int i = j - 1; i > 0; i--) {
			if (A[i][j]) {
				if (!A[i][j - 1]) {
					TmpNodes[NodesN] = j - 1;
					NodesN++;
					break;
				}
			}
			else {
				if (A[i][j - 1]) {
					TmpNodes[NodesN] = j - 1;
					NodesN++;
					break;
				}
			}
		}
	}
	NodesN++;//for last = arr.length
	(*SNodes) = new int[NodesN];
	for (int i = 0; i < NodesN - 1; i++) {
		(*SNodes)[i] = TmpNodes[i];
	}
	(*SNodes)[NodesN - 1] = 0;
}

void changeBLow(float** Matrix, int indexX, int N, float* x, float* b) {
	for (int i = indexX; i < N; i++) {
		b[i] -= Matrix[i][indexX] * x[indexX];
	}
}

void changeBUp(float** Matrix, int indexX, int N, float* x, float* b) {
	for (int i = indexX; i >= 0; i--) {
		b[i] -= Matrix[i][indexX] * x[indexX];
	}
}

void FreeMem(float **A, int n)
{
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
}

void blockSolverLow(float** MatrixLow, int* SNodesLow, int NodesNLow, float* xLow, float* bLow, int N) {
	for (int k = 0; k < NodesNLow - 1; k++) {
		for (int i = SNodesLow[k]; i < SNodesLow[k + 1]; i++) {
			xLow[i] = bLow[i] / MatrixLow[i][i];
			changeBLow(MatrixLow, i, N, xLow, bLow);
		}
	}
}

void blockSolverUp(float** MatrixUp, int* SNodesUp, int NodesNUp, float* xUp, float* bUp, int N) {
	for (int k = 0; k < NodesNUp - 1; k++) {
		for (int i = SNodesUp[k]; i > SNodesUp[k + 1]; i--) {
			xUp[i] = bUp[i] / MatrixUp[i][i];
			changeBUp(MatrixUp, i, N, xUp, bUp);
		}
	}xUp[0] = bUp[0] / MatrixUp[0][0];
}