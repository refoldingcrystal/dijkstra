# Algorytm Dijkstry

## Użycie

Aby skompilować program należy użyć polecenia `make` 

`./dijkstra <plik_z_grafem> [start] [koniec]`

Jeżeli nie zostanie podany:
- plik z grafem -> program zakończy działanie 
- wierzchołek startowy -> program ustawi go na '1' 
- wierzchołek koncowy -> program wypisze odleglosci do wszystkich wierzchołków 

Program zakończy działanie także w przypadku gdy plik z grafem nie istnieje

## Reprezentacja grafu

W pierwszym wierszu pliku znajdują się dwie liczby całkowite `n` i `m` (liczba wierzchołków i liczba połączeń).

W następnych `m` wierszach znajdują się opisy krawędzi. W każdym wierszu znajdują się trzy liczby całkowite `a`, `b` i `w`, reprezentujące krawędź o wadze `w` między wierchołkiem `a` i wierzchołkiem `b`.

```
graph.txt
9 11
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 4 11
3 6 2
4 5 6
5 6 9
7 8 1
8 9 2
```
