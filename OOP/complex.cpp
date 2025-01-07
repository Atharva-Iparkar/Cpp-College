#include<iostream>
using namespace std;

class Complex {
private:
    float x, y;
public:
    Complex() {
        x = 0;
        y = 0;
    }

    Complex operator+(Complex);
    Complex operator*(Complex);

    friend istream &operator>>(istream &input, Complex &t) {
        input >> t.x;
        input >> t.y;
        return input;
    }

    friend ostream &operator<<(ostream &output, Complex &t) {
        output << t.x << "+" << t.y << "i \n";
        return output;
    }
};

Complex Complex::operator+(Complex c) {
    Complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

Complex Complex::operator*(Complex c) {
    Complex temp2;
    temp2.x = (x * c.x) - (y * c.y);
    temp2.y = (x * c.y) + (y * c.x);
    return temp2;
}

int main() {
    Complex c1, c2, c3, c4;
    cout << "Constructor is : " << c1 << endl;
    cout << "Enter 1st number : " << endl;
    cin >> c1;
    cout << "Enter 2nd number : " << endl;
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "The 1st number is : " << c1 << endl;
    cout << "The 2nd number is : " << c2 << endl;
    cout << "The Addition is : " << c3 << endl;
    cout << "The multiplication is : " << c4 << endl;
    return 0;
}
