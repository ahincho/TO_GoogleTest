
# include "LinkedList.h"
# include <iostream>
# include "assert.h"

# include "gtest/gtest.h"

using namespace std;

template <typename T>
void LinkedList<T>::append(T e)
{
    if(isEmpty())
    {
        last = new Node<T>;
        last->data = e;
        last->next = last;
    }
    else
    {
        Node<T> *n = new Node<T>;
        n->data = e;
        n->next = last->next;
        last->next = n;
    }
}

template <typename T>
T LinkedList<T>::head()
{
    if(isEmpty())
    {
        return 0;
    }
    return last->next->data;
}

template <typename T>
T LinkedList<T>::tail()
{
    if(isEmpty())
    {
        return 0;
    }
    return last->next->next->data;
}

template <typename T>
int LinkedList<T>::size()
{
    int sz = 0;
    Node<T>* iter = last;
    while(iter)
    {
        iter = iter->next;
        if(iter == last)
        {
            iter = nullptr;
        }
        sz++;
    }
    return sz;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return last == 0;
}

template <typename T>
void LinkedList<T>::printList()
{
    Node<T> *iter = last->next;
    cout << "Lista:" << endl;
    while(iter != last)
    {
        cout << iter->data << endl;
        iter = iter->next;
    }
    cout << last->data << endl;
    cout << "Fin de Lista ..." << endl;
}

int main()
{
    LinkedList<int> listInt;
    // Assert - isEmpty(new) == True
    assert(listInt.isEmpty() == true);
    // Assert - size(new) == 0
    assert(listInt.size() == 0);
    // Assert - head(new) == NULL
    assert(listInt.head() == 0);
    // Assert - tail(new) == NULL
    assert(listInt.tail() == 0);
    // Assert - size(append(L, E)) > 0
    listInt.append(19);
    assert(listInt.size() > 0);
    // Size me devolvia 2 ...
    // Assert - size(append(new, E)) == 1
    assert(listInt.size() == 1);
    // Assert - isEmpty(append(L, E)) == False
    assert(listInt.isEmpty() == false);
    // Assert - head(append(new, E)) == E
    assert(listInt.head() == 19);
    // Assert - tail(append(L, E)) == E
    assert(listInt.tail() == 19);
    // Assert - head(append(new, E), F)) == E
    listInt.append(21);
    assert(listInt.head() == 21);
    // Imprimir la Lista
    listInt.printList();
    return 0;
}

TEST (LinkedList, size)
{
	LinkedList<int> listInt;
	listInt.append(19);
	EXPECT_EQ(1, listInt.size());
}

TEST (LinkedList, isEmpty)
{
        LinkedList<int> listInt;
        EXPECT_EQ(true, listInt.isEmpty());
}

TEST (LinkedList, isNotEmpty)
{
        LinkedList<int> listInt;
        listInt.append(19);
	EXPECT_EQ(false, listInt.isEmpty());
}

TEST (LinkedList, head)
{
        LinkedList<int> listInt;
        listInt.append(19);
        EXPECT_EQ(19, listInt.head());
}

TEST (LinkedList, tail)
{
        LinkedList<int> listInt;
        listInt.append(19);
	listInt.append(21);
        EXPECT_EQ(21, listInt.tail());
}

