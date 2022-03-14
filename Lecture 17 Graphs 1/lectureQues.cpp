#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i] == true)
                continue;

            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        cout << current << endl;
        for (int i = 0; i < n; i++)
        {
            // apna edge khud na ho
            if (i == current)
                continue;
            // agar edge not visited toh push it in the queue
            if (edges[current][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            printDFS(edges, n, i, visited);
    }
}

bool hasPath(int **edges, int n, int v1, int v2)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    pendingVertices.push(v1);
    visited[v1] = true;
    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();

        if (current == v2)
            return true;
        for (int i = 0; i < n; i++)
        {
            // apna edge khud na ho
            if (i == current)
                continue;
            // agar edge not visited toh push it in the queue
            if (edges[current][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}
/*
vector<int> *getPath(int **edges,int n, int sv, int ev, bool *visited)
{
    vector<int> *path;


    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == ev){
            path->push_back(ev);
            return path;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i] == true)
                continue;

            if (getPath(edges, n, i, ev, visited)->size() != 0)
                {path->push_back(sv);}
        }


    }


}

void pathprinter(int **edges,int n, int sv, int ev, bool *visited){
    vector<int> *p = getPath(edges, n, sv, ev, visited);
    for (int i = 0; i < p->size(); i++)
    {
        cout << p->at(i) << " ";

    }
    cout << endl;

}
*/
// finding one path using dfs
// recursion krke pehle end vertex tak chle jayenge
// fir vaha se ek ek krke vertices add krte rahenge vector mein
vector<int> getPahtDFS(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = true;
    // checking if sarting vertex is the end vertex
    if (sv == ev)
    {
        vector<int> path;
        path.push_back(sv);
        // cout << sv << endl;
        return path;
    }
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            vector<int> ans = getPahtDFS(edges, n, i, ev, visited);
            if (ans.size())
            {
                ans.push_back(sv);
                // cout << sv << endl;
                return ans;
            }
        }
    }
    // if no path
    vector<int> path;
    return path;
}

// printing path using bfs
// queue mein daalte rahenge
// also maintain a map jisme value of the key is parent of the vertex
// jab queue mein ev mil jaaye, using the map poora trace krlo
// by using the map i mean ev se uske parent par jao and then parent of parent
void getPathBFS(int **edges, int n, int sv, int ev)
{
    queue<int> pendingVertices;
    unordered_map<int, int> tracker;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        if (current == ev)
        {
            cout << current << " ";
            while (current != sv)
            {
                cout << tracker[current] << " ";
                current = tracker[current];
            }
        }

        // cout << current << endl;
        for (int i = 0; i < n; i++)
        {
            // apna edge khud na ho
            if (i == current)
                continue;
            // agar edge not visited toh push it in the queue
            if (edges[current][i] == 1 && !visited[i])
            {
                tracker[i] = current;
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    return;
}



// checking if the graph is connected or not
// counter lga liya aur ek part of graph mein check kr liya kitne vertex hai
// counter ko total vertices se compare kr liya
bool isConnected(int **edges, int n, int sv)
{
    int count = 0;
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        //cout << current << endl;
        count++;
        for (int i = 0; i < n; i++)
        {
            // apna edge khud na ho
            if (i == current)
                continue;
            // agar edge not visited toh push it in the queue
            if (edges[current][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    if (count == n)
        return true;
    else
        return false;
}

// helper function for print connected components
// same as bst par visited array as a pointer pass krdi
void printConnectedHelper(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    //bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            // apna edge khud na ho
            if (i == current)
                continue;
            // agar edge not visited toh push it in the queue
            if (edges[current][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

// printing all the connected components of the graph
// loop lga ke saare unvisited vertices par bst lga diya
void printConnected(int **edges, int n, bool *visited)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printConnectedHelper(edges, n, i, visited);
            cout << endl;
        }
    }
    
}

int main()
{
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // print(edges, n, 0, visited);
    // printBFS(edges, n, 0);
    // cout << hasPath(edges,n,1,3);
    // pathprinter(edges, n, 0, 3, visited);
    // vector<int> path = getPahtDFS(edges, n, 0, 3, visited);
    // for (int i = 0; i < path.size(); i++)
    // {
    //     cout<< path[i] <<  " ";
    // }
    //getPathBFS(edges, n, 0, 3);
    //cout << isConnected(edges, n, 0);
    printConnected(edges, n, visited);
}
