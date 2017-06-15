#pragma once
#include <iostream>
#include "ofVec2f.h"
#include "ofMatrix4x4.h"

class Matrix3f {
	private:
		float mat[3][3];



	private:
		Matrix3f getMatrixNull();
		void copyValue(Matrix3f& other);


	public:
		// Construtores
		Matrix3f();
		Matrix3f(float degree);
		Matrix3f(float v1, float v2, float v3,
				 float v4, float v5, float v6,
				 float v7, float v8, float v9);
		Matrix3f(Matrix3f &other);

		// Geters
		float getValueOf(int i, int j);
		float getDeterminant();
		Matrix3f getTransposed();
		Matrix3f getInverse();
		

		float a();
		float b(); 
		float c(); 
		float d(); 
		float e(); 
		float f();
		float g();
		float h();
		float k();

		// Seters
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


		ofVec2f transform(const ofVec2f& vector, float z = 1.0f) const;
		ofMatrix4x4 to4x4();
};
