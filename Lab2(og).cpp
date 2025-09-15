#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
  //Billy's input - Had to include the <numeric> library to be able get the iota() and numeric() to test and compile what we got so far.
  #include <numeric> 


// function 1 generate an array of random numbers given size as it's length 
int* intRandom1DArray(int size) {
    
    srand((unsigned)time(NULL));

    
    int* result = new int[size];

    
    std::generate_n(result, size, [&]() { return rand() % 51; });

    return result;
}
// Function 2 generates vector of vectors that is equivalent to a 2D array of random numbers
std::vector<std::vector<int>> intRand2DArray(int rows, int cols) {
    auto createRow = [cols]() {
        std::vector<int> row(cols);
        std::generate(row.begin(), row.end(), []() { return rand() % 51; });
        return row;
    };

    std::vector<std::vector<int>> matrix(rows);
    std::generate(matrix.begin(), matrix.end(), createRow);
    return matrix;
}

// Function 3 Convert an 2D array to a string
std::string arrayToString(int** input, int rows, int cols) {
    std::string result;
    std::for_each(input, input + rows, [&](int* row) {
        std::for_each(row, row + cols, [&](int num) {
            result += std::to_string(num) + " ";
        });
        result += '\n';
    });
    return result;
}
//function 4 generates an ordered array of int
int* generateOrderedArray(int n) {
    int* result = new int[n]; 
    
    std::iota(result, result + n, 0);

    return result;
}
//function 5  calculates the average of a 2d int array
double calculateAverage(int** array, int rows, int cols) {

    int totalSum = std::accumulate(array[0], array[0] + rows * cols, 0);

    
    double average = static_cast<double>(totalSum) / (rows * cols);
    return average;
}

int main() {
  std::cout << "Hello World!\n";


  // Testing for original Function 1
    std::cout << "Testing original intRandom1DArray function:\n";
    int length_1D = 10;
    int* test1D = intRandom1DArray(length_1D);
    for (int i = 0; i < length_1D; i++) {
        std::cout << test1D[i] << " ";
    }
    std::cout << "\n\n";
    delete[] test1D;  // cleanup

    // Testing for original Function 2 
    std::cout << "Testing original intRand2DArray function:\n";
    int length_2D = 10;
    int height_2D = 10;
    auto test2D = intRand2DArray(length_2D, height_2D);
    for (const auto& row : test2D) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // Testing for original Function 3
    std::cout << "Test original arrayToString fucntion:\n";
    int** test2DString = new int*[length_2D];
    for (int i = 0; i < length_2D; i++) {
        test2DString[i] = new int[length_2D];
        for (int j = 0; j < height_2D; j++) {
            test2DString[i][j] = i * height_2D + j + 1;  // simple values
        }
    }
    std::string strRep = arrayToString(test2DString, length_2D, height_2D);
    std::cout << strRep << "\n";
    for (int i = 0; i < length_2D; i++) delete[] test2DString[i];
    delete[] test2DString;

    // Testing for original Function 4
    std::cout << "Test original ordered array function:\n";
    int n = 10;
    int* orderedArray = generateOrderedArray(n);
    for (int i = 0; i < n; i++) {
        std::cout << orderedArray[i] << " ";
    }
    std::cout << "\n\n";
    delete[] orderedArray;

    // Testing for original Function 5
    std::cout << "Test original calculateAverage function:\n";
    
    std::cout << "Average = " << calculateAverage(test2DString, length_2D, height_2D) << "\n\n";
    


     return 0;
}
