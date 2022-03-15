#include "voucher.h"

adr_vc alokasi_vc(infotype_vc x) {
    adr_vc P = new elm_vc;
    info(P) = x;
    prev(P) = Nil;
    next(P) = Nil;
    return P;
}

void createListVc(list_vc &L) {
    First(L) = Nil;
    Last(L) = Nil;
}

void insertFirstVc(list_vc &L, adr_vc P) {
    if(First(L) != Nil && Last(L) != Nil) {
        next(P) = First(L);
        prev(First(L)) = P;
        First(L) = P;
    } else {
        First(L) = P;
        Last(L) = P;
    }
}

void deleteFirstVc(list_vc &L, adr_vc &P) {
    P = First(L);
    if(First(L) != Last(L)) {
        First(L) = next(P);
        next(P) = Nil;
        prev(First(L)) = Nil;
    } else {
        First(L) = Nil;
        Last(L) = Nil;
    }
}

void deleteLastVc(list_vc &L, adr_vc &P) {
    if (First(L) == Last(L)){
        P = First(L);
        First(L) = Nil;
        Last(L) = Nil;
    } else {
        P = Last(L);
        Last(L) = prev(Last(L));
        next(Last(L)) = Nil;
        prev(P) = Nil;
    }
}
void deleteAfterVc(list_vc &L, adr_vc &P, adr_vc Prec) {
    if (next(Prec) == Last(L)) {
        P = Last(L);
        Last(L) = Prec;
        prev(P) = Nil;
        next(Prec) = Nil;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = Nil;
        prev(P) = Nil;
    }
}
void deleteElementVc(list_vc &L, string x) {
    adr_vc temp = findVc(L, x);
    if(temp == Nil) {
        cout << "Data Hapus Tidak Ditemukan." << endl;
    } else {
        adr_vc hapus;
        if(temp == First(L)) {
            deleteFirstVc(L, hapus);
        } else if(temp == Last(L)) {
            deleteLastVc(L, hapus);
        } else {
            deleteAfterVc(L, prev(temp), hapus);
        }
    }
}

adr_vc findVc(list_vc L, string x) {
    adr_vc P = First(L);
    while(P != Nil) {
        if(info(P).nama_vc == x) {
            return P;
        }
        P = next(P);
    }
    return Nil;

}

int countVc(list_vc L) {
    adr_vc P = First(L);
    if(First(L) != Nil) {
        int i = 0;
        while(P != Nil) {

            P = next(P);
            i++;
        }
        return i;
    } else {
        return 0;
    }

}

void showVc(list_vc L) {
    adr_vc P = First(L);
    if(First(L) != Nil) {
        int i = 1;
        while(P != Nil) {
            cout << i << ")";
            cout << info(P).nama_vc << endl;
            cout << info(P).kode << endl;
            P = next(P);
            i++;
        }
    } else {
        cout << "List Kosong." << endl;
    }
}
