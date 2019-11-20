#include <iostream>
#include "Polinomial.hpp"
#include<string>

using namespace std;

int main() {
	Polinomial p1;
	Polinomial p2;
	cin >> p1;
	cout << "p1: " << p1 << endl;
	Polinomial p1_copy(p1);
	cin >> p2;
	cout << "p2: " << p2 << endl;
	p1 += p2;
	cout << "p1 += p2: " << p1 << endl;
	p1 -= p2;
	cout << "p1 -= p2: " << p1 << endl;
	p1 *= p2;
	cout << "p1 *= p2: " << p1 << endl;
	cout << "p1 + p2: " << p1_copy + p2 << endl;
	cout << "p1 - p2: " << p1_copy - p2 << endl;
	cout << "p1 * p2: " << p1_copy * p2 << endl;
}