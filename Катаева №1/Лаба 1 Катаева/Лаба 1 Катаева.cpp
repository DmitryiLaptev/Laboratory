#include "pch.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>

std::pair<int, bool> input_int() {
	std::string s;
	std::cin >> s;

	std::stringstream ss(s);
	int i;
	ss >> i;
	return std::make_pair(i, ss.eof());
}

std::pair<double, bool> input_double() {
	std::string s;
	std::cin >> s;

	std::stringstream ss(s);
	double d;
	ss >> d;
	return std::make_pair(d, ss.eof());
}

// Вектор векторов - это исходная матрица построчно
// Функция каждый раз возвращает новую матрицу
std::vector<std::vector<double>> matrix() {
	std::string s;

	std::vector<std::vector<double>> matr;
	int rows, cols;

	bool ok = true;
	do {
		if (!ok) {
			std::cout << "Wrong input ..." << std::endl;
			ok = true;
		}
		std::cout << "Enter the number of rows: " << std::endl;
		std::pair<int, bool> ib = input_int();
		rows = ib.first;
		ok = ib.second;
	} while (!ok || rows <= 0);

	ok = true;
	do {
		if (!ok) {
			std::cout << "Wrong input ..." << std::endl;
			ok = true;
		}
		std::cout << "Enter the number of cols: " << std::endl;
		std::pair<int, bool> ib = input_int();
		cols = ib.first;
		ok = ib.second;
	} while (!ok || cols != (rows + 1));

	for (int i = 0; i < rows; i++)
	{
		std::vector<double> str;
		double num;
		std::cout << "Enter the row " << i << ":" << std::endl;
		for (int j = 0; j < cols; j++)
		{

			ok = true;
			do {
				if (!ok) {
					std::cout << "Wrong input ..." << std::endl;
					ok = true;
				}
				std::cout << "Enter the element(" << i << "," << j << "): ";
				std::pair<double, bool> ib = input_int();
				num = ib.first;
				ok = ib.second;
			} while (!ok);
			str.push_back(num);
		}
		matr.push_back(str);
	}
	return matr;
}

// Функция печати на консоль вектора значений
std::ostream& operator<<(std::ostream& os, std::vector<double> vec) {
	os << "[";                                  // печатаем открываюзую скобку
	for (int i = 0; i < vec.size(); i++) {      // цикл по каждому элементу
		if (i != 0) os << ",";                  // если элемент не первый, то печатаем запятую после предыдущего
		os << vec[i];                           // печатаем сам элемент
	}
	os << "]";                                  // печатаем закрывающую скобку
	return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<double>> m) {
	for (int i = 0; i < m.size(); i++) {
		os << m[i] << std::endl;
	}
	return os;
}

// Метод Гаусса
std::vector<double> gauss_method(std::vector<std::vector<double>> mat) {

	std::vector<std::vector<double>> m = mat;				    // получаем исходную матрицу
																// Приведение матрицы к "треугольной"
	for (int var = 0; var < m.size() - 1; var++) {              // цикл по узловому элементу
		for (int row = var + 1; row < m.size(); row++) {        // цикл по каждой строке под узловой
			double k = m[row][var] / m[var][var];               // вычисляем отношение строк
			for (int col = var; col < m.size() + 1; col++) {    // цикл по каждому элементу строки под узловой
				m[row][col] -= k * m[var][col];                 // вычисляем каждый элемент строки под узловой
			}
		}
	}

	// Вычисление результата
	std::vector<double> result(m.size(), 0);                    // вектор под результат, изначально заполняем нулями
	for (int var = m.size() - 1; var >= 0; var--) {             // цикл в обратном порядке, результат вычисляем с конца
		double sum = m[var][m.size()];                          // переменная для накопления - изначально заполняется значением правой части системы для соответствующей переменной
		for (int prev = var + 1; prev < m.size(); prev++) {     // цикл по уже вычисленным переменным
			sum -= result[prev] * m[var][prev];                 // добавляем в накопитель отрицательное значение произведения вычисленного результата и соответствуюзего элемента матрицы
		}
		result[var] = sum / m[var][var];                        // делим значение накопителя на элемент матрицы для данного результата
	}

	return result;                                              // возвращаем результат
}

