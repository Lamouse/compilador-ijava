lex ijcompiler.l
yacc -d -v ijcompiler.y
gcc -o ijcompiler y.tab.c lex.yy.c -ll -ly
#./ijparser < demo7.java
#./ijparser -t < demo.java
#./ijparser -t < demo6.java
#./ijparser -t < demo2.java
#./ijparser -s < demo5.java
#./ijparser < demo3.java
#./ijparser < demo4.java
#./ijparser < demo8.java
#./ijparser -t < demo9.java
