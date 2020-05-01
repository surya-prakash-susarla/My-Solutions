#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <memory>

using namespace std;
typedef unsigned long long int long_int;

struct node
{
    long_int count;
    long_int depth;
    node()
    {
        count = 0;
    }
    unordered_map<char, shared_ptr<node>> map_values;
};

void __find__(shared_ptr<node> current_node, const long_int &group_size, long_int &answer_score)
{
    if (current_node->count < group_size) {
        return;
    }
    if (current_node->count == group_size && current_node->map_values.size() != 1 )
    {
        answer_score += current_node->depth;
        current_node->map_values.clear();
        current_node->count = 0;
        return;
    }
    vector < unordered_map<char,shared_ptr<node>>::iterator  > it_values;
    for (unordered_map<char, shared_ptr<node>>::iterator it = current_node->map_values.begin(); it != current_node->map_values.end(); it++)
    {
        current_node->count -= it->second->count;
        if (it->second->count < group_size)
        {
            it_values.push_back(it);
            current_node->count += it->second->count;
        }
        else
        {
            __find__(it->second, group_size, answer_score);
            if (it->second->count)
            {
                it_values.push_back(it);
                current_node->count += it->second->count;
            }
        }
    }
    answer_score += (current_node->count / group_size) * current_node->depth;
    current_node->count = current_node->count % group_size;
}

void make_trie(shared_ptr<node> current_node, const string &value, int index)
{
    current_node->count++;
    if (index == value.size()){
        return;
    }
    auto it = current_node->map_values.find(value[index]);
    if (it == current_node->map_values.end())
    {
        shared_ptr<node> new_node = make_shared<node>();
        new_node->depth = current_node->depth + 1;
        current_node->map_values[value[index]] = new_node;
        make_trie(new_node, value, index + 1);
    }
    else
    {
        make_trie(it->second, value, index + 1);
    }
}

long_int __calc__()
{
    long_int n;
    long_int k;
    cin >> n >> k;
    vector<string> values(n);
    for_each(values.begin(), values.end(), [](string &current_value) {
        cin >> current_value;
    });
    shared_ptr<node> root = make_shared<node>();
    root->depth = 0;
    root->count = 0;
    for_each(values.begin(), values.end(), [root](string &current_value) {
        make_trie(root, current_value, 0);
    });
    long_int answer_score = 0;
    __find__(root, k, answer_score);
    return answer_score;
}

int main()
{
    long_int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << __calc__();
        if (i < t)
            cout << endl;
    }
    return 0;
}