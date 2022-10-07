#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
//#include <Windows.h>
#include <regex>
using namespace std;

int dz4_1() {
	string s;
	cout << "Введите в 1 строку 10 чисел : " << endl;
	getline(cin, s); //считывает всё включая пробелы
	
	ofstream fout("File_dz_4.txt");
	fout << s;
	fout.close();
	
	double x = 0, sum = 0;
	ifstream fin("File_dz_4.txt");
	for (int i = 0; i < 10; i++) {
		if (!(fin >> x)) {
			cout << "Введены неверные данные!" << endl;
			return 0;
		}
		sum += x;
	}
	cout << sum;
	return 0;
}

int sign(double x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}
int dz4_2() {
	double num;
	cout << "Введите число: ";
	if (!(cin >> num)) {
		cout << "Введены неверные данные";
		return 0;
	}
	int rez;
	rez = sign(num);
	if (rez == 1) cout << "Число положительное";
	else if (rez == 0) cout << "0 не отрицательный";
	else cout << "Число отрицательное";
	return 0;
}


int S_triangle() { // допилить несколько формул
	cout << "Ввидите номер команды: " << endl;
	cout << "1 - посчитать площадь по Формуле Герона" << endl;
	cout << "2 - посчитать площадь через 2 стороны и угол между ними" << endl;
	cout << "3 - посчитать площадь через основание и высоту" << endl;
	cout << "4 - посчитать площадь через сторону и 2 прележащих к ней угла" << endl;
	int num = 0;
	if (!(cin >> num)) {
		cout << "Неверная команда" << endl;
		return 0;
	}
	double a = 0, b = 0, c = 0, p = 0, alpha = 0, beta = 0, h = 0;
	switch (num)
	{
	case 1:
		cout << "Введите все стороны треугольника: ";
		cin >> a;
		cin >> b;
		cin >> c;
		if (a <= 0 || b <= 0 || c <= 0) {
			cout << "Стороны треугольника должны быть положительными" << endl;
			return 0;
		}
		p = (a + b + c) / 2;
		if (max(a, max(b, c)) >= (a + b + c - max(a, max(b, c))))
		{
			cout << "Неравенство треугольника не выполняется! ";
			return 0;
		}
		cout << "Площадь треугольника равна: " << sqrt((p * (p - a) * (p - b) * (p - c)));
		break;
	case 2:
		cout << "Введите величину 1 стороны, 2 стороны, и угла между ними в градусах:" << endl;
		if (!(cin >> a >> b >> alpha) || alpha <= 0 || a <= 0 || b <= 0) {
			cout << "Неверные данные";
			return 0;
		}
		cout << "Площадь треугольника равна: " << (a * b * sin(alpha * M_PI / 180)) / 2 << endl;
		break;
	case 3:
		cout << "Введите основание и высоту" << endl;
		if (!(cin >> a >> h) || a <= 0 || h <= 0) {
			cout << "Неверные данные";
			return 0;
		}
		cout << "Площадь треугольника равна: " << a * h / 2 << endl;
		break;
	case 4:
		cout << "Введите сторону, 1 угол прелижащий к ней и 2 угол прилежащий к ней:" << endl;
		if (!(cin >> a >> alpha >> beta) || alpha <= 0 || a <= 0 || beta <= 0 || (alpha + beta >=180)) {
			cout << "Неверные данные";
			return 0;
		}
		cout << "Площадь треугольника равна: ";
		cout << pow(a, 2) * sin(alpha * M_PI / 180) * sin(beta * M_PI / 180) / 2 / sin((180 - alpha - beta) * M_PI / 180);
		break;
	default:
		cout << "Неверная команда" << endl;
		break;
	}
	
	return 0;
}
int S_rectangle() {
	double a, b;
	cout << "Введите все стороны треугольника";
	if (!(cin >> a >> b) || a<0 || b<0) {
		cout << "Введены неверные данные!";
		return 0;
	}
	cout << "Площадь прямоугольника равна: " << a * b << endl;
	return 0;
}
int S_circle() {
	double R;
	cout << "Введите радиус: ";
	if (!(cin >> R) || R<0) {
		cout << "Введены неверные данные!";
		return 0;
	}
	cout << "Площадь круга равна: " << pow(R, 2) * M_PI;;
	return 0;
}
int dz4_3() {
	cout << "Площадь какой фигуры необходимо посчитать? (1 - треугольник, 2 - прямоугольник, 3 - круг)" << endl;
	int num;
	if (!(cin >> num) || num < 1 || num > 3) {
		cout << "Введены неверные данные!" << endl;
		return 0;
	}
	if (num == 3) {
		S_circle();
	}
	else if (num == 2) {
		S_rectangle();
	}
	else if (num == 1) {
		S_triangle();
	}
	return 0;
}

int dz4_4() {
	int count_zvezd = 0;
	for (int i = 0; i < 13; i++) {
		for (int z = 0; z < 50; z++) {
			if (i < 7 && i > 0) {
				if (z < 8) {
					cout << "*";
				}
				else cout << "-";
			}
			else {
				cout << "-";
			}
		}
		cout << "\n";
	}
	return 0;
}

int dz4_5() {
	HWND hwnd = GetConsoleWindow(); //окно
	HDC hdc = GetDC(hwnd); //холст
	double x = 0;
	for (float i = 0; i < 3.14 * 100; i += 0.05) {
		SetPixel(hdc, x, 200 + 40 * sin(i), RGB(2, 255, 255));
		x += 1;
	}
	x = 0;
	for ( double i = 0; i < 3.14 * 100; i += 0.05) {
		SetPixel(hdc, x, 200, RGB(255, 255, 255));
		x += 1;
	}
	x = 0;
	for ( double i = 0; i < 3.14 * 100; i += 0.05) {
		SetPixel(hdc, 440, x, RGB(255, 255, 255));
		x += 1;
	}
	ReleaseDC(hwnd, hdc);
	cin.ignore();
	return 0;
}

int rim_number(char x) {
	if (x == 'I') return 1;
	if (x == 'V') return 5;
	if (x == 'X') return 10;
	if (x == 'L') return 50;
	if (x == 'C') return 100;
	if (x == 'D') return 500;
	if (x == 'M') return 1000;
	cout << "Введены некорректные данные!";
	return 0;
}
int dz4_6() {
	string s;
	cout << "Введите строку римское число: ";
	cin >> s;
	cmatch result;
	regex regular("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
	if (regex_match(s.c_str(), result, regular)) cout << "Число равно: ";
	else {
		cout << "Введено неверное число";
		return 0;
	}
	int res = 0, temp = 0, n = 0;
	for (int i = 0; i < s.size(); i++) {
		n = rim_number(s[i]);
		if (n < temp) {
			res += temp;
			temp = n;
		}
		else if (n > temp) {
			if (temp == 0) {
				temp = n;
			}
			else {
				res += n - temp;
				temp = 0;
			}
		}
		else {
			res += temp + n;
			temp = 0;
		}
	}
	res += temp;
	cout << res;
	return 0;
}

int main() {
	setlocale(0, "");
	//dz4_1();
	//dz4_2();
	//dz4_3();
	//dz4_4();
	//dz4_5();
	//dz4_6();
	return 0;
}