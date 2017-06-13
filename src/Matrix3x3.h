#pragma once

class Matrix3f {
	private:
		float mat[3][3];



	private:
		Matrix3f getMatrixNull() {
			return Matrix3f(0, 0, 0,
							0, 0, 0,
							0, 0, 0);
		}

		void copyValue(Matrix3f& other) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					mat[i][j] = other.getValueOf(i, j);
				}
			}
		}


	public:
	
		Matrix3f() {
			// Gera matris identidade
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					mat[i][j] = i == j ? 1 : 0;
				}
			}
		}

		Matrix3f(float v1, float v2, float v3,
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

		Matrix3f(Matrix3f &other) {
			// Construtor de copia
			copyValue(other);
		}

		float getValueOf(int i, int j) { return mat[i][j]; }
		void setValueTo(int i, int j, float value) { mat[i][j] = value; }

		float getDeterminant() {
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


		Matrix3f getTransposed() {
			// Pega a transposta sem mudar a matriz
			Matrix3f transposed(
				mat[0][0], mat[1][0], mat[2][0],
				mat[0][1], mat[1][1], mat[2][1],
				mat[0][2], mat[1][2], mat[2][2]);
			return transposed;
		}

		void setTransposed() {
			// Muda a matriz para Wtranspostas
			Matrix3f transp(getTransposed());
			
			copyValue(transp);
		}

		Matrix3f getInverse() {
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


		void print() {
			for (int i = 0; i < 3; i++) {
				std::cout << " | ";
				for (int j = 0; j < 3; j++) {
					std::cout << mat[i][j] << " | ";
				}
				std::cout << std::endl << std::endl;
			}
		}
		// TODO - Cópia de matriz: operador =
		// TODO - Multiplicação de matrizes: operador *

};
