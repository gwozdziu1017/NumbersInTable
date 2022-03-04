/*
 * User provides to program vector of numbers (>=0) and number of columns
 * Program prints numbers in table like output with constant cell width equal to the widest number in given vector
 * e.g
 * [1,2,3,4,5,10] 2:
 * +---+----+
 * |   1|  2|
 * +----+---+
 * |   3|  4|
 * +----+----
 * ...
 * |   9| 10|
 * +----+---+
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

int getNoOfDigitsInNumber(const int number)
{
    if(number == 0)
        return 1;
    else
        return (int) log10 ((double) number) + 1;

}
// returns value of column width = the widest number in vector
int getWidthOfColumn(const std::vector<int>& vec)
{
    std::set<int> setOfWidths; // width of every number in vec
    for(auto number : vec)
    {
        if(number == 0)
        {
            setOfWidths.insert(1);
        }
        else
        {
            setOfWidths.insert(getNoOfDigitsInNumber(number));
        }
    }

    return*(setOfWidths.rbegin());
}

void printDashes(const int width)
{
    for(int i = 0; i < width; i++)
    {
        std::cout << "-";
    }
}
void printTableFrame(const int width, const int noOfColumns)
{
    for(int i = 0; i < noOfColumns; i++)
    {
        std::cout << "+";
        printDashes(width);
    }
    std::cout << "+";
}

void printSpaces(const int noOfSpaces)
{
    for(int i = 0; i < noOfSpaces; i++)
    {
        std::cout << " ";
    }
}

void printNumber(const int number)
{
    std::cout << number;
}
void printNumbersInTable(const int number, const int width)
{
    int numberOfNecessarySpaces = 0;
    std::cout << "|";

    numberOfNecessarySpaces = width - getNoOfDigitsInNumber(number);
    if(numberOfNecessarySpaces == 0) // if zero then it's widest number
            printNumber(number);
    else // there must be spaces before number
    {
        printSpaces(numberOfNecessarySpaces);
        printNumber(number);
    }
}

void printTable(const std::vector<int>& vec, int noOfColumn)
{
    if(noOfColumn > vec.size() || noOfColumn == 0)
    {
        noOfColumn = vec.size();
    }
    int widthOfWidestNumber = getWidthOfColumn(vec);
    int tempIt = 0;
    bool isBreak = false;

    printTableFrame(widthOfWidestNumber, noOfColumn);
    std::cout << std::endl;
    for(auto it = vec.begin(); it < vec.end();)
    {
        tempIt = 0;
        while(tempIt < noOfColumn) {
            if(it >= vec.end())
            {
                isBreak = true;
                break;
            }
            printNumbersInTable(*it, widthOfWidestNumber);
            it++;
            tempIt++;
        }

        std::cout << "|";
        if(isBreak)
        {
            printSpaces(widthOfWidestNumber);
            std::cout << "|";
        }
        std::cout << std::endl;
        printTableFrame(widthOfWidestNumber, noOfColumn);
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> vec = {1, 22, 333, 4444, 55555,666666};
    printTable(vec, 0);

    return 0;
}
