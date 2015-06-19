#ifndef MATRIX_PROJECT_CPP_
#define MATRIX_PROJECT_CPP_

using std::string;

class Matrix {
public:
	int* matrix;
	string matrix_str;
	int rowsNum;
	int colsNum;

	Matrix(string matrix_str);

	void is_legal(string matrix);
	int rows_number();
	int cols_number();
	int* plus_matrixes(string matrix1, string matrix2);
	int* minus_matrixes(string matrix1, string matrix2);
	int* mult_matrixes(string matrix1, string matrix2);
	void change_value(string matrix1, int i, int j, int value);
};

#endif /* MATRIX_PROJECT_CPP_ */
