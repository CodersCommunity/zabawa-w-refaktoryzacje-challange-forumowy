# Zabawa w refaktoryzacje - challange forumowy

Jakiś czas temu zapowiedziałem na czacie tą zabawę. 

##O CO CHODZI?

Co jakiś czas będę wrzucał w tym temacie jakiś prosty algorytm, który będzie zazwyczaj sortować czy wyszukiwać. Będzie to jeden z tych podręcznikowych algorytmów, czyli skuteczny, szybki ale też okropny jeżeli chodzi o czytelność kodu.

##CO TRZEBA ZROBIĆ?

Waszym (naszym) zadaniem będzie doprowadzenie tego kodu do ładu i składu - szeroko pojęta refaktoryzacja. W skład tej refaktoryzacji będzie wchodzić:

- optymalizacja pamięci
- optymalizacja nazw zmiennych
- wyodrębnienie odpowiedzialności (czyli stworzenie funkcji, klas które będą pomagać zrozumieć kod)
- zastosowanie wzorców projektowych i implementacyjnych dla chętnych stworzenie testów
- unikanie zbędnych komentarzy - dobry kod sam się tłumaczy ze swojego zachowania, najczęściej jeżeli kusi Cię, żeby zrobić jakiś komentarz, spróbuj najpierw przebudować metodę tak, aby nie trzeba było danego kawałka kodu komentować. 

##CO TRZEBA WIEDZIEĆ?

Jeżeli jesteś w trakcie nauki i znasz język od kilku miesięcy - musisz wiedzieć, gdzie szukać informacji. Jeżeli masz już doświadczenie i wiedzę, wykorzystaj ją i pobaw się z nami. 

Terminy, które warto znać i próbować wykorzystać:

- Znaczące nazwy (czyli zamiast zmiennych o nazwach h, m s zastosować hours, minutes, seconds) - jednak nie tylko w odniesieniu do zmiennych, ale też do klas i funkcji 
- trzeba znać jakąkolwiek standaryzację pisania kodu - na przykład w PHP warto przeczytać o PSR-1 i PSR-2 - mówią one o tym jakie wcięcia w kodzie stosować, czy pisać camelCase czy pascalCase, czy UpperCase czy lowercase oraz o wielu wielu innych dobrych praktykach
- Abstrakcja danych
- Prawo Demeter
- obsługa błędów
- hermetyzacja danych
- polimorfizm

Refaktoryzacja często się wiąże z czystym kodem (ang. clean code), dlatego warto poznać takie pojęcia jak:

*  **S** - zasada pojedynczej odpowiedzialności
*  **O** - zasada otwarte-zamknięte
*  **L** - zasada podstawiania Liskow
*  **I** - zasada segregacji interfejsów
*  **D** - zasada odwracania zależności

Aby wiedzieć, która część kodu nadaje się do refaktoryzacji stosuje się technikę rozpoznawania "brzydkich zapachów", a to ich lista:

http://pastebin.com/0jen1ect

Oczywiście nie wymagam od nas wykorzystania tych wszystkich rzeczy - ten temat ma być edukujący, więc osoby, które nic nie wiedzą, właśnie się dowiedziały paru istotnych pojęć i w przyszłości będą mogły poszukać informacji o tych rzeczach. 

#OGÓLNE ZASADY

*Nie ma oceniania osób za to co piszą, jak piszą - każdy może się wypowiedzieć, każdy może tutaj wykazać się wiedzą lub chęcią do zdobycia jej. 
Chciałbym tylko zachować względny porządek w tym wątku, więc prosiłbym aby do zadanego kodu wypowiadać się tylko i wyłącznie pod postem z tym kodem.*

Tak pozatym to liczę na waszą współpracę i na to, że pomysł się spodoba :)



Miłej zabawy!

Link: http://forum.miroslawzelent.pl/65816/zabawa-w-refaktoryzacje-challange-forumowy
