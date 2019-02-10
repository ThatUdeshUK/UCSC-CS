#include <bits/stdc++.h>

using namespace std;

class Test
{
  private:
    int x;

  public:
    Test(int x = 100);

    Test(const Test &b);

    friend void print(const Test &test);

    friend class Fuck;

    void setX(int x)
    {
        this->x = x;
    }

    int getX()
    {
        return x;
    }
};

Test::Test(int x)
{
    this->x = x;
}

Test::Test(const Test &b)
{
    this->x = b.x / 2;
}

void print(const Test &test)
{
    cout << test.x << endl;
}

class Fuck;

int main()
{
    Test test1;
    cout << &test1 << endl;

    print(test1);
}