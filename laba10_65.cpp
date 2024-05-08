#include <iostream>
#include <cmath>
using namespace std;

// Тип TPoint - точка у двовимірному просторі
struct TPoint {
    double x, y;
};

// Тип TTriangle - трикутник з вершинами A, B, C типу TPoint
struct TTriangle {
    TPoint A, B, C;
};

// Функція, що обчислює відстань між двома точками
double Distance(TPoint p1, TPoint p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Функція, що обчислює периметр трикутника
double Perim(TTriangle T) {
    double perimeter = 0.0;
    perimeter += Distance(T.A, T.B);
    perimeter += Distance(T.B, T.C);
    perimeter += Distance(T.C, T.A);
    return perimeter;
}

int main() {
    // Введення координат вершин трикутників
    TPoint A, B, C, D;
    cout << "Enter coordinates of point A: ";
    cin >> A.x >> A.y;
    cout << "Enter coordinates of point B: ";
    cin >> B.x >> B.y;
    cout << "Enter coordinates of point C: ";
    cin >> C.x >> C.y;
    cout << "Enter coordinates of point D: ";
    cin >> D.x >> D.y;

    // Створення трикутників за введеними вершинами
    TTriangle ABC = {A, B, C};
    TTriangle ABD = {A, B, D};
    TTriangle ACD = {A, C, D};

    // Обчислення і виведення периметрів трикутників
    cout << "Perimeter of triangle ABC: " << Perim(ABC) << endl;
    cout << "Perimeter of triangle ABD: " << Perim(ABD) << endl;
    cout << "Perimeter of triangle ACD: " << Perim(ACD) << endl;

    return 0;
}