// Метод простых итераций
std::vector<double> iteration_method(std::vector<std::vector<double>> mat, double eps) {

	std::vector<std::vector<double>> m = mat;					// получаем исходную матрицу

	std::vector<double> result;
	for (int i = 0; i < m.size(); i++) {
		result.push_back(double(std::rand()) / RAND_MAX);                    // вектор под результат, изначально заполняем нулями
	}

	while (true) {
		std::vector<double> result1;                            // вектор под следующий результат по итогам итерации
		for (int row = 0; row < m.size(); row++) {              // цикл для каждой переменной в итерации
			double r = m[row][m.size()];                        // заполняем накопитель правой частью
			for (int col = 0; col < m.size(); col++) {          // в цикле вычитаем остальные переменные
				if (col != row) {                               // условие чтобы не вычитать собственное значение
					r -= m[row][col] * result[col];
				}
			}
			r /= m[row][row];                                   // делим накопитель на соответствующее значение матрицы
			result1.push_back(r);                               // заносим вычисленное значение в результат итерации
		}

		// result - результат предыдущей итерации
		// result1 - результат текущей итерации
		double sum_eps = 0;                                     // вычисляем суммарную разницу между result и result1
		for (int i = 0; i < result.size(); i++) {
			sum_eps += std::abs(result1[i] - result[i]);
		}
		if (sum_eps < eps) return result1;                      // если разница меньше требуемого `eps` - результат найден

		result = result1;                                       // иначе укладываем результат текущей итерации в result и запускаем итерацию заново
	}
}

// Метод Зейделя
// Метод идентичен методу простой итерации за исключением единственного нюанса:
//   при вычислении значений текущей итерации используются уже вычисленные значения текущей итерации,
//   если они доступны. Если не доступны, то значения предыдущей итерации
std::vector<double> seidel_method(std::vector<std::vector<double>> mat, double eps) {

	std::vector<std::vector<double>> m = mat;					// получаем исходную матрицу

	std::vector<double> result;
	for (int i = 0; i < m.size(); i++) {
		result.push_back(double(std::rand()) / RAND_MAX);                    // вектор под результат, изначально заполняем нулями
	}

	while (true) {
		std::vector<double> result1;
		for (int row = 0; row < m.size(); row++) {
			double r = m[row][m.size()];
			for (int col = 0; col < m.size(); col++) {
				if (row < col) {                                // это единственное отличие от метода простой итерации
					r -= m[row][col] * result[col];             // там использовался result[col], тут result1[col] (текущая итерация), если уже вычислен,
				}
				else if (row > col) {                         // или result[col] (предыдущая итерация)
					r -= m[row][col] * result1[col];
				}
			}
			r /= m[row][row];
			result1.push_back(r);
		}

		double sum_eps = 0;
		for (int i = 0; i < result.size(); i++) {
			sum_eps += std::abs(result1[i] - result[i]);
		}
		if (sum_eps < eps) return result1;

		result = result1;
	}
}



bool is_good2(std::vector<std::vector<double>> m) {
	for (int col = 0; col < m.size(); col++) {
		double sum = 0;
		for (int row = 0; row < m.size(); row++) {
			if (col != row) {
				if (m[row][row] == 0) return false;
				sum += std::abs(m[row][col] / m[row][row]);
			}
		}
		if (sum >= 1.0) return false;
	}
	return true;
}


int main() {
	std::srand(std::time(nullptr));

	std::vector<std::vector<double>> m = matrix();

	std::cout << "Gauss method:\t\t" << gauss_method(m) << std::endl;

	bool good = is_good2(m);
	std::cout << "good: " << good << std::endl;
	if (good) {
		std::cout << "Iteration method:\t" << iteration_method(m, 0.0001) << std::endl;
		std::cout << "Seidel method:\t\t" << seidel_method(m, 0.0001) << std::endl;
	}

	return 0;
}
