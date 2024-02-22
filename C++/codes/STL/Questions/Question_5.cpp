#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> first;
    first.assign(7, 100);
    vector<int>::iterator it;
    it = first.begin() + 1;
    int myints[] = {1776, 7, 4};
    cout << int(first.size()) << '\n';
    return 0;
}