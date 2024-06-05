/*
 ============================================================================
 Name        	        :LOTTO.c
 Kurzbeschreibung       :LOTTOSPIEL-SIMULATION
 EingabeParameter       :VOID
 Rückgabeparameter      : 0 (Programm beenden )
 Author            	    :Hamza Sliti
 Mat.Nr                 :11131474
 Version          	    :1
 Datum letzte Änderung  :16.12.2020
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 Funktionsname : Binomialkoeffizient
 Kurzbeschreibung der Aufgabe der Funktion: BERECHNEN DES BINOMIALKOEFFIZIENTEN

 Eingaben  : int n , int k

 Ausgaben  : VOID


 Autor     : Hamza Sliti

 Version   : 2

 Datum letzte Änderung  :16.12.2020

 */

void Binomialkoeffizient(int n, int k) {
	//   1 <= N <= 99
	// k ist die Anzahl der Zahlen der Binomialkoeffizienten
	int i = 1;
	int z = 1;    // Variable des binomialkoeffizienten
	int binomialkoeffizient[1000] = { 0 }; //Zahlenarray für die Binomialkoeffizienten der Mehrfachheiten(k): 1 bis n-1

	do { //Berechnung des Binomialkoeffizienten für die einzelnen Mehrfachheiten k
		z = z * (n - i + 1) / i; //Formel zur berechnung des Binomialkoeffizienten
		binomialkoeffizient[i - 1] = z; //Die Binomialkoeffizienten im Array mit dem Index 0 bis k speichern
		i = i + 1;
	} while (i <= k); //Solange bis die Wahrscheinlichkeiten für die k Treffermöglichkeiten erechnet sind

	printf(
			"Die Anzahl an Zahlenkombinationen in einem Feld aus %d Zahlen liegt für:\n",
			n);
	for (i = 0; i < k; i++) {
		printf("- %d Zahlen bei: %d \n", i + 1, binomialkoeffizient[i]);
	}
}

/*
 Funktionsname : umwandeln
 Kurzbeschreibung der Aufgabe der Funktion: UMWANDEL DER ZEICHENKETTE IN ZAHLEN-ARRAY

 Eingaben  : char zeichen , int k

 Ausgaben  : Tipzahlen


 Autor     : Hamza Sliti

 Version   : 2

 Datum letzte Änderung  :16.12.2020

 */

int *umwandeln(char *zeichen, int k) {
	int i = 0, j = 0, z = 0; //i ist der index des übergeben zeichen-arrays, das den string mit den zahlen entählt,
	static int TipZahlen[98] = { 0 };
	char einzelneZahlen[3]; //zeichen-array, das jeweils eine zeichenfolge speichert bis ein komma erreicht wird oder das ende des strings also die zeichenzusammensetzung jeder zahl

	do {
		einzelneZahlen[j] = zeichen[i]; //die zeichen werden auf das andere zeichen array übertragen
		i = i + 1;        //der index beider arrays mit 1 addiert
		j = j + 1;
		if (zeichen[i] == ',' || zeichen[i] == '\0') { //ist das darauffolgende zeichen im array ein komma oder das ende des arrays:
			einzelneZahlen[j] = '\0'; //wird das array das die zeichen bis dahin übertragenbekommen hat geschlossen
			TipZahlen[z] = atoi(einzelneZahlen); //und die zeichenzahl dieses arrays in eine int-zahl konventiert und im zahlen-array gespeichert
			z = z + 1;
			if (zeichen[i] == '\0') { //wurde das ende erreicht, wird die schleife verlassen
				break;
			}
			i = i + 1; //hier wird der index erneut mit eins addiert, damit im nächsten durchlauf das array "einzelneZahlen" nicht das komma des "zeichen"-arrays speichert
			j = 0; //der index des "einzelneZahlen"-arrays wird 0 gesetzt, damit beim nächsten durchlauf wieder die richtige zahl konventiert wird
		}
	} while (z < k);       //es werden nur die k ersten zahlen übernommen

	TipZahlen[z] = '\0';       //zum schluss wird das array geschlossen
	return TipZahlen;       //und zurückgegeben
}

