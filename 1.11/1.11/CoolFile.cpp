#include "CoolFile.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <limits>


void CoolFile::fillFile(const std::string& filename, int count)
{
    srand(time(NULL));
    std::ofstream file(filename, std::ios::binary);
    for (int i = 0; i < count; ++i) {
        int num = rand() % 200 - 100;
        file.write((char*)&num, sizeof(int));
    }
    file.close();
    std::cout << "Файл готов (" << count << " чисел)\n";
}

int CoolFile::task1(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    int count = 0, num{};
    std::cout << "Содержимое " << filename << " (int):\n";

    while (file.read((char*)&num, sizeof(int))) {
        std::cout << num << " ";
        if (num % 2 != 0) {
            int root = (int)std::sqrt(num);
            if (root * root == num) {
                count++;
            }
        }
    }
    std::cout << "\n";
    return count;
}

int CoolFile::task2(const std::string& filename, int n)
{
    std::ifstream file(filename, std::ios::binary);
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int num{}, idx = 0;
    std::cout << "Чтение матрицы " << n << "x" << n << " из " << filename << ":\n";
    while (file.read((char*)&num, sizeof(int)) && idx < n * n) {
        int i = idx / n, j = idx % n;
        matrix[i][j] = num;
        idx++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout <<  matrix[i][j] << '\t';
        std::cout << "\n";
    }

    int bestRow = 0, maxCount = 0;
    for (int i = 0; i < n; i++) {
        int rowCount = 0;
        for (int j = 0; j < n; j++) {
            int sum = i + j;
            if (sum > 0 && matrix[i][j] % sum == 0) {
                rowCount++;
            }
        }
        if (rowCount > maxCount) {
            maxCount = rowCount;
            bestRow = i;
        }
    }
    return bestRow;
}

void CoolFile::fillToysFile(const std::string& filename, int count)
{
    std::ofstream file(filename, std::ios::binary);
    for (int i = 0; i < count; ++i) {
        Toy toy;
        sprintf_s(toy.name, sizeof(toy.name), "Игрушка %d", i + 1);
        toy.price = 300 + (rand() % 1700);
        toy.ageMin = rand() % 5;
        toy.ageMax = toy.ageMin + 1 + (rand() % 8);
        file.write((char*)&toy, sizeof(Toy));
    }
    file.close();
    std::cout << "Файл игрушек " << filename << " готов (" << count << " игрушек)\n";
}

std::string CoolFile::task3_mostExpensiveToyUnder4(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    Toy toy;
    std::string result = "";
    double maxPrice = -1;

    std::cout << "Игрушки из файла " << filename << ":\n";

    while (file.read((char*)&toy, sizeof(Toy)))
    {
        std::cout << "Название: " << toy.name
            << ", цена: " << toy.price
            << ", возраст: " << toy.ageMin << "-" << toy.ageMax << "\n";

        if (toy.ageMax <= 4 && toy.price > maxPrice) {
            maxPrice = toy.price;
            result = std::string(toy.name);
        }
    }
    return result;
}

void CoolFile::fillNumbersTextFile(const std::string& filename, int count)
{
    srand(time(NULL));
    std::ofstream file(filename);
    for (int i = 0; i < count; ++i) {
        int num = rand() % 200 - 100;
        file << num << std::endl;
    }
    file.close();
    std::cout << "Текстовый файл " << filename << " готов (" << count << " чисел)\n";
}

double CoolFile::task4_avgMaxMin(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    int minVal = INT_MAX, maxVal = INT_MIN;
    bool hasData = false;

    std::cout << "Числа из " << filename << ":\n";

    while (std::getline(file, line)) {
        if (!line.empty()) {
            int num = std::stoi(line);
            std::cout << num << " ";
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
            hasData = true;
        }
    }

    std::cout << std::endl;

    if (!hasData) return 0.0;
    return (minVal + maxVal) / 2.0;
}

void CoolFile::fillNumbersMultiTextFile(const std::string& filename, int lines, int numsPerLine)
{
    srand(time(NULL));
    std::ofstream file(filename);
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < numsPerLine; ++j) {
            int num = rand() % 200 - 100;
            file << num;
            if (j < numsPerLine - 1) file << " ";
        }
        file << std::endl;
    }
    file.close();
    std::cout << "Многочисленный файл " << filename << " готов ("
        << lines << " строк по " << numsPerLine << " чисел)\n";
}

long long CoolFile::task5_productEvenNumbers(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    long long product = 1;
    bool hasEven = false;

    std::cout << "Содержимое " << filename << ":\n";

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::cout << line << "\n";

        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            if (num % 2 == 0) {
                product *= num;
                hasEven = true;
            }
        }
    }

    return hasEven ? product : 0;
}

void CoolFile::fillTextFile(const std::string& filename, int lines)
{
    srand(time(NULL));
    std::ofstream file(filename);
    std::string linesData[] = {
        "Привет Hello мир",
        "Только русский текст",
        "123 цифры и слова",
        "мяу, мяу, myau",
        "No English letters",
        "Все кириллицей",
        "Mixed text ABC",
        "Чисто русский",
        "Latin and Russian"
    };

    int variants = sizeof(linesData) / sizeof(linesData[0]);

    for (int i = 0; i < lines; ++i) {
        file << linesData[i % variants] << std::endl;
    }
    file.close();
    std::cout << "Текстовый файл " << filename << " готов (" << lines << " строк)\n";
}

void CoolFile::fillTextFileUser(const std::string & filename, int lines)
{
    std::ofstream file(filename);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистить хвост после ввода числа

    std::cout << "Введите " << lines << " строк(и) текста:\n";
    std::string line;
    for (int i = 0; i < lines; ++i) {
        std::cout << i + 1 << ": ";
        std::getline(std::cin, line);
        file << line << std::endl;
    }
    file.close();
    std::cout << "Текстовый файл " << filename << " заполнен вашими строками (" << lines << " строк)\n";
}


int CoolFile::task6_copyNoLatinLines(const std::string& inputFile, const std::string& outputFile)
{
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;
    int copiedLines = 0;

    std::cout << "Строки из " << inputFile << ":\n";

    while (std::getline(in, line)) {
        std::cout << line << "\n";

        bool hasLatin = false;
        for (unsigned char c : line) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                hasLatin = true;
                break;
            }
        }


        if (!hasLatin) {
            out << line << std::endl;
            copiedLines++;
        }
    }

    in.close();
    out.close();


    std::cout << "\nСтроки без латинских букв (из файла " << outputFile << "):\n";
    std::ifstream checkOut(outputFile);
    while (std::getline(checkOut, line)) {
        std::cout << line << "\n";
    }
    checkOut.close();

    return copiedLines;
}
