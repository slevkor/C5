#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "matrix_project.hpp"

using std::string;
using namespace std;

static void print_matrix(int* m, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(m + (c * i + j)) << " ";
		}
		cout << endl;
	}
}

static string matrix_to_string(int* m, int r, int c) {
	ostringstream stream;
	stream << "[";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			stream << *(m + (c * i + j));
			if (j != c - 1) {
				stream << ",";
			}
		}
		if (i != r - 1) {
			stream << ";";
		}
	}
	stream << "]";
	string result = stream.str();
	return result;
}

Matrix::Matrix(string matrix_str1) :
		matrix_str(matrix_str1) {
	//update rowNum
	rowsNum = count(matrix_str1.begin(), matrix_str1.end(), ';') + 1;

	//split to rows (by ";")
	string row_str = matrix_str1.substr(1, matrix_str1.size() - 2);
	for (int i = 0; i < rowsNum; i++) {
		string row = row_str.substr(0, row_str.find(";"));
		row_str = row_str.substr(row_str.find(";") + 1, row_str.size() - 1);

		//split to cols (by ",")
		if (i == 0) {
			colsNum = count(row.begin(), row.end(), ',') + 1;
			matrix = (int*) malloc(sizeof(int) * (rowsNum * colsNum));
		}
		string col_str = row;
		for (int j = 0; j < colsNum; j++) {
			string col = col_str.substr(0, col_str.find(","));
			*(matrix + (colsNum * i + j)) = atoi(col.c_str());
			col_str = col_str.substr(col_str.find(",") + 1, col_str.size() - 1);
		}
	}
}

bool Matrix::is_legal() {
	int rowsNumber = count(matrix_str.begin(), matrix_str.end(), ';') + 1;
	string row_str = matrix_str.substr(1, matrix_str.size() - 2);
	int colsNumber = 0;
	for (int i = 0; i < rowsNumber; i++) {
		string row = row_str.substr(0, row_str.find(";"));
		row_str = row_str.substr(row_str.find(";") + 1, row_str.size() - 1);
		if (i == 0) {
			colsNumber = count(row.begin(), row.end(), ',') + 1;
		} else {
			if (colsNumber != count(row.begin(), row.end(), ',') + 1) {
				return false;
			}
		}
	}
	return true;
}

int Matrix::rows_number() {
	return rowsNum;
}

int Matrix::cols_number() {
	return colsNum;
}

string Matrix::plus_matrixes(string matrix2) {
	Matrix m2(matrix2);
	int* plusMatrix = (int*) malloc(sizeof(int) * (rowsNum * colsNum));
	for (int i = 0; i < (rowsNum * colsNum); i++) {
		*(plusMatrix + i) = *(matrix + i) + *(m2.matrix + i);
	}
	return matrix_to_string(plusMatrix, rowsNum, colsNum);
}

string Matrix::minus_matrixes(string matrix2) {
	Matrix m2(matrix2);
	int* minusMatrix = (int*) malloc(sizeof(int) * (rowsNum * colsNum));
	for (int i = 0; i < (rowsNum * colsNum); i++) {
		*(minusMatrix + i) = *(matrix + i) - *(m2.matrix + i);
	}
	return matrix_to_string(minusMatrix, rowsNum, colsNum);
}

string Matrix::mult_matrixes(string matrix2) {
	Matrix m2(matrix2);
	int index = 0;
	int* multMatrix = (int*) malloc(sizeof(int) * (rowsNum * m2.colsNum));
	for (int i = 0; i < rowsNum; i++) {
		for (int j = 0; j < m2.colsNum; j++) {
			int rowSum = 0;
			for (int k = 0; k < colsNum; k++) {
				rowSum += (*(matrix + (i * colsNum) + k))
						* (*(m2.matrix + (k * m2.colsNum) + j));
			}
			*(multMatrix + index) = rowSum;
			index++;
		}
	}
	return matrix_to_string(multMatrix, rowsNum, m2.colsNum);
}

string Matrix::mult_matrix_int(int x) {
	int* multMatrix = (int*) malloc(sizeof(int) * (rowsNum * colsNum));
	for (int i = 0; i < (rowsNum * colsNum); i++) {
		*(multMatrix + i) = *(matrix + i) * x;
	}
	return matrix_to_string(multMatrix, rowsNum, colsNum);
}

void Matrix::change_value(int i, int j, int value) {
	*(matrix + ((i - 1) * colsNum) + j - 1) = value;
}

string Matrix::get_value(int i, int j) {
	ostringstream stream;
	stream << *(matrix + ((i - 1) * colsNum) + j - 1);
	return stream.str();
}

