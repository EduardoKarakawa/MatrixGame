#include "Matrix3x3.h"

float Matrix3f::getValueOf(int i, int j) { return mat[i][j]; }
void Matrix3f::setValueTo(int i, int j, float value) { mat[i][j] = value; }


float Matrix3f::a() { return mat[0][0]; }
float Matrix3f::b() { return mat[0][1]; }
float Matrix3f::c() { return mat[0][2]; }

float Matrix3f::d() { return mat[1][0]; }
float Matrix3f::e() { return mat[1][1]; }
float Matrix3f::f() { return mat[1][2]; }

float Matrix3f::g() { return mat[2][0]; }
float Matrix3f::h() { return mat[2][1]; }
float Matrix3f::k() { return mat[2][2]; }


Matrix3f Matrix3f::getMatrixNull() {
	return Matrix3f(0, 0, 0,
		0, 0, 0,
		0, 0, 0);
}

void Matrix3f::copyValue(Matrix3f& other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = other.getValueOf(i, j);
		}
	}
}



Matrix3f::Matrix3f() {
	// Gera matris identidade
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = i == j ? 1 : 0;
		}
	}
}

Matrix3f::Matrix3f(float degree) {
	float radian = degree * PI / 180.0f;
	mat[0][0] = cosf(radian);	mat[0][1] = -sinf(radian);	mat[0][2] = 0;
	mat[1][0] = sinf(radian);	mat[1][1] = cosf(radian);	mat[1][2] = 0;
	mat[2][0] = 0;				mat[2][1] = 0;				mat[2][2] = 1;
}

Matrix3f::Matrix3f( float v1, float v2, float v3,
					float v4, float v5, float v6,
					float v7, float v8, float v9) {

	// Construtor com parametros
	mat[0][0] = v1;
	mat[0][1] = v2;
	mat[0][2] = v3;
	mat[1][0] = v4;
	mat[1][1] = v5;
	mat[1][2] = v6;
	mat[2][0] = v7;
	mat[2][1] = v8;
	mat[2][2] = v9;
}

Matrix3f::Matrix3f(Matrix3f &other) {
	// Construtor de copia
	copyValue(other);
}

Matrix3f Matrix3f::translate(float x, float y) {
	Matrix3f out = Matrix3f();
	out.setValueTo(2, 0, x);
	out.setValueTo(2, 1, y);

	return out;
}

Matrix3f Matrix3f::scale(float w, float h) {
	Matrix3f out = Matrix3f();
	out.setValueTo(0, 0, w);
	out.setValueTo(1, 1, h);

	return out;
}

Matrix3f Matrix3f::rotate(float degree) {
	return Matrix3f(degree);
}

float Matrix3f::getDeterminant() {
	// Calculo do determinante
	float determinant = 0;

	determinant += mat[0][0] * mat[1][1] * mat[2][2];
	determinant += mat[0][1] * mat[1][2] * mat[2][0];
	determinant += mat[0][2] * mat[1][0] * mat[2][1];

	determinant -= mat[0][2] * mat[1][1] * mat[2][0];
	determinant -= mat[0][0] * mat[1][2] * mat[2][1];
	determinant -= mat[0][1] * mat[1][0] * mat[2][2];

	return determinant;
}

Matrix3f Matrix3f::getTransposed() {
	// Pega a transposta sem mudar a matriz
	Matrix3f transposed(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2]);
	return transposed;
}

void Matrix3f::setTransposed() {
	// Muda a matriz para Wtranspostas
	Matrix3f transp(getTransposed());

	copyValue(transp);
}

Matrix3f Matrix3f::getInverse() {
	if (getDeterminant() != 0) {
		Matrix3f adj;
		for (int line = 0; line < 3; line++) {
			for (int column = 0; column < 3; column++) {

				float minor[2][2];
				int auxi = 0;
				int auxj = 0;
				for (int minor_i = 0; minor_i < 3; minor_i++) {
					for (int minor_j = 0; minor_j < 3; minor_j++) {

						if ((line != minor_i) && (column != minor_j)) {

							minor[auxi][auxj] = mat[minor_i][minor_j];

							auxj++;
						}
					}
					auxi += auxj >= 2 ? 1 : 0;
					auxj = 0;
				}
				float tmp_det = (line + column) % 2 == 0 ? 1 : -1;
				tmp_det *= (minor[0][0] * minor[1][1]) - (minor[0][1] * minor[1][0]);
				adj.setValueTo(line, column, tmp_det);

			}
		}

		adj.setTransposed();
		Matrix3f inverse;
		float det = getDeterminant();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				inverse.setValueTo(i, j, adj.getValueOf(i, j) / det);

			}
		}

		return inverse;
	}

	return getMatrixNull();
}

void Matrix3f::print() {
	for (int i = 0; i < 3; i++) {
		std::cout << " | ";
		for (int j = 0; j < 3; j++) {
			std::cout << mat[i][j] << " | ";
		}
		std::cout << std::endl << std::endl;
	}
}

void Matrix3f::operator= (Matrix3f &other)
{
	copyValue(other);
}

Matrix3f Matrix3f::operator+ (Matrix3f &other)
{
	Matrix3f result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.setValueTo(i, j, mat[i][j] + other.getValueOf(i, j));
		}
	}
	return result;
}

Matrix3f Matrix3f::operator+= (Matrix3f &other)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] += other.getValueOf(i, j);
		}
	}

	return *this;
}

Matrix3f Matrix3f::operator- (Matrix3f &other)
{
	Matrix3f result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.setValueTo(i, j, mat[i][j] - other.getValueOf(i, j));
		}
	}
	return result;
}

Matrix3f Matrix3f::operator-= (Matrix3f &other)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] -= other.getValueOf(i, j);
		}
	}
	return *this;
}

Matrix3f Matrix3f::operator* (Matrix3f &other) {
	Matrix3f result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float value = 0;

			for (int aux = 0; aux < 3; aux++) {
				value += mat[i][aux] * other.getValueOf(aux, j);
			}

			result.setValueTo(i, j, value);
		}
	}

	return result;
}

Matrix3f Matrix3f::operator*= (Matrix3f &other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float value = 0;

			for (int aux = 0; aux < 3; aux++) {
				value += mat[i][aux] * other.getValueOf(aux, j);
			}

			mat[i][j] = value;
		}
	}

	return *this;
}

Matrix3f Matrix3f::operator* (float escalar) {
	Matrix3f result;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			result.setValueTo(i, j, mat[i][j] * escalar);

	return result;
}

Matrix3f Matrix3f::operator*= (float escalar){
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			mat[i][j] *= escalar;

	return *this;
}


ofVec2f Matrix3f::transform(const ofVec2f& vector, float z) const {
	return ofVec2f( mat[0][0] * vector.x + mat[0][1] * vector.y + mat[0][2] * z,
					mat[1][0] * vector.x + mat[1][1] * vector.y + mat[1][2] * z);
}

ofMatrix4x4 Matrix3f::to4x4() {
	return ofMatrix4x4(
		a(),  b(), 0.0f,  c(),
		d(),  e(), 0.0f,  f(),
		0.0, 0.0f, 1.0f, 0.0f,
		g(),  h(), 0.0f, k());

}