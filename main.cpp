#include <iostream>
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

int BigDecimalInt::Size()
{
    return (int)number.size();
}

ostream& operator<< (ostream& COUT, BigDecimalInt INT)
{
    COUT << (INT.sign == '-' ? "-" : "") << INT.number;
    return COUT;

}

bool BigDecimalInt::operator< (BigDecimalInt anotherDec)
{
    string first = this->number;
    string second = anotherDec.number;
    fillzeros(first, second);
    if (sign == '-' && anotherDec.Sign() == '+') return true;
    else if (sign == '+' && anotherDec.Sign() == '-') return false;
    else if (sign == '+' && anotherDec.Sign() == '+') {
        for (int i = 0; i < first.length(); i++)
        {
            if (second[i] > first[i]) return true;
            else if (second[i] < first[i]) return false;
        }
        return false;
    }
    else {
        for (int i = 0; i < first.length(); i++)
        {
            if (second[i] > first[i]) return false;
            else if (second[i] < first[i]) return true;
        }
        return false;
    }

}


BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec)
{
    this->number = anotherDec.number;
    this->sign = anotherDec.sign;
    return *this;
}


bool BigDecimalInt::operator== (BigDecimalInt anotherDec)
{
    string first = this->number;
    string second = anotherDec.number;
    fillzeros(first, second);
    if (sign != anotherDec.Sign()) return false;
    else
    {
        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] != second[i]) return false;
        }
        return true;
    }
}


bool BigDecimalInt::operator>(BigDecimalInt anotherDec)
{
    string first = this->number;
    string second = anotherDec.number;
    fillzeros(first, second);
    if (sign == '+' && anotherDec.Sign() == '-') return true;
    else if (sign == '-' && anotherDec.Sign() == '+') return false;
    else if (sign == '+' && anotherDec.Sign() == '+') {
        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] > second[i]) return true;
            else if (first[i] < second[i]) return false;
        }
        return false;
    }
    else {
        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] > second[i]) return false;
            else if (first[i] < second[i]) return true;
        }
        return false;
    }

}


char BigDecimalInt::Sign()
{
    return sign;
}


BigDecimalInt::BigDecimalInt(string digits)
{
    regex num("[+,-]?[0-9]+");
    if (regex_match(digits, num))
    {
        if (!isdigit(digits[0]))
        {
            sign = digits[0];
            number = digits.erase(0, 1);
        }
        else
        {
            sign = '+';
            number = digits;
        }
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }
}


BigDecimalInt::BigDecimalInt(long long int num)
{
    string digits = to_string(num);
    if (digits[0] == '-')
    {
        sign = digits[0];
        number = digits.erase(0, 1);
    }
    else
    {
        sign = '+';
        number = digits;
    }
}


BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt num2)
{
    if (sign == '-' && num2.sign == '+') {
        sign = '+';
        return(num2 - *this);

    }
    else if (sign == '+' && num2.sign == '-') {
        num2.sign = '+';
        return(*this - num2);

    }
    else {
        string result;
        string first = number;
        string second = num2.number;
        fillzeros(first, second);
        int tm;
        int carry = 0;
        for (int i = first.size() - 1; i >= 0; i--)
        {
            tm = (first[i] - '0') + (second[i] - '0');
            tm = (first[i] - '0') + (second[i] - '0') + carry;
            if (tm > 9)
            {
                tm -= 10;
                carry = 1;
            }
            else
                carry = 0;

            result = char(tm + '0') + result;
        }
        if (carry)
            result = "1" + result;
        if (sign == '-' && num2.sign == '-')
            result = "-" + result;
        BigDecimalInt sum(result);
        return sum;
    }
}


void BigDecimalInt::fillzeros(string& number1, string& number2)
{
    while (number1.size() > number2.size()) number2.insert(0, 1, '0');
    while (number1.size() < number2.size()) number1.insert(0, 1, '0');
}



BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {


    if (sign == '+' && anotherDec.sign == '-') {
        anotherDec.sign = '+';
        return(*this + anotherDec);
    }
    else if (sign == '-' && anotherDec.sign == '-') {
        anotherDec.sign = '+';
        sign = '+';
        return(anotherDec - *this);
    }

    else if (sign == '-' && anotherDec.sign == '+') {
        anotherDec.sign = '-';
        return(*this + anotherDec);
    }

    else {
        string big = number, small = anotherDec.number;
        int n = 0, flow = 0;
        string newNum = "";
        char s;
        fillzeros(small, big);

        if (*this < anotherDec) {
            swap(small, big);
            s = '-';
        }

        for (int i = big.size(); i > 0; i--)
        {
            n = (big[i - 1] - 48) - (small[i - 1] - 48) - flow;
            flow = 0;
            if (n < 0) {

                n += 10;
                flow = 1;

            }
            newNum += char(n + 48);

        }

        reverse(newNum.begin(), newNum.end());

        while (newNum[0] == '0' && newNum.size() > 1) newNum = newNum.erase(0, 1);


        if (*this < anotherDec) {
            newNum = s + newNum;
        }
        BigDecimalInt num3(newNum);
        return num3;

    }

}


int main()
{
    BigDecimalInt hah("-100");
    BigDecimalInt hah1("2");
    BigDecimalInt hah3 = hah - hah1;
    cout << hah3 << endl;
}
