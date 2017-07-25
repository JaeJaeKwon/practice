#pragma once

class Vector3
{
public:
				float x, y, z;

				Vector3(void);
				Vector3(float x_, float y_, float z_);

				void Set(float x_, float y_, float z_);
				void Set(const Vector3& rhs);
				void SetZero(void);

				bool IsZero(void) const;
				bool IsOne(void) const;

				float Dot(const Vector3& rhs) const;
				Vector3 Cross(const Vector3& rhs) const;

				float Length(void)const;
				float LengthSq(void)const;

				float Distance(const Vector3& rhs)const;
				float DistanceSq(const Vector3& rhs)const;

				Vector3& Normalize(void);
				Vector3 GetNormalize(void)const;

				Vector3 operator+(const Vector3& rhs) const;
				Vector3& operator+=(const Vector3& rhs);
				Vector3 operator-(const Vector3& rhs) const;
				Vector3& operator-=(const Vector3& rhs);

/*				Vector3 operator*(const Vector3& rhs) const;
				Vector3& operator*=(const Vector3& rhs);*/
				Vector3 operator*(float rhs) const;
				Vector3& operator*=(float rhs);
				Vector3 operator/(float rhs) const;
				Vector3& operator/=(float rhs);

				Vector3 operator-(void) const;

				bool operator==(const Vector3& v) const;
				bool operator!=(const Vector3& v) const;



private:

};
