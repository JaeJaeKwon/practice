#include "vector3.hpp"
#include "DebugUtil.hpp"
#include <cmath>

Vector3::Vector3(void) : x(0), y(0),z(0)
{
}

Vector3::Vector3(float x_, float y_, float z_) : x(x_), y(y_),z(z_)
{
}

void Vector3::Set(float x_, float y_, float z_)
{
				x = x_;
				y = y_;
				z = z_;
}

void Vector3::Set(const Vector3 & rhs)
{
				Set(rhs.x, rhs.y, rhs.z);
}

void Vector3::SetZero(void)
{
				Set(0, 0, 0);
}

bool Vector3::IsZero(void) const
{
				return (x == 0) && (y==0) && (z==0);
}

bool Vector3::IsOne(void) const
{
				return (x == 1) && (y==1) && (z==1);
}

float Vector3::Dot(const Vector3 & rhs) const
{
				return x*rhs.x + y*rhs.y + z*rhs.z;
}

Vector3 Vector3::Cross(const Vector3 & rhs) const
{
				Vector3 result;
				result.x = y*rhs.z - z*rhs.y;
				result.y = z*rhs.x - x*rhs.z;
				result.z = x*rhs.y - y*rhs.x;

				return result;
}

float Vector3::Length(void) const
{
				return std::sqrtf(LengthSq());
}

float Vector3::LengthSq(void) const
{
				return x*x + y*y + z*z;
}

float Vector3::Distance(const Vector3 & rhs) const
{
				return Vector3(*this - rhs).Length();
}

float Vector3::DistanceSq(const Vector3 & rhs) const
{
				return Vector3(*this - rhs).LengthSq();
}

Vector3 & Vector3::Normalize(void)
{
				float length = this->Length();
				*this /= length;

				return *this;
}

Vector3 Vector3::GetNormalize(void) const
{
					float length = this->Length();
				return  Vector3(*this / length);
}

Vector3 Vector3::operator+(const Vector3 & rhs) const
{
				return Vector3(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vector3 & Vector3::operator+=(const Vector3 & rhs)
{
				// TODO: insert return statement here
				x += rhs.x;
				y += rhs.y;
				z += rhs.z;

				return *this;
}

Vector3 Vector3::operator-(const Vector3 & rhs) const
{
				return Vector3(x-rhs.x, y-rhs.y, z-rhs.z);
}

Vector3 & Vector3::operator-=(const Vector3 & rhs)
{
				x -= rhs.x;
				y -= rhs.y;
				z -= rhs.z;

				return *this;

				// TODO: insert return statement here
}

Vector3 Vector3::operator*(float rhs) const
{
				return Vector3(x*rhs, y*rhs, z*rhs);
}

Vector3 & Vector3::operator*=(float rhs)
{
				x *= rhs;
				y *= rhs;
				z *= rhs;

				return *this;
}

Vector3 Vector3::operator/(float rhs) const
{
				DEBUG_ASSERT(rhs == 0, "Divided by 0");
				return Vector3(x/rhs, y/rhs, z/rhs);
}

Vector3 & Vector3::operator/=(float rhs)
{
				DEBUG_ASSERT(rhs == 0, "Divided by 0");
				x /= rhs;
				y /= rhs;
				z /= rhs;

				return *this;
}

Vector3 Vector3::operator-(void) const
{
				return Vector3(-x,-y,-z);
}

bool Vector3::operator==(const Vector3 & rhs) const
{
				return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}

bool Vector3::operator!=(const Vector3 & rhs) const
{
				return !(*this == rhs);
}
