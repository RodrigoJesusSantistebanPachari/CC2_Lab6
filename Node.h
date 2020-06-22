#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
	private:
		T elem;
		Node *next;
	public:
		
		//Constructors
		
		Node(){
			this->elem = 0;
			next = NULL;
		}
		Node(T elem){
			this->elem = elem;
			next = NULL;
		}
		Node(Node &next1){
			this->elem=next1.elem;
			this->next=next1.next;
		}
		
		//Getters and Setters
		
		T getElement(){
			return elem;
		}
		void setElement(T element){
			this->elem = element;
		}
		Node *getNext(){
			return this->next;
		}
		void setNext(Node *next1){
			this->next = next1;
		}
		
		//Destructor
		
		~Node(){
		}
};

#endif
