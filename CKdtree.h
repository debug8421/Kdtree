/*
 * CKdtree.h
 *
 *  Created on: 2011-7-24
 *      Author: Tiandao
 */

#ifndef CKDTREE_H_
#define CKDTREE_H_
#include <assert.h>
#include <CVector.h>
template <typename T>
struct node
{
	CVector<T> *ptr_vec_data;
	node * ptr_lchild;
	node * ptr_rchild;
	node * ptr_parent;
}
template <typename T>
class CKdtree {
public:
	CKdtree();
	virtual ~CKdtree();
	virtual void build_kdtree(CVector<T> *ptr_exemplar_set, int cnt);
protected:
	node * ptr_root;

};

#endif /* CKDTREE_H_ */
