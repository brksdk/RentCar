#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fahrzeugverwaltung.h"
#include "kundenverwaltung.h"


int carnumbers=100;
void vehicleRegister();
void vehicleList();
void deleteVehicle();
int MAXAUTO();
int carID();
int hauptMenu();
void readCarsFile();
void saveCarsFile();
void carexcel();
void show3();
void show2();

void fahrzeugVerwaltung(){
    int selection;
    system("cls");
    show();
    	printf("\t\t\t\t\t______________________\n\n");
    printf("\t\t\t\t\t1-Fahrzeug-Verwaltung\n");
	printf("\t\t\t\t\t\t1-Fahrzeug eintragen\n\t\t\t\t\t\t2-Fahrzeugliste auflisten\n\t\t\t\t\t\t3-Fahrzeug loschen\n\t\t\t\t\t\t0-Zuruck\n\t\t\t\t\t2-Kundenverwaltung\n\t\t\t\t\t3-Leihauftraege\n\t\t\t\t\t0-EXIT\n");
	printf("\t\t\t\t\t______________________");
	printf("\n\n\t\t\t\t\tBitte auswählen: ");
	scanf("%d",&selection);
	switch(selection){
		case 0:
			
			hauptMenu();
			break;
		case 1:
			vehicleRegister();
			break;
		case 2:
			vehicleList();
			break;
		case 3:
			deleteVehicle();
			break;
			default : { printf("\n\nEtwas falsch gegangen. Drucken Sie irgendwas, um zurück zu kehren"); getche(); fahrzeugVerwaltung();} break;
   }
}
int MAXAUTO(){
	int i;
	int MAXCAR=0;
	for(i=0;i<carnumbers;i++){
		if(fahrzeug[i].durum==1||fahrzeug[i].durum==2 || fahrzeug[i].durum==3) 
		MAXCAR++;
	}
	return MAXCAR;	
}
int carID(){
	int i;
	int GESAMTAUTOZAHL=MAXAUTO(); // SÝLÝNMÝÞ ARABALAR DAHÝL
	for(i=GESAMTAUTOZAHL;i<carnumbers;i++){
		return i;	
	}
	return -1;
}
void vehicleRegister(){
	system("cls");
	int NEWID=carID();
	//printf("yeni aracimin indexi : %d\n",ID);
	printf("\t\t\t---------/*-------------------------------/*-----------\n");
	printf("\t\t\t--------/***-----------------------------/***----------\n");
	printf("\t\t\t-------/*****/----Fahrzeugverwaltung----/*****/--------\n");
	printf("\t\t\t---------***/-----------------------------***/---------\n");
	printf("\t\t\t----------*/-------------------------------*/----------\n\n");
			printf("\t\t\t          *                                *       \n");
		printf("\t\t\t         ***                              ***       \n");
		printf("\t\t\t    *************                    *************  \n");
		printf("\t\t\t     ***********                      ***********   \n");
		printf("\t\t\t      *********     AUTO EINTRAGEN     *********    \n");
		printf("\t\t\t     ***********                      ***********   \n");
		printf("\t\t\t    *************                    *************  \n");
		printf("\t\t\t         ***                              ***       \n");
		printf("\t\t\t          *                                * \n ");
		printf("\t\t\t---------------------------------------------------------\n\n");
	if(NEWID!=-1){
	printf("\t\tJetz tragen Sie Ihr %d.Fahrzeug ein.\n",NEWID+1);
	printf("Marke: ");
	scanf("%s",&fahrzeug[NEWID].marka);
	printf("Model: ");
    scanf("%s",&fahrzeug[NEWID].model);
	printf("Tagespreis: ");
	scanf("%d",&fahrzeug[NEWID].fiyat);
	fahrzeug[NEWID].durum=1; // 1 demek dolu demek	
	fahrzeug[NEWID].id=NEWID;
	system("color A1"); //MAVÝ EKRAN
    printf("\t\tDas Fahrzeug wurde erfolgreich eingetragen.\n");
    printf("\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
    }
    /*printf("%d.incinin markasi: %s\n",ID,fahrzeug[ID].marka);
    printf("%d incinin modeli :%s\n",ID,fahrzeug[ID].model);
    printf("%d incinin fiyati :%d\n",ID,fahrzeug[ID].fiyat);*/
    else{
    	system("color C0"); // KIRMIZI EKRAN
    	printf("\t\tEs gibt kein Platz mehr. Sie konnen die Gesamtanzahl der Fahrzeugen steigern,damit die mehr Fahrzeuge eingetragen werden konnen.\n");
	}
	getche();
	system("color F0"); // ANA EKRAN
	hauptMenu();	
}
void saveCarsFile(){
	FILE*MYFILE=fopen("carinfos.dat","wb");
	fwrite(fahrzeug,sizeof(FAHRZEUG),100,MYFILE);	// araç sayým max 100 olduðu için 100 yazdým
	fclose(MYFILE);
}
void readCarsFile(){
	FILE*MYFILE=fopen("carinfos.dat","rb");
	fread(fahrzeug,sizeof(FAHRZEUG),100,MYFILE);  // araç sayým max 100 olduðu için 100 yazdým
	fclose(MYFILE);
}
void vehicleList(){
	show3();
	system("cls");
	int i,MAXCAR=MAXAUTO();
	printf("\t\t\t---------/*-------------------------------/*-----------\n");
	printf("\t\t\t--------/***-----------------------------/***----------\n");
	printf("\t\t\t-------/*****/----Fahrzeugverwaltung----/*****/--------\n");
	printf("\t\t\t---------***/-----------------------------***/---------\n");
	printf("\t\t\t----------*/-------------------------------*/----------\n\n");
	printf("kayitli arac sayim: %d\n\n\n\n",MAXCAR);
	if(MAXCAR!=0){
	printf("+----+---------------+---------------+------------+\n");
	printf("| ID |     Marke     |     Model     | Tagespreis |\n");
	printf("+----+---------------+---------------+------------+\n");
	for(i=0;i<MAXCAR+1;i++){
		if(fahrzeug[i].durum==1 || fahrzeug[i].durum==3){
		printf("|%-4d|",fahrzeug[i].id+1);
		printf("%-15s|",fahrzeug[i].marka);
        printf("%-15s|",fahrzeug[i].model);
        printf("%7d Euro|\n",fahrzeug[i].fiyat);
      	printf("+----+---------------+---------------+------------+\n");
        }
	}
    }
    else{
    	int selection;
    	system("color C0"); // KIRMIZI EKRAN
    	printf("\tEs gibt kein Fahrzeug. Sie konnen entweder aus der CSV-Datei Fahrzeuge importieren oder ein neues eintragen.\n\n");
    	printf("\t1-Fahzeug Eintragen\n\t2-Daten-Import aus CSV Datei\n\t0-Zuruck\n");
    	scanf("%d",&selection);
    	switch(selection){
    		case 0:
    			system("color F0"); // ANA EKRAN
    			hauptMenu();
    		break;
    		case 1:
    			system("color F0"); // ANA EKRAN
    			vehicleRegister();
    		break;
    		case 2:
    			system("color F0"); // ANA EKRAN
    			carexcel();
    		break;
		}
    	
	}
	printf("\t\t\t\tDrucken Sie irgendeine Taste um fortzufahren.\n");
	getche();
	system("color F0"); // ANA EKRAN
	hauptMenu();
}
void deleteVehicle(){
	system("cls");
	printf("\t\t\t---------/*-------------------------------/*-----------\n");
	printf("\t\t\t--------/***-----------------------------/***----------\n");
	printf("\t\t\t-------/*****/----Fahrzeugverwaltung----/*****/--------\n");
	printf("\t\t\t---------***/-----------------------------***/---------\n");
	printf("\t\t\t----------*/-------------------------------*/----------\n\n");
	int i,a,MAXCAR=MAXAUTO();
	if(MAXCAR!=0){
	printf("+----+---------------+---------------+------------+\n");
	printf("| ID |     Marke     |     Model     | Tagespreis |\n");
	printf("+----+---------------+---------------+------------+\n");
	for(i=0;i<MAXCAR;i++){
		if(fahrzeug[i].durum==1){
		printf("|%-4d|",fahrzeug[i].id+1);
		printf("%-15s|",fahrzeug[i].marka);
        printf("%-15s|",fahrzeug[i].model);
        printf("%-12d|\n",fahrzeug[i].fiyat);
      	printf("+----+---------------+---------------+------------+\n");
        }
	}
	printf("Welches Fahrzeug wollen Sie loschen?\n");
	scanf("%d",&a);
	fahrzeug[a-1].durum=2;
	system("color A1"); //MAVÝ EKRAN
	printf("\tDas Fahrzeug wurde erfolgreich geloscht\n\tDrucken Sie irgendeine Taste um fortzufahren.\n");	
    }
    else{
    	system("color C0"); // KIRMIZI EKRAN
    	printf("\t\tEs gibt kein Fahrzeug. Die Fahrzeugen existieren,damit Sie ein loschen konnen.\n");
	}
	getche();
	system("color F0"); // ANA EKRAN
	hauptMenu();
}

void carexcel(){
	show2();
	char line[200];
    FILE*CSVfile=fopen("cars.csv","r");
    FILE*myFile=fopen("carinfos.dat","a+b");
    int car_index=0;   
	int i=0;                                                  
        while(fgets(line,sizeof(line),CSVfile)){
        	//printf("while ýn icinde\n");
        	if(strcmp(line,"          ")){
        	//printf("ilk if in icinde\n");
			car_index++;
			FAHRZEUG fahrzeuge;
		        if(car_index!=1){
		          i++;
		          //printf("ikinci if in icinde\n");
				  char *token;
				  char *dateStr;
			      token=strtok(line,";");
				  strcpy(fahrzeuge.marka,token);
				  //printf("marka alindi\n");
				  token=strtok(NULL,";");
				  strcpy(fahrzeuge.model,token);
				  //printf("model alindi\n");
				  token=strtok(NULL,";");
				  fahrzeuge.fiyat=atoi(token);
				  //printf("fiyat alindi\n");
				  token=strtok(NULL,";");
				  fahrzeuge.durum=atoi(token);
				  //printf("durum alindi\n");
				  token=strtok(NULL,";");
				  dateStr=strtok(NULL,";");
				  fahrzeuge.id=atoi(token);
				  //printf("id alindi\n");
				 fwrite(&fahrzeuge,sizeof(FAHRZEUG),1,myFile);
	 			  //printf("%d. marka: %s\n",i+1,fahrzeuge.marka);
	 			  strcpy(fahrzeug[i-1].marka,fahrzeuge.marka);
	 			  //printf("%s\n",fahrzeug[i-1].marka);
	 			  //printf("%d. model: %s\n",i+1,fahrzeuge.model);
	 			  strcpy(fahrzeug[i-1].model,fahrzeuge.model);
	 			  //printf("%s\n",fahrzeug[i-1].model);
	 			  //printf("%d. fiyat: %d\n",i+1,fahrzeuge.fiyat);
	 			  fahrzeug[i-1].fiyat=fahrzeuge.fiyat;
	 			  //printf("%d\n",fahrzeug[i-1].fiyat);
	 			  //printf("%d. durum: %d\n",i+1,fahrzeuge.durum);
	 			  fahrzeug[i-1].durum=fahrzeuge.durum;
	 			  //printf("%d\n",fahrzeug[i-1].durum);
	 			  //printf("%d. id: %d\n",i+1,fahrzeuge.id);
	 			  fahrzeug[i-1].id=fahrzeuge.id;
	 			  //printf("%d\n",fahrzeug[i-1].id);
	 		}
	 	}
	 }
	system("cls");
	system("color A1");
	printf("\n\n\n\t\t\t\tDie Daten wurden erfolgreich importiert.\n");
}

void show3(){
	int i;
	for(i=0;i<12;i++){
		printf("\t...wird geladen\n");
		printf("\t....wird geladen\n");
		system("cls");
	}
}
void show2(){
	int i;
	for(i=0;i<50;i++){
		printf("...wird importiert\n");
		printf("....wird importiert\n");
		system("cls");
	}
	
}
                                
	
	
	
	
	
	
	
	
	
	

