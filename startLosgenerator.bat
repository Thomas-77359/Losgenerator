echo off
REM Erzeugt ein Los
REM Vorbedingung: Es muss ein Textfile �bergeben welche im selben Folder sein muss.
REM Die Zahlen k�nnen direkt per Copy&Paste aus der Calc-Tabelle �bernommen werden.
REM Sie sind dann und m�ssen auch Tab-getrennt sein: 	1	8	15	22	29	37
REM Es muss die angestrebte mittlere Distanz als Fliesskommazahl angegeben werden.
REM Als minimale Anfangszahl kann hier 12.0 verwendet werden.
REM Die Anzahl Tipps kann 14 und mehr betragen. 
REM Das Resultat kann direkt aus dem cmd kopiert werden.
REM Mit Rechtsklick auf den Blackscreen kann "Mark" ausgew�hlt werden, mit dem Cursor k�nnen dann die Zahlen 
REM ausgew�hlt werden, mit Druck auf die Enter-Taste werden sie ins Clipboard kopiert.
REM Mit Ctrl+V k�nnen dann die Zahlen direkt in die Tabelle eingef�gt werden, sie sind Space-getrennt.

Losgenerator.exe Loszahlen.cvs 13.5