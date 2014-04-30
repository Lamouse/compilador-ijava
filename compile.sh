lex ijparser.l
yacc -d ijparser.y
gcc -o ijparser y.tab.c lex.yy.c -ll -ly
./ijparser -t < demo.java
./ijparser -t < demo2.java
./ijparser -t < demo3.java
./ijparser -t < demo4.java
