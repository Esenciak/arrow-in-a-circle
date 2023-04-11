#include <iostream>
#include <cmath>
#define PI 3.14

using namespace std;

int main() {
    // Punkt startowy
    cout << "Podaj X oraz Y punktuy startowego: " << endl;
    double x1;
    double y1;
    cout << "X: ";
    cin >> x1;
    cout << "Y: ";
    cin >> y1;

    // Promien
    cout << "Podaj promien: ";
    double radius;
    cin >> radius;

    if (radius < 0)
    {
        cout << "Promien nie moze byc mniejszy od 0";
        return 0;
    }
    else

    // Punkt koncowy
    cout << "Podaj X oraz Y punktuy koncowego: " << endl;
    double x2;
    double y2;
    cout << "X: ";
    cin >> x2;
    cout << "Y: ";
    cin >> y2;

    // obliczenie x3, y3 czolo strzalki
    double x3 = x1 + (x2 - x1) * radius / sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double y3 = y1 + (y2 - y1) * radius / sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    /* x3, y3
    cout << "x3: " << x3 << endl;
    cout << "y3: " << y3 << endl;
    */

    // D�ugo�� ramienia strzalki to 1/10 promienia
    double strza�kaDlugosc = radius / 10;

    // kat nachylenia w stopniach od 10 do 45
    double kat;
    do {
        cout << "Podaj kat nachylenia strzalki (od 10 do 45): ";
        cin >> kat;
    } while (kat < 1 || kat > 45);

    // zmiana angle na radians
    double angleRad = kat * PI / 180;

    // obliczy� wz�r na prost� od x1,y1 do x2,y2
    // y = mx + b
    // m = (y2 - y1) / (x2 - x1)
    double m = (y2 - y1) / (x2 - x1);

    // oblicz stopnie k�ta prostej od x1,y1 do x2,y2
    // angle = atan(m) * 180 / PI

    double katLine = atan(m) * 180 / PI;

    // oblicz x4,y4 czyli koniec strza�ki pod k�tem od x3,y3 umieszczonej na prostej m i b
    // korzystaj�c ze wzoru na prost� i k�t

    double x4 = x3 - strza�kaDlugosc * cos(katLine + angleRad);
    double y4 = y3 - strza�kaDlugosc * sin(katLine + angleRad);


    // obliczanie x5, y5 czyli koniec strza�ki pod k�tem od x3,y3 umieszczonej na linii m i b
    // korzystaj�c ze wzoru na prost� i k�t

    double x5 = x3 - strza�kaDlugosc * cos(angleRad - katLine);
    double y5 = y3 - strza�kaDlugosc * sin(angleRad - katLine);

    /* poka� wszystkie 5 punkt�w

    cout << "x1.y1: " << x1 << "." << y1 << endl;
    cout << "x2.y2: " << x2 << "." << y2 << endl;
    cout << "x3.y3: " << x3 << "." << y3 << endl;
    cout << "x4.y4: " << x4 << "." << y4 << endl;
    cout << "x5.y5: " << x5 << "." << y5 << endl;
    */

    cout << "Punkt opisujacy czolo strzalki X,Y: " << x3 << " ," << y3 << endl;
    cout << "Punkt opisujacy 1 ramie strzalki X,Y: " << x4 << " ," << y4 << endl;
    cout << "Punkt opisujacy 2 ramie strzalki X,Y: " << x5 << " ," << y5 << endl;

    return 0;
}