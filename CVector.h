#ifndef _CVECTOR_H_
#define _CVECTOR_H_
#include <math.h>
#include <assert.h>
#include <cstddef>
#include <stdlib.h>
template <typename T>
class CVector
{
   protected:
	size_t dim;
	T *ptr_data;
    public:
	CVector(const CVector & vec);
	CVector(const int dim, const T *src = NULL);

	CVector(const T &x, const T &y, const T &z)
	{
		dim = 3;
		ptr_data = (T*)malloc(sizeof(T)*dim);
		ptr_data[0] = x;
		ptr_data[1] = y;
		ptr_data[2] = z;
	}
	CVector(const T &x,const T &y)
	{
		dim = 2;
		ptr_data[0] = x;
		ptr_data[1] = y;
	}
	CVector(const T &x)
	{
		dim = 1;
		ptr_data[0] = x;
	}
	CVector()
	{
		dim = 0;
		ptr_data = NULL;
	}
	virtual ~CVector()
	{
		free(ptr_data);
		ptr_data = NULL;
		dim = 0;
	}

	CVector &operator=(const CVector &vec);
	T norm()
	{
	
	  T value = 0;
	  for(int i = 0; i < dim; i ++)
	  {
	  	value += ptr_data[i]^2;
	  }
	  return sqrt(value);
	}
	CVector operator-(const CVector &v);
	CVector operator+(const CVector &v);
	CVector operator/(const T &value);
    friend	CVector operator*(const CVector &vec, const T &value);
    T &get(const size_t index)
	{
		assert(index >0 && index < dim);
		return ptr_data[index]; 
	}

	T set(const size_t index,const  T &newvalue)
	{
		assert(index > 0 && index < dim);
		T old = ptr_data[index];
		ptr_data[index] = newvalue;
		return old;
		
	}
	T dist(const CVector &v1,const  CVector &v2);

};
#endif
