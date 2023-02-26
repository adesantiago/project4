//
//  main.cpp
//  Pj4_905327084
//
//  Created by Alex De Santiago on 7/22/21.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


int locateMaximum( const  string  array[ ],  int  n ) // fix to check ascii index as well if same size
{
    if (n <= 0)
        return -1;
    int maxindex = 0;
    int maxlength = 0;
    for (int i = 0; i < n; i++) //checks string
    {
        string pos = array[i];
        if (array[i].size() > maxlength)
        {
            maxlength = array[i].size();
            maxindex = i;
        }
        else if (array[i].size() == maxlength)
        {
            if (array[i] > array[maxindex])
            {
                maxindex = i;
            }
        }
    }
    return maxindex;
}


bool hasDuplicatedValues( const string array[ ], int  n )
{
    if (n <= 0)
        return false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i] == array[j] && i != j)
                return true;
        }
    }
    return false;
}


int countAllVowels( const string array[ ], int n )
{
    if (n <= 0)
        return -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string pos = array[i];
        for (int j = 0; j < pos.size(); j++)
        {
            char letter = pos.at(j);
            if (letter == 'A' || letter == 'a' || letter == 'E' || letter == 'e' || letter == 'I' || letter == 'i' || letter == 'O' || letter == 'o' || letter == 'U' || letter == 'u' || letter == 'Y' || letter == 'y')
            {
                count++;
            }
        }
    }
    return count;
}


int moveToEnd( string array[ ], int n, int position )
{
    if (n <= 0 || position < 0 || position >= n)
        return -1;
    string element = array[position];
//    for (int i = position; i < n-1; i++)
//    {
//        array[i] = array[i+1];
//    }
    array[position] = array[n-1];
    array[n-1] = element;
    return position;
}


int countIntegers(const string array[ ], int  n ) //fix to make it count strings that have all integers
{
    if (n <= 0)
        return -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string pos = array[i];
        bool isAllInt = true;
        if (pos == "") // empty string returns a number so making it break if string is empty
        {
            break;
        }
        for (int j = 0; j < pos.size(); j++)
        {
            int character = pos.at(j);
            if (!(character < 57 && character > 48))
            {
                isAllInt = false;
            }
         }
         if (isAllInt)
         {
           count++;
         }
    }
    return count;
}


int rotateRight( string array[ ], int n, int amount )
{
    if (n <= 0 || amount < 0)
        return -1;
    for (int i = 0; i < amount; i++)
    {
        string element = array[n-1];
        for (int j = n-1; j > 0; j--)
        {
            array[j] = array[j-1];
        }
        array[0] = element;
    }
    return n*amount;
}


int shiftLeft( string array[ ], int n, int amount, string placeholder )
{
    if (n <= 0 || amount < 0)
        return -1;
    for (int i = 0; i < amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[j] = array[j+1];
            
        }
        array[n-1] = placeholder;
    }
    if (amount > n)
    {
        amount = n;
    }
    return amount;
}

int main()
{
    string a[6] = { "123", "456", "delta", "gamma", "beta", "delta" };

    assert(locateMaximum(a, 6) == 3);
    assert(hasDuplicatedValues(a, 6 ) == true);
    assert(hasDuplicatedValues(a, 3 ) == false);
    assert(countAllVowels(a, 6) == 8);
    assert(countIntegers(a, 6) == 2);
    string c[7] = {"AA", "BB", "aa", "bb", "cc", "dd", "ee" };
    assert(shiftLeft(c, 5, 10, "foo" ) == 5);
    string b[7] = { "AA", "BB", "aa", "bb", "cc", "dd", "ee" };
    assert(locateMaximum(b, 6 ) == 5);
    string d[7] = { "55", "4A", "35", "55.", "15.0", "15.0", "A12A" };
    assert(countIntegers(d, 6) == 2);
    string e[8] = { "+55", "-66", "6.6", "7+4", "77+", "48-", "", " "};
    assert(countIntegers(e, 8) == 0);
    //assert(shiftLeft(a, 6, 1, "butt") == 1 && a[0] == "456" && a[5] == "butt");
    //assert(rotateRight(a, 6, 1) == 6 && a[0] == "delta" && a[5] == "beta");
    //assert(moveToEnd(a, 6, 0) == 0 && a[0] == "delta" && a[5] == "123");
    

cerr << "All tests hath succeeded" << endl;
    return( 0 );
 }
