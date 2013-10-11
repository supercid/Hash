//============================================================================
// Name        : ListaDuplamenteEncadeada.cpp
// Author      : Alcidemar Lopes
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __ERRO__ -999
#define __SUCESSO__ 0

using namespace std;

template <class Type>
struct nodeType{
public:
	nodeType();
	//~nodeType();
	nodeType(Type value);
	Type valor;
	nodeType<Type> *next;
	nodeType<Type> *previous;
};

template <class Type>
nodeType<Type>::nodeType(){

	previous = NULL;
	next = NULL;

}

template <class Type>
nodeType<Type>::nodeType(Type value){

	valor = value;
	next = NULL;
	previous = NULL;

1q}


///////////////////////////////////////////////////////////////////////////////
template <class Type>
class doublyLinkedListType
{
public:

	bool isEmptyList() const;
	int print() const;
	int printReverse() const;
	int length() const;
	void limparLista();
	Type front() const;
	Type end() const;
	//Type back() const;
	int insertNode(Type value);
	int insertNodeAt(int position, Type value);
	Type removeNode(); //remove o ultimo
	int findRemoveNode(Type value); //procura, delete e diz a posicao. Se nao for achado retorna erro
	Type removeNodeAt(int position);
	int findValue(Type value) const;
	int copyFromList(doublyLinkedListType<Type> *l1);
	doublyLinkedListType();
	~doublyLinkedListType();
private:
	//variable to store the number of list elements
	nodeType<Type> *first; //pointer to the first node of the list

};

template <class Type>
doublyLinkedListType<Type>::doublyLinkedListType() //default constructor
{
	first = NULL;
}

template <class Type>
doublyLinkedListType<Type>::~doublyLinkedListType() //default constructor
{
	nodeType<Type> *temp;

	while (first != NULL)
	{
		temp = first;
		//set temp to the current node
		cout<<endl<<"Desalocando no' de valor "<<temp->valor<<endl;
		first = first->next; //advance first to the next node
		delete temp;

		//deallocate the memory occupied by temp
	}
	cout<<endl<<"Todos os nos foram removidos"<<endl;
	cout<<endl<<"Lista desalocada"<<endl;
}

template <class Type>
void doublyLinkedListType<Type>::limparLista()
{
	nodeType<Type> *temp;

	while (first != NULL)
		//while there are nodes in the list
	{
		temp = first;
		//set temp to the current node
		first = first->next; //advance first to the next node
		delete temp;
		//deallocate the memory occupied by temp
	}
}

template <class Type>
int doublyLinkedListType<Type>::print() const
{


	nodeType<Type> *current = first;

	if(current == NULL){
		cout<<"\nA lista está vazia"<<endl;
		return __ERRO__;
	}
	else{

		while (current != NULL) //while more data to print
		{
			cout << current->valor << " ";
			current = current->next;
		}
	}
	return __SUCESSO__;
}//end print



template <class Type>
int doublyLinkedListType<Type>::printReverse() const
{


	nodeType<Type> *current = first;

	if(current == NULL){
		cout<<"\nA lista está vazia"<<endl;
		return __ERRO__;
	}
	else{

		while (current->next!= NULL) //chegar até o fim
		{

			current = current->next;
		}

		while(current!=NULL){
			cout << current->valor << " ";
			current = current->previous;
		}
	}
	return __SUCESSO__;
}//end print


template <class Type>
int doublyLinkedListType<Type>::findValue(Type value) const
{


	nodeType<Type> *current = first;
	int contador = 0;
	if(current == NULL){
		cout<<"\nA lista está vazia"<<endl;
		return __ERRO__;
	}
	else{
		while (current != NULL )
		{
			++contador;

			if(current->valor == value)
				return contador;
			else
				current = current->next;
		}
	}

	return __ERRO__;
}//end print


