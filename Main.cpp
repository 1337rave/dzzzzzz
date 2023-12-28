#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Parameterized constructor
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(1);
        }

        simplify();
    }

    int gcd(int a, int b) const {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            exit(1);
        }

        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    int num1, den1, num2, den2;

    // Введення першого дробу
    std::cout << "Enter the first fraction (numerator denominator): ";
    std::cin >> num1 >> den1;
    Fraction fraction1(num1, den1);

    // Введення другого дробу
    std::cout << "Enter the second fraction (numerator denominator): ";
    std::cin >> num2 >> den2;
    Fraction fraction2(num2, den2);

    char operation;

    // Вибір операції
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    Fraction result;

    // Виконання вибраної операції
    switch (operation) {
    case '+':
        result = fraction1 + fraction2;
        break;
    case '-':
        result = fraction1 - fraction2;
        break;
    case '*':
        result = fraction1 * fraction2;
        break;
    case '/':
        result = fraction1 / fraction2;
        break;
    default:
        std::cerr << "Error: Invalid operation." << std::endl;
        return 1;
    }

    // Виведення результату
    std::cout << "Result: ";
    result.display();
    std::cout << std::endl;

    return 0;
}
