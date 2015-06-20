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

	bool is_legal();
	int rows_number();
	int cols_number();
	string plus_matrixes(string matrix2);
	string minus_matrixes(string matrix2);
	string mult_matrixes(string matrix2);
	string mult_matrix_int(int x);
	void change_value(int i, int j, int value);
	string get_value(int i, int j);
};

#endif /* MATRIX_PROJECT_CPP_ */
