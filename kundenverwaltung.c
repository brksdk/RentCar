#include <stdio.h>
#include <stdlib.h>
#include "fahrzeugverwaltung.h"
#include "kundenverwaltung.h"
#include <locale.h>


int customernumbers=1000;
void customerRegister();
void customersList();
void excelforcustomers();
void deleteCustomer();
void kundenVerwaltung(){
	int selection;
	system("cls");
	show();
	printf("\t\t\t\t\t______________________\n\n");
	printf("\t\t\t\t\t1-Fahrzeug-Verwaltung\n\t\t\t\t\t2-Kundenverwaltung\n");
	printf("\t\t\t\t\t\t1-Neuen Kunden erstellen\n\t\t\t\t\t\t2-Kunden auflisten\n\t\t\t\t\t\t0-Zuruck\n\t\t\t\t\t3-Leihauftraege\n\t\t\t\t\t0-EXIT\n");
	printf("\t\t\t\t\t______________________");
	printf("\n\n\t\t\t\t\tBitte auswählen: ");
	scanf("%d",&selection);
	switch(selection){
		case 0:
			hauptMenu();
			break;
		case 1:
			customerRegister();
			break;
		case 2:
			customersList();
			break;
			default : { printf("\n\nEtwas falsch gegangen. Drucken Sie irgendwas, um zurück zu kehren"); getche(); kundenVerwaltung();} break;
	}
}
int MAXCUSTOMER(){
	int i;
	int MAXCUSTOMER=0;
	for(i=0;i<customernumbers;i++){
		if(kunden[i].durum==1||kunden[i].durum==2) // 0 boþ 1 dolu 2 silindi
		MAXCUSTOMER++;
	}
	return MAXCUSTOMER;	
}
int customerID(){  //ýd numarasý ile i deðeri ayný deðil !!!!
	int i;
	int MAXCUSTOMERS=MAXCUSTOMER();
	printf("su an %d musterim var\n",MAXCUSTOMERS);
	for(i=MAXCUSTOMERS;i<customernumbers;i++){
		return i;	
	}
	return -1;
}
void customerRegister(){
	system("cls");
	int i;
	int NEWID=customerID();
	printf("\t\t\t     ---------/*-------------------------------/*-----------\n");
	printf("\t\t\t     --------/***-----------------------------/***----------\n");
	printf("\t\t\t     -------/*****/-----Kundenverwaltung-----/*****/--------\n");
	printf("\t\t\t     ---------***/-----------------------------***/---------\n");
	printf("\t\t\t     ----------*/-------------------------------*/----------\n\n");
printf("\t\t\tKUNDEN                                                 ERSTELLEN\n");
printf("\n");
printf("\t\t\t*********    ***                                     *** *********\n");
printf("\t\t\t*********    ***  ***                           ***  *** *********\n");
printf("\t\t\t************      ***  ***                 ***  ***   ************\n");
printf("\t\t\t************           ***  ***       ***  ***        ************\n");
printf("\t\t\t************                ***  ***  ***             ************\n");
printf("\t\t\t************                     ***                  ************\n");
printf("\t\t\t------------------------------------------------------------------\n\n");
	if(NEWID!=-1){
	printf("\t\tJetz erstellen Sie %d.Kunde.\n",NEWID+1);
	printf("Vorname: ");
	scanf("%s",&kunden[NEWID].vorname);
	printf("Nachname: ");
    scanf("%s",&kunden[NEWID].nachname);
	printf("Alter: ");
	scanf("%d",&kunden[NEWID].alter);
	printf("Geburtsdatum Tag Monat Jahr\n");
	scanf("%d%d%d",&kunden[NEWID].gun,&kunden[NEWID].ay,&kunden[NEWID].yil);
	printf("Geschlecht: ");
	scanf("%s",&kunden[NEWID].geschlecht);
	printf("ID NO: ");
	scanf("%lli",&kunden[NEWID].ID);
	printf("Telefon: ");
	scanf("%s",&kunden[NEWID].telefon);
	printf("Stadt: ");
	scanf("%s",&kunden[NEWID].stadt);
	printf("Landkreis: ");
	scanf("%s",&kunden[NEWID].landkreis);
	printf("Strasse: ");
	scanf("%s",&kunden[NEWID].strasse);
	printf("Hausnummer: ");
	scanf("%d",&kunden[NEWID].hausnummer);
	printf("Turnummer: ");
	scanf("%d",&kunden[NEWID].turnummer);
    kunden[NEWID].durum=1; // 1 demek dolu demek
	kunden[NEWID].id=NEWID;
	system("color A1"); //MAVÝ EKRAN
    printf("\t\tDie Kundeinfos wurde erfolgreich hinzugefugt.\n");
    printf("\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
    }
    else{
    	system("color C0"); // KIRMIZI EKRAN
    	printf("\t\tEs gibt kein Platz mehr. Sie konnen die Gesamtanzahl der Kunden steigern,damit die mehr Kunden erstellt werden konnen.\n");
	}
	getche();
	system("color F0"); // ANA EKRAN
	hauptMenu();	
}
void saveCustomersFile(){
	FILE*MYFILE=fopen("customerinfos.dat","wb");
	fwrite(kunden,sizeof(KUNDE),1000,MYFILE);
	fclose(MYFILE);
}
void readCustomersFile(){
	FILE*MYFILE=fopen("customerinfos.dat","rb");
	fread(kunden,sizeof(KUNDE),1000,MYFILE);
	fclose(MYFILE);
}
void customersList(){
	system("cls");
	int i,selection,MAXCUSTOMERS=MAXCUSTOMER();
	printf("kayitli musteri sayim: %d\n\n\n\n",MAXCUSTOMERS);
	    	if(MAXCUSTOMERS!=0){
			printf("+----+-----------------+------------------+------------+--------------+-------+------------------------+---------------+----------------------------------------------------+\n");
			printf("| ID |     Vorname     |     Nachname     | Geschlecht |GeburtsDatum  | Alter |  Identifikation Nummer | TelefonNummer |                        Adresse                     |\n");
			printf("+----+-----------------+------------------+------------+--------------+-------+------------------------+---------------+----------------------------------------------------+\n");
				for(i=0;i<MAXCUSTOMERS+1;i++){
					if(kunden[i].durum==1){
					printf("|%-4d|",kunden[i].id+1);
					printf("%-17s|",kunden[i].vorname);
        			printf("%-18s|",kunden[i].nachname);
        			printf("%-12s|",kunden[i].geschlecht);
        			printf("%2d.%2d.%-8d|",kunden[i].gun,kunden[i].ay,kunden[i].yil);
        			printf("%-7d|",kunden[i].alter);
        			printf("%-24lld|",kunden[i].ID);
        			printf("%-15s|",kunden[i].telefon);
        			printf("%s-%s %s STR Hausnr.:%d Turnr.:%d\n",kunden[i].stadt,kunden[i].landkreis,kunden[i].strasse,kunden[i].hausnummer,kunden[i].turnummer);
      				printf("+----+-----------------+------------------+------------+--------------+-------+------------------------+---------------+----------------------------------------------------+\n");
        			}
				}
    		}
    		else{
    		system("cls");
    		system("color C0"); // KIRMIZI EKRAN
    		printf("\tEs gibt keine Kunde. Sie konnen entweder aus der CSV-Datei Kunden importieren oder einen neuen Kunden erstellen.\n\n");
    		printf("\t1-Neuen Kunden erstellen\n\t2-Daten-Import aus CSV Datei\n\t0-Zuruck\n");
    		scanf("%d",&selection);
    			switch(selection){
    				case 0:
    					system("color F0"); // ANA EKRAN
    					hauptMenu();
    				break;
    				case 1:
    					system("color F0"); // ANA EKRAN
    					customerRegister();
    				break;
    				case 2:
    					excelforcustomers();
    					system("color F0"); // ANA EKRAN
    				break;
				}
			}
	printf("\t1-Kunden Loschen\n\t0-Hauptmenu\n");
	scanf("%d",&selection);
	if(selection==1)
	deleteCustomer();
	else
	hauptMenu();
	printf("\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
	getche();
	system("color F0"); // ANA EKRAN
	hauptMenu();
}
void deleteCustomer(){
	int selection;
	printf("Welcher Kunde wollen Sie loschen?\n");
	scanf("%d",&selection);
	kunden[selection-1].durum=2;  // 0 boþ 1 dolu 2 silindi
	system("cls");
	system("color A1"); //MAVÝ EKRAN
	printf("\t\tDer Kunde wurde erfolgreich geloscht.\n");	
}
void excelforcustomers(){
	char line[200];
    FILE*CSVfile=fopen("carcustomers.csv","r");
    FILE*myFile=fopen("customerinfos.dat","a+b");
    int car_index=0;   
	int i=0;                                                  
        while(fgets(line,sizeof(line),CSVfile)){
        	//printf("while ýn icinde\n");
        	if(strcmp(line,"          ")){
        	//printf("ilk if in icinde\n");
			car_index++;
			KUNDE kunden_excel;
		        if(car_index!=1){
		          i++;
		          //printf("ikinci if in icinde\n");
				  char *token;
			      token=strtok(line,";");
				  strcpy(kunden_excel.vorname,token);
				  //printf("vorname bilgisi alindi\n");
			      token=strtok(NULL,";");
				  strcpy(kunden_excel.nachname,token);
				  //printf("nachname bilgisi alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.alter=atoi(token);
				  //printf("alter bilgisi alindi\n");
				  token=strtok(NULL,";");
				  strcpy(kunden_excel.geschlecht,token);
				  //printf("geschlecht bilgisi alindi\n");
				  token=strtok(NULL,";");
				  strcpy(kunden_excel.telefon,token);
				  //printf(" telefon bilgisi alindi\n");
				  token=strtok(NULL,";");
				  strcpy(kunden_excel.email,token);
				  //printf("mailbilgisi alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.durum=atoi(token);
				  //printf("durum bilgisi alindi\n");
				  
				  token=strtok(NULL,";");
				  kunden_excel.id=atoi(token);
				  //printf("id bilgisi alindi\n");
				   
				  token=strtok(NULL,";");
				  strcpy(kunden_excel.stadt,token);
				  //printf("stadt alindi\n");
				  token=strtok(NULL,";");
				  strcpy(kunden_excel.landkreis,token);
				  //printf("landkreis alindi\n");
				  token=strtok(NULL,";");
				  strcpy(kunden_excel.strasse,token);
				  //printf("strasse alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.hausnummer=atoi(token);
				  //printf("hausnummer alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.turnummer=atoi(token);
				  //printf("turnummer alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.gun=atoi(token);
				  //printf("gun alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.ay=atoi(token);
				  //printf("ay alindi\n");
				  token=strtok(NULL,";");
				  kunden_excel.yil=atoi(token);
				  //printf("yil alindi\n");
				  
				  token=strtok(NULL,";");
				  kunden_excel.ID=atoll(token);
				  //printf("ID bilgisi alindi\n");
				  
				  fwrite(&kunden_excel,sizeof(KUNDE),1,myFile);
				  //printf("fwrite dan cikti\n");
							//printf("%d.vorname :%s\n",i+1,kunden_excel.vorname);
								strcpy(kunden[i-1].vorname,kunden_excel.vorname);
							//	printf("%s\n",kunden[i-1].vorname);
						//printf("%d.nachname :%s\n",i+1,kunden_excel.nachname);
								strcpy(kunden[i-1].nachname,kunden_excel.nachname);
						//		printf("%s\n",kunden[i-1].nachname);
						//	printf("%d.alter :%d\n",i+1,kunden_excel.alter);
								kunden[i-1].alter=kunden_excel.alter;
						//		printf("%d\n",kunden[i-1].alter);
						//	printf("%d.gechlecht :%s\n",i+1,kunden_excel.geschlecht);
								strcpy(kunden[i-1].geschlecht,kunden_excel.geschlecht);
						//		printf("%s\n",kunden[i-1].geschlecht);		
						//	printf("%d.tel :%s\n",i+1,kunden_excel.telefon);
								strcpy(kunden[i-1].telefon,kunden_excel.telefon);
						//		printf("%s\n",kunden[i-1].telefon);	
					    //	printf("%d.mail :%s\n",i+1,kunden_excel.email);
								strcpy(kunden[i-1].email,kunden_excel.email);
						//		printf("%s\n",kunden[i-1].email);
						//	printf("%d.durum :%d\n",i+1,kunden_excel.durum);
								kunden[i-1].durum=kunden_excel.durum;
						//		printf("%d\n",kunden[i-1].durum);		
						//	printf("%d.id :%d\n",i+1,kunden_excel.id);
								kunden[i-1].id=kunden_excel.id;
						//		printf("%d\n",kunden[i-1].id);
								
					//	printf("%d.stadt :%s\n",i+1,kunden_excel.stadt);				
						strcpy(kunden[i-1].stadt,kunden_excel.stadt);
					//	printf("%s\n",kunden[i-1].stadt);
						
					//	printf("%d.landkreis :%s\n",i+1,kunden_excel.landkreis);
						strcpy(kunden[i-1].landkreis,kunden_excel.landkreis);
					//	printf("%s\n",kunden[i-1].landkreis);
						
					//	printf("%d.strasse :%s\n",i+1,kunden_excel.strasse);
						strcpy(kunden[i-1].strasse,kunden_excel.strasse);
					//	printf("%s\n",kunden[i-1].strasse);
						
					//	printf("%d.hausnummer :%d\n",i+1,kunden_excel.hausnummer);
						kunden[i-1].hausnummer=kunden_excel.hausnummer;
					//	printf("%d\n",kunden[i-1].hausnummer);
						
					//	printf("%d.turnummer :%d\n",i+1,kunden_excel.turnummer);
						kunden[i-1].turnummer=kunden_excel.turnummer;				
					//	printf("%d\n",kunden[i-1].turnummer);
						
					//	printf("%d.gun :%d\n",i+1,kunden_excel.gun);
						kunden[i-1].gun=kunden_excel.gun;
					//	printf("%d\n",kunden[i-1].gun);
						
					//	printf("%d.ay :%d\n",i+1,kunden_excel.ay);
						kunden[i-1].ay=kunden_excel.ay;
					//	printf("%d\n",kunden[i-1].ay);
						
					//	printf("%d.yil :%d\n",i+1,kunden_excel.yil);
						kunden[i-1].yil=kunden_excel.yil;
					//	printf("%d\n",kunden[i-1].yil);
						
					//	printf("%d.ID :%lld\n",i+1,kunden_excel.ID);	
						kunden[i-1].ID=kunden_excel.ID;
					//	printf("%lld\n",kunden[i-1].ID); 
						 
						
			    }
		
			}		
		}
	fclose(myFile);
	fclose(CSVfile);
    system("cls");
	system("color A1");
	printf("\n\n\n\t\t\tDie Daten wurden erfolgreich importiert.\n");
}



