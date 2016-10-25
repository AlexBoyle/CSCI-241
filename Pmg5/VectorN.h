#ifndef VECTORN_H
#define VECTORN_H

#include <iostream>
#include <stdexcept>

using std::out_of_range;
using std::cout;
using std::ostream;
using std::size_t;
class VectorN{
	private:
		size_t maxIndex;
		double *arr;
	public:
		/***********************
		*VectorN()
		*
		*Default constructor that sets everything to null
		***********************/
		VectorN();

		/***********************
                *VectorN(const double[], size_t)
                *
		*Param: const double[]: array to initiate this object
                *	size_t: lenght of array
		*
		*set this object to the givin array and size
                ***********************/
		VectorN(const double[], size_t);

		/***********************
                *VectorN(const VectorN&)
                *
                *Param: VectorN: the boject this is being set to
                *
		*This take a VectorN object and make This equal to it
                ***********************/
		VectorN(const VectorN&);

		/***********************
                *~VectorN()
                *
                *This destroys the objects values and refrences
                ***********************/
		~VectorN();

		/***********************
                *VectorN& operator=(const VectorN&)
                *
                *Param: VectorN: the boject being set to this object
                *
                *This overrides the = operator for VectorN
                ***********************/
		VectorN& operator=(const VectorN&);

		/***********************
                * void clear()
                *
                *This destroys the objects values and refrences
                ***********************/
		void clear();

		/***********************
                * size_t size() const;
                *
                *returns the lenght of this VectorN
                ***********************/
		size_t size() const;

		/***********************
                * VectorN operator+(const VectorN&) const
                *
                *Param: VectorN: the object being added to this object
                *
                *This overrides the + operator for VectorN
                ***********************/
		VectorN operator+(const VectorN&) const;

		/***********************
                * VectorN operator-(const VectorN&) const;
                *
                *Param: VectorN: the object being subtracted to this object
                *
                *This overrides the - operator for VectorN
                ***********************/
		VectorN operator-(const VectorN&) const;

		/***********************
                * VectorN operator*(const VectorN&) const;
                *
                *Param: VectorN: the object being multiplied to this object
                *
                *This overrides the * operator for VectorN
                ***********************/
		double operator*(const VectorN&) const;

		/***********************
                *VectorN operator*(const double&) const
                *
                *Param: double: number being multiplyed by
                *
                *This overrides the * operator for VectorN
                ***********************/
		VectorN operator*(const double&) const;

		/***********************
                *friend VectorN operator*(const double&, const VectorN&)
                *
                *Param: double: number being multiplyed by
                *	VectorN: vector  being multiplyed
                *This overrides the * operator for VectorN
                ***********************/
		friend VectorN operator*(const double&, const VectorN&);

		/***********************
                *friend ostream& operator<<(ostream&, const VectorN&)
                *
                *Param: ostream: output
                *       VectorN: vector being output
                *output object
                ***********************/
		friend ostream& operator<<(ostream&, const VectorN&);

		/***********************
                * double& operator[](const int&) const
                *
                *Param: int: index being requested
                *
                *get subscript
                ***********************/
		double& operator[](const int&) const;

		/***********************
                *double at(int) const
                *
                *Param: int: index being requested
                *
                *get subscript
                ***********************/
		double at(int) const;

		/***********************
                *double& at(int)
                *
                *Param: int: index being requested
                *
                *get subscript
                ***********************/
		double& at(int);

		/***********************
                * bool operator==(const VectorN&) const
                *
                *Param: vectorN: vector being compared 
                *
                *check equality
                ***********************/
		bool operator==(const VectorN&) const;
};

#endif
