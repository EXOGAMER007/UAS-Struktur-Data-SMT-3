#include <iostream>
using namespace std;

struct list
{
  int nilai;
  list *next;
  list *prev;
};

list *head, *tail, *cur, *newNode;

void createDoubleLinkedList(int data)
{
  head = new list();
  head->nilai = data;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

void addLast(int data)
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    newNode = new list();
    newNode->nilai = data;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

void printDoubleLinkedList()
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    cout << "Isi Data :" << endl;
    cur = head;
    int nilai = 1;
    while (cur != NULL)
    {
      cout << "Nilai ke -" << nilai << " :" << cur->nilai << endl;
      nilai++;
      cur = cur->next;
    }
  }
}

int main()
{
  int data[5] = {10, 20, 30, 40, 50};
  for (int i = 0; i < 5; i++)
  {
    if (i == 0)
    {
      createDoubleLinkedList(data[i]);
    }
    else
    {
      addLast(data[i]);
    }
  }
  printDoubleLinkedList();
  return 0;
}