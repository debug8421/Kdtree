#include "CSortBase.h"
template <typename T>
void CSortBase::init(T *ptr_src_data, size_t cnt)
{
	assert(ptr_src_data != NULL);
	assert(cnt > 0);
	if(this->ptr_src_data != NULL)
	{
		free(this->ptr_src_data);
		this->ptr_src_data = NULL;
		this->cnt = 0;
	}
	size_t len = sizeof(T)*cnt;
	this->ptr_src_data = (T*)malloc(len);
	memcpy(ptr_src_data, this->ptr_src_data, len);
	this->cnt = cnt;
}
