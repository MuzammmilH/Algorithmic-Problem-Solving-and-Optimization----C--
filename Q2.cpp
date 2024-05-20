//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//
//
//int extractMatrixSize(const string& line) {
//    // Find the position of '(' and 'x' in the line
//    size_t openingParenthesis = line.find('(');
//    size_t closingParenthesis = line.find(')');
//
//    // Check if the expected characters are found
//    if (openingParenthesis != string::npos && closingParenthesis != string::npos &&
//        openingParenthesis < closingParenthesis) {
//
//        // Extract the substring between '(' and 'x' and convert it to an integer
//        string sizeStr = line.substr(openingParenthesis + 1, closingParenthesis - openingParenthesis - 1);
//        return stoi(sizeStr);
//    }
//    else {
//        cerr << "Error: Matrix size not found in the expected format." << endl;
//        return -1; // Return -1 to indicate an error
//    }
//}
//
//char** readMatrixFromFile(const std::string& filename, int& rows, int& cols) {
//    // Open the file
//    std::ifstream file(filename);
//
//    // Check if the file is open
//    if (!file.is_open()) {
//        std::cerr << "Error opening the file." << std::endl;
//        return nullptr;
//    }
//
//    // Read the size of the matrix
//    file >> rows >> cols;
//
//    // Allocate dynamic memory for the matrix
//    char** matrix = new char* [rows];
//    for (int i = 0; i < rows; ++i) {
//        matrix[i] = new char[cols];
//    }
//
//    // Read the matrix from the file
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            file >> matrix[i][j];
//        }
//    }
//
//    // Close the file
//    file.close();
//
//    // Return the matrix
//    return matrix;
//}
//
//void displayMatrix(char** matrix, int rows, int cols) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            std::cout << matrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//void deleteMatrix(char** matrix, int rows) {
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//
//
//
//int main() {
//    ifstream inputFile("input.txt");
//
//    if (!inputFile.is_open()) {
//        cerr << "Error opening the file." << endl;
//        return 1;
//    }
//
//    // Read the first line to get the matrix size
//    string line;
//    getline(inputFile, line);
//
//    // Matrix size obtained from extractMatrixSize function
//    int matrixSize = extractMatrixSize(line);
//
//    // Display the extracted matrix size
//    if (matrixSize != -1) {
//        cout << "Matrix Size: " << matrixSize << endl;
//
//     
//    }
//
//    // Close the file
//    inputFile.close();
//
//    return 0;
//}

#include "filereading.h"
#include <iostream>


int pattrenCounter(char** matrix, char** pattern, int matrixSize, int patternSize) {
    int count = 0;

    for (int row = 0; row <= matrixSize - patternSize; ++row) {
        for (int col = 0; col <= matrixSize - patternSize; ++col) {
            bool flag = true;

            for (int i = 0; i < patternSize; ++i) {
                for (int j = 0; j < patternSize; ++j) {
                    if (matrix[row + i][col + j] != pattern[i][j]) {
                        flag = false;
                        break;
                    }
                }

                if (flag == false) { break; }
            }

            if (flag == true) {
                count++;
                row += patternSize - 1; 
                break; 
            }
        }
    }
    
    if (count == 1) { count = 0; }
    
    return count;
}
void runnerCode(const std::string fileName) {
    int expRes, pSize;
    int tSize = matrixSize(fileName);
    char** matrix = readMatrixFromFile(fileName, tSize);
    char** pattrens = pattren(fileName, matrix, tSize, expRes, pSize);

    std::cout << std::endl;
    std::cout << "Given Matrix" << std::endl;
    displayMatrix(matrix, tSize);

    std::cout << std::endl;
    std::cout << "Given Pattren" << std::endl;
    displayMatrix(pattrens, pSize);

    std::cout << std::endl;
    std::cout << "Occurance Expected: " << expRes << std::endl;

    std::cout << std::endl;
    std::cout << "Occurance found: "
    << pattrenCounter(matrix, pattrens, tSize, pSize) << std::endl;
    
    if (expRes == pattrenCounter(matrix, pattrens, tSize, pSize)) {
        std::cout << "\nTrue" << std::endl;
    }
    else {
        
        std::cout << "\nFalse" << std::endl;
    }

    deleteMatrix(matrix, tSize);
    deleteMatrix(pattrens, pSize);
    return ;

}
int main() {
    
    runnerCode("TestCase1.txt");
    runnerCode("TestCase2.txt");
    runnerCode("TestCase3.txt");

}

