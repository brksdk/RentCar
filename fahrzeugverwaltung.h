#ifndef fahrzeugverwaltung
#define fahrzeugverwaltung

typedef struct {
    char marka[20],model[20];
    int fiyat;
    int durum;
    int id;
}FAHRZEUG;

FAHRZEUG fahrzeug[100];  // 0 yok 1 dolu 2 silinmi� 3 kiralanm��

void fahrzeugVerwaltung();

#endif // FAHRZEUGVERWALTUNG_H_INCLUDED
