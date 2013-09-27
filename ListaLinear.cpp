//============================================================================
// Name        : Lista ligada
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
struct nodeType
{
public:
	nodeType();
	//~nodeType();
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
class linkedListType
{
public:

	bool isEmptyList() const;
	int print() const;
	int length() const;
	void limparLista();
	Type front() const;
	Type end() const;
	//Type back() const;
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
	//variable to store the number of list elements
	nodeType<Type> *first; //pointer to the first node of the list
};

template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = NULL;
}

template <class Type>
linkedListType<Type>::~linkedListType() //default constructor
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

int main() {

	linkedListType<int> *minhaLista2 = new linkedListType<int>();
	linkedListType<int> *minhaLista = new linkedListType<int>();
	cout<<minhaLista->findValue(3)<<endl<<endl;
	minhaLista->insertNode(1);

	minhaLista->insertNode(2);
	minhaLista->insertNode(3);
	minhaLista->insertNode(4);

	cout<<"Tamanho da minha lista: "<< minhaLista->length()<<endl<<endl;
	puts("Minha lista: ");
	minhaLista->print();


	cout<<endl<<"Primeiro elemento da minha lista: "<<minhaLista->front()<<endl;



	cout<<minhaLista->findValue(3)<<endl<<endl;

	cout<<"Inserindo 10 na 2: "<<endl<<endl;
	minhaLista->insertNodeAt(2,10);
	minhaLista->print();

	cout<<endl<<"Agora vou procurar e remover o 10"<<endl;
	cout<<"10 esta na posicao: "<<minhaLista->findRemoveNode(10)<<endl<<endl;
	cout<<endl<<"Lista depois da remocao do 10:"<<endl;
	minhaLista->print();

	cout<<endl<<"Agora vou procurar e remover o ultimo de valor "<<minhaLista->removeNode()<<endl;
	cout<<endl<<"Lista depois da remocao do ultimo:"<<endl<<endl;

	cout<<endl<<"Agora vou procurar e remover o valor na posicao 2: "<<minhaLista->removeNodeAt(2)<<endl<<endl;

	minhaLista->print();

	cout<<endl<<"Agora vou procurar e remover o 50 e o 55 no fim"<<endl;
	minhaLista->insertNode(50);
	minhaLista->insertNode(55);
	minhaLista->print();
	cout<<endl<<endl;

	cout<<endl<<"Agora vou procurar e remover o valor na posicao 3: "<<minhaLista->removeNodeAt(3)<<endl<<endl;

	minhaLista->print();
	cout<<endl<<endl;

	cout<<"Vou procurar pelo elemento 200 e remove-lo: "<<minhaLista->findRemoveNode(200)<<endl<<endl;
	minhaLista->print();
	cout<<endl<<endl;

	minhaLista2->insertNode(9);
	minhaLista2->insertNode(15);
	minhaLista2->insertNode(22);
	cout<<endl<<endl<<"Imprimindo a segunda lista"<<endl;
	minhaLista2->print();

	cout<<endl<<endl<<"Copiando da segunda pra primeira"<<endl;
	cout<<endl<<endl<<"Realizei a copia de " <<minhaLista->copyFromList(minhaLista2)<<"elementos da lista dois pra um"<<endl;
	minhaLista->print();

	//cout<<endl<<"Vou limpar minha lista um"<<endl;
	//minhaLista->limparLista();
	//minhaLista->print();
	//cout<<endl<<endl;

	//cout<<endl<<"Vou limpar minha lista dois"<<endl;
	//minhaLista2->limparLista();
	//minhaLista2->print();
	//cout<<endl<<endl;

	delete(minhaLista);
	delete(minhaLista2);
	return 0;

}
