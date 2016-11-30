#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>


using std::cout;
using std::ostream;
using std::size_t;
using std::underflow_error;


template <class T>
struct Node {
	T value;
	Node* next;
	/****************************
	*Node(T)
	*
	*Constructor takes value T
	****************************/
	Node(T);
};
template <class T> Node<T>::Node(T num){
	value = num;
	next = nullptr;
}

template <class T>
class Queue{
	private:

	public:
		 size_t qsize;
                Node<T>* qfront;
                Node<T>* qback;
		/**********************************************
		*Queue()
		*
		*default constructor
		**********************************************/
		Queue();

                /**********************************************
                *~Queue()
                *
                *destructor
                **********************************************/
		~Queue();

                /**********************************************
                *Queue(const Queue<T>&)
                *
		*param: Queue: object being copied
                *
		*copy constructor
                **********************************************/
		Queue(const Queue<T>&);

                /**********************************************
                *Queue& operator=(const Queue<T>&)
                *
		*param: Queue:object being set to this boject
                *
		*assignment operator
                **********************************************/
		Queue<T>& operator=(const Queue<T>&);


                /**********************************************
                * void clear()
                *
                *Clears object
                **********************************************/
		void clear();

                /**********************************************
                *size_t size() const
                *
                *get current size
                **********************************************/
		size_t size() const;

                /**********************************************
                *size_t capacity() const
                *
                *het current capacity
                **********************************************/
		size_t capacity() const;

                /**********************************************
                * bool empty() const
                *
                *if is empty true else false
                **********************************************/
		bool empty() const;

                /**********************************************
                *T front() const
                *
                *return front element
                **********************************************/
		T front() const;

                /**********************************************
                * T back() const
                *
                *return last element
                **********************************************/
		T back() const;

                /**********************************************
                *void push(const int&)
                *
		*Param: int: int being pushed into the back of the queue
		*
                *Push new element to queue
                **********************************************/
		void push(const T&);

                /**********************************************
                *void pop()
                *
                *remove the first element
                **********************************************/
		void pop();

                /**********************************************
                * bool operator==(const Queue<T>&) const
		*
                *param: Queue: object being compared to this 
                *
		*compare operator
                **********************************************/
		bool operator==(const Queue<T>&) const;

};

template<class U> ostream& operator<< (ostream&, const Queue<U>&);
template <class T> ostream& operator<< (ostream& out, const Queue<T>& queue){
        out << '(' ;
        Node<T> *current = queue.qfront;
        for(size_t i = 0; i < queue.size(); i ++){
                out << current->value;
                if(i !=queue.size() - 1)
                        out<< ", ";
                current = current->next;
        }
        out << ')';
        return out;
}

#endif
