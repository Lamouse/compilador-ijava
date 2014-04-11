lex ijparser.l
yacc --report='all' -d ljparser.y
gcc -o ljparser y.tab.c lex.yy.c -ll -ly
./ljparser < echo.java
