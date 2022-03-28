#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fahrzeugverwaltung.h"
#include "kundenverwaltung.h"
#include <locale.h>


int hauptMenu();
void show();
void programmExit();

int main() {
readCarsFile(); 
readCustomersFile();
system("color F0"); //A1 OKEY C0 YANLIÞ F0 ANA EKRAN
hauptMenu();
return 0;
}

int hauptMenu(){
	int selection;
	system("cls");
	setlocale(LC_ALL, "German");
	show();
	printf("\n\t\t\t\tHerzlichen Willkommen zum Autoverleih Programm\n");
	printf("\t\t\t\t\t______________________\n\n");
	printf("\t\t\t\t\t1-Fahrzeug-Verwaltung\n\t\t\t\t\t2-Kundenverwaltung\n\t\t\t\t\t3-Leihaufträge\n\t\t\t\t\t0-EXIT\n");
	printf("\t\t\t\t\t______________________");
	printf("\n\n\t\t\t\t\tBitte auswählen: ");
	scanf("%d",&selection);
	switch(selection){
		case 0:
			saveCarsFile();
			saveCustomersFile();
		char b;
		printf("\n\t\t\t\tSind Sie sicher? (j/n): ");
		b=getche();
		if (b =='n')
		{
		hauptMenu();
	}
		else if( b == 'j')
		{ 
		programmExit();
		}
else {
printf("\n\nEtwas falsch gegangen. Drucken Sie irgendwas, um zurück zu kehren"); getche(); hauptMenu(); 
} break;
			exit(EXIT_FAILURE);
		case 1:
		    fahrzeugVerwaltung();
			break;
		case 2:
			kundenVerwaltung();
			break;
		case 3: 
		    leihauftraege();
			break;
			
			default : { printf("\n\nEtwas falsch gegangen. Drucken Sie irgendwas, um zurück zu kehren"); getche(); hauptMenu();} break;
	}	
}

void show(){
printf("                                   ________________________________                                            \n");
printf("                                  /\\                               \\                  \n");
printf("                                 /  \\                               \\              \n");
printf("                                /    \\ _____________________________ \\                                          \n");
printf("                               /     //            | |              \\ \\                        \n");
printf("       *                      /     //             | |               \\ \\                     \n");
printf("    * * *  __________________/     //              | |                \\ \\___________________   \n");
printf("    *  *  /___/_/           \\\\    //               | |                 \\             \\______\\      \n");
printf("     *   /_____              \\\\  //                | |                  \\              ______\\    \n");
printf("  * * * /___/_/_______________\\\\//_________________|_|___________________\\____________\\_______\\                                 \n");
printf("     *  |   | |                 |                   |                    |            |       |                          __________          \n");
printf("    *   |___|_|                 |             -__-  |              -__-  |            |_______|                         /          \\    \n");
printf("        |                       |                   |                    |                    |               _____    /  Herzlich  \\  \n");
printf("        |                       |                   |                    |                    |______   _    /     \\  /              \\    \n");
printf("        |          _________    |                   |                    |  _________         |______| /!\\  / HALLO \\ \\  Willkommen  /           \n");
printf("        |         /* * * * *\\   |                   |                    | /* * * * *\\        |        \\_/  \\       /  \\            /\n");
printf("        |________/* * * * * *\\__|___________________|____________________|/* * * * * *\\_______|              \\_____/    \\__________/\n");
printf("                 * * * * * * *                                            * * * * * * *                                         \n");
printf("                 * * * * * * *                                            * * * * * * *                                            \n");
printf("                  * * * * * *                                              * * * * * *                                                \n");
printf("                   * * * * *                                                * * * * *                                        \n");        
}

void programmExit(){
	printf("\n\t\t\t\tAuf Wiedersehen\n");
}


