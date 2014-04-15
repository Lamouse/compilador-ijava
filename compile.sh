lex ijparser.l
yacc -d ijparser.y
gcc -o ijparser y.tab.c lex.yy.c -ll -ly
./ijparser < demo.java
./ijparser < demo2.java
./ijparser < demo3.java