/*
 Funktionsname : gueltigkeit
 Kurzbeschreibung der Aufgabe der Funktion: PRÜFEN DER GÜLTIGKEIT DER TIP/LOTTO-ZAHLEN

 Eingaben  : int zahl , int j , int Tipzahlen , int n

 Ausgaben  : int gueltig


 Autor     : Hamza Sliti

 Version   : 2

 Datum letzte Änderung  :16.12.2020

 */

int gueltigkeit(int zahl, int j, int *Tipzahlen, int n) //Prüft sowohl die Tipzahlen als auch die Zufallszahlen auf ungültigkeit oder doppeltes vorkommen
{
	int gueltig = 0, z = 0; //gueltigkeit ist der rückgabewert, der aussagen wird ob die zahl ungültig oder dopplet ist

	if (zahl <= n && zahl >= 1) {   // Abfrage ob die Zahl zwischen 1 und n ist.
		gueltig = 1;  //wenn ja, ist der rückgabewert 1
	} else {
		gueltig = 0;       //wenn nicht 0
	}
	if (gueltig == 1) { // Nur wenn sie im gültigem wertebereich liegen wird weitegeprüft
		for (z = 1; z <= j; z++) { // Prüfen ob die zahlen nicht doppelt vorkommen
			if (zahl == Tipzahlen[j - z]) { //Jede zahl wird mit den Zahlen die einen kleineren index haben verglichen, ist irgendeine Zahl mit einer anderen gleich,
				gueltig = 2;
				break; //Verlassen der schleife fals die Zahl bereits im array vorhanden ist, mit dem Rückgabewert 2
			}
		}
	}
	//wird 0 zurückgegeben, ist bekannt das die zahl zu gros oder klein war, wird 2 zurückgegeben, kann es zwar sein das die zahl im gültigen bereich lag, jedoch doppelt vorkam
	return gueltig; //nur wenn 1 zurückgegeben wird ist die zahl gültig und nicht doppelt;   gueltig an main zurückgeben
}

/*
 Funktionsname : Sortieren
 Kurzbeschreibung der Aufgabe der Funktion: SORTIEREN DER ZAHLEN
 Eingaben  : int a,b

 Ausgaben  : (*(int*) a - *(int*) b


 Quelle     : http://www.cplusplus.com/reference/cstdlib/qsort/


 Version   : 1

 Datum letzte Änderung  :16.12.2020

 */

int Sortieren(const void * a, const void * b) {
	return (*(int*) a - *(int*) b);
}

/*
 Funktionsname : Zufallszahlen
 Kurzbeschreibung der Aufgabe der Funktion: BERECHNEN DER ZUFALLS-ZIEHUNGSERGEBNISSE

 Eingaben  : int z , int k , int n

 Ausgaben  : Lottozahlen


 Autor     : Hamza Sliti

 Version   : 2

 Datum letzte Änderung  :16.12.2020

 */

int *Zufallszahlen(int z, int k, int n) {
	int i = 0;
	int zahl = 0;       //variable für die Zufallszahl
	static int Lottozahlen[99] = { 0 };

	time_t initialisierungswert; //initialisierungswet, ist eine variable die eine anzahl von sekunden enthalten kann. Sie entspricht der größe eines long-int Datentyps

	srand((unsigned int) time(&initialisierungswert)); //  Programmstart anders. durch die division mit der Schleifendurchlaufs-zählervariable k ist gewährleistet das die initialisierung auch bei mehrfachem Durchlauf jedes mal anders ist.

	do {
		zahl = rand();       //zahl ist die zufallszahl
		Lottozahlen[i] = zahl; //und wird im Lottozahlen array als ziehungszahl gespeichert
		if (gueltigkeit(zahl, i, Lottozahlen, n) == 1) { //ist die zahl ungleich 1, also ungültig bleibt der index unverändert und die gespeicherte
			i = i + 1;    //zahl wird mit der nächsten Zufallszahl überschrieben
		}
	} while (i < k);       //bis k zahlen im Array sind

	return Lottozahlen;
}
/*
 Funktionsname : Vergleichen
 Kurzbeschreibung der Aufgabe der Funktion: VERGLEICHEN DER TIP- UND LOTTOZAHLEN

 Eingaben  : int TipZahlen , int Lottozahlen , int k

 Ausgaben  : vergleich


 Autor     : Hamza Sliti

 Version   : 2

 Datum letzte Änderung  :16.12.2020

 */

