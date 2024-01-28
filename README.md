# Get Next Line (Mandatory + Bonus)

![get_next_line](https://github.com/ayogun/42-project-badges/blob/main/badges/get_next_linem.png?raw=true)

## Überblick

Dieses Repository enthält die Implementierung der Funktion get_next_line, die das Lesen von Zeilen aus einem Dateideskriptor erleichtert. Die Aufgabe erfordert die korrekte Verarbeitung von Datei- und Standardinput und stellt Anforderungen an die Handhabung des Buffering-Prozesses.

## Dateien und Verzeichnisstruktur

- `get_next_line.c`: Implementierung der get_next_line-Funktion.
- `get_next_line_utils.c`: Hilfsfunktionen für die get_next_line-Implementierung.
- `get_next_line.h`: Header-Datei mit der Funktionssignatur von get_next_line.

## Compiler-Flags

- `-D BUFFER_SIZE=n`: Definiert die Puffergröße für die read()-Funktion.
  - Die Puffergröße kann von Peer-Evaluatoren und der Moulinette modifiziert werden.
  - Das Projekt sollte sowohl mit als auch ohne das `-D BUFFER_SIZE` Flag kompilierbar sein.

## Funktion - get_next_line

### Prototyp

```c
char *get_next_line(int fd);
```

### Parameter

- `fd`: Der Dateideskriptor, von dem gelesen werden soll.

### Rückgabewert

- Lesen der Zeile: Korrektes Verhalten.
- `NULL`: Es gibt nichts mehr zu lesen oder ein Fehler ist aufgetreten.

### Externe Funktionen

- `read`, `malloc`, `free`

### Anforderungen

- Wiederholte Aufrufe von `get_next_line()` sollten es ermöglichen, eine Textdatei zeilenweise zu lesen.
- Die Funktion sollte sowohl mit Dateien als auch mit der Standardeingabe korrekt funktionieren.
- Die zurückgegebene Zeile sollte das abschließende `\n`-Zeichen enthalten, es sei denn, das Ende der Datei wurde erreicht und endet nicht mit einem `\n`.
- Die Header-Datei `get_next_line.h` muss mindestens den Prototyp der Funktion `get_next_line()` enthalten.
- Füge alle benötigten Hilfsfunktionen in der Datei `get_next_line_utils.c` hinzu.

## Besondere Anmerkungen

- Der Compileraufruf muss die Option `-D BUFFER_SIZE=n` enthalten, um die Puffergröße für `read()` zu definieren.
- Die Funktion hat ein undefiniertes Verhalten, wenn sich die Datei seit dem letzten Aufruf des Dateideskriptors geändert hat und `read()` das Dateiende nicht erreicht hat.
- Undefiniertes Verhalten tritt ebenfalls auf, wenn eine binäre Datei gelesen wird.
- Die Implementierung sollte effizient sein, unabhängig von der BUFFER_SIZE-Wertigkeit.

## Verbotene Elemente

- Die Verwendung von libft ist nicht erlaubt.
- `lseek()` ist untersagt.
- Globale Variablen sind untersagt.
