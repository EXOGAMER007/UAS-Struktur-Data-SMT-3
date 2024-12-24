#include <iostream>
#include <vector>
using namespace std;

const int N = 4; // Jumlah node (4 nodes: 0, 1, 2, 3)

vector<int> adj[N]; //  merepresentasikan graph
bool visited[N];    // Array untuk melacak node yang sudah dikunjungi

// Fungsi untuk menambahkan edge ke graph
void addEdge(int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// Fungsi rekursif DFS
void DFS(int node)
{
  visited[node] = true; // Tandai node sebagai sudah dikunjungi
  cout << node << " ";  // Cetak node yang sedang dikunjungi

  for (int neighbor : adj[node])
  {
    if (!visited[neighbor]) // Jika neighbor belum dikunjungi
    {
      DFS(neighbor); // Rekursif ke neighbor
    }
  }
}

int main()
{
  // Inisialisasi semua node sebagai belum dikunjungi
  for (int i = 0; i < N; i++)
  {
    visited[i] = false;
  }

  // Membuat Graph
  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(1, 2);
  addEdge(2, 3);

  cout << "DFS Traversal dimulai dari node 0: ";
  DFS(0); // DFS dimulai dari node 0
  cout << endl;
  for (int i = 0; i < N; i++) // visualisasi hubungan antar node
  {
    cout << "Node " << i << ": ";
    for (int neighbor : adj[i])
    {
      cout << neighbor << " ";
    }
    cout << endl;
  }

  return 0;
}
