#include <iostream>
#include<bits/stdc++.h>
#include <list>
typedef long long ll;
using namespace std;

class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}
void Graph::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout <<currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
    ll n,i;
    char ch;
    cin>>n;
    Graph g(n);
    ch='\0';
    map<ll,ll>m;
    for(i=0;i<n;i++)
    {
        cin>>ch;
        while(ch!='#')
        {
            if(ch!='#' && ch!=(char)(i+48)){
                g.addEdge(i,(int)((int)ch-48));
                m[i]++;
            }
            cin>>ch;
            
        }
    }
    g.BFS(0);   
    return 0;
}