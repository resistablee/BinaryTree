#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


struct node 
{
	int data;
	node* right;
	node* left;
};

node* AddChild(node* list, int val)
{
	if(list == NULL)
	{
		list = new node;
		list->data = val;
		list->right = NULL;
		list->left = NULL;
		return list;
	}
	
	if(list->data < val)
	{
		list->right = AddChild(list->right, val);
	}
	else
	{
		list->left = AddChild(list->left, val);
	}
	
	//printf("Adres: %d | Deger: %d\n", list, list->data);
	return list;
}

void traver(node* list)
{
	if(list == NULL)
	{
		return;
	}
	
	traver(list->left); //Küçükten büyüge siralar.
	//traver(list->right); //Büyükten kücüge siralar.
	printf("Deger: %d\n", list->data);
	traver(list->right); //Küçükten büyüge siralar.
	//traver(list->left); //Büyükten kücüge siralar.
}

void SearchData(node* list, int val)
{
	if(list == NULL)
	{
		return;
	}
	
	if(list->data == val)
	{
		printf("\nDegerin bulundugu node adresi: %d", list);
	}
	
	
	SearchData(list->left, val); 
	SearchData(list->right, val); 
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	node* list = NULL;
	list = AddChild(list, 10);
	AddChild(list, 50);
	AddChild(list, 80);
	AddChild(list, 40);
	AddChild(list, 20);
	AddChild(list, 30);
	AddChild(list, 70);
	AddChild(list, 90);
	AddChild(list, 60);
	AddChild(list, 100);
	AddChild(list, 0);
	
	/*traver(list);
	
	printf("************************************************************************");
	
	SearchData(list, 20);*/
}





