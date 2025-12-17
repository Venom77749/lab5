#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "CoolFile.h"

int getInt(const char* num);

int main() {
    setlocale(LC_ALL, "rus");

    std::string numbersFile = "numbers.bin";
    std::string toysFile = "toys.bin";
    std::string numbersTextFile = "numbers.txt";
    std::string numbersMultiFile = "numbers_multi.txt";
    std::string textFile = "text.txt";
    std::string noLatinFile = "no_latin.txt";

    int choice;

    do {
        std::cout << "1 - Задание 1 (квадраты нечетных)\n";
        std::cout << "2 - Задание 2 (лучшая строка матрицы)\n";
        std::cout << "3 - Задание 3 (игрушки)\n";
        std::cout << "4 - Задание 4 (ср. max и min)\n";
        std::cout << "5 - Задание 5 (произведение чётных)\n";
        std::cout << "6 - Задание 6 (строки без латиницы)\n";
        std::cout << "0 - Выход\n";
        choice = getInt("Ваш выбор: ");

        switch (choice) {
        case 1: {
            int num = getInt("\n[Задание 1] Сколько чисел записать в numbers.bin? ");

            CoolFile::fillFile(numbersFile, num);

            int squares = CoolFile::task1(numbersFile);
            std::cout << "Квадратов нечетных чисел: " << squares << "\n";
            break;
        }
        case 2: {
            int n;
            std::cout << "\n[Задание 2] Размер квадратной матрицы n: ";
            std::cin >> n;
            int bestRow = CoolFile::task2(numbersFile, n);
            std::cout << "Лучшая строка: " << bestRow << "\n";
            break;
        }
        case 3: {
            int toysCount;
            std::cout << "\n[Задание 3] Сколько игрушек записать в " << toysFile << "? ";
            std::cin >> toysCount;
            CoolFile::fillToysFile(toysFile, toysCount);

            std::string expensiveToy = CoolFile::task3_mostExpensiveToyUnder4(toysFile);
            std::cout << "Самая дорогая игрушка до 4 лет: " << expensiveToy << "\n";
            break;
        }
        case 4: {
            int textNums;
            std::cout << "\n[Задание 4] Сколько чисел записать в " << numbersTextFile << "? ";
            std::cin >> textNums;
            CoolFile::fillNumbersTextFile(numbersTextFile, textNums);

            double avg = CoolFile::task4_avgMaxMin(numbersTextFile);
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "Среднее арифметическое max и min: " << avg << "\n";
            break;
        }
        case 5: {
            int lines, perLine;
            std::cout << "\n[Задание 5] Сколько строк в " << numbersMultiFile << "? ";
            std::cin >> lines;
            std::cout << "Сколько чисел в каждой строке? ";
            std::cin >> perLine;
            CoolFile::fillNumbersMultiTextFile(numbersMultiFile, lines, perLine);

            long long product = CoolFile::task5_productEvenNumbers(numbersMultiFile);
            std::cout << "Произведение чётных чисел: " << product << "\n";
            break;
        }
        case 6: {
            int textLines = getInt("\n[Задание 6] Сколько строк записать в text.txt? ");

            int choiceLines;
            std::cout << "Хотите ввести свои строки?\n";
            std::cout << "1 - Да, ввести вручную\n";
            std::cout << "2 - Нет, сгенерировать автоматически\n";
            choiceLines = getInt("Ваш выбор: ");

            if (choiceLines == 1) {
                CoolFile::fillTextFileUser(textFile, textLines);
            }
            else {
                CoolFile::fillTextFile(textFile, textLines);
            }

            int copied = CoolFile::task6_copyNoLatinLines(textFile, noLatinFile);
            std::cout << "Скопировано строк без латинских букв: " << copied << "\n";
            break;
        }

        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор, попробуйте ещё раз.\n";
        }

    } while (choice != 0);

    return EXIT_SUCCESS;
}

int getInt(const char* num)
{
    int value;
    while (true) {
        std::cout << num;
        std::cin >> value;

        if (!std::cin.fail()) {
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
        std::cout << "Ошибка ввода! Введите целое число.\n";
    }
}