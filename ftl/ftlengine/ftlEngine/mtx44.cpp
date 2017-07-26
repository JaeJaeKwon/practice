#include "mtx44.hpp"
#include <iostream>
#include <memory>
//C++ Additions

/*! A 4D Matrix for a 2D game, z is used for Z-order.  This matrix uses row
vectors.  This means the members of a vector are placed in each row of the
matrix.
\verbatim
|Xx Xy Xz 0 |
|Yx Yy Yz 0 |
|Zx Zy Zz 0 |
|Tx Ty Tz 1 |
\endverbatim
*/
Mtx44::Mtx44(void)
{
	MakeIdentity();
}
Mtx44::Mtx44(const Mtx44& rhs)
{
	*this = rhs;
}
//Member functions
//Sets all of the matrix values to 0
void Mtx44::MakeZero(void)
{
				std::memset(m, 0, sizeof(m));
}
//Sets the matrix to the Identity Matrix
void Mtx44::MakeIdentity(void)
{
				MakeZero();
				m[0][0] = 1;
				m[1][1] = 1;
				m[2][2] = 1;
				m[3][3] = 1;
}
//Sets this matrix to a tranlsation matrix with the given values
void Mtx44::MakeTranslate(float x, float y, float zOrder)
{
	MakeIdentity();

	m[HB_ROWS - 1][0] = x;
	m[HB_ROWS - 1][1] = y;
	m[HB_ROWS - 1][2] = zOrder;
}
//Sets this matrix to a tranlsation matrix with the given values
void Mtx44::MakeTranslate(const Vector3& trans, float zOrder)
{
	MakeIdentity();

	m[HB_ROWS - 1][0] = trans.x;
	m[HB_ROWS - 1][1] = trans.y;
	m[HB_ROWS - 1][2] = zOrder;
}
//Sets the matrix to a scale matrix with the given values
void Mtx44::MakeScale(float x, float y)
{
	MakeIdentity();

	m[0][0] = x;
	m[1][1] = y;
}
//Sets this matrix to a scale matrix with the given values
void Mtx44::MakeScale(const Vector3& scale)
{
	MakeIdentity();

	m[0][0] = scale.x;
	m[1][1] = scale.y;
}
//Sets this matrix to a Rotation matrix around the Z axix
void Mtx44::MakeRotateZ(float radians)
{
	MakeIdentity();

	m[0][0] = cosf(radians);
	m[0][1] = -sinf(radians);
	m[1][0] = sinf(radians);
	m[1][1]= cosf(radians);
}
//Sets this Matrix to scale rotate and translation matrix with the give values
void Mtx44::MakeTransform(float scaleX, float scaleY, float radians,
	float transX, float transY, float zOrder)
{
	Mtx44 scale;
	scale.MakeScale(scaleX, scaleY);

	Mtx44 rotation;
	rotation.MakeRotateZ(radians);

	Mtx44 translate;
	translate.MakeTranslate(transX, transY, zOrder);
	
		*this	= translate*(scale*rotation);
}
//Sets this Matrix to scale rotate and translation matrix with the give values
void Mtx44::MakeTransform(const Vector3& scale, float radians,
	const Vector3& trans, float zOrder)
{
	Mtx44 scaleM;
	scaleM.MakeScale(scale);

	Mtx44 rotation;
	rotation.MakeRotateZ(radians);

	Mtx44 translate;
	translate.MakeTranslate(trans, zOrder);
	
		*this	= translate *(scaleM*rotation);
}

//Operators
//Lets the user mulitply two matricies together
Mtx44 Mtx44::operator*(const Mtx44& rhs) const
{
	Mtx44 multiple;
	for (int k = 0; k < HB_ROWS; ++k)
	{
		for (int j = 0; j < HB_ROWS; ++j)
		{
			for (int i = 0; i < HB_ROWS; ++i)
			{
				multiple.m[k][j] += m[k][i] * rhs.m[i][j];
			}
		}
	}
	return multiple;
}
//Lets the user mulitply two matricies together
Mtx44& Mtx44::operator*=(const Mtx44& rhs)
{
	*this = (*this) * rhs;

	return *this;
}
//Lets the user mulitply two matricies together
Mtx44& Mtx44::operator=(const Mtx44& rhs)
{
	for (int i = 0; i < HB_ROWS; ++i)
	{
		for (int j = 0; j < HB_COLS; ++j)
		{
			m[i][j] = rhs.m[i][j];
		}
	}
	return *this;
}
//Tests if two matricies are the same
bool Mtx44::operator==(const Mtx44& rhs) const
{
	if (*this != rhs)
	{
		return false;
	}
	return true;
}
//Tests if two matrices are not the same
bool Mtx44::operator!=(const Mtx44& rhs) const
{
for (int i = 0; i < HB_ROWS; ++i)
	{
		for (int j = 0; j < HB_COLS; ++j)
		{
			if (m[i][j] != rhs.m[i][j])
			{
				return true;
			}
		}
	}

return false;

}


//Non member functions
//Makes all matrix values 0
void Mtx44::MakeZero(Mtx44& result)
{
	result.MakeZero();
}
//Sets the given matrix to the Identity matrix
void Mtx44::MakeIdentity(Mtx44& result)
{
	result.MakeIdentity();
}
//Multiplies two matricies together
void Mtx44::Multiply(Mtx44& result, const Mtx44& first, const Mtx44& second)
{
	result = first * second;
}

//Sets the given matrix to a translate matrix
void Mtx44::MakeTranslate(Mtx44& result,
	float transX, float transY, float zOrder)
{
	result.MakeTranslate(transX, transY, zOrder);
}
//Sets the given matrix to a scale matrix
void Mtx44::MakeScale(Mtx44& result, float scaleX, float scaleY)
{
	result.MakeScale(scaleX, scaleY);
}
//Sets the given matrix to a Rotation around the Z axis matrix
void Mtx44::MakeRotateZ(Mtx44& result, float radians)
{
	result.MakeRotateZ(radians);
}

//Sets the given matrix to a scale rotate and translate matrix
void Mtx44::MakeTransform(Mtx44& result, float scaleX, float scaleY,
	float radians,
	float transX, float transY,
	float zOrder)
{
	result.MakeTransform(scaleX, scaleY, radians, transX, transY, zOrder);
}
//Tests if two matricies are the same
bool Mtx44::IsEqual(const Mtx44& mtx1, const Mtx44& mtx2)
{
				if (mtx1 == mtx2)
				{
								return true;
				}
				return false;
}