int *Vergleichen(int *TipZahlen, int *Lottozahlen, int k) {
	int j = 0, z = 0;
	static int vergleich[1000] = { 0 };

	do {
		do { //Die ertse schleife vergleicht eine Zahl der Tipzahl mit jeder Lottozahlen
			if (TipZahlen[j] == Lottozahlen[z]) { //wenn ein der Lottozahlen gleich der jeweiligen Tipzahl ist
				vergleich[j] = 1; //wird im Rückgabearray eine 1 gespeichert, unswar hat die eins den selben index wie eine richtig getippte Tipzahl
				j = j + 1; // wenn z.b. die zweite Tipzahl irgendwo im Lottozahlenarray vorkommt, dan ist die 1. an der 2. position des rückgabearrays
				z = 0;
			} else {
				z = z + 1;
			}
		} while (z < k);
		vergleich[j] = 0; //wenn die zweite zahl nicht im Lottozahlenarray vorkommt ist die 0 an der 2.Position des Rückgabewerts
		j = j + 1; //Und es wird die nächstezahl des Tipzahlenarrays vergliechen
		z = 0; //mit allen Lottozahlen, deshalb wird der lottozahlenindex wieder 0 gesetzt
	} while (j < k);       //bis k Zahlen verglichen worden sind

	return vergleich;       //Das array zurückgeben
}
/*
 Funktionsname : Ausgabe
 Kurzbeschreibung der Aufgabe der Funktion: AUSGABE DER ZIEHUNGSERGEBNISSE


 Eingaben  : int TipZahlen,int Lottozahlen,int Vergleich,int z, int k

 Ausgaben  : j


 Autor     : Hamza Sliti

 Version   : 2

 Datum letzte Änderung  :16.12.2020

 */

