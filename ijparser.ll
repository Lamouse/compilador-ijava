
define i32 @main() {
  entry:
    %a = alloca i1
    %b = alloca i32*
    %c = alloca i1*

    %0 = add i1 0, 0
    %1 = getelementptr i1* %a, i32 0
    store i1 %0, i1* %1

    %2 = add i32 3, 0
    %3 = call noalias i8* @malloc(i32 %2)
    %4 = bitcast i8* %3 to i32*
    store i32* %4, i32** %b

    %5 = add i32 2, 0
    %6 = call noalias i8* @malloc(i32 %5)
    %7 = bitcast i8* %6 to i1*
    store i1* %7, i1** %c

    %8 = add i32 2, 0
    %9 = add i32 3, 0
    %10 = load i32** %b
    %11 = getelementptr i32* %10, i32 %9
    store i32 %8, i32* %11

    %12 = add i1 0, 0
    %13 = add i32 1, 0
    %14 = load i1** %c
    %15 = getelementptr i1* %14, i32 %13
    store i1 %12, i1* %15

    %16 = add i32 3, 0
    %17 = load i32** %b
    %18 = getelementptr i32* %17, i32 %16
    %19 = load i32* %18
    %20 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %21 = call i32 (i8*, ...)* @printf( i8* %20, i32 %19)

    %22 = add i32 1, 0
    %23 = load i1** %c
    %24 = getelementptr i1* %23, i32 %22
    %25 = load i1* %24
    %26 = icmp eq i1 %25, 0
    br i1 %26, label %then0, label %else0

  then0:
    %27 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %28 = call i32 (i8*, ...)* @printf( i8* %27)
    br label %ifcont0

  else0:
    %29 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %30 = call i32 (i8*, ...)* @printf( i8* %29)
    br label %ifcont0

  ifcont0:

    %31 = add i32 1, 0
    ret i32 %31
}

declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
