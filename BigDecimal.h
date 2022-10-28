#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class BigDecimalInt
{
    private:
        char sign;
        string number;
        void fillzeros(string& number1, string& number2);

    public:
        BigDecimalInt(string digits);
        BigDecimalInt(long long int = 0);
        BigDecimalInt operator+ (BigDecimalInt num2);
        bool operator> (BigDecimalInt anotherDec);
        bool operator< (BigDecimalInt anotherDec);
        bool operator== (BigDecimalInt anotherDec);
        BigDecimalInt operator= (BigDecimalInt anotherDec);
        BigDecimalInt operator-(BigDecimalInt anotherDec);
        char Sign();
        int Size();
        friend ostream& operator<< (ostream& COUT, BigDecimalInt INT);
};

#endif