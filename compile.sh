lex ijparser.l
yacc -d ijparser.y
gcc -o ijparser y.tab.c lex.yy.c -ll -ly
#./ijparser -t -s < demo.java
#./ijparser -t < demo2.java
#./ijparser -s < demo5.java
#./ijparser < demo3.java
#./ijparser < demo4.java
