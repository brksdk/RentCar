#include <stdio.h>
#include <stdlib.h>
#include "fahrzeugverwaltung.h"
#include "kundenverwaltung.h"
#include <locale.h>

void leihauftraege();
void rentVehicle();
void rentedCarList();
void existingVehicleList();

void leihauftraege(){
	setlocale(LC_ALL, "German");
	system("cls");
	int selection;
	show();
	printf("\t\t\t\t\t______________________\n\n");
	printf("\t\t\t\t\t1-Fahrzeug-Verwaltung\n\t\t\t\t\t2-Kundenverwaltung\n\t\t\t\t\t3-Leihauftraege\n");
	printf("\t\t\t\t\t\t1-Gemietete Fahrzeuge auflisten\n\t\t\t\t\t\t2-Vorhandene Fahrzeuge auflisten\n\t\t\t\t\t\t3-Fahrzeug ausleihen\n\t\t\t\t\t\t0-Zuruck\n\t\t\t\t\t0-EXIT\n");
	printf("\t\t\t\t\t______________________");
	printf("\n\n\t\t\t\t\tBitte auswählen: ");
	scanf("%d",&selection);
	switch(selection){
		case 0:
			hauptMenu();
			break;
		case 1:
			rentedCarList();
			break;
		case 2:
			existingVehicleList();
			break;
		case 3:
			rentVehicle();
			break;
	default : { printf("\n\nEtwas falsch gegangen. Drucken Sie irgendwas, um zurück zu kehren"); getche(); hauptMenu();} break;
	}	
}

void rentVehicle(){
	system("cls");
	int i,a,b,MAXCAR=MAXAUTO();
	int MAXCUSTOMERS=MAXCUSTOMER();
	if(MAXCAR!=0){
		printf("+----+---------------+---------------+------------+\n");
		printf("| ID |     Marke     |     Model     | Tagespreis |\n");
		printf("+----+---------------+---------------+------------+\n");
			for(i=0;i<MAXCAR+1;i++){
				if(fahrzeug[i].durum==1){
					printf("|%-4d|",fahrzeug[i].id+1);
					printf("%-15s|",fahrzeug[i].marka);
        			printf("%-15s|",fahrzeug[i].model);
        			printf("%7d Euro|\n",fahrzeug[i].fiyat);
      				printf("+----+---------------+---------------+------------+\n");
        		}
			}
    }
	printf("\nWelches Fahrzeug wollen Sie ausleihen?\n");
	scanf("%d",&a);
	fahrzeug[a-1].durum=3; // 3 kiralanmýþ demek
	printf("%d\n",MAXCUSTOMERS);
	if(MAXCUSTOMERS!=0){
		printf("+----+-----------------+------------------+------------+-------------+-------+------------------------+---------------+----------------------------------------+\n");
		printf("| ID |     Vorname     |     Nachname     | Geschlecht |GeburtsDatum | Alter |  Identifikation Nummer | TelefonNummer |                  Adresse               |\n");
		printf("+----+-----------------+------------------+------------+-------------+-------+------------------------+---------------+----------------------------------------+\n");
			for(i=0;i<MAXCUSTOMERS+1;i++){
				if(kunden[i].durum==1){
					printf("|%-4d|",kunden[i].id+1);
					printf("%-17s|",kunden[i].vorname);
        			printf("%-18s|",kunden[i].nachname);
        			printf("%-12s|",kunden[i].geschlecht);
        			printf("%d.%d.%-8d|",kunden[i].gun,kunden[i].ay,kunden[i].yil);
        			printf("%7d|",kunden[i].alter);
        			printf("%-24lld|",kunden[i].ID);
        			printf("%-15s|",kunden[i].telefon);
        			printf("%s-%s %s No:%d.%d|\n",kunden[i].stadt,kunden[i].landkreis,kunden[i].strasse,kunden[i].hausnummer,kunden[i].turnummer);
      				printf("+----+-----------------+------------------+------------+------------+-------+------------------------+---------------+----------------------------------------+\n");
        		}
			}
    }
	printf("\nWelcher Kunde leiht es aus?\n");
	scanf("%d",&b);
	system("color A1"); //MAVÝ EKRAN
	printf("\tDas Fahrzeug,dessen ID Nummer %d ist, wurde erfolgreich fur Herr/Frau %s %s ausgeliehen\n",a,kunden[b-1].vorname,kunden[b-1].nachname);
	printf("\t\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
	getche();
	system("color F0");  //ANA EKRAN
	hauptMenu();	
}
void rentedCarList(){
	system("cls");
	int i;
	system("color F9");
	printf("\t\t\tGemiete Fahrzeuge\n");
	system("color F0");
	printf("+----+---------------+---------------+------------+\n");
	printf("| ID |     Marke     |     Model     | Tagespreis |\n");
	printf("+----+---------------+---------------+------------+\n");
		for(i=0;i<100;i++){
			if(fahrzeug[i].durum==3){
				printf("|%-4d|",fahrzeug[i].id+1);
				printf("%-15s|",fahrzeug[i].marka);
       			printf("%-15s|",fahrzeug[i].model);
        		printf("%-12d|\n",fahrzeug[i].fiyat);
        		printf("+----+---------------+---------------+------------+\n");
			}
		}
	printf("\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
	getche();
	hauptMenu();	
}

void existingVehicleList(){
	system("cls");
	printf("\t\t\tVorhandene Fahrzeuge\n\n");
	int i,MAXCAR=MAXAUTO();
	if(MAXCAR!=0){
		printf("+----+---------------+---------------+------------+\n");
		printf("| ID |     Marke     |     Model     | Tagespreis |\n");
		printf("+----+---------------+---------------+------------+\n");
			for(i=0;i<MAXCAR+1;i++){
				if(fahrzeug[i].durum==1){
					printf("|%-4d|",fahrzeug[i].id+1);
					printf("%-15s|",fahrzeug[i].marka);
        			printf("%-15s|",fahrzeug[i].model);
        			printf("%-12d|\n",fahrzeug[i].fiyat);
      				printf("+----+---------------+---------------+------------+\n");
        		}
			}
	}
	else{
    	system("color C0"); // KIRMIZI EKRAN
    	printf("\t\tEs gibt kein Fahrzeug. Die Fahrzeugen existieren,damit Sie sie auflisten konnen.\n");
	}
	printf("\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
	getche();
	system("color F0"); // ANA EKRAN
	hauptMenu();	
}
