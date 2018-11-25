#include <bits/stdc++.h>

using namespace std;

template <typename T>
class HashMap
{
  private:
    int m;
    vector<pair<int, T>> *table;

    int hash_func(int key)
    {
        return key % m;
    }

  public:
    HashMap(int m)
    {
        this->m = m;
        this->table = new vector<pair<int, T>>[m];
    };

    ~HashMap()
    {
        for (size_t i = 0; i < m; i++)
        {
            vector<pair<int, T>>().swap(this->table[i]);
        }

        delete[] table;
    }

    void insert(int key, T value)
    {
        this->table[hash_func(key)].push_back(make_pair(key, value));
    }

    T search(int key)
    {
        vector<pair<int, T>> cell = this->table[hash_func(key)];

        for (size_t i = 0; i < cell.size(); i++)
        {
            if (cell[i].first == key)
            {
                return cell[i].second;
            }
        }
        throw invalid_argument("Key error");
    }
};

int main()
{
    HashMap<int> hashMap(7);
    hashMap.insert(20, 100);
    hashMap.insert(9, 200);
    hashMap.insert(17, 300);
    hashMap.insert(30, 400);
    cout << hashMap.search(30) << endl;
    cout << hashMap.search(17) << endl;
    cout << hashMap.search(9) << endl;
    cout << hashMap.search(10) << endl;
    return 0;
}