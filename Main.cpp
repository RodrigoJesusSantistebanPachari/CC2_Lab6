#include<iostream>
#include "LinkedList.h"

using namespace std;

int main(){
	
	
	//Nodes
	
	cout<<"We will create three Nodes\n\n";
	float n1,n2,n3;
	cout<<"\nEnter a number ";cin>>n1;
	cout<<"\nEnter a number ";cin>>n2;
	cout<<"\nEnter a number ";cin>>n3;
	Node <float> node1(n1);
	Node <float> node2(n2);   
	Node <float> node3(n3);
	cout<<"\n\nPrinting current nodes: \n";
	cout<<node1.getElement()<<" -> "<<node2.getElement()<<" -> "<<node3.getElement()<<" -> \n\n";





	//LinkedList
	//We will create a menu with options to insert, delete or to print a Linked List
	
    cout<<"\n\nWe will create a LinkedList now\n\n";
    LinkedList <float>list;
	int option=0;
	
	cout<<"\n1. Insert an element"<<endl;
	cout<<"2. Print your LinkedList"<<endl;
	cout<<"3. Remove an element"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Enter the option\n"; cin>>option;
	
	while(option != 4){
		
		if(option == 1){
			
			float number;
			cout<<"Enter an element\n"; cin>>number;
			list.insert(number);
			cout<<"\nThe number has been inserted correctly\n";
		}
		
		else if(option == 2){
			
			cout<<"\n\nYour curren LinkedList is\n\n";
			list.print();
		}
		
		else if(option == 3){
			
			float number;
			cout<<"Enter an element\n"; cin>>number;
			list.remove(number);
			
		}
		
		else{
			
			cout<<"\nIncorrect Option\nEnter and option again\n"; cin>>option;
			
		}
		
		cout<<"\n\n\n1. Insert an element"<<endl;
		cout<<"2. Print your LinkedList"<<endl;
		cout<<"3. Remove an element"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter the option\n"; cin>>option;
	}
	
	//We will create a new LinkedList using our Copy Constructor
	
	LinkedList <float>list1(list);
	
	//We will use our Iterator now to print our List
	
	cout <<"\n\nWe will use the iterator to print your LinkedList now\n\n";

	for (LinkedList<float>::Iterator iter = list1.begin(); iter != list1.end(); ++iter){
		cout << *iter << " -> ";
	}
	cout<<"\n";
	

	
	//Our destructor will be invoked now
	return 0;
}
