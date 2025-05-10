//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;

//stworzymy liczbe sekund czyli od ktorej sekundy ma zaczac sie odliczanie
//ilosc sekund
int s=3666;


//Tu stworzymy timer odliczajacy w dol az do zadanej daty lub wydarzenia
//Do stworzonego labela bedzie odswiezal sie co sek czas
//W proprieties - interval jest domyslnie 1000 czyli jedna sekunda jak sleep(1000)
// Jezeli w proprieties - enabled jest na true to wykonaj instrukcje z ikony zegara

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{  //cokolwiek tu wpiszemy bedzie sie wykonywalo co sekunde bo interval = 1000(1 sek)
   //chcemy co sekunde wyswietlac napis ze zaktualizowanym licznikiem (aktualnym czasem)

   s--; //co sekunde bedziemy zmniejszac liczbe startowa
   //teraz wypada zmienic liczbe sekund na godziny i minuty :

   int godzin, minut, sekund;
   //teraz potrzebujemy napisy stringi do wyswietlania:
   AnsiString godz,min,sek ;     // AnsiString - to nowy typ string uzywany w builderze c++
   //Przypisujemy przypisywanie:

   godzin = s / 3600;   // nie bedzie zaokraglania bo s to int
   godz = IntToStr(godzin); //konwencja int na string, string=IntToString(int)
   if ( godzin<10 ) godz="0"+godz; // jesli godzin jest mniej niz 10 to dopisz 0

   minut = (s - godzin * 3600) / 60;   // rownanie zmieniajace sek na minuty
   min = IntToStr(minut); //konwencja int na string, string=IntToString(int)
   if ( minut<10 ) min="0"+min; // jesli godzin jest mniej niz 10 to dopisz 0

   sekund = s - godzin * 3600 - minut * 60; //ile sekund zostalo po odliczeniu godzin i minut
   sek = IntToStr(sekund); //konwencja int na string, string=IntToString(int)
   if ( sekund<10 ) sek="0"+sek; // jesli godzin jest mniej niz 10 to dopisz 0


   // 1 godz = 3600s poniewaz:
   // 1 minuta = 60 sekund
   // 1 godz = 60 minut
   // 60 minut * 60 sekund = 3600 sekund

// teraz to wszystko musimy wstawic do przycisku label1 - properties - caption:
//zeby to wyswietlic co sekunde
Label1->Caption = godz + ":" + min + ":" + sek;

//co ma sie stac jak zegar zakonczy odliczanie:

if ( s<=0 ) //jezeli liczba s w iteracji osiagnie liczbe 0 lub mniejsza to caption labela1 zmienimy na tekst "Koniec czasu!"
{
  Label1->Caption="END OF TIME!";
  Timer1->Enabled=false; // i wylaczymy timera
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
Show();
Application->BringToFront()  ; // ta funkcja pozwoli minimalizowac program do traya czyli prawy dolny róg windows 
}
//---------------------------------------------------------------------------

