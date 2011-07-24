/*
 * CKdtree.h
 *
 *  Created on: 2011-7-24
 *      Author: Tiandao
 */

#ifndef CKDTREE_H_
#define CKDTREE_H_
#include <assert.h>
template <typename T>
class CKdtree {
public:
	CKdtree();
	virtual ~CKdtree();
	virtual void build_kdtree(T **ptr_data, int cnt, int dim, int depth);
};

#endif /* CKDTREE_H_ */
