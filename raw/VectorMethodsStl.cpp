#include <iostream>
#include <vector>

using namespace std;

template <typename t>
void empty_vector_range(vector<t> values)
{
    values.clear();
    return;
}

template <typename T>
void __print__(const vector<T> input)
{
    cout << endl;
    for (const T &i : input)
        cout << i << " ";
    cout << endl;
}

int main()
{

    vector<int> values = {1, 2, 3, 4};
    __print__(values);
    empty_vector_range(values);
    __print__(values);

    return 0;
}