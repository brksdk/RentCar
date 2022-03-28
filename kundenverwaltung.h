#ifndef kundenverwaltung
#define kundenverwaltung

typedef struct{
char vorname[20];
char nachname[20];
char geschlecht[10];
char email[30];
char telefon[15];
long long ID;
int alter;
int durum;
int id;
char fahrzeug[30];
int gun,ay,yil;
char stadt[10],strasse[15],landkreis[15];
int turnummer,hausnummer;
} KUNDE;

KUNDE kunden[1000];

void kundenVerwaltung();

#endif // KUNDENVERWALTUNG_H_INCLUDED
