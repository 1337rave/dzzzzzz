#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Перевантаження оператору "+"
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Перевантаження оператору "-"
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Перевантаження оператору "*"
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imag * other.imag), (real * other.imag) + (imag * other.real));
    }

    // Перевантаження оператору "/"
    Complex operator/(const Complex& other) const {
        double denominator = (other.real * other.real) + (other.imag * other.imag);
        if (denominator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            exit(1);
        }

        return Complex(((real * other.real) + (imag * other.imag)) / denominator,
            ((imag * other.real) - (real * other.imag)) / denominator);
    }

    // Функція для виведення комплексного числа
    void display() const {
        std::cout << real << " + " << imag << "i";
    }
};

int main() {
    double real1, imag1, real2, imag2;

    // Введення першого комплексного числа
    std::cout << "Enter the first complex number (real imag): ";
    std::cin >> real1 >> imag1;
    Complex complex1(real1, imag1);

    // Введення другого комплексного числа
    std::cout << "Enter the second complex number (real imag): ";
    std::cin >> real2 >> imag2;
    Complex complex2(real2, imag2);

    char operation;

    // Вибір операції
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    Complex result;

    // Виконання вибраної операції
    switch (operation) {
    case '+':
        result = complex1 + complex2;
        break;
    case '-':
        result = complex1 - complex2;
        break;
    case '*':
        result = complex1 * complex2;
        break;
    case '/':
        result = complex1 / complex2;
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
