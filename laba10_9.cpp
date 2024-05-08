#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Функція, що обробляє рядок та знаходить середнє геометричне чисел
double findGeometricMean(const string& line) {
    size_t pos = line.find(' '); // знаходимо позицію першого пробілу
    if (pos == string::npos) // якщо не знайдено пробіл, виходимо
        return -1;
    
    // отримуємо дві числа з рядка
    double a = stod(line.substr(0, pos)); // перше число до пробілу
    double b = stod(line.substr(pos + 1)); // друге число після пробілу
    
    // знаходимо середнє геометричне
    return sqrt(a * b);
}

// Функція, що перевіряє, чи задовольняє рядок умовам завдання
bool satisfiesConditions(const string& line) {
    // Перевіряємо, чи рядок містить два числа розділені пробілом
    size_t pos = line.find(' ');
    if (pos == string::npos)
        return false;
    
    // Перевіряємо, чи обидва числа є невід'ємними
    double a = stod(line.substr(0, pos));
    double b = stod(line.substr(pos + 1));
    if (a < 0 || b < 0)
        return false;
    
    return true;
}

int main() {
    ifstream inputFile("input_9.txt"); // відкриваємо вхідний файл
    ofstream outputFile("output_9.txt"); // відкриваємо вихідний файл
    
    if (!inputFile.is_open() || !outputFile.is_open()) { // перевіряємо, чи файли вдало відкрито
        cout << "Failed to open files." << endl;
        return 1;
    }
    
    string line;
    while (getline(inputFile, line)) { // зчитуємо рядок з вхідного файлу
        if (satisfiesConditions(line)) { // перевіряємо, чи рядок задовольняє умовам
            double result = findGeometricMean(line); // обчислюємо середнє геометричне
            outputFile << result << endl; // записуємо результат у вихідний файл
        } else {
            outputFile << "Invalid input" << endl; // якщо рядок не задовольняє умовам, записуємо помилку
        }
    }
    
    inputFile.close(); // закриваємо вхідний файл
    outputFile.close(); // закриваємо вихідний файл
    
    return 0;
}