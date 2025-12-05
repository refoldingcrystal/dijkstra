# Algorytm Dijkstry

## Użycie

Aby skompilować program należy użyć polecenia `make` 

`./dijkstra <plik_z_grafem> [start] [koniec]`

Jeżeli nie zostanie podany:
- Plik z grafem, program zakończy działanie 
- Wierzchołek startowy, program ustawi go na '1' 
- Wierzchołek koncowy, program wypisze trasy do wszystkich wierzchołków 

Program zakończy działanie także w przypadku gdy plik z grafem nie istnieje

## Reprezentacja grafu

W pierwszym wierszu pliku znajdują się dwie liczby całkowite `n` i `m` (liczba wierzchołków i liczba połączeń).

W następnych `m` wierszach znajdują się opisy krawędzi. W każdym wierszu znajdują się trzy liczby całkowite `a`, `b` i `w`, reprezentujące krawędź o wadze `w` między wierchołkiem `a` i wierzchołkiem `b`.

## Todo

- efektywne liczenie wszystkich sciezek
- sciezka miedzy rozlacznymi wierzcholkami sie wykrzacza
