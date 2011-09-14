#ifndef _CSORT_H_
#define _CSORT_H_
#include <assert.h>
#include <cstddef>
template <typename T>
class CSortBase
{
	public:
		virtual void init(T *ptr_src_data, size_t cnt);
		virtual void destroy();
		virtual void setup_timer();
		virtual time_t time_start();
		virtual time_t time_stop();
		virtual time_t time_cost();
		virtual T* get_dsc();
		virtual void sort()=0;
	protected:
		T *ptr_src_data;
		T *ptr_dsc_data;
		size_t cnt;	
		time_t start;
		time_t stop;
};
#endif
