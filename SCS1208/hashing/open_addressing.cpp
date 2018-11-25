#include <bits/stdc++.h>

using namespace std;

template <typename T>
class HashMap
{
  private:
    int m;
    int probing;
    pair<int, T> *table;

    int hash_func(int key)
    {
        return key % m;
    }

    int hash_func2(int key)
    {
        return 8 - (key % 8);
    }

    int probe(int key, int pos, int step)
    {
        if (probing == PROBE_QUADRATIC)
        {
            throw invalid_argument("Quadratic probing is not supported yet");
            // return (pos + (min(step, ) % m;
        }
        else if (probing == PROBE_DOUBLE_HASH)
        {
            return (pos + step * hash_func2(key));
        }
        else
        {
            return (pos + 1) % m;
        }
    }

    void init(int m, int probing)
    {
        this->probing = probing;
        this->m = m;
        this->table = new pair<int, T>[m];
        fill_n(this->table, m, make_pair(-1994, NULL));
    }

  public:
    static const int NULL_VALUE = -1994;
    static const int PROBE_LINEAR = 0;
    static const int PROBE_QUADRATIC = 1;
    static const int PROBE_DOUBLE_HASH = 2;

    HashMap(int m)
    {
        init(m, PROBE_LINEAR);
    }

    HashMap(int m, int probing)
    {
        if (!(probing <= 2 && probing >= 0))
            throw invalid_argument("Invalid probing");
        init(m, probing);
    }

    ~HashMap()
    {
        delete[] this->table;
    }

    void insert(int key, T value)
    {
        int pos = hash_func(key);
        int count = 0;
        while (this->table[pos].first != NULL_VALUE && count < m)
        {
            pos = probe(key, pos, count);
            count++;
        }
        if (count >= m)
            throw invalid_argument("Table full");
        this->table[pos].first = key;
        this->table[pos].second = value;
    }

    T search(int key)
    {
        int pos = hash_func(key);
        int count = 0;
        while (this->table[pos].first != NULL_VALUE && count < m)
        {
            if (this->table[pos].first == key)
            {
                return this->table[pos].second;
            }
            pos = probe(key, pos, count);
            count++;
        }
        if (count >= m)
            throw invalid_argument("Table full");
        throw invalid_argument("Key error");
    }
};

int main(int argc, char const *argv[])
{
    HashMap<int> hashMap(7, HashMap<int>::PROBE_DOUBLE_HASH);
    hashMap.insert(20, 100);
    hashMap.insert(9, 200);
    hashMap.insert(17, 300);
    hashMap.insert(30, 400);
    cout << hashMap.search(30) << endl;
    cout << hashMap.search(17) << endl;
    cout << hashMap.search(9) << endl;
    cout << hashMap.search(20) << endl;
    return 0;
}
