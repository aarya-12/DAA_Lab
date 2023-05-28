
#include <bits/stdc++.h>
using namespace std;
# define V 8
bool hCycle(int graph[V][V], int X[], int pos){
    if (pos == V)   //if all vertices are included
    {
        if (graph[X[pos - 1]][X[0]] == 1)//if last vertex is connected to source vertex
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++)
    {
          if (graph [X[pos - 1]][v] == 0)//check if vertex connected to previous one
            break;
          for (int i = 0; i < pos; i++)//check if vertex already included
           { if (X[i] == v){
            break;}
           }
          
            X[pos] = v;
            if (hCycle (graph, X, pos + 1) == true)
                return true;
            X[pos] = -1;
          
    }
    return false;
}

int main(){
    int graph[8][8] = {{0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 1, 0},
        };
    /*{
        {0, 1, 1, 0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
    };*/
    int *X = new int[8]; //outputArray
    X[0] = 0; //Source vertex
    for (int i = 1; i < 8; i++){
        X[i] = -1;
    }
    if (hCycle(graph, X, 1) == false )
    {
        cout << "\nNo Hamiltonian Cycle";
    }
    else{
        cout << "The Hamiltonian Cycle is: \n";
        for (int i = 0; i < 8; i++)
          cout << X[i] << " ";
        cout << X[0] << " ";
        cout << endl;
    }
}

