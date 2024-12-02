#include "Complex.h"
#include "Array.h"
#include <iostream>
using namespace std;

int main()
{
    auto lambda = [](Complex other) -> Complex
    {
        return other + Complex(1, 1);
    };
    Complex a(1, 2);       // test kompleksnog broja
    Complex b(-1, -2);     // test kompleksnog br sa negativnim vrijednostima
    cout << a << endl;     // test ispisa kompl br
    cout << b << endl;     // test ispisa kompl br sa neg vr
    cout << a + b << endl; // test preklopljenog operatora za sabiranje i ispisa
    Array c(1);
    c.append(a);             // test append metode
    c.append(b);             // opet
    cout << c << endl;       // test preklopa operatora ispisa
    cout << c.at(0) << endl; // test preklopa operatora ispisa uz at metodu
    c.at(0) = Complex(1, 3); // test mijenjanja elemenata kako je zahtijevano metodom at
    cout << c << endl;
    cout << c.at(1) << endl;
    c.transform(lambda); // test validnosti transform metode za nekonstantne nizove
    cout << c << endl;
    const Array d(std::move(c));         // test pomjerajuce inicijalizacije na konstantan niz
    cout << d.transform(lambda) << endl; // test funkcionalnosti transform metode na konstantnom objektu
    return 0;
}