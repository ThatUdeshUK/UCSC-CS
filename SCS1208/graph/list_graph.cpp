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
    while (PTR->val != from && PTR != NULL)
    {
        PTR = PTR->sibling;
    }
    if (PTR == NULL) {
        cout << "There is no such vertex as " << from << endl;
    } else {
        Edge *EPTR = PTR->edge;
        while (EPTR->sibling != NULL)
        {
            EPTR = EPTR->sibling;
        }
        if (EPTR == NULL) {
            cout << "There is no such vertex as " << to << endl;
        } else {
            Edge *newEdge = new Edge();
            newEdge->to = to;
            EPTR->sibling = newEdge;
        }
    }
}

void traverseVertexes()
{
    Vertex *PTR = START;
    while (PTR != NULL)
    {
        cout << PTR->val << ", ";
        PTR = PTR->sibling;
    }
}

main(int argc, char const *argv[])
{
    addVertex(5);
    addVertex(10);
    addVertex(7);
    addVertex(8);
    addVertex(3);
    traverseVertexes();
    return 0;
}
