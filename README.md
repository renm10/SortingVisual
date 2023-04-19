# Bubble Sort Visualizer 📈

A bubble sort visualizer created by C++ and [SFML](https://www.sfml-dev.org/index.php).

## Follow Steps
1. Compiling
```
g++ -I<Destination of SFML>\include -c ./src/sortingvisual.cpp -o sortingvisual.o
```
2. Linking
```
g++ -L<Destination of SFML>\lib .\sortingvisual.o -o sortingvisual.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main [-mwindows]
```
- ⚠️ *Adding a **-mwindows** command in the g++ -L command **WILL NOT** open a console.*
**(NO COUT STATEMENTS WILL BE DISPLAYED IN THE TERMINAL)**

3. Running the Code
```
.\sortingvisual.exe
```

## Usage
Space Bar: Start the Algorithm
Q : Quit (Close window)
