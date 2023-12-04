#include <iostream>
#include <string>
#include <vector>

/* Given a string find the first character that is a digit and return it*/
char firstDigit(std::string inputString)
{
    for (int i = 0; i < inputString.size(); i++)
    {
        if (isdigit(inputString[i]))
        {
            return inputString[i];
        }
    }
    return ' ';
}

/* Given a string find the last character that is a digit and return it*/
char lastDigit(std::string inputString)
{
    for (int i = inputString.size() - 1; i >= 0; i--)
    {
        if (isdigit(inputString[i]))
        {
            return inputString[i];
        }
    }
    return ' ';
}

/*Check if the string starts with a digit in 0 to 9 or in 'one', 'two', ,... 'nine' and return the digit in int*/
int startsWithDigit(std::string inputString)
{
    if (isdigit(inputString[0]))
    {
        return inputString[0] - '0';
    }
    else if (inputString.length() >= 3 && inputString.substr(0, 3) == "one")
    {
        return 1;
    }
    else if (inputString.length() >= 3 && inputString.substr(0, 3) == "two")
    {
        return 2;
    }
    else if (inputString.length() >= 5 && inputString.substr(0, 5) == "three")
    {
        return 3;
    }
    else if (inputString.length() >= 4 && inputString.substr(0, 4) == "four")
    {
        return 4;
    }
    else if (inputString.length() >= 4 && inputString.substr(0, 4) == "five")
    {
        return 5;
    }
    else if (inputString.length() >= 3 && inputString.substr(0, 3) == "six")
    {
        return 6;
    }
    else if (inputString.length() >= 5 && inputString.substr(0, 5) == "seven")
    {
        return 7;
    }
    else if (inputString.length() >= 5 && inputString.substr(0, 5) == "eight")
    {
        return 8;
    }
    else if (inputString.length() >= 4 && inputString.substr(0, 4) == "nine")
    {
        return 9;
    }
    else
    {
        return -1;
    }
}

std::pair<int, int> getFirstLast(std::string inputString)
{
    std::pair<int, int> result;
    for (int i = 0; i < inputString.size(); i++)
    {
        int digit = startsWithDigit(inputString.substr(i, inputString.size() - i));
        if (digit != -1)
        {
            result.first = digit;
            break;
        }
    }
    for (int i = inputString.size() - 1; i >= 0; i--)
    {
        int digit = startsWithDigit(inputString.substr(i, inputString.size() - i));
        if (digit != -1)
        {
            result.second = digit;
            break;
        }
    }
    return result;
}

int main()
{
    long long int sum = 0;
    while (std::cin)
    {
        std::string inputString;
        std::cin >> inputString;
        std::pair<int, int> result = getFirstLast(inputString);
        std::cout << result.first << " " << result.second << std::endl;
        sum += result.first * 10 + result.second;
    }
    std::cout << sum << std::endl;
}