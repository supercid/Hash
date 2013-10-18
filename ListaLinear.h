//============================================================================
// Name        : Lista ligada
// Author      : Alcidemar Lopes
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#ifndef _ListaLinear_h
#define _ListaLinear_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __ERRO__ -999
#define __SUCESSO__ 0

using namespace std;

template <class Type>
class nodeType{
public:
	nodeType();
	nodeType(Type value);
	Type valor;
	nodeType<Type> *next;
};

template <class Type>
nodeType<Type>::nodeType(){
	next = NULL;
}

template <class Type>
nodeType<Type>::nodeType(Type value){
	valor = value;
	next = NULL;
}

////////////////////////////////////////////////////////////////////////////////

template <class Type>
class linkedListType{
public:

	bool isEmptyList() const;
	int print() const;
	int length() const;
	void limparLista();
	Type front() const;
	Type end() const;
	void insertNode(Type value);
	int insertNodeAt(int position, Type value);
	Type removeNode(); //remove o ultimo
	int findRemoveNode(Type value); //procura, delete e diz a posicao. Se nao for achado retorna erro
	Type removeNodeAt(int position);
	int findValue(Type value) const;
	int copyFromList(linkedListType<Type> *l1);
	linkedListType();
	~linkedListType();
private:
	nodeType<Type> *first; //ponteiro pra cabeca
};

template <class Type>
linkedListType<Type>::linkedListType() {
	first = NULL;
}

template <class Type>
linkedListType<Type>::~linkedListType(){
	nodeType<Type> *temp;

	while (first != NULL){
		temp = first; //aponta tempo para o no atual
		cout<<endl<<"Desalocando no' de valor "<<temp->valor<<endl;
		first = first->next; //caminha para o proximo no
		delete temp;
	}
	cout<<endl<<"Todos os nos foram removidos"<<endl;
	cout<<endl<<"Lista desalocada"<<endl;
}


template <class Type>
int linkedListType<Type>::copyFromList(linkedListType<Type> *l1){

	nodeType<Type> *atualL0 = first;
	int contador = 0;

	nodeType<Type> *l1Atual = l1->first;

	if(l1->first == NULL){
		return contador; //lista l1 e' vazia e nao temos o que inserir
	}
	else{
		while(atualL0->next!=NULL){//procurando o ultimo elemento de l0

			atualL0 = atualL0->next;
		}

		while(l1Atual!=NULL){
			atualL0->next = new nodeType<Type>(l1Atual->valor);
			atualL0 = atualL0->next;
			l1Atual = l1Atual->next;
			++contador;

		}
	}

	return contador;
}


template <class Type>
void linkedListType<Type>::insertNode(Type value){

	nodeType<Type> *novo = new nodeType<Type>(value);
	nodeType<Type> *atual = first;
	nodeType<Type> *anterior;

	if(first == NULL){
		first = novo;
	}
	else{
		while(atual!=NULL){
			anterior = atual;
			atual = atual->next;
		}
		anterior->next = novo;
	}
}


template <class Type>
Type linkedListType<Type>::removeNode(){ //retorna o valor da chave

	nodeType<Type> *atual = first;
	nodeType<Type> *anterior;
	Type chave;


	if(first == NULL){
		cout<<endl<<"Lista vazia"<<endl;
		return (Type)__ERRO__; //GAMBIARRA
	}
	else{
		while(atual->next!=NULL){

			anterior = atual;
			atual = atual->next;
		}
		chave = atual->valor;
		delete(atual);
		anterior->next = NULL;

		return chave;
	}

}


template <class Type>
int linkedListType<Type>::insertNodeAt(int position, Type value){

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
Type linkedListType<Type>::removeNodeAt(int position){


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
void linkedListType<Type>::limparLista()
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
int linkedListType<Type>::print() const
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
int linkedListType<Type>::findValue(Type value) const
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
int linkedListType<Type>::findRemoveNode(Type value)
{

	nodeType<Type> *current = first;
	nodeType<Type> *anterior;
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
				anterior->next = current->next;
				delete(current);
				return contador;

			}
			else{
				anterior = current;
				current = current->next;
			}
		}
	}

	return __ERRO__;
}//end print


template <class Type>
int linkedListType<Type>::length() const
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
Type linkedListType<Type>::front() const
{
	if(first == NULL){
		cout<<"Lista Vazia"<<endl;
		return (Type)__ERRO__;
	}
	else
		return first->valor; //return the info of the first node
}//end front



template <class Type>
Type linkedListType<Type>::end() const
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

#endif