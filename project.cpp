#include <iostream>
using namespace std;

// Function to check if the matrix is scalar, diagonal, identity, or only square
void checkMatrixType(int result[10][10], int rows, int cols)
{
    bool isScalar = true, isDiagonal = true, isIdentity = true;

    int diagonalValue = result[0][0]; // For scalar check, we'll use the first diagonal element

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            // Check for scalar: diagonal elements must be the same, and off-diagonal elements must be zero
            if (i != j && result[i][j] != 0)
            {
                isScalar = false;
            }
            if (i == j && result[i][j] != diagonalValue)
            {
                isScalar = false;
            }

            // Check for diagonal: non-diagonal elements must be zero
            if (i != j && result[i][j] != 0)
            {
                isDiagonal = false;
            }

            // Check for identity: diagonal elements must be 1, off-diagonal elements must be zero
            if (i == j && result[i][j] != 1)
            {
                isIdentity = false;
            }
            if (i != j && result[i][j] != 0)
            {
                isIdentity = false;
            }
        }
    }

    // Display result based on checks
    if (isIdentity)
    {
        cout << "The matrix is an Identity matrix." << endl;
    }
    else if (isScalar)
    {
        cout << "The matrix is a Scalar matrix." << endl;
    }
    else if (isDiagonal)
    {
        cout << "The matrix is a Diagonal matrix." << endl;
    }
    else
    {
        cout << "The matrix is a Square matrix, but it is neither Scalar, Diagonal, nor Identity." << endl;
    }
}

int main()
{
    int rows1, cols1;
    int rows2, cols2;
    char choice;
    int choice2;
    int result[10][10];
    bool compatible = false;
    // Input 1st matrix dimensions
    cout << "Enter the number of rows for the matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for the matrix 1: ";
    cin >> cols1;
    if (rows1 <= 0 || cols1 <= 0)
    {
        cout << "Matrix dimensions cannot be 0 or Negative. Please rerun the program";
        return 0;
    }
    int A[rows1][cols1];

    // Input elements of matrix A
    cout << endl
         << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Input 2nd matrix dimensions
    cout << endl
         << "Enter the number of rows for the matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for the matrix 2: ";
    cin >> cols2;
    if (rows2 <= 0 || cols2 <= 0)
    {
        cout << "Matrix dimensions cannot be 0 or Negative. Please rerun the program";
        return 0;
    }
    int B[rows2][cols2];
    // Input elements of matrix B
    cout << endl
         << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < rows2; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> B[i][j];
        }
    }

    cout << endl
         << "Press A for Addition." << endl
         << "Press S for Subtraction." << endl
         << "Press M for Multiplication." << endl;
    cin >> choice;

    if (choice == 'A' || choice == 'a')
    {
        // Addition
        if (rows1 == rows2 && cols1 == cols2)
        {
            compatible = true;
            for (int i = 0; i < rows1; ++i)
            {
                for (int j = 0; j < cols1; ++j)
                {
                    result[i][j] = A[i][j] + B[i][j];
                }
            }
        }
        else
        {
            cout << "Matrix dimensions Not compatible";
        }

        if (compatible)
        {
            cout << endl
                 << "Result of matrix addition:" << endl;
            for (int i = 0; i < rows1; ++i)
            {
                for (int j = 0; j < cols1; ++j)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl
                 << "Do you want to see Type of your Result matrix?" << endl
                 << "If you want then press 1" << endl;
            cin >> choice2;
            if (choice2 == 1)
            {
                checkMatrixType(result, rows1, cols1);
            }
            else
            {
                return 0;
            }
        }
    }
    else if (choice == 'S' || choice == 's')
    {
        // Subtraction
        if (rows1 == rows2 && cols1 == cols2)
        {
            compatible = true;
            for (int i = 0; i < rows1; ++i)
            {
                for (int j = 0; j < cols1; ++j)
                {
                    result[i][j] = A[i][j] - B[i][j];
                }
            }
        }
        else
        {
            cout << "Matrix dimensions Not compatible";
        }
        if (compatible)
        {
            cout << endl
                 << "Result of matrix Subtraction:" << endl;
            for (int i = 0; i < rows1; ++i)
            {
                for (int j = 0; j < cols1; ++j)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl
                 << "Do you want to see Type of your Result matrix?" << endl
                 << "If you want then press 1" << endl;
            cin >> choice2;
            if (choice2 == 1)
            {
                checkMatrixType(result, rows1, cols1);
            }
            else
            {
                return 0;
            }
        }
    }
    else if (choice == 'M' || choice == 'm')
    {
        // Multiplication
        if (cols1 == rows2)
        {
            compatible = true;
            for (int i = 0; i < rows1; ++i)
            {
                for (int j = 0; j < cols2; ++j)
                {
                    result[i][j] = 0;
                    for (int k = 0; k < cols1; ++k)
                    {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            if (compatible)
            {
                cout << endl
                     << "Result of matrix multiplication:" << endl;
                for (int i = 0; i < rows1; ++i)
                {
                    for (int j = 0; j < cols2; ++j)
                    {
                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl
                     << "Do you want to see Type of your Result matrix?" << endl
                     << "If you want then press 1" << endl;
                cin >> choice2;
                if (choice2 == 1)
                {
                    checkMatrixType(result, rows1, cols2);
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            cout << "Matrix dimensions are not compatible for multiplication!" << endl;
            return 0;
        }
    }
    else
    {
        cout << " Invalid choice, please rerun the program.";
        return 0;
    }

    return 0;
}
