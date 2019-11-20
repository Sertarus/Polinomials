#ifndef POLINOMIALS_H
#define POLINOMIALS_H

#include<iostream>

class Polinomial
{
public:
	Polinomial();

	Polinomial(int degree);

	Polinomial(const Polinomial& other);

	~Polinomial();

	void setCoefficient(int index, double coefficient);

	double getCoefficient(int index);

	int getDegree() const;

	Polinomial& operator+=(const Polinomial& right);

	Polinomial& operator-=(const Polinomial& right);

	Polinomial& operator*=(const Polinomial& right);

	friend Polinomial operator+(const Polinomial& left, const Polinomial& right);

	friend Polinomial operator-(const Polinomial& left, const Polinomial& right);

	friend Polinomial operator*(const Polinomial& left, const Polinomial& right);

	friend std::ostream& operator<<(std::ostream& out, const Polinomial& p);

	friend std::istream& operator>>(std::istream& in, Polinomial& p);

private:
	double* coefficients;
	int degree;
};

#endif