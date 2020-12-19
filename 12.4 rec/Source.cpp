#include <iostream>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};
void insert(Elem*& L, Info value);
Info remove(Elem*& L);
int Count(Elem* first, Elem* L)
{
	if (L == NULL)
		return 0;
	else
		if (L->link != first)
			return 1 + Count(first, L->link);
		else
			return 1;
}
int main()
{
	Elem* L = NULL,
		* first = NULL;
	for (int i = 1; i <= 10; i++)
		insert(L, i);
	while (L != NULL)
		cout << remove(L) << " ";
	cout << Count(first, L) << endl;
	cout << endl;
	return 0;
}

void insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;
		T->link = tmp;
	}
	else
	{
		L = tmp;
	}
	tmp->link = L;
}

Info remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link;
	Info value = L->info;
	if (T != L)
	{
		Elem* tmp = L->link;
		delete L;
		L = tmp;
		T->link = L;
	}
	else
	{
		delete L;
		L = NULL;
	}
	return value;
}
