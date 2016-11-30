#include "Queue.h" 
template <class T> Queue<T>::Queue(){
	qsize = 0;
	qfront= nullptr;
	qback= nullptr;
}
template <class T> Queue<T>::~Queue(){
	this->clear();
}
template <class T> Queue<T>::Queue(const Queue& queue){
	qsize = 0;
	operator=(queue);
}
template <class T> Queue<T>& Queue<T>::operator=(const Queue<T>& queue){
	if(!operator==(queue)){
		this->clear();
		Node<T> *current = queue.qfront;
	        for(size_t i = 0; i < queue.qsize; i ++){
	                push(current->value);
			current = current->next;
	        }
	}
	return *this;
}
template <class T> void Queue<T>::clear(){
	while (qsize > 0){
		this->pop();
	}
	qsize = 0;
	qfront = nullptr;
	qback = nullptr;
}
template <class T> size_t Queue<T>::size() const{
	return qsize;
}
template <class T> bool Queue<T>::empty() const{
	return qsize == 0;
}
template <class T> T Queue<T>::front() const{
	if(this->empty())
		throw underflow_error("Caught queue underflow on front()");
	return qfront->value;
}
template <class T> T Queue<T>::back() const{
	if(this->empty())
		throw underflow_error("Caught queue underflow on back()");
	return qback->value;
}
template <class T> void Queue<T>::push(const T& num){
	if(qfront == nullptr){
		qfront = new Node<T>(num);
		qback  = qfront;
	}
	else{
		qback->next = new Node<T>(num);
		qback = qback->next;
	}
	qsize ++;
}
template <class T> void Queue<T>::pop(){
	if (empty())
		throw underflow_error("Caught queue underflow on pop()");

	Node<T> *temp = qfront;
	qfront = qfront->next;
	temp->next = nullptr;
	delete temp;
	qsize --;
}
template <class T> bool Queue<T>::operator==(const Queue<T>& queue) const{
	if(qsize != queue.qsize || qfront->value != queue.qfront->value || qback->value != queue.qback->value)
                return false;
	Node<T> *current = qfront;
	Node<T> *currentO = queue.qfront;
        for(size_t i = 0; i < qsize; i ++){
                if(current->value != currentO->value)
                        return false;
		current = current->next;
		currentO = currentO->next;
        }
        return true;
}

template class Queue<char>;
template class Queue<int>;

