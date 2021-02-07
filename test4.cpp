// test4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

int detrmineMonth(int day, int* month)
{
    int i = -1;
    while (day >= 0)
    {
        i = i + 1;
        day = day - month[i];
    }
    return(i);
}

int detrmineDay(int day, int* month)
{
    int i = -1;
    while (day >= 0)
    {
        i = i + 1;
        day = day - month[i];
    }
    day = day + month[i];
    return(day);
}

int main()
{
    int daysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    std::string monthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 365);
    generator.seed(std::time(nullptr));
    int randDay = distribution(generator);
    std::cout << "The random day is: " << randDay << "\n";
    std::cout << "The date is " << monthNames[detrmineMonth(randDay, daysMonth)] << " " << detrmineDay(randDay, daysMonth);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
