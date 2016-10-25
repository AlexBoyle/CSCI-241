#include "Vector3.h"

Vector3::Vector3(float x1, float y1, float z1){
	v = new float[3];
	v[0] = x1;
	v[1] = y1;
	v[2] = z1;
}

ostream& operator<<(ostream& out, const Vector3& vector){
	out << "(" << vector[0] << " ," << vector[1] << " ," << vector[2] << " )";
	return out;
}

Vector3 Vector3::operator+(const Vector3& vector) const{
	Vector3 vec (v[0] + vector[0], v[1] + vector[1], v[2] + vector[2]);
	return vec;
}

Vector3& Vector3::operator=(const Vector3& vector){
	v[0] = vector[0];
	v[1] = vector[1];
	v[2] = vector[2];
	return *this;
}

Vector3 Vector3::operator-(const Vector3& vector) const{
	return Vector3(v[0] - vector[0], v[1] - vector[1], v[2] - vector[2]);
}
float Vector3::operator*(const Vector3& vector) const{
	return (v[0] * vector[0]) + (v[1] * vector[1]) + (v[2] * vector[2]);
}
Vector3 Vector3::operator*(const float& num) const{
        return Vector3(v[0] * num, v[1] * num, v[2] * num);
}

bool Vector3::operator==(const Vector3& vector) const{
	return (v[0] == vector[0] && v[1] == vector[1] && v[2] == vector[2]);
}
float& Vector3::operator[](const int& num) const{
	if(num == 0)
		return v[0];
	if(num == 1)
		return v[1];
	if(num ==2)
		return v[2];
	throw;

}

Vector3 operator*(const float& num, const Vector3& vector){
	return Vector3(num * vector[0], num * vector[1], num * vector[2]);
}

