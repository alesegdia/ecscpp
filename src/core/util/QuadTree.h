#ifndef __QUADTNODE_H__
#define __QUADTNODE_H__

template <class Type>
class QuadTNode
{
public:
	QuadTNode* childs[4];
	Type* item;
}

#endif
