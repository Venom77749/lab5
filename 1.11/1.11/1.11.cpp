#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "CoolFile.h"

int main() {
    setlocale(LC_ALL, "rus");

    std::string numbersFile = "numbers.bin";
    std::string toysFile = "toys.bin";
    std::string numbersTextFile = "numbers.txt";
    std::string numbersMultiFile = "numbers_multi.txt";
    std::string textFile = "text.txt";
    std::string noLatinFile = "no_latin.txt";

    CoolFile::fillFile(numbersFile, 100);

    std::cout << "\nЗадание 1\n";
    int squares = CoolFile::task1(numbersFile);
    std::cout << "Квадратов нечетных чисел: " << squares << "\n";

    std::cout << "\nЗадание 2\n";
    int bestRow = CoolFile::task2(numbersFile, 10);
    std::cout << "Лучшая строка: " << bestRow << "\n";

    CoolFile::fillToysFile(toysFile, 20);

    std::cout << "\nЗадание 3\n";
    std::string expensiveToy = CoolFile::task3_mostExpensiveToyUnder4(toysFile);
    std::cout << "Самая дорогая игрушка до 4 лет: " << expensiveToy << "\n";

    CoolFile::fillNumbersTextFile(numbersTextFile, 50);

    std::cout << "\nЗадание 4\n";
    double avg = CoolFile::task4_avgMaxMin(numbersTextFile);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Среднее арифметическое max и min: " << avg << "\n";

    CoolFile::fillNumbersMultiTextFile(numbersMultiFile, 10, 5);

    std::cout << "\nЗадание 5\n";
    long long product = CoolFile::task5_productEvenNumbers(numbersMultiFile);
    std::cout << "Произведение чётных чисел: " << product << "\n";

    CoolFile::fillTextFile(textFile, 10);

    std::cout << "\nЗадание 6\n";
    int copied = CoolFile::task6_copyNoLatinLines(textFile, noLatinFile);
    std::cout << "Скопировано строк без латинских букв: " << copied << "\n";

    return EXIT_SUCCESS;
}
