#include <iostream>
#include <regex>
using namespace std;

class BigDecimalInt
{
    private:
            char sign;
            string number;
            void fillzeros(int maxSize, string& number1, string& number2);
    public:
        BigDecimalInt(string digits)
        {
            regex num ("[+,-]?[0-9]+");
            if( regex_match(digits,num) )
            {
                if ( !isdigit(digits[0]) )
                {
                    sign = digits[0];
                    number = digits.erase(0,1);
                }
                else
                {
                    sign = '+';
                    number = digits;
                }
            }
            else
            {
                cout << "Invalid Input !";
            }
        }
        BigDecimalInt(long long int num = 0)
        {
            string digits = to_string(num);
            if (digits[0] == '-')
            {
                    sign = digits[0];
                    number = digits.erase(0,1);
            }
            else
            {
                sign = '+';
                number = digits;
            }
        }
        string getnum()
        {
            return sign+number;
        }
        BigDecimalInt operator+ (BigDecimalInt num2);

};
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt num2)
{
    string result = "";
	string first = number;
	string second = num2.number;
//  if (sign == '-' && num2.sign == '+')
//	{
//	    BigDecimalInt f (first);
//        BigDecimalInt s (second);
//	    return s - f;
//	}
//	else if (sign == '+' && num2.sign == '-')
//	{
//        BigDecimalInt f (first);
//        BigDecimalInt s (second);
//		return f - s;
//	}
    int maxsize;
    if ( first.size() > second.size() )
        maxsize = first.size();
    else
        maxsize = second.size();
    fillzeros(maxsize , first,second);
    int tm;
    int carry = 0;
    for(int i = maxsize - 1 ; i >= 0 ; i--)
    {
        tm = (first[i] + second[i] - '0');
        if (carry == 1)
            tm = (first[i] + second[i] - '0') + 1;
        if ((tm - '0') > 9)
		{
			tm -= 10;
			carry = 1;
		}
		else
			carry = 0;

		result = char(tm) + result;
	}
	if (carry)
		result = "1" + result;
    if ( sign == '-' && num2.sign == '-')
        result = "-" + result;
	BigDecimalInt sum(result);
    return sum;
}
void BigDecimalInt::fillzeros(int maxSize, string& number1, string& number2)
{
    int difference;
	if (number1.size() > number2.size())
	{
		difference = maxSize - number2.size();
		for (int i = 0; i < difference; i++)
			number2 = "0" + number2;
	}
	else if (number1.size() < number2.size())
	{
		difference = maxSize - number1.size();
		for (int i = 0; i < difference; i++)
			number1 = "0" + number1;
	}
}

ostream& operator << (ostream& out, BigDecimalInt text)
{
   out << text.getnum();
}

int main()
{
    BigDecimalInt hah("-1");
    BigDecimalInt hah1("-1000000456456456400");
    BigDecimalInt hah2 = hah + hah1;
    cout << hah2;
}
