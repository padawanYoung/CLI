#include "main.h"
#include "stdio.h"

int main (void){
	treeInit ();
	regCliCommand("GET SMTH1 Pasha -.2", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH1 Egor 2", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH1 Sveta 2", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH2 Kostya 2", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH2 Tata 2", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH2 Oxxxymiron 2", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH3 Misha 1000", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH3 Zamai 1000", 3, &setSmth1_2Callback);
	regCliCommand("GET SMTH3 Guf 1000", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH1 Pasha 2", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH1 Egor 2", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH1 Sveta 2", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH2 Kostya 2", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH2 Tata 2", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH2 Oxxxymiron 2", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH3 Misha 1000", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH3 Zamai 1000", 3, &setSmth1_2Callback);
	regCliCommand("SET SMTH3 Guf 1000", 3, &setSmth1_2Callback);
	treeDeinit();
	return 0;
}
