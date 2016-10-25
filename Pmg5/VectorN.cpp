#include "VectorN.h"

VectorN::VectorN(){
	arr = nullptr;
	maxIndex = 0;
}
VectorN::VectorN(const double value[], size_t n){
	if(n == 0){
		arr = nullptr;
		maxIndex = n;
	}
	else {
		arr = new double[n];
		for(int i = 0; i < n; i ++){
			arr[i] = value[i];
		}
		maxIndex = n;
	}
}
VectorN::VectorN(const VectorN& vec){
	arr = new double[vec.size()];
	for(int i = 0; i < vec.size(); i ++){
		arr[i] = vec[i];
	}
	maxIndex = vec.size();
}
VectorN::~VectorN(){
	this->clear();
}
VectorN& VectorN::operator=(const VectorN& vec){
	if(!operator==(vec)){
		this->clear();
		arr = new double[vec.size()];
        	for(int i = 0; i < vec.size(); i ++){
        	        arr[i] = vec[i];
        	}
        	maxIndex = vec.size();
	}
	return *this;
}
void VectorN::clear(){
	arr = nullptr;
	maxIndex = 0;
}
size_t VectorN::size() const{
	return maxIndex;
}
VectorN VectorN::operator+(const VectorN& vec) const{
	int num = 0;
	if(this->size() > vec.size())
		num = vec.size();
	else
		num = this->size();

	double* ar = new double[num];
	for(int i = 0; i < num; i ++){
		ar[i] = arr[i] + vec[i];
	}
	return VectorN(ar,num);
}
VectorN VectorN::operator-(const VectorN& vec) const{
        int num = 0;
        if(this->size() > vec.size())
                num = vec.size();
        else
                num = this->size();

	double* ar = new double[num];
        for(int i = 0; i < num; i++){
                ar[i] = arr[i] - vec[i];
        }
        return VectorN(ar,num);
}
double VectorN::operator*(const VectorN& vec) const{
        double ar = 0;
        for(int i = 0; i < maxIndex; i ++){
                ar += arr[i] * vec[i];
        }
        return ar;
}
VectorN VectorN::operator*(const double& dou) const{
	double* ar = new double[maxIndex];
        for(int i = 0; i < maxIndex; i ++){
                ar[i] = arr[i] * dou;
        }
        return VectorN(ar,maxIndex);
}
VectorN operator*(const double& dou, const VectorN& vec){
	 double* ar = new double[vec.size()];
        for(int i = 0; i < vec.size(); i ++){
                ar[i] = vec[i] * dou;
        }
        return VectorN(ar,vec.size());
}
ostream& operator<<(ostream& out, const VectorN& vec){
	out << '(' ;
	for(int i = 0; i < vec.size(); i ++){
		out << vec[i] ;
		if(i !=vec.size() - 1)
			out<< ", ";
	}
	out << ')';
	return out;
}
double& VectorN::operator[](const int& num) const{
	return arr[num];
}
double VectorN::at(int num) const{
	if(num < 0 || num >= maxIndex)
		 throw out_of_range("subscript out of range");
	return arr[num];
}
double& VectorN::at(int num){
	if(num < 0 || num >= maxIndex)
                 throw out_of_range("subscript out of range");
        return arr[num];
}
bool VectorN::operator==(const VectorN& vec) const{
	if(this->size() != vec.size())
                return false;
        for(int i = 0; i < maxIndex; i ++){
                if(arr[i] != vec[i])
                        return false;
        }
        return true;

}

