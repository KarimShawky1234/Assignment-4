//
//  main.cpp
//  Assignment4
//
//  Created by kareem ahmed shawky on 4/7/23.
//

#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

vector<int> insertAfter(int firstValue, int secondValue, vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == firstValue)
        {
            vec.insert(vec.begin() + i + 1, secondValue);
        }
    }
    return vec;
}

int main()
{
    vector<int> v;
    int n, num, firstVal, secondVal;
    cout << "Enter the numbers of integers you will enter ";
    cin >> n;
    cout << "Enter the integers you will store ";

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    cout << "Enter a value to check for occurrences ";
    cin >> firstVal;
    cout << "Enter the value to add into the vector after each occurrences ";
    cin >> secondVal;
    v = insertAfter(firstVal, secondVal, v);
    LinkedList list;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        list.InsNode(v[i]);
    }
    cout << "The items in the list are: " << endl;
    list.printList();
    cout << "The sum of the list: " << list.sumList();

    return 0;

}
