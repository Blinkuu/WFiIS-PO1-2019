/* Celem zadania jest napisanie uzytecznych klas, ktore pozwalaja na dostep 
   do tekstu (slow w zdaniu) "tak jakby" tekst by tablica dwuwymiarowa.
   
   Konieczne bedzie napisanie dwoch klas, ReadAccess i ReaWriteAccess udostepniajace roznie operatory []

   W zadaniu wystepuja tez przydatne funkcje, koniec slowa: eofWord
   i koniec tekstu eofSentence
   
   UWAGA: w op[] musimy sie przenosic do i-tego slowa, dokladnie na jego poczatek.
   Najlepiej naposac sobie w tym celu osoba funkcje, ktora obliczy nam przesuniecie wzgledem poczatku napisu gdzie zaczyna sie slowo.
   Jesli i == 0 oczywisce zwracamy 0
   Jesli i != przeuwamy sie do kolejnych znakow, zliczajac je, i zliczamy spacje.
   Jesli napotkamy spacje to znaczy ze w nastepnym znaku jest albo pocztek nowego slowa albo, koniec napisu.
   W kazdym przypadku przesuniecie bedzie to bedzie ilosc znakow zliczonych do tej pory +-1.

   UWAGA: w rozwiazniu nie nalezy kpioiwac napisow, dzielic ich itp. nigdzie nie wymagamy tego zeby mozna wylo wypisac samo i-te slowo.
 */
#include <iostream>
#include "WordAccess.h"
int main() {
  const ReadAccess p("Ala ma kota");

  int i = 0;
  while ( p[i][0] != 0 ) {
    std::cout << "Litera pierwsza i druga w slowie " << p[i][0] << " " << p[i][1] << std::endl;
    i++;
  } 

  const ReadAccess p2("Dawniej wszystko bylo lepsze");
  i= 0;
  while ( not WordAccess::eofSentence( p2[i] ) ) {
    int j = 0;
    while ( not WordAccess::eofWord( p2[i][j] ) ) {
      std::cout << " " << p2[i][j];
      ++j;
    }
    ++i;
    std::cout << std::endl;
  }

  
  char z[] = {"To jest tekst, ktory bedziemy zmieniac"};
  ReadWriteAccess pz(z);
  i = 0;
  while ( pz[i][0] != 0 ) {
    std::cout << "Litera pierwsza i druga w slowie przed zmianami " << pz[i][0] << " " << pz[i][1] << std::endl;
    pz[i][1] = '-';
    std::cout << "Litera pierwsza i druga w slowie po zmianie     " << pz[i][0] << " " << pz[i][1] << std::endl;
    i++;
  }


  std::cout << z << std::endl;
}
/* wynik
Litera pierwsza i druga w slowie A l
Litera pierwsza i druga w slowie m a
Litera pierwsza i druga w slowie k o
 D a w n i e j
 w s z y s t k o
 b y l o
 l e p s z e
Litera pierwsza i druga w slowie przed zmianami T o
Litera pierwsza i druga w slowie po zmianie     T -
Litera pierwsza i druga w slowie przed zmianami j e
Litera pierwsza i druga w slowie po zmianie     j -
Litera pierwsza i druga w slowie przed zmianami t e
Litera pierwsza i druga w slowie po zmianie     t -
Litera pierwsza i druga w slowie przed zmianami k t
Litera pierwsza i druga w slowie po zmianie     k -
Litera pierwsza i druga w slowie przed zmianami b e
Litera pierwsza i druga w slowie po zmianie     b -
Litera pierwsza i druga w slowie przed zmianami z m
Litera pierwsza i druga w slowie po zmianie     z -
T- j-st t-kst, k-ory b-dziemy z-ieniac
*/
