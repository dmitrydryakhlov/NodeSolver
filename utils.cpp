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
	printf("\n\n");
}

void printVectorI(int* b, int N) {
	printf("Vector int:\n");
	for (int i = 0; i < N; i++) {
		printf("%d   ", b[i]);
	}
	printf("\n\n");
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

void mallocMatrixCCS(float** AVal, int** ACol, int** AIndx, int nz, int N) {
	(*AVal) = new float[nz];
	(*ACol) = new int[nz];
	(*AIndx) = new int[N + 1];
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

void makeBlock6x6LowCCS(float * MatrixLowVal, int * MatrixLowRow, int * MatrixLowIndx, int NzL, int N)
{
	for (int i = 0; i < NzL; i++)
		MatrixLowVal[i] = 1;

	MatrixLowRow[0] = 0; MatrixLowRow[6] = 5; MatrixLowRow[12] = 4;
	MatrixLowRow[1] = 1; MatrixLowRow[7] = 2; MatrixLowRow[13] = 5;
	MatrixLowRow[2] = 4; MatrixLowRow[8] = 3; MatrixLowRow[14] = 5;
	MatrixLowRow[3] = 5; MatrixLowRow[9] = 5;
	MatrixLowRow[4] = 1; MatrixLowRow[10] = 3;
	MatrixLowRow[5] = 4; MatrixLowRow[11] = 5;

	MatrixLowIndx[0] = 0;
	MatrixLowIndx[1] = 4;
	MatrixLowIndx[2] = 7;
	MatrixLowIndx[3] = 10;
	MatrixLowIndx[4] = 12;
	MatrixLowIndx[5] = 14;
	MatrixLowIndx[6] = 16;
}

void makeBlock6x6UpCCS(float * MatrixUpVal, int * MatrixUpRow, int * MatrixUpIndx, int NzU, int N)
{
	for (int i = 0; i < NzU; i++)
		MatrixUpVal[i] = 1;

	MatrixUpRow[0] = 0; MatrixUpRow[6] = 0; MatrixUpRow[12] = 3;
	MatrixUpRow[1] = 0; MatrixUpRow[7] = 1; MatrixUpRow[13] = 4;
	MatrixUpRow[2] = 1; MatrixUpRow[8] = 4; MatrixUpRow[14] = 5;
	MatrixUpRow[3] = 2; MatrixUpRow[9] = 0;
	MatrixUpRow[4] = 2; MatrixUpRow[10] = 1;
	MatrixUpRow[5] = 3; MatrixUpRow[11] = 2;

	MatrixUpIndx[0] = 0;
	MatrixUpIndx[1] = 1;
	MatrixUpIndx[2] = 3;
	MatrixUpIndx[3] = 4;
	MatrixUpIndx[4] = 6;
	MatrixUpIndx[5] = 9;
	MatrixUpIndx[6] = 16;
}

void randMatrixLow(float** a, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i >= j) && (rand() / 100000.0f < 0.3f)) {
				a[i][j] = rand() % 10;
			}
			else {
				a[i][j] = 0.0;
			}
		}
		a[i][i] = 1;
	}
}

void randMatrixUp(float** a, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i <= j) && (rand() / 100000.0f < 0.3f)) {
				a[i][j] = rand() % 10;
			}
			else {
				a[i][j] = 0.0;
			}
		}
		a[i][i] = 1;
	}
}

void CalcSuperNodesLowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx,
	int **SNodesLow, int &NodesNLow, int NzL, int N) {
	int *TmpNodes = new int[N];
	TmpNodes[0] = 0;
	NodesNLow = 1;
	int lowIndx = 0;
	int upIndx = 0;
	for (int j = 0; j < N - 1; j++) { //ןמ גסול סעמכבצאל/////////////////
		lowIndx = MatrixLowIndx[j];
		upIndx = MatrixLowIndx[j + 1];
		for (int i = lowIndx + 1; i < upIndx; i++) {
			if (MatrixLowRow[i] != MatrixLowRow[i + (upIndx - lowIndx - 1)]) {
				TmpNodes[NodesNLow] = j + 1;
				NodesNLow++;
				break;
			}
		}
	}
	NodesNLow++;//for last = arr.length
	(*SNodesLow) = new int[NodesNLow];
	for (int i = 0; i < NodesNLow - 1; i++)
		(*SNodesLow)[i] = TmpNodes[i];
	(*SNodesLow)[NodesNLow - 1] = N;
	delete[]TmpNodes;
}

