#include "user.h"

adr_user alokasi_user(infotype_user x) {
    adr_user P = new elm_user;
    info(P) = x;
    prev(P) = Nil;
    next(P) = Nil;
    next_vc(P) = Nil;
    return P;
}

void createListUser(list_user &L){
    First(L) = Nil;
    Last(L) = Nil;
}

void insertFirstUser(list_user &L, adr_user P) {
    if(First(L) != Nil && Last(L) != Nil) {
        next(P) = First(L);
        prev(First(L)) = P;
        First(L) = P;
    } else {
        First(L) = P;
        Last(L) = P;
    }
}

void deleteFirstUser(list_user &L, adr_user &P) {
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

void deleteLastUser(list_user &L, adr_user &P) {
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
void deleteAfterUser(list_user &L, adr_user &P, adr_user Prec) {
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
void deleteElementUser(list_user &L, string x) {
    adr_user temp = findUser(L, x);
    if(temp == Nil) {
        cout << "Data Hapus Tidak Ditemukan." << endl;
    } else {
        adr_user hapus;
        if(temp == First(L)) {
            deleteFirstUser(L, hapus);
        } else if(temp == Last(L)) {
            deleteLastUser(L, hapus);
        } else {
            deleteAfterUser(L, prev(temp), hapus);
        }
    }
}

adr_user findUser(list_user L, string x) {
    adr_user P = First(L);
    while(P != Nil) {
        if(info(P).nama == x) {
            return P;
        }
        P = next(P);
    }
    return Nil;
}

void showUser(list_user L) {
    adr_user P = First(L);
    if(First(L) != Nil) {
            int i = 1;
        while(P != Nil) {
            cout << i << ")";
            cout << "Nama Pengguna: " << info(P).nama << endl;
            cout << "Username: " << info(P).akun << endl;
            if(next_vc(P) == Nil) {
                cout << "Tidak ada Voucher." << endl << endl;
            } else {
                cout << "User Memiliki Voucher: " << endl;
                cout << "Nama Voucher: " << info(next_vc(P)).nama_vc << endl;
                cout << "Kode Unik: " << info(next_vc(P)).kode << endl << endl;
            }
            P = next(P);
            i++;
        }
    } else {
        cout << "List Kosong." << endl;
    }
}

int count_user(list_user L) {
    adr_user P = First(L);
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

void insertRelation(list_user &L1, list_vc L2, string nama, string nama_vc){
    adr_user P;
    adr_vc Q;

    P = findUser(L1, nama);
    Q = findVc(L2, nama_vc);
    if(P != Nil && Q != Nil) {
        next_vc(P) = Q;
    }
}

void deleteRelation(list_user &L1, list_vc L2, string nama, string nama_vc) {
    adr_user P;
    adr_vc Q;

    Q = findVc(L2, nama_vc);
    if(Q != Nil) {
        P = First(L1);
        while(P != Nil) {
            if(next_vc(P) == Q) {
                next_vc(P) = Nil;
            }
            P =next(P);
        }
    }
}
