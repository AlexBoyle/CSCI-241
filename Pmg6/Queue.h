#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>


using std::cout;
using std::ostream;
using std::size_t;
using std::underflow_error;

class Queue{
	private:
		size_t qsize;
		size_t qcapacity;
		int qfront;
		int qback;
		int* qarray;
	public:
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
                *Queue(const Queue&)
                *
		*param: Queue: object being copied
                *
		*copy constructor
                **********************************************/
		Queue(const Queue&);

                /**********************************************
                *Queue& operator=(const Queue&)
                *
		*param: Queue:object being set to this boject
                *
		*assignment operator
                **********************************************/
		Queue& operator=(const Queue&);

               /**********************************************
                *friend ostream& operator<<(ostream&, const Queue&);
                *
		*Param: ostream: output
		*	Queue: object being output
		*
                *output operator
                **********************************************/
		friend ostream& operator<<(ostream&, const Queue&);

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
                *int front() const
                *
                *return front element
                **********************************************/
		int front() const;

               /**********************************************
                * int back() const
                *
                *return last element
                **********************************************/
		int back() const;

               /**********************************************
                *void push(const int&)
                *
		*Param: int: int being pushed into the back of the queue
		*
                *Push new element to queue
                **********************************************/
		void push(const int&);

               /**********************************************
                *void pop()
                *
                *remove the first element
                **********************************************/
		void pop();

               /**********************************************
                *void reserve(const unsigned int&)
                *
		*param: unsigned int: new capacity of queue
                *
		*increase the size of the queue
                **********************************************/
		void reserve(const unsigned int&);

               /**********************************************
                * bool operator==(const Queue&) const
		*
                *param: Queue: object being compared to this 
                *
		*compare operator
                **********************************************/
		bool operator==(const Queue&) const;

};

#endif
