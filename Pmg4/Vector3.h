#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::ostream;

class Vector3 {
	private:
	public:
		float* v;
		/************************************
		* Vector3(float = 0, float = 0, float = 0)
		* Params: float: the x value of the vector, default 0
		*	  float: the y value of the vector, default 0
		*	  float: the z value of the vector, default 0
		*
		* The constructor
		************************************/
		Vector3(float = 0, float = 0, float = 0);

		/************************************
                * friend ostream& operator<<(ostream&, const Vector3&)
                *
                * Params: ostream: the output stream
                *         Vector3: the vector being printed
		*
		* Return: the stream being output to
                ************************************/
		friend ostream& operator<<(ostream&, const Vector3&);

		/************************************
                * friend Vector3 operator*(const float&, const Vector3&)
                *
                * Params: float: the number being multiplied to a vector
                *         Vector3: the vector being multiplied by
		*
		* Return: vecotr that is the multiplied producto of the float
                ************************************/
		friend Vector3 operator*(const float&, const Vector3&);

		/************************************
                * Vector3& operator=(const Vector3&)
                *
                * Params: Vector3: the vector being set to "this" vector
		*
		* Return: the vector being set
	        ************************************/
		Vector3& operator=(const Vector3&);

		/************************************
                * Vector3 operator+(const Vector3&) const
                *
                * Params: Vector3: vector being added to this vector
		*
		* Return: a vector that is the sum of both vectors
                ************************************/
		Vector3 operator+(const Vector3&) const;

		/************************************
                * Vector3 operator-(const Vector3&) const
                *
                * Params: Vector3: the vector being subtrcted from this vector
		*
		* Return: a vector of the subtracted vectors
                ************************************/
                Vector3 operator-(const Vector3&) const;

		/************************************
                * float operator*(const Vector3&) const
                *
                * Params: Vector3: the vector being multiply be this vector
		*
		* Return: a float that is the sum of the multiplied values
                ************************************/
                float operator*(const Vector3&) const;

		/************************************
                * float operator*(const Vector3&) const
                *
                * Params: float: the float being multiplied by the vector
                *
                * Return: a vector product
                ************************************/
		Vector3 operator*(const float&) const;

		/************************************
                * float operator*(const Vector3&) const
                *
                * Params: Vector3: vector being comapred
                *
                * Return: a bool true if equal false otherwise
                ************************************/
                bool operator==(const Vector3&) const;

		 /************************************
                * float operator*(const Vector3&) const
                *
                * Params: int: index requested
                *
                * Return: a float of the value of the index
                ************************************/
		float& operator[](const int&) const;
};

#endif
