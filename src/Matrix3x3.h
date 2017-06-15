#pragma once
#include <iostream>

class Matrix3f {
	private:
		float mat[3][3];



	private:
		Matrix3f getMatrixNull();
		void copyValue(Matrix3f& other);


	public:
		// Construtores
		Matrix3f();
		Matrix3f(float v1, float v2, float v3,
				 float v4, float v5, float v6,
				 float v7, float v8, float v9);
		Matrix3f(Matrix3f &other);


		float getValueOf(int i, int j);
		float getDeterminant();
		Matrix3f getTransposed();
		Matrix3f getInverse();
		void setValueTo(int i, int j, float value);
		void setTransposed();
		void print();

		// Sobrecarga de Operadores
		void Matrix3f::operator= (Matrix3f &other);
		Matrix3f Matrix3f::operator*= (Matrix3f &other);
		Matrix3f Matrix3f::operator* (Matrix3f &other);
		Matrix3f Matrix3f::operator+= (Matrix3f &other);
		Matrix3f Matrix3f::operator+ (Matrix3f &other);
		Matrix3f Matrix3f::operator-= (Matrix3f &other);
		Matrix3f Matrix3f::operator- (Matrix3f &other);
		Matrix3f Matrix3f::operator* (float escalar);
		Matrix3f Matrix3f::operator*= (float escalar);

};