void CalcSuperNodesUpCCS(float * MatrixUpVal, int * MatrixUpRow, int * MatrixUpIndx,
	int ** SNodesUp, int & NodesNUp, int NzU, int N) {
	int *TmpNodes = new int[N];

	TmpNodes[0] = N - 1;
	NodesNUp = 1;

	int lowIndx = 0;
	int upIndx = 0;
	for (int j = N - 1; j > 0; j--) { //ןמ גסול סעמכבצאל
		upIndx = MatrixUpIndx[j];
		lowIndx = MatrixUpIndx[j - 1];
		for (int i = upIndx - 1; i > lowIndx; i--) {
			if (MatrixUpRow[i] != MatrixUpRow[i - (upIndx - lowIndx - 1)]) {
				TmpNodes[NodesNUp] = j - 1;
				NodesNUp++;
				break;
			}
		}
	}
	NodesNUp++;//for last = arr.length
	(*SNodesUp) = new int[NodesNUp];
	for (int i = 0; i < NodesNUp - 1; i++)
		(*SNodesUp)[i] = TmpNodes[i];

	(*SNodesUp)[NodesNUp - 1] = 0;
	delete[]TmpNodes;
}

void changeBLowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx,
	int indexX, int N, float* x, float* bLow) {
	if (indexX == N - 1)
		return;
	int lowIndx = MatrixLowIndx[indexX];
	int upIndex = MatrixLowIndx[indexX + 1];
	for (int i = lowIndx; i < upIndex; i++) {
		bLow[MatrixLowRow[i]] -= MatrixLowVal[i] * x[indexX];
	}
}

void changeBUpCCS(float *MatrixUpVal, int *MatrixUpRow, int *MatrixUpIndx,
	int indexX, int N, float* x, float* b) {
	int upIndx = MatrixUpIndx[indexX + 1]-2;
	int lowIndex = MatrixUpIndx[indexX];
	for (int i = upIndx; i >= lowIndex; i--) {
		b[MatrixUpRow[i]] -= MatrixUpVal[i] * x[indexX];
	}
}

void blockSolverLowCCS(float *MatrixLowVal, int *MatrixLowRow, int *MatrixLowIndx,
	int* SNodesLow, int NodesNLow, float* xLow, float* bLow, int N) {

	for (int k = 0; k < NodesNLow - 1; k++) { //ןמ גסול םמהאל
		for (int i = SNodesLow[k]; i < SNodesLow[k + 1]; i++) { //ןמ גסול סעמכבצאל םמהא

			xLow[i] = bLow[i] / MatrixLowVal[MatrixLowIndx[i]];
			changeBLowCCS(MatrixLowVal, MatrixLowRow, MatrixLowIndx, i, N, xLow, bLow);

		}
	}
}

void blockSolverUpCCS(float *MatrixUpVal, int *MatrixUpRow, int *MatrixUpIndx,
	int* SNodesUp, int NodesNUp, float* xUp, float* bUp, int N) {
	for (int k = 0; k < NodesNUp - 1; k++) { //ןמ גסול םמהאל
		for (int i = SNodesUp[k]; i > SNodesUp[k + 1]; i--) { //ןמ גסול סעמכבצאל םמהא
			xUp[i] = bUp[i] / MatrixUpVal[MatrixUpIndx[i]];
			changeBUpCCS(MatrixUpVal, MatrixUpRow, MatrixUpIndx, i, N, xUp, bUp);
		}
	}xUp[0] = bUp[0] / MatrixUpVal[MatrixUpIndx[0]];
}

void blockSolverUp(float** MatrixUp, int* SNodesUp, int NodesNUp, float* xUp, float* bUp, int N) {
	for (int k = 0; k < NodesNUp - 1; k++) {
		for (int i = SNodesUp[k]; i > SNodesUp[k + 1]; i--) {
			xUp[i] = bUp[i] / MatrixUp[i][i];
			changeBUp(MatrixUp, i, N, xUp, bUp);
		}
	}xUp[0] = bUp[0] / MatrixUp[0][0];
}

void blockSolverLow(float** MatrixLow, int* SNodesLow, int NodesNLow, float* xLow, float* bLow, int N) {
	for (int k = 0; k < NodesNLow - 1; k++) {
		for (int i = SNodesLow[k]; i < SNodesLow[k + 1]; i++) {
			xLow[i] = bLow[i] / MatrixLow[i][i];
			changeBLow(MatrixLow, i, N, xLow, bLow);
		}
	}
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
	for (int i = 0; i < NodesN - 1; i++)
		(*SNodes)[i] = TmpNodes[i];
	(*SNodes)[NodesN - 1] = N;
}