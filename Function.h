#ifndef FUNCTION_H
#define FUNCTION_H

double funtionF(double x, double y) {
	// return 2 * x * (x - 1) + 2 * y * (y - 1);
	return 4.0;
}

double funtionU1(double x, double y) {
	return x * (x - 1) * y * (y - 1);
}

double funtionU2(double x, double y) {
	return (x - 1) * (x - 1) + (y - 1) * (y - 1);
}

// Subtract matrix 2 dimension: a - b - c
double** subtractMatrix(double** a, double** b, double** c, int n) {
	double** matrix = new double*[n];
        for (int i = 0; i < n; i++)
                matrix[i] = new double[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			matrix[i][j] = a[i][j] - b[i][j] - c[i][j];
		}
	}

	return matrix;
}

// Subtract 3 vector: a - b - c
double* subtractVector(double* a, double* b, double* c, int n) {
    double* matrix = new double[n];

    for (int i = 0; i < n; i++) {
            
        matrix[i]= a[i] - b[i] - c[i];
    }

    return matrix;
}

// Subtract 2 vector: a - b
double* subtractVector2(double* a, double* b, int n) {
    double* matrix = new double[n];

    for (int i = 0; i < n; i++) {
            
        matrix[i]= a[i] - b[i];
    }

    return matrix;
}

// Multiply 2 matrix a[n][n], b[n][n]
double** multiplyMatrix(double** a, double** b, int n) {
	double** matrix = new double*[n];
        for (int i = 0; i < n; i++)
                matrix[i] = new double[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
			
			for (int k = 0; k < n; k++) {
				matrix[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return matrix;
}

// Multiply 2 matrix a[n][n], b[n]
double* multiplyMatrix2(double** a, double* b, int n) {
	double* matrix = new double[n];

	for (int i = 0; i < n; i++) {
		matrix[i] = 0;

		for (int j = 0; j < n; j++) {
			matrix[i] += a[i][j] * b[j];
		}
	}

	return matrix;
}

// Multiply 2 matrix a[m][n], b[n][p]
double** multiplyMatrix3(double** a, double** b, int m, int n, int p) {
    double** matrix = new double*[m];
        for (int i = 0; i < m; i++)
            matrix[i] = new double[p];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            matrix[i][j] = 0;
            
            for (int k = 0; k < n; k++) {
                matrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return matrix;
}

// Multiply 2 matrix a[m][n], b[n]
double* multiplyMatrix4(double** a, double* b, int m, int n) {
    double* matrix = new double[m];

    for (int i = 0; i < m; i++) {
        matrix[i] = 0;

        for (int j = 0; j < n; j++) {
            matrix[i] += a[i][j] * b[j];
        }
    }

    return matrix;
}

double** matrixTransposition(double**a, int n) {
	double** matrix = new double*[n];
        for (int i = 0; i < n; i++)
                matrix[i] = new double[n];

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = a[j][i];
		}
	}

	return matrix;     
}

// Calculate Inverse Matrix

double** matrixInverse(double** A, int n)
{
	double** a = new double*[2 * n];
        for (int i = 0; i < 2 * n; i++)
                a[i] = new double[2 * n];

    double** matrix = new double*[n];
        for (int i = 0; i < n; i++)
                matrix[i] = new double[n];

    double d = 0.0;

    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++)
    	{
    		a[i][j] = A[i][j];
    	}
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j == (i + n))
            {
                a[i][j] = 1;
            }
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i-1][1] < a[i][1])
        {
            for(int j = 0; j < n * 2; j++)
            {
                d = a[i][j];
                a[i][j] = a[i-1][j];
                a[i-1][j] = d;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (j != i)
            {
                d = a[j][i] / a[i][i];
                for (int k = 1; k <= n * 2; k++)
                {
                    a[j][k] = a[j][k] - (a[i][k] * d);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        d = a[i][i];
        for (int j = 0; j < n * 2; j++)
        {
            a[i][j] = a[i][j] / d;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = a[i][j + n];
        }
    }

    return matrix;
}

#endif