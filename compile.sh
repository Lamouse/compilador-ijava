lex ijscanner.l
gcc -o ijscanner lex.yy.c -ll
./ijscanner < echo.java