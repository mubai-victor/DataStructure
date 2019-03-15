
#include "stdafx.h"
#include "Test.h"
#include "Mytriplet.h"
Status InitTriplet(Triplet&T, Elemtype v1, Elemtype v2, Elemtype v3){
	T = static_cast<Triplet>(malloc(3 * sizeof(Elemtype)));
	if (!T)
		return ERROR;
	T[0] = v1; T[1] = v2; T[2] = v3;
	return OK;
}
Status DestruyTripet(Triplet&T){
	free(T);
	T = NULL;
	return OK;
}
Status Get(Triplet &T, int i, Elemtype &e){
	if (!T || i<1 || i>3)
		return ERROR;
	e = T[i-1];
	return OK;

}
Status Put(Triplet &T, int i, Elemtype e){
	if (!T || i<1 || i>3)
		return ERROR;
	T[i - 1] = e;
	return OK;
}
Status IsAscending(Triplet &T){
	if (!T)
		return ERROR;
	if (T[0] <= T[1] && T[1] <= T[2])
		return true;
	else
		return false;
}
Status IsDescending(Triplet &T){
	if (!T)
		return ERROR;
	if (T[0] > T[1] && T[1] > T[2])
		return true;
	else
		return false;
}
Status Max(Triplet &T, Elemtype &e){
	if (!T)
		return ERROR;
	e = T[0] > T[1] ? (T[0] > T[2] ? T[0] : T[2]) : (T[1]>T[2]?T[1]:T[2]);
	return OK;
}
Status Min(Triplet &T, Elemtype &e){
	if (!T)
		return ERROR;
	e = T[0] < T[1] ? (T[0] < T[2] ? T[0] : T[2]) : (T[1]<T[2]?T[1]:T[2]);
	return OK;

}