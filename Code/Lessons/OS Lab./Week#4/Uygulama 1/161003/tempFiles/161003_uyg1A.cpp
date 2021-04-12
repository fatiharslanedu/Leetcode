// @Author : Fatih Arslan
// Lesson : Operating Systems Lab.
// Lab Application 1

#include <iostream>
#include <stdlib.h>
#define SIZE 1000
using namespace std;
// This function check the number and if is prime, return true.
bool iPrime(int cNumber)
{
    int count;

    if (cNumber == 2)
        return true;
    if (cNumber % 2 == 0)
        return false;
    for (count = 3; count * count <= cNumber; count += 2)
    {
        if (cNumber % count == 0)
            return false;
    }
    return true;
}
// This function gives the prime factor for given number.
int nextPrimeFunction(int primeNumber)
{
    int cNumber = (primeNumber == 2) ? 3 : primeNumber + 2;

    while (!iPrime(cNumber))
        cNumber += 2;
    return cNumber;
}

int main()
{
    int number, currentArray[SIZE];
    int fact = 2;
    int pow = 1;
    cout << "Enter a number: ";
    cin >> number;
    cout << number;
    cout << endl;
    int i = 0;
    while (number > 1)
    {
        while (number % fact == 0)
        {
            currentArray[i] = fact;
            number = number / fact;
            i++;
        }
        fact = nextPrimeFunction(fact);
    }

    // This loop create the proper format for given print pattern.
    for (int j = 0; j < i; j++)
    {
        if (j == 0)
        {
            cout << currentArray[j];
        }
        if (currentArray[j] == currentArray[j + 1])
        {
            pow++;
        }
        else
        {
            // given exponential and multiply string definition.
            if (pow != 1)
            {
                cout << "^" << pow;
            }
            if (j + 1 != i)
            {
                cout << " x " << currentArray[j + 1];
                pow = 1;
            }
        }
    }
    cout << endl;
    return 0;
}
