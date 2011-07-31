#ifndef _CVECTOR_H_
#define _CVECTOR_H_
#include <math.h>
template <typename T>
class CVector<T>
{
   protected:
	int dim;
	T *data;
    public:
	CVector(int dim, T *src = NULL)
	{
		assert(dim > 0);
		int size = sizeof(T)*dim;
		data = (T*)malloc(size);
		if(src == NULL)
		memset(data, size, 0);
		else
		{
		    memcpy(src, data, size);
		}
	}

	CVector(T &x, T &y, T &z)
	{
		dim = 3;
		data = (T*)malloc(sizeof(T)*dim);
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}
	CVector(T &x, T &y)
	{
		dim = 2;
		data[0] = x;
		data[1] = y;
	}
	CVector(T &x)
	{
		dim = 1;
		data[0] = x;
	}
	CVector()
	{
		dim = 0;
		data = NULLL;
	}
	virtual ~CVecotr()
	{
		delete data[];
		data = NULL;
		dim = 0;
	}
	T norm()
	{
	
	  T value = 0;
	  for(unsight int i = 0; i < dim; i ++)
	  {
	  	value += data[i]^2;
	  }
	  return sqrt(value);
	}
	T dist(CVector v1, CVector v2);

}
#endif
