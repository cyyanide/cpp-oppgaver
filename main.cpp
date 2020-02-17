/*
 
 Lag en klasse fraction() (brøk) med en teller og en nevner.
 Lag en konstruktør og overlast noen operatorer slik at koden nedenfor kan kjøre:
 
 */

#include "../../std_lib_facilities.h"

class Fraction {
public:
    int a, b;

    Fraction(const int a, const int b) {
        this->a = a;
        this->b = b;
    }
};

int divider(int k, int l)
{
    if (k < l){
        return divider(l, k);
    }
    int m;
    while (l != 0){
        m = k % l;
        k = l;
        l = m;
    }
    return k;
}

Fraction forkort(Fraction x)
{
    int d = divider(x.a, x.b);
    x.a /= d;
    x.b /= d;
    return x;
}

Fraction& operator+(const Fraction& b1, const Fraction& b2) {
    if (b1.b == b2.b){
        Fraction plus(b1.a + b2.a, b1.b);
        return plus;
    }
    else
    {
    Fraction plus(b1.a + b2.a, b1.b + b2.b);
    return plus;
    }
}
Fraction& operator+(const Fraction& b1, int i) {
    Fraction plus2((b1.a * i) + (i * b1.b), b1.b * i);
    return plus2;
}

bool operator<(const Fraction& b1, const Fraction& b2) {
    return (b1.a * b2.b < b2.a * b1.b);
}

bool operator<(const Fraction& b1, int i) {
    return(b1.a * i < i * b1.b);
}

bool operator==(const Fraction& b1, const Fraction& b2) { //
    return (b1.a * b2.b == b2.a * b1.b);
}

ostream& operator << (ostream& o, const Fraction& f) {
    if (f.a == f.b){                        // skal ikke printe (1, 1), bare 1
        return o << f.a;
    }
    else{
    o << "(" << f.a << ", " << f.b << ")"; //printer vanlig brok
    return o;
    }
}

// Oppgaveteksten:

int  main() {
    Fraction  f1(1, 2);
    Fraction  f2(2, 9);
    Fraction  f3(2, 4);
    if (f1 < f2) {
        cout << f1 << " er  minst " << endl;
    }
    else if (f1 == f2) {
        cout << "de er like" << endl;
    }
    else {
        cout << f2 << "er  minst";
    }
    if (f1 < 4) {
        f1 = f1 + f2;
        cout << f1 << endl;
    }
    
    f2 = f2 + 5;
    cout << forkort(f2) << endl;
    cout << forkort(f3 + f3) << endl;
    
}


