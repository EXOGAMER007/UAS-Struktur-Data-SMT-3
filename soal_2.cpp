#include <iostream>
using namespace std;

struct node
{
  int nilai;
  node *kanan;
  node *kiri;
  node *parent;
};

node *root = NULL;
node *newNode, *cur, *subParent;

void createFirstNode(int data)
{
  root = new node();
  root->nilai = data;
  root->kanan = NULL;
  root->kiri = NULL;
  root->parent = NULL;
  cout << "Node pertama (" << data << ") dibuat.\n";
}

void insertNode(int data)
{
  newNode = new node();
  newNode->nilai = data;
  newNode->kanan = NULL;
  newNode->kiri = NULL;
  newNode->parent = NULL;

  cur = root;
  subParent = NULL;

  // Cari lokasi untuk node baru
  while (cur != NULL)
  {
    subParent = cur;
    if (data < cur->nilai)
    {
      cur = cur->kiri;
    }
    else
    {
      cur = cur->kanan;
    }
  }

  // Set parent dan posisi untuk node baru
  newNode->parent = subParent;
  if (data < subParent->nilai)
  {
    subParent->kiri = newNode;
  }
  else
  {
    subParent->kanan = newNode;
  }
  cout << "Node dengan nilai " << data << " ditambahkan ke tree.\n";
}

void inorderTraversal(node *cur)
{
  if (cur != NULL)
  {
    inorderTraversal(cur->kiri);  // Kunjungi kiri
    cout << cur->nilai << " ";    // Cetak nilai node
    inorderTraversal(cur->kanan); // Kunjungi kanan
  }
}

void printNode()
{
  if (root == NULL)
  {
    cout << "Belum ada node.\n";
  }
  else
  {
    cout << "Isi Data Tree (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;
  }
}

int main()
{
  createFirstNode(10); // Membuat root
  insertNode(15);      // Menyisipkan node
  insertNode(5);
  insertNode(12);
  insertNode(3);
  printNode(); // Mencetak isi tree
  return 0;
}
