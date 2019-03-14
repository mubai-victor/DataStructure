#ifndef MYTRIPLET_H
#define MYTRIPLET_H

#include "Test.h"
Status InitTriplet(Triplet&T, Elemtype v1, Elemtype v2, Elemtype v3);
Status DestruyTripet(Triplet&T);
Status Get(Triplet &T, int i, Elemtype &e);
Status Put(Triplet &T,int i,Elemtype e);
Status IsAscending(Triplet &T);
Status IsDescending(Triplet &T);
Status Max(Triplet &T,Elemtype &e);
Status Min(Triplet &T,Elemtype &e);

#endif