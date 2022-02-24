#include "mat4.h"

namespace sparky { namespace maths {

	mat4::mat4()
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;
	}

	mat4::mat4(float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	mat4& mat4::multiply(const mat4& other)
	{
		mat4 result;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; i++) 
				{
					sum += (elements[x + i*4] * other.elements[i + y*4]);
				}
				result.elements[x + y*4] = sum;
			}
		}

		return result;
	}

	mat4 operator*(mat4 left, const mat4& right){ return left.multiply(right);}

	mat4& mat4::operator *= (const mat4& other) { return multiply(other); }

}	}