/*
1. Read in rows and col into const int
2. Declare array1, array2, and sumarray as int arrays with size as rows and col
3. Declare addMatrix and printResult as void functions
4. In main function
5. Input time into seed. Input seed into srand function
6. Read in num into int
7. For i is less than rows
    For j is than col
        Generate random numbers between 0 and 50 and store in array1
8. For i is less than rows
    For j is than col
        Generate random numbers between 0 and 50 and store in array2
9. Call addMatrix function with array1, array2, and sumarray as arguments
10. In addMatrix function
11. Initialize sum
12. For i is less than rows
    For j is than col
        Calculate sum by array1 plus array2 and store in sumarray
13. Read in + into char variable
14. Call printResult function with 3 arrays and char as arguments
15. In printResult function
16. Display array1
17. Display array2
18. Display the first row of array1, array2, and sumarray
19. Display the second row of array1, array2, and sumarray
    Print '+' between array1 and array 2 and print '=' between array2 and sumarray
20. Display the third row of array1, array2, and sumarray
*/

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// read # of rows and columns into const int
// 3 columns, 3 rows
const int rows = 3;
const int col = 3;

// arrays
int array1 [rows][col] = {};
int array2 [rows][col] = {};
int sumarray [rows][col] = {};

// function prototypes
void addMatrix(int array1[rows][col], int array2[rows][col], int sumarray[rows][col]);
void printResult(int array1[rows][col], int array2[rows][col], int sumarray[rows][col], char);

int main ()
{
    // generates random number
    unsigned seed = time(0);
    srand(seed);

    int num;

    // get elements for array 1
    for (int i = 0; i < rows; i++)  // moves along rows
    {
        for (int j = 0; j < col; j++)   // moves along columns
        {
            num = rand () % 51; // random numbers between 0-50
            array1 [i][j] = num;
        }
    }

    // get elements for array 2
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            num = rand () % 51;
            array2 [i][j] = num;
        }
    }

    // call addmatrix function with 3 arrays as arguments
    addMatrix (array1, array2, sumarray);

}
// in addMatrix function
void addMatrix(int array1[rows][col], int array2[rows][col], int sumarray[rows][col])
{
    // initialize variables
    int sum = 0;
    int i;

    for (i = 0; i < rows; i++)  // moves along rows
    {
        for (int j = 0; j < col; j++)   // moves along columns
        {
            sum = array1 [i][j] + array2 [i][j];    // adds both arrays in the same element
            sumarray [i][j] = sum;  // stores sums into sum array
        }
    }

    // read in + into char
    char plussign = '+';

    // call printResult with 3 arrays and char
    printResult (array1, array2, sumarray, plussign);
}

// in printResult function
void printResult(int array1[rows][col], int array2[rows][col], int sumarray[rows][col], char plussign)
{
    cout << "Matrix 1 is: " << endl;
    int i;

    // display matrix 1
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(3) << left << array1 [i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Matrix 2 is: " << endl;

    // display matrix 2
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(3) << left << array2 [i][j];
        }
        cout << endl;
    }

    //------------------------------------------------

    cout << endl;
    cout << "The addition of the matrices is" << endl;

    // display 1st row of matrix 1
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << array1 [0][i];

    cout << "    ";

    // display 1st row of matrix 2
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << array2 [0][i];

    cout << "    ";

    // display 1st row of sum matrix
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << sumarray [0][i];

    cout << endl;

    //----------------------------------------------

    // display 2nd row of matrix 1
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << array1 [1][i];

    // print char plussign
    cout << " " << plussign << "  ";

    // display 2nd row of matrix 2
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << array2 [1][i];

    cout << " =  ";

    // display 2nd row of sum matrix
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << sumarray [1][i];

    cout << endl;
    //----------------------------------------------

    // display 3rd row of matrix 1
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << array1 [2][i];

    cout << "    ";

    // display 3rd row of matrix 2
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << array2 [2][i];

    cout << "    ";

    // display 3rd row of sum matrix
    for (int i = 0; i < col; i++)
        cout << setw(3) << left << sumarray [2][i];

}

/*
Matrix 1 is:
22 20 36
42 38 40
0  30 19

Matrix 2 is:
30 7  2
36 42 18
29 12 17

The addition of the matrices is
22 20 36     30 7  2      52 27 38
42 38 40  +  36 42 18  =  78 80 58
0  30 19     29 12 17     29 42 36

---------------------------------

Matrix 1 is:
40 33 47
30 18 8
30 13 34

Matrix 2 is:
4  12 9
30 21 8
8  13 4

The addition of the matrices is
40 33 47     4  12 9      44 45 56
30 18 8   +  30 21 8   =  60 39 16
30 13 34     8  13 4      38 26 38

---------------------------------

Matrix 1 is:
12 0  41
42 29 22
8  1  23

Matrix 2 is:
12 24 8
48 34 28
22 24 18

The addition of the matrices is
12 0  41     12 24 8      24 24 49
42 29 22  +  48 34 28  =  90 63 50
8  1  23     22 24 18     30 25 41
*/
