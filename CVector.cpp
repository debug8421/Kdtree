#include "CVector.h"
template <typename T>
CVector<T>::CVector(const CVector &vec)
{
	dim = vec.dim;
	size_t len = dim*sizeof(T);
	ptr_data = (T*)malloc(len);
	memcpy(vec.data, ptr_data, len );
}

template <typename T>
CVector<T>& CVector<T>::operator=(const CVector &vec)
{
	if(this == &vec)
	  return (*this);
	if(ptr_data)
	 { 
		 free(ptr_data);
		 ptr_data = NULL;
	 }
	dim = vec.dim;
	size_t len = dim*sizeof(T);
	ptr_data = (T*)malloc(len);
	memcpy(vec.ptr_data,ptr_data,len);

	return (*this);
}
template <typename T>
CVector<T>::CVector(const int dim,const T *src)
{
	assert(dim > 0);
	size_t len = sizeof(T)*dim;
	ptr_data = (T*)malloc(len);
	if(src == NULL)
	memset(ptr_data, len, 0);
	else
	{
		 memcpy(src, ptr_data, len);
	}
}


template <typename T>
T CVector<T>::dist(const CVector &v1,const CVector &v2)
{
	return (v1-v2).norm();	 
}
template <typename T>
CVector<T> CVector<T>::operator+(const CVector &v)
{
	assert(this->dim == v.dim);
	CVector vec = CVector(dim);
   for(size_t i = 0;i <  v.dim; i ++)
   {
	 vec.ptr_data[i] = v.ptr_data[i]+ this->ptr_data[i];

   }
   return vec;
}

template <typename T>
CVector<T> CVector<T>::operator-(const CVector &v)
{
	
	assert(this->dim == v.dim);
	CVector vec = CVector(dim);
   for(size_t i = 0;i <  v.dim; i ++)
   {
	 vec.ptr_data[i] = v.ptr_data[i] - this->ptr_data[i];
   }
   return vec;
}

template <typename T>
CVector<T> CVector<T>::operator/(const T &value)
{
	assert(0 != value);
	T val = T(1)/value;
	return (*this)*val;
}

template <typename T>
CVector<T> operator*(const CVector<T> &vec, const T &value)
{

	CVector<T> result = CVector<T>(vec.dim);
   for(size_t i = 0;i <  vec.dim; i ++)
   {
	 result.ptr_data[i] = vec.ptr_data[i]*value;
   }
   return result;
}

template <typename T>
CVector<T> operator*(const T &value, const CVector<T> &vec)
{
   CVector<T> result = CVector<T>(vec.dim);
   for(size_t i = 0; i < vec.dim; i++)
   {
	result.ptr_data[i] = vec.ptr_data[i]*value;
   }
   return result;
}


