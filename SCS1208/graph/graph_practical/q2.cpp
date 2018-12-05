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
    int color;
    Vertex *sibling;
};

Vertex *START = NULL;

void addVertex(int value)
{
    if (START == NULL)
    {
        START = new Vertex();
        START->color = 0;
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
        newVertex->color = 0;
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

Vertex *findVertex(int key)
{
    Vertex *PTR = START;
    while (PTR != NULL && PTR->val != key)
    {
        PTR = PTR->sibling;
    }
    return PTR;
}

queue<Vertex *> bfsq;

void breadthFirstSearch(Vertex *start)
{
    start->color = 1;
    bfsq.push(start);
    while (!bfsq.empty())
    {
        Vertex *v = bfsq.front();
        cout << v->val << ", ";
        Edge *PTR = v->edge;
        while (PTR != NULL)
        {
            Vertex *vv = findVertex(PTR->to);
            if (vv != NULL && vv->color == 0)
            {
                vv->color = 1;
                bfsq.push(vv);
            }
            PTR = PTR->sibling;
        }
        bfsq.pop();
    }
}

main(int argc, char const *argv[])
{
    addVertex(0);
    addVertex(1);
    addVertex(2);
    addVertex(3);

    addEdge(0, 2);
    addEdge(2, 0);

    addEdge(0, 1);

    addEdge(1, 2);

    addEdge(2, 3);

    addEdge(3, 3);

    Vertex *start = findVertex(2);
    breadthFirstSearch(start);

    return 0;
}
