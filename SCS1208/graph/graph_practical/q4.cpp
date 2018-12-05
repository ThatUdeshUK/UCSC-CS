#include <bits/stdc++.h>

using namespace std;

class Edge
{
  public:
    int to;
    Edge *sibling;
};

class Vertex
{
  public:
    int val;
    Edge *edge;
    Vertex *sibling;
};

Vertex *START = NULL;

void addVertex(int value)
{
    if (START == NULL)
    {
        START = new Vertex();
        START->val = value;
    }
    else
    {
        Vertex *PTR = START;
        while (PTR->sibling != NULL)
        {
            PTR = PTR->sibling;
        }
        Vertex *newVertex = new Vertex();
        newVertex->val = value;
        PTR->sibling = newVertex;
    }
}

void addEdge(int from, int to)
{
    Vertex *PTR = START;
    while (PTR != NULL && PTR->val != from)
    {
        PTR = PTR->sibling;
    }
    if (PTR == NULL)
    {
        cout << "There is no such vertex as " << from << endl;
    }
    else
    {
        Edge *EPTR = PTR->edge;
        if (EPTR == NULL)
        {
            Edge *newEdge = new Edge();
            newEdge->to = to;
            PTR->edge = newEdge;
        }
        else
        {
            while (EPTR->sibling != NULL)
            {
                EPTR = EPTR->sibling;
            }
            Edge *newEdge = new Edge();
            newEdge->to = to;
            EPTR->sibling = newEdge;
        }
    }
}


main(int argc, char const *argv[])
{
    addVertex(1);
    addVertex(2);
    addVertex(3);
    addVertex(4);

    addEdge(3, 1);
    addEdge(1, 2);
    addEdge(4, 2);
    addEdge(3, 4);
    addEdge(2, 4);

    return 0;
}
