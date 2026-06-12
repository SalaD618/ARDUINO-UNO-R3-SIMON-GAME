Simon Game – Arduino
Un proiect simplu și educativ care implementează jocul clasic Simon Says folosind un Arduino, patru LED-uri, patru butoane și un algoritm de generare și verificare a secvențelor.

Descriere
Acest proiect reproduce jocul Simon Game, în care Arduino generează o secvență de culori, iar jucătorul trebuie să o repete apăsând butoanele corespunzătoare.
La fiecare nivel, secvența devine mai lungă, iar jocul continuă până când jucătorul greșește.


Hardware necesar
Arduino UNO / Nano / Mega
4 LED-uri (Roșu, Verde, Albastru, Galben)
4 rezistențe pentru LED-uri (220–330Ω)
4 butoane
4 rezistențe pentru butoane (dacă nu se folosește INPUT_PULLUP)
Fire de conexiune
Breadboard

Conexiuni
LED-uri
Culoare	Pin Arduino
Roșu	12
Verde	11
Albastru	10
Galben	9


Butoane
Buton	Pin Arduino
Roșu	5
Verde	4
Albastru	3
Galben	2


Butoanele folosesc INPUT_PULLUP, deci logica este inversată:
0 = apăsat, 1 = eliberat.

Funcționalitate
Arduino generează o secvență aleatorie de culori.
LED-urile redau secvența.
Jucătorul trebuie să repete secvența apăsând butoanele.
Dacă jucătorul greșește:
toate LED-urile clipesc de 3 ori
jocul revine la nivelul 0
Dacă jucătorul reușește:
nivelul crește
se adaugă o nouă culoare în secvență

Codul sursă
Codul complet al jocului se află în fișierul:

Cod
SimonGame.ino
Include:

inițializarea pinilor
generarea secvenței
redarea secvenței
citirea inputului de la butoane
verificarea corectitudinii
resetarea jocului

Cum rulezi proiectul
Deschide Arduino IDE
Încarcă fișierul .ino
Selectează placa și portul corect
Apasă Upload


