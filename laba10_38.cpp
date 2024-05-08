#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Функція, що обробляє рядок та перевіряє, чи може слон перейти з одного поля на інше за один хід
bool canBishopMove(int x1, int y1, int x2, int y2) {
    // Перевіряємо, чи координати лежать на одній діагоналі
    return abs(x2 - x1) == abs(y2 - y1);
}

// Функція, яка перевіряє, чи задовольняє рядок умовам завдання
bool satisfiesConditions(int x1, int y1, int x2, int y2) {
    // Перевіряємо, чи координати лежать в діапазоні від 1 до 8
    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 || x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8)
        return false;

    return true;
}

int main() {
    ofstream outputFile("output_38.txt");

    if (!outputFile.is_open()) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    int x1, y1, x2, y2;

    cout << "Введіть координати першого поля (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Введіть координати другого поля (x2, y2): ";
    cin >> x2 >> y2;

    if (!satisfiesConditions(x1, y1, x2, y2)) {
        cout << "Некоректні координати. Координати мають бути цілими числами від 1 до 8." << endl;
        outputFile << "Invalid input" << endl;
        return 1;
    }

    if (canBishopMove(x1, y1, x2, y2)) {
        cout << "Слон може перейти з одного поля на інше за один хід." << endl;
        outputFile << "true" << endl;
    } else {
        cout << "Слон не може перейти з одного поля на інше за один хід." << endl;
        outputFile << "false" << endl;
    }

    outputFile.close();

    return 0;
}
