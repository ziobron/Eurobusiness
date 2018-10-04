# LogicalImages
[![Build Status](https://www.travis-ci.org/LordLukin/LogicalImages.svg?branch=master)](https://www.travis-ci.org/LordLukin/LogicalImages) 
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/a43fc0aad42c42c19499964f519d2e0e)](https://app.codacy.com/app/LordLukin/LogicalImages?utm_source=github.com&utm_medium=referral&utm_content=LordLukin/LogicalImages&utm_campaign=Badge_Grade_Settings)

Eurobusiness (Monopoly)
=====================
Celem głównym jest implementacja modelu gry Eurobusiness. Natkniemy się przy tym na wiele wyzwań z dziedziny architektury oprogramowania - jak zamodelować prawidłowo grę. Będziemy musieli wykorzystać kilka wzorców projektowych, które powinny ułatwić późniejsze modyfikacje kodu. W podstawowej wersji gra będzie mieć interaktywną formę rozgrywki, gdzie graczej sami decydują o swoich poczynaniach. Dodatkowo możliwa będzie opcja rozgrywki automatycznej, gdzie zaimplementowane algorytmy będą same decydować o poczynaniach graczy. Dodatkowym celem jest wykorzystanie biblioteki graficznej do wyświetlania planszy.

**Input:**
Plik konfiguracyjny z nazwami pól i kart w formacie JSON:

```
{
  "fields": {
    "0": "Start",
    "1": "Grecja - Saloniki",
    "2": "Szansa (niebieska)",
    "3": "Grecja - Ateny"
    "4": "Parking strzeżony",
    ...
  },
  "blueCards": {
    "0": "Płacisz na budowę szpitala 400 $.",
    "1": "Otrzymujesz w spadku 200 $.",
    "2": "Masz urodziny otrzymujesz od każdego gracza po 20 $.",
    ...
  },
  "redCards": {
    "0": "Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $.",
    "1": "Remontujesz swoje domy. Płacisz do banku za każdy dom 50 $, za każdy hotel 200 $.",
    "2": "Wracasz do Madrytu.",
    ...
  }
}
```

**Output:**
Zapis przebiegu rozgrywki w formacie tekstowym:

```
Players: Red, Blue, Yellow
Turn 1:
  Red:		Money: 3000$, Field: 0, Owns: nothing,
			Rolls 8, Action: Buys "Włochy - Mediolan" (-200$),
			Money: 2800$, Field: 8, Owns: Property 8 (0 houses, 0 hotels),
  Blue: 	Money: 3000$, Field: 0, Owns: nothing,
			Rolls 7, Action: RedCard 2 ("Wracasz do Madrytu."),
			Money: 3000$, Field: 14, Owns: nothing,
  Yellow: 	Money: 3000$, Field: 0, Owns: nothing,
			Rolls 4, Action: Pays 400$,
			Money: 2600$, Field: 4, Owns: nothing,
Turn 2:
  ...
  
Winner: Red
```

**Założenia:**
Przyjmujemy zasady polskiej wersji gry, tzn. Eurobusiness, a nie Monopoly - https://pokazywarka.pl/zasady-gry-w-eurobusiness/
Plansza ma 40 pól, 16 czerwonych kart, 16 niebieskich kart
W grze nie rozróżniamy poszczególnych banknotów, a bank ma nieograniczoną ilość gotówki.

**Wymagania obowiązkowe**, do zaimplementowania w tejże kolejności:

1. Model gry: plansza z 40 polami, 16 kartami czerwonymi, 16 niebieskimi z nazwami i/lub wartościami wczytanymi z pliku konfiguracyjnego
2. Model graczy
3. Model kart własności (nieruchomości)
4. Losowy rzut 2 kostkami, początek gry na polu Start, każdy z graczy otrzymuje na start 3000$
5. Logowanie stanu gry co ruch każdego gracza do pliku wyjściowego
6. Każdorazowe przejście przez pole "Start" lub zatrzymanie się na nim, nagradzane jest wypłacaną przez bank sumą w wysokości 400$, o ile grający nie "udaje się do wiezienia". 
7. Pole "Parking strzeżony" traktowane jest jako pole dodatkowe nie podlegające wykupowi. Osoba znajdująca się swoim pionkiem na tym polu płaci do banku 400$. Pole "Podatek od wzbogacenia" traktowane jest podobnie, przy czym grający wpłaca do banku 200$. 
8. Pole "Darmowy parking" funkcjonuje w grze jako pole nie przynoszące ani zysku ani strat. 
9. Gdy gracz stanie na polu z niezakupionym terenem budowalanym, gracz może go wykupić za cenę wskazaną na karcie własności
10. Gdy gracz stanie na polu z zakupionym przez siebie terenem budowlanym nic się nie dzieje
11. Gdy gracz stanie na polu z zakupionym przez innego gracza terenie budowlanym, płaci mu cenę wskazaną na karcie własności
12. Gdy gracz stanie na polu z niezakupionym terenem budowlanym i nie wykupi go, wszysch gracze licytują się o akt własności zaczynając od połowy ceny zakupu.
13. Pole "Więzienie" w przypadku odwiedzania go nie ma efektu. W pozostałych przypadkach (gracz na polu "Idziesz do więzienia", karta "Idziesz do więzienia", wyrzucenie 12 oczek i ponowne wyrzucenie 12 oczek) gracz przesuwa swój pionek na pole "Więzienie". Przebywający w "Wiezieniu" opuszcza dwie kolejki rzutów, tracąc prawo do sprzedaży i kupna nieruchomości oraz pobierania opłat za postój. 
14. Jeżeli chce wyjść wcześniej z "Więzienia" musi zapłacić 100$ grzywny i wyrzucić "dublet" - 12 oczek. W razie nieudanej próby wyrzucenia "dubletu" gracz płaci grzywnę 400$ (dopłaca 300$) i opuszcza "Więzienie". 

**Wymagania dodatkowe**, do zaimplementowania w tejże kolejności:

1. Gdy gracz stanie na polu z szansą (czerwona lub niebieska) gracz zastosowuje się do polecenia z pierwszej z góry karty po czym wsuwa ją pod spód stosu.
2. W sytuacji gdy wszystkie tereny budowlane jednego państwa znajdują się w reku jednego gracza ma on prawo nabyć w banku, bezpośrednio przed swoją kolejką rzutów, dom lub domy. W każdej rundzie grający może nabyć maksymalnie 3 domy - stawiając każdorazowo na terenie danego miasta jeden dom. Drugi dom można postawić pod warunkiem posiadania w każdym mieście danego państwa po 1 domu. Jedno miasto można zabudować maksymalnie 4 domami. Trzeci i czwarty dom stawiamy do zasady proporcjonalnej zabudowy. O ile na terenie wszystkich miast jednego państwa stoją już po 4 domy, ich właściciel może kupić hotel. Aby nabyć hotel zwracamy do banku znajdujące się w danym mieście 4 domy + opłatę wskazaną na "Akcie własności". W każdym okrążeniu gracz może nabyć maksymalnie 3 hotele. W jednym mieście może stać tylko 1 hotel
3. Grający ma prawo przed swoja kolejka rzutu sprzedać innemu grającemu, za dowolną umówioną cenę niezabudowane tereny miast, o ile na żadnym z posiadanych przez sprzedającego, terenie budowlanym nie stoją domy lub hotel. Przed dokonaniem transakcji należy je odsprzedać do banku, który płaci: 
a) za domy - połowę ich wartości 
b) za hotel - 1/2 wartości 4 domów + 1/2 dopłaty za hotel 
4. Tylko bank jest upoważniony do udzielania pożyczki pod zastaw hipoteczny terenu (wysokość obciążenia hipoteki wskazana jest na karcie każdego "Aktu własności"). Domy i hotele, które nie mogą służyć jako zastaw pożyczki, należy przed zastawieniem terenu sprzedać do banku, na wyżej wymienionych warunkach. W momencie zwrotu pożyczki do banku pożyczający wpłaca również kwotę =10% wartości pożyczki. Zastawienie terenu powoduje odwrócenie "Aktu własności". 
5. W przypadku nabycia nieruchomości obciążonej długiem hipotecznym nabywca może zaraz wpłacić do banku sumę obciążenia hipotecznego plus 10% odsetek, lub tez zrezygnować na pewien czas z oddania długu wpłacając na razie do banku sumę 10% odsetek. Przy późniejszej spłacie długu, grający ponownie płaci 10% odsetek. Gracz, który nie może uregulować swoich należności wobec innego grającego w całości gotówką, może to uczynić częściowo gotówka a częściowo swoimi terenami (budowlanymi, kolejami, elektrownia, wodociągami) co do wartości których umawiają się zainteresowane strony. 
6. Grający, który jest niewypłacalny wobec innego grającego (nie ma czym zapłacić), przerywa grę a swoją własność oddaje wierzycielowi przy czym domy i hotele bank odkupuje za połowę ceny, a gotówkę wypłaca wierzycielowi. 
7. Grę można zakończyć w każdym momencie, jeśli tylko zgodzą się na to wszyscy gracze. W tym przypadku gracze obliczają swój majątek tj.: 
- gotówkę, 
- wartość nie zastawionych terenów budowlanych, elektrowni, linii kolejowych, wodociągów, 
- połowę wartości nieruchomości zastawionych, 
- wartość domów i hoteli. 
Posiadacz największego majątku - zwycięża.

**Wymagania dodatkowe**, do spełnienia w dowolnej kolejności po implementacji wszystkich wymagań obowiązkowych:

1. Wizualizacja gry i jej stanu krok po kroku z wykorzystaniem biblioteki graficznej (najlepiej Qt lub OpenCV)
2. Gracze komputerowi - algorytmy automatycznego podejmowania decyzji
3. Zapis i odczyt stanu gry
