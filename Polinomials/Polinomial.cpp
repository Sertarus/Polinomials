#include "Polinomial.hpp"
#include <iostream>
#include <string>

using namespace std;

Polinomial::Polinomial() {

}

Polinomial::Polinomial(int degree) {
	this->coefficients = new double[degree + 1]();
	this->degree = degree;
}

Polinomial::Polinomial(const Polinomial& other) : Polinomial(other.degree){
	for (int i = 0; i <= other.degree; i++) {
		this->coefficients[i] = other.coefficients[i];
	}
}

Polinomial::~Polinomial() {
	delete[] this->coefficients;
}

void Polinomial::setCoefficient(int index, double coefficient) {
	try
	{
		if (index > this->degree) throw "Index Out Of Bounds";
		this->coefficients[index] = coefficient;
	}
	catch (const char* err) {
		cerr << err << endl;
	}
}

double Polinomial::getCoefficient(int index) {
	try
	{
		if (index > this->degree) throw "Index Out Of Bounds";
		return this->coefficients[index];
	}
	catch (const char* err) {
		cerr << err << endl;
	}
	return -1;
}

int Polinomial::getDegree() const {
	return this->degree;
}

Polinomial& Polinomial::operator+=(const Polinomial& right) {
	Polinomial new_polinomial = Polinomial(right.degree > this->degree ? right.degree : this->degree);
	for (int i = 0; i <= new_polinomial.degree; i++) {
		new_polinomial.coefficients[i] = (i <= right.degree ? right.coefficients[i] : 0) + (i <= this->degree ? this->coefficients[i] : 0);
	}
	delete[] this->coefficients;
	this->coefficients = new double[new_polinomial.degree + 1];
	memcpy_s(this->coefficients, (new_polinomial.degree + 1) * sizeof(double), new_polinomial.coefficients, (new_polinomial.degree + 1) * sizeof(double));
	this->degree = new_polinomial.degree;
	return *this;
}

Polinomial& Polinomial::operator-=(const Polinomial& right) {
	Polinomial new_polinomial = Polinomial(right.degree > this->degree ? right.degree : this->degree);
	for (int i = 0; i <= new_polinomial.degree; i++) {
		new_polinomial.coefficients[i] = (i <= this->degree ? this->coefficients[i] : 0) - (i <= right.degree ? right.coefficients[i] : 0);
	}
	delete[] this->coefficients;
	this->coefficients = new double[new_polinomial.degree + 1];
	memcpy_s(this->coefficients, (new_polinomial.degree + 1) * sizeof(double), new_polinomial.coefficients, (new_polinomial.degree + 1) * sizeof(double));
	this->degree = new_polinomial.degree;
	return *this;
}

Polinomial& Polinomial::operator*=(const Polinomial& right) {
	Polinomial new_polinomial = Polinomial(right.degree + this->degree);
	for (int i = 0; i <= right.degree; i++) {
		for (int j = 0; j <= this->degree; j++) {
			new_polinomial.coefficients[i + j] = right.coefficients[i] * this->coefficients[j] + new_polinomial.coefficients[i + j];
		}
	}
	delete[] this->coefficients;
	this->coefficients = new double[new_polinomial.degree + 1];
	memcpy_s(this->coefficients, (new_polinomial.degree + 1) * sizeof(double), new_polinomial.coefficients, (new_polinomial.degree + 1) * sizeof(double));
	this->degree = new_polinomial.degree;
	return *this;
}

Polinomial operator+(const Polinomial& left, const Polinomial& right) {
	Polinomial result = Polinomial(right.degree > left.degree ? right.degree : left.degree);
	result += left;
	result += right;
	return Polinomial(result);
}

Polinomial operator-(const Polinomial& left, const Polinomial& right) {
	Polinomial result = Polinomial(right.degree > left.degree ? right.degree : left.degree);
	result += left;
	result -= right;
	return Polinomial(result);
}

Polinomial operator*(const Polinomial& left, const Polinomial& right) {
	Polinomial result = Polinomial(left.degree * right.degree);
	result += left;
	result *= right;
	return Polinomial(result);
}

std::ostream& operator<<(std::ostream& out, const Polinomial& p) {
	string str = "";
	for (int i = p.degree; i >=0; i--)
		str += (p.coefficients[i] == 0 ? "" : (p.coefficients[i] > 0 ? "+ " : "- ") + to_string(abs(p.coefficients[i])) + (i == 0 ? "" : "x")
			+ (i < 2 ? "" : "^" + to_string(i)) + " ");
	if (str.length() == 0) {
		cout << "0";
	}
	else {
		cout << str.substr(2);
	}
	return out;
}

std::istream& operator>>(std::istream& in, Polinomial& p) {
	int degree;
	std::cout << "Degree: ";
	in >> degree;
	p.coefficients = new double[degree + 1]();
	p.degree = degree;
	for (int i = 0; i <= p.degree; i++) {
		std::cout << "x^" << i << ": ";
		in >> p.coefficients[i];
	}
	return in;
}