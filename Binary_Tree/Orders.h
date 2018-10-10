/* This code implements a Node for Binary Tree */

#ifndef ORDERS_H_INCLUDED
#define ORDERS_H_INCLUDED

struct InorderSwitch
{
	int pause, left, right, up;
	InorderSwitch() { pause = 1, left = 0, right = 2, up = 3; }
};

struct PreorderSwitch {
	int pause, left, right, up;
	PreorderSwitch() { pause = 0, left = 1, right = 2, up = 3; }
};

struct PostorderSwitch {
	int pause, left, right, up;
	PostorderSwitch() { pause = 2, left = 0, right = 1, up = 3; }
};

#endif // BTNODE_H_INCLUDED