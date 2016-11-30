#include "Queue.h" 
Queue::Queue(){
	this->clear();
}
Queue::~Queue(){
	delete[] qarray;
}
Queue::Queue(const Queue& queue){
	*this = queue;
}
Queue& Queue::operator=(const Queue& queue){
	if(!operator==(queue)){
		qsize = queue.size();
        	qcapacity = queue.capacity();
        	qarray = new int[qcapacity];

	        for(size_t i = 0; i < qcapacity; i ++){
	                qarray[i] = queue.qarray[i];
	        }
	        qfront = queue.qfront;
	        qback = queue.qback;
	}
	return *this;
}
ostream& operator<<(ostream& out, const Queue& queue){
	out << '(' ;
        for(size_t i = 0; i < queue.size(); i ++){
                out << queue.qarray[(i + queue.qfront) %queue.capacity() ] ;
                if(i !=queue.size() - 1)
                        out<< ", ";
        }
        out << ')';
        return out;

}
void Queue::clear(){
	qsize = 0;
        qcapacity = 0;
        qfront = 0;
        qback = 0;
        qarray = nullptr;
}
size_t Queue::size() const{
	return qsize;
}
size_t Queue::capacity() const{
	return qcapacity;
}
bool Queue::empty() const{
	return qsize == 0;
}
int Queue::front() const{
	if(this->empty())
		throw underflow_error("Caught queue underflow on front()");
	return qarray[qfront];
}
int Queue::back() const{
	if(this->empty())
		throw underflow_error("Caught queue underflow on back()");
	return qarray[qback];
}
void Queue::push(const int& num){
	if (qsize == qcapacity){
		if (qcapacity == 0)
			reserve(1);
		else
			reserve(qcapacity * 2);
	}
        qback = (qback + 1) % qcapacity;
        qarray[qback] = num;
        ++qsize;
}
void Queue::pop(){
	if (empty())
		throw underflow_error("Caught queue underflow on pop()");

	qfront = (qfront + 1) % qcapacity;
	--qsize;
}
void Queue::reserve(const unsigned int& len){
	if(len > qcapacity){
		int* temp = new int[len];
		int current = qfront;

		for(size_t i = 0; i < qsize; i ++){
			temp [i] = qarray[current];
			current = (current + 1) % qcapacity;
		}
		qcapacity = len;
		qfront = 0;
		qback = qsize - 1;
		delete[] qarray;
		qarray = temp;
	}
}
bool Queue::operator==(const Queue& queue) const{
	if(qsize != queue.qsize || qfront != queue.qfront || qback != queue.qback || qcapacity != queue.qcapacity)
                return false;
        for(size_t i = 0; i < qsize; i ++){
                if(qarray[(i + qfront) % qcapacity] != queue.qarray[(i + qfront) % qcapacity])
                        return false;
        }
        return true;
}

