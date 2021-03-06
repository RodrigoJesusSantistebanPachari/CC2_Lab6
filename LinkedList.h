#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include<iostream>

using namespace std;

template <class L>
class LinkedList{
	private:
		int size;
		Node <L> *head;
	public:
		
		class Iterator {
			
			friend class LinkedList;
			
			private:
				Node<L> *PtrNode;
				Iterator(Node<L> *begining){
					PtrNode = begining;
				}

			public:
				
				Iterator(){
					PtrNode = NULL;	
				}

				//We will overload our operators: == , !=, ++, = and *

				bool operator == (const Iterator &i) const {
					return PtrNode == i.PtrNode;
				}

				bool operator != (const Iterator &i) const {
					return !(*this == i);
				}
					
				Iterator &operator ++ () {
					PtrNode = PtrNode->getNext();
					return *this;
				}
				
				Iterator &operator = (const Iterator &i) {
					if (this != &i)
						*PtrNode = *i.PtrNode;
					return *this;
				}

				const L &operator * () const {
					return PtrNode->getElement();
				}
		};
	
		//Begin function: Our iterator will point to the head
		Iterator begin() const{ 
			return Iterator(head); 
		}
		
		//End function: Our iterator will point to NULL
		Iterator end() const{ 
			return NULL; 
		}
		
		//Constructors
		
		LinkedList(){
			this->size = 0;
			head = NULL;
		}
		
		LinkedList(int element){
			this->size = 1;
			head = new Node<L>(element);
		}
		
		LinkedList(LinkedList &list){
			this->size = list.size;
			this->head = new Node<L>(list.head->getElement());
			Node<L> *aux2;
			aux2 = head;
			Node <L>*aux;
			aux = list.head;
			while(aux->getNext()){
				aux2->setNext(new Node<L>(aux->getNext()->getElement()));
				aux = aux->getNext();
				aux2 = aux2->getNext();
			}
		}
		
		
		//Destructor
		
		~LinkedList(){
			cout<<"\nThe destructor is starting to work\n";
			Node <L>*ptr = head;
			Node <L>*next = NULL;
			while(ptr != NULL){
				next = ptr->getNext();
				delete ptr;
				ptr = next;
			}
			delete ptr;
			delete next;
			cout<<"\nThe destructor has deleted your Linked List\n";
		}
		
		//Member Functions
		
		void insert(L number){
			Node<L> *new_node = new Node<L>();
			new_node->setElement(number);
			
			Node <L>*aux1 = head;
			Node <L>*aux2;
			
			while((aux1!=NULL)&&(aux1->getElement() < number)){
				aux2 = aux1;
				aux1 = aux1->getNext();
			}
			
			if(head==aux1){
				head = new_node;
			}
			
			else{
				aux2->setNext(new_node);
			}
			
			new_node->setNext(aux1);
			size++;
			
		}
		
		void print(){
			
			Node <L>*current_node = new Node<L>();
			current_node = head;
			
			while(current_node != NULL){
				cout<<current_node->getElement()<<" -> ";
				current_node = current_node->getNext();
			}
			
			cout<<endl;
			
		}
		
		void remove(L number1){
			
			if(head !=NULL){
				Node <L>*aux_delete = head;
				Node <L>*previous = NULL;
				
				while((aux_delete != NULL)&&(aux_delete->getElement() != number1)){
					previous = aux_delete;
					aux_delete = aux_delete->getNext();
				}
				
				if(aux_delete == NULL){
					cout<<"\nThe element hasn't been found\n";
				}
				
				else if(previous == NULL){
					head = head->getNext();
					delete aux_delete;
					cout<<"\nThe number has been removed correctly\n";
				}
				
				else{
					previous->setNext(aux_delete->getNext());
					delete aux_delete;
					cout<<"\nThe number has been removed correctly\n";
				}
				
			}
			else{
				cout<<"\nYour Linked List is empty\n";
			}
			
		}
		

};

#endif