template <class Type>
int doublyLinkedListType<Type>::length() const
{
	int count = 0;
	nodeType<Type> *aux = first;
	while(aux!=NULL){
		count++;
		aux = aux->next;
	}
	return count;
}


template <class Type>
Type doublyLinkedListType<Type>::front() const
{
	if(first == NULL){
		cout<<"Lista Vazia"<<endl;
		return (Type)__ERRO__;
	}
	else
		return first->valor; //return the info of the first node
}//end front



template <class Type>
Type doublyLinkedListType<Type>::end() const
{
	nodeType<Type> *atual = first;

	Type chave;


	if(first == NULL){
		cout<<endl<<"Lista vazia"<<endl;
		return (Type)__ERRO__; //GAMBIARRA
	}
	else{

		while(atual->next!=NULL){

			atual = atual->next;
		}
		return atual->valor;
	}

}//end front


template <class Type>
int doublyLinkedListType<Type>::insertNode(Type value){

	nodeType<Type> *novo = new nodeType<Type>(value);
	nodeType<Type> *atual = first;
	int posicao = 0;


	if(first == NULL){
		first = novo;
		//nao precisamos atualizar ponteiros
		return 1;
	}
	else
	{
		++posicao;
		while(atual->next!=NULL){
			++posicao;
			atual = atual->next;
		}
		++posicao;
		atual->next = novo;
		novo->previous = atual;
	}


	return posicao;

}



template <class Type>
int doublyLinkedListType<Type>::insertNodeAt(int position, Type value){

	nodeType<Type> *novo = new nodeType<Type>(value);
	nodeType<Type> *atual = first;
	nodeType<Type> *anterior;

	int contador = 1;


	if(first == NULL){
		cout<<"lista vazia"<<endl;
		return __ERRO__;
	}
	else{
		while(atual!=NULL && contador<=position){

			if(contador == position){

				novo->next = atual;
				atual->previous = novo;
				novo->previous = anterior;
				anterior->next = novo;

				return __SUCESSO__;
			}

			anterior= atual;
			atual = atual->next;
			++contador;
		}

	}

	return __ERRO__;

}


template <class Type>
Type doublyLinkedListType<Type>::removeNode(){ //retorna o valor da chave


	nodeType<Type> *atual = first;
	//nodeType<Type> *anterior;
	Type chave;


	if(first == NULL){
		cout<<endl<<"Lista vazia"<<endl;
		return (Type)__ERRO__; //GAMBIARRA
	}
	else{
		while(atual->next!=NULL){

			//anterior = atual;
			atual = atual->next;
		}
		chave = atual->valor;
		atual->previous->next = NULL;
		delete(atual);
		//anterior->next = NULL;

		return chave;
	}


}



template <class Type>
Type doublyLinkedListType<Type>::removeNodeAt(int position){


	nodeType<Type> *atual = first;
	nodeType<Type> *anterior;
	Type chave;

	int contador = 1;


	if(first == NULL){
		cout<<"lista vazia"<<endl;
		return (Type)__ERRO__;
	}
	else{
		while(atual!=NULL && contador<=position){

			if(contador == position){
				chave = atual->valor;
				anterior->next = atual->next;
				atual->next->previous = anterior;
				return chave;
			}

			anterior= atual;
			atual = atual->next;
			++contador;
		}

	}

	return (Type)__ERRO__;

}


template <class Type>
int doublyLinkedListType<Type>::findRemoveNode(Type value)
{

	nodeType<Type> *current = first;
	//nodeType<Type> *anterior;
	int contador = 0;

	if(current == NULL){
		cout<<"\nA lista está vazia"<<endl;
		return __ERRO__;
	}
	else{
		while (current != NULL )
		{
			++contador;

			if(current->valor == value){
				current->previous->next = current->next;
				current->next->previous = current->previous;
				delete(current);
				return contador;

			}
			else{
				//anterior = current;
				current = current->next;
			}
		}
	}

	return __ERRO__;
}//end print
