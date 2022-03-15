#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "voucher.h"

using namespace std;

#define First(L) L.First
#define Last(L)  L.Last
#define Nil      NULL
#define next(P)  P->next
#define prev(P)  P->prev
#define info(P)  P->info

#define next_vc(P) P->next_vc

struct infotype_user{
    string nama;
    string akun;
};

typedef struct elm_user *adr_user;

struct elm_user {
    infotype_user info;
    adr_user next;
    adr_user prev;
    adr_vc next_vc;
};

struct list_user {
    adr_user First;
    adr_user Last;
};

int count_user(list_user L);

adr_user alokasi_user(infotype_user x);
void createListUser(list_user &L);

void insertFirstUser(list_user &L, adr_user P);

void deleteFirstUser(list_user &L, adr_user &P);
void deleteLastUser(list_user &L, adr_user &P);
void deleteAfterUser(list_user &L, adr_user &P, adr_user Prec);
void deleteElementUser(list_user &L, string x);

adr_user findUser(list_user L, string x);
void showUser(list_user L);

void insertRelation(list_user &L1, list_vc L2, string nama, string nama_vc);
void deleteRelation(list_user &L1, list_vc L2, string nama, string nama_vc);


#endif // USER_H_INCLUDED