int Ausgabe(int *TipZahlen, int *Lottozahlen, int *Vergleich, int z, int k) {
	int i = 0, j = 0;
	printf("\n\n\n%d. Ziehung:", z); //z ist der schleifenzähler der schleife die solange läuft bis 3 treffer vorliegen
	printf("\nIhre Tipzahlen: ");       //Ausgabe der Tipzahlen:
	for (i = 0; i < k; i++) {
		printf("%d,", TipZahlen[i]);
	}
	printf("\nDie Lottozahlen:");       //Ausgabe der Lottozahlen:
	for (i = 0; i < k; i++) {
		printf("%d,", Lottozahlen[i]);
	}
	j = 0;       //Zähler der Treffer
	for (i = 0; i < k; i++) {       //Ausgabe der treffe Zahl und ihrer Position
		if (Vergleich[i] == 1) {
			j = j + 1;
			printf("\nSie haben ihre %d.zahl, die %d richtig getippt!", i + 1,
					TipZahlen[i]);
		}
	}
	if (j > 0) {
		printf("\nund somit %d Treffer", j);
	}       //Ausgabe der Treffer
	else {
		printf("\nSie haben keinen Treffer");
	}       //sonst ausgabe das es keine gibt

	return j;
}
//HAUPTPROGRAMM
int main(void) {

	int i = 0, j = 0, z = 0; // schleifenzähler
	int k = 0, n = 0;    //   1 <= N <= 99  ||  k ist die Anzahl der Zahlen
	int gueltig = 0;     //gueltig ist der rückgabewert der funktion gueltigkeit
	int *TipZahlen = NULL, *Lottozahlen = NULL, *Vergleich = NULL; //Pointer auf die Funktion zum Umwandeln des Zeichenstrings in ein Zahlen-array, und auf die Funktion zur berechnung der Zufallszahlen
	char zeichen[200] = { '0' };       // das array mit den eingegebenen zeichen

	printf(
			"***************************** LOTTOSPIEL ******************************\n\n"); //Überschrift

	printf("\nBitte geben Sie N ein : ");
	scanf("%d", &n);                 //N einlesen
	printf("\nBitte geben Sie K ein :");
	scanf("%d", &k);                 //K einlesen

	printf(
			"\nGeben sie ihren %d-stelligen Lottotip ein.\nDie Zahlen dürfen nicht größer als %d sein und nicht doppelt vorkommen.\nTrennen sie die Zahlen mit einem Komma:",
			k, n);       //Aufforderung zum eingeben der Zahlen
	scanf("%s", zeichen);        // einlesen der eingegebenen Zahlen als String

	TipZahlen = umwandeln(zeichen, k); // Übergabe des Strings an die Funktion, die aus den zeichen zwischen den kommas ganze Zahlen macht

	Binomialkoeffizient(n, k); // Aufruf der Funktion, die die Binomialkoeffizienzen berechnet und ausgibt

	z = 0;
	do { //In dieser Schleife wird der Nutzer aufgefordert seine Zahlen zu korrigieren fals diese doppelt oder ungültig sind
		gueltig = gueltigkeit(TipZahlen[z], z, TipZahlen, n); //Wird an die Funktion übergeben die jede zahl in bezug zum ganzen array auf gültigkeit und doppeltes vorkommen prüft
		if (gueltig == 2) { //ist der Rückgabewert 2, ist vorher eingegeben Zahl doppelt, wird eine Meldung ausgegeben
			printf(
					"\ndie %d. Zahl ist doppelt!\nGeben sie statt dieser Zahl eine andere ein:",
					z + 1);       //und die Aufforderung eine neue einzutippen
			scanf("%d", &TipZahlen[z]); //die mit dem index z, an der stelle der falschen zahl gespeichert wird
		}
		if (gueltig == 0) { //ist der Rückgabewert 0, ist vorher eingegeben Zahl ungültig, und es wird eine FehlerMeldung ausgegeben
			printf(
					"\ndie %d. Zahl ist ungueltig!\nGeben sie statt dieser Zahl eine gültige ein:",
					z + 1);      //und die Aufforderung eine neue einzutippen
			scanf("%d", &TipZahlen[z]); //die mit dem index z, an der stelle der falschen zahl gespeichert wird
		}
		if (gueltig == 1) { //Nur wenn 1 zurückgegeben wird, wird der index mit 1 addiert
			z = z + 1; //damit die neu eingegebenen Zahlen ebenfalls geprüft werden können
		}
		if (TipZahlen[z] == '\0' && z != k) { //Wenn das Zahlenarray zuende ist und z<k, also noch keine k Zahlen im Array enthalten waren:
			printf(
					"Sie haben zu wenig Zahlen eingetippt!\nGeben sie eine weitere Zahl ein:"); //wird aufgefordert eine weitere Zahle einzugenen
			scanf("%d", &TipZahlen[z]); //die an der stelle gespeichert wird an der das ende zeichen war
			TipZahlen[z + 1] = '\0'; //dieses ende zeichen wird um eins nachhinten geschoben, wodurch die bedingung wieder erfüllt ist und die schleife ein weiteres mal durchlaufen werden kann
		}
	} while (TipZahlen[z] != '\0');   //bis das ende der schleife erreicht wurde

	i = 1;       //i ist der Zähler der Durchläufe der Ziehungen
	do { //Schleife zur Wiederholung der Lottoziehung bis mindestens 3 Treffer erzielt wurden
		Lottozahlen = Zufallszahlen(i, k, n); //Die Lottozahlen werden in der funktion Zufallszahlen berechnet
		qsort((void *) TipZahlen, k, sizeof(int), Sortieren); //Funktion qsort sortiert das array mit den Tipzahlen der größe nach
		qsort((void *) Lottozahlen, k, sizeof(int), Sortieren); //Funktion qsort sortiert das array mit den Lottozahlen der größe nach
		Vergleich = Vergleichen(TipZahlen, Lottozahlen, k); //die Funktion hat den rückgabewert eines int-arrays mit k Zahlen hat
		j = Ausgabe(TipZahlen, Lottozahlen, Vergleich, i, k); //Alle Ergebnisse werden an die Funktion Ausgabe übergeben und ausgegeben
		i = i + 1;
	} while (j < 3); //bis mindestens 3 Treffer erzielt wurden, i ist der Rückgabewert von Ausgabe und gibt an wie viele treffer erzeilt wurden

	return (0);

}
