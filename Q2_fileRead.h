#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

void displayMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

char** pattren(const std::string& filename, char** matrix, int size, int &result, int &pSize) {
    std::ifstream file(filename);


    if (!file.is_open()) {
        std::cout << "File Opening Failed" << std::endl;
        return nullptr;
    }

    char ch;
    while (file >> ch && ch != ')') {}
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            while (file.peek() == ',') {
                file.ignore();
            }
            file >> ch;          
        }        
    }
    
    while (file.peek() == '\n') {
        file.ignore();
    }

    std::string pattrenLine;
    std::getline(file, pattrenLine);
    while (file.peek() == '\n') {
        file.ignore();
    }
    file >> ch;
    result = ch - '0';
    //std::cout << line << std::endl;
 
    pSize = sqrt(pattrenLine.length());
    
    char** pattrens = new char* [pSize];
    for (int i = 0; i < pSize; ++i) {
        pattrens[i] = new char[pSize];
    }
   
    for (int i = 0; i < pSize; i++) {
        for (int j = 0; j < pSize; j++) {
            pattrens[i][j] = pattrenLine[(i * pSize) + j];
        }
    }
    //displayMatrix(pattrens, m);
    return pattrens;
}


int matrixSize(const std::string& filename) {
    
    std::ifstream sizeFile(filename);

    if (!sizeFile.is_open()) {
        std::cout<< " File Reading Failed " << std::endl;
        return 0;
    }

    char size;
    while (sizeFile >> size && size != '(') {}

    sizeFile >> size;
    sizeFile.close();
    return size - '0';

}


char** readMatrixFromFile(const std::string& filename, int& tSize) {

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << " File Reading Failed " << std::endl;
        return nullptr;
    }


    char mat;
    while (file >> mat && mat != ')') {}

    char** matrix = new char* [tSize];
    for (int i = 0; i < tSize; ++i) {
        matrix[i] = new char[tSize];
    }

    for (int i = 0; i < tSize; ++i) {
        for (int j = 0; j < tSize; ++j) {
            while (file.peek() == ',') {
                file.ignore();
            }
            file >> matrix[i][j];
        }
    }

    file.close();

    return matrix;
}




