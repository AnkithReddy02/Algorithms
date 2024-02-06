#include<bits/stdc++.h>
using namespace std;


class Complex {
private:
    int real;
    int imaginary;

public:
    Complex(int r, int i): real(r), imaginary(i) {

    }

    Complex operator+(const Complex & c) {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    friend ostream & operator <<(ostream & os, const Complex & c);
    
};


// Friend Declared functions can access private members.
// Printing out the object.
ostream & operator <<(ostream & os, const Complex & c) {
    os << c.real << " + i * " << c.imaginary << endl; 

    return os;
}


// Addition of two vectors
template <typename T> 
vector<T> operator+(const vector<T> & v1, const vector<T> & v2) {
    assert(v1.size()==v2.size());

    vector<T> res;

    for(int i=0;i<v1.size();i++) {
        res.push_back(v1[i] + v2[i]);
    }

    return res;
}

// Printing the vector.
template <typename T> 
ostream & operator <<(ostream & os, const vector<T> & v) {
    for(T x : v) {
        os << x << ' ';
    }

    return os;
}

int main() {
    Complex c1(2, 3), c2(3, 4);

    Complex c3 = c1 + c2;

    cout << c3;

    vector<string> v1 = {"2", "3"};

    vector<string> v2 = {"4", "5"};

    vector<string> v3 = v1 + v2;

    cout << v3 << endl;
}