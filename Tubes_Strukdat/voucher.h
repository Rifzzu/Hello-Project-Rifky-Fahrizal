#ifndef VOUCHER_H_INCLUDED
#define VOUCHER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

#define First(L) L.First
#define Last(L)  L.Last
#define Nil      NULL
#define next(P)  P->next
#define prev(P)  P->prev
#define info(P)  P->info

#define next_vc(P) P->next_vc

struct infotype_vc{
    string nama_vc;
    string kode;
};
typedef struct elm_vc *adr_vc;

struct elm_vc {
    infotype_vc info;
    adr_vc next;
    adr_vc prev;
};

struct list_vc {
    adr_vc First;
    adr_vc Last;
};

int countVc(list_vc L);

adr_vc alokasi_vc(infotype_vc x);
void createListVc(list_vc &L);

void insertFirstVc(list_vc &L, adr_vc P);

void deleteFirstVc(list_vc &L, adr_vc &P);
void deleteLastVc(list_vc &L, adr_vc &P);
void deleteAfterVc(list_vc &L, adr_vc &P, adr_vc Prec);
void deleteElementVc(list_vc &L, string x);

adr_vc findVc(list_vc L, string x);
void showVc(list_vc L);


#endif // VOUCHER_H_INCLUDED
