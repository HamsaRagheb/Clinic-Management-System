#ifndef STRUCTS_H_
#define STRUCTS_H_
#include "STD_TYPES.h"
#define Max_Size 20
#define Size 10

typedef struct Patient
{
	u8 name[Max_Size];
	u8 age;
	u8 gender[Size];
	u16 id;
	struct Patient *next;

} patient_node;

typedef struct Reservation
{
	u8 time[Max_Size];
	u16 id;
	struct Reservation *next;
} reservation;

#endif