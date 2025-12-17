#pragma once

#include <string>

class CoolFile
{
    struct Toy
    {
        char name[50];
        double price;
        int ageMin, ageMax;
    };

public:
    static void   fillFile(const std::string& filename, int count);
    static int    task1(const std::string& filename);
    static int    task2(const std::string& filename, int n);

    static void   fillToysFile(const std::string& filename, int count);
    static std::string task3_mostExpensiveToyUnder4(const std::string& filename);

    static void   fillNumbersTextFile(const std::string& filename, int count);
    static double task4_avgMaxMin(const std::string& filename);

    static void   fillNumbersMultiTextFile(const std::string& filename, int lines, int numsPerLine);
    static long long task5_productEvenNumbers(const std::string& filename);

    static void   fillTextFile(const std::string& filename, int lines);
    static void fillTextFileUser(const std::string& filename, int lines);
    static int    task6_copyNoLatinLines(const std::string& inputFile, const std::string& outputFile);
};