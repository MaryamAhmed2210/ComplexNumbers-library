#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber 
{
private:
    double real;
    double imaginary;	
public:
    ComplexNumber(double r = 0.0, double i = 0.0);
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    void display() const;
    ComplexNumber operator+(const ComplexNumber &ref) const;
    ComplexNumber operator-(const ComplexNumber &ref) const;
    ComplexNumber operator*(const ComplexNumber &ref) const;
    ComplexNumber operator/(const ComplexNumber &ref) const;
    ComplexNumber &operator=(const ComplexNumber &ref);
    friend ostream &operator<<(ostream &out, const ComplexNumber &a);
};


ComplexNumber::ComplexNumber(double r, double i) : real(r), imaginary(i) {}


ComplexNumber& ComplexNumber::operator=(const ComplexNumber &ref) 
{
    if (this != &ref) { 
        real = ref.real;
        imaginary = ref.imaginary;
    }
    return *this;
}
void ComplexNumber::display() const 
{
    if (imaginary >= 0)
        cout << real << "+" << imaginary << "i";
    else
        cout << real << imaginary << "i";
} 
ComplexNumber ComplexNumber::operator+(const ComplexNumber &ref) const 
{
    return ComplexNumber(this->real + ref.real, this->imaginary + ref.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &ref) const 
{
    return ComplexNumber(this->real - ref.real, this->imaginary - ref.imaginary);
}


ComplexNumber ComplexNumber::operator*(const ComplexNumber &ref) const 
{
    double a1 = real * ref.real;
    double a2 = imaginary * ref.imaginary;
    double b1 = real * ref.imaginary;
    double b2 = imaginary * ref.real;
    return ComplexNumber(a1 - a2, b1 + b2);
}


ComplexNumber ComplexNumber::operator/(const ComplexNumber &ref) const 
{
    double denominator = pow(ref.real, 2) + pow(ref.imaginary, 2);
    double num_real = (real * ref.real) + (imaginary * ref.imaginary);
    double num_imag = (imaginary * ref.real) - (real * ref.imaginary);
    return ComplexNumber(num_real / denominator, num_imag / denominator);
}


ostream &operator<<(ostream &out, const ComplexNumber &a) 
{
    if (a.imaginary >= 0)
        out << a.real << "+" << a.imaginary << "i";
    else
        out << a.real << a.imaginary << "i";
    return out;
}

int main() 
{
    ComplexNumber a(6.0, 6.0);
    ComplexNumber b(3.0, 3.0);
    
    cout << "--- Complex Number Operations ---" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << endl<< endl;

    ComplexNumber r = a + b;
    cout << "Addition (a + b)       : " << r << endl;

    ComplexNumber m = a - b;
    cout << "Subtraction (a - b)    : " << m << endl;

    ComplexNumber p = a * b;
    cout << "Multiplication (a * b) : " << p << endl;

    ComplexNumber d = a / b;
    cout << "Division (a / b)       : " << d << endl;
    cout << endl << endl;
 	 
    return 0;
}