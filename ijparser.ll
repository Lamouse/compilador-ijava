
define i32 @main() {
  entry:
    %a = alloca i1
    %b = alloca i32*

    %0 = add i1 0, 0
    %1 = getelementptr i1* %a, i32 0
    store i1 %0, i1* %1

    %2 = add i32 3, 0
    %3 = call noalias i8* @malloc(i32 %2)
    %4 = bitcast i8* %3 to i32*
    store i32* %4, i32** %b

    %5 = add i32 1, 0
    %6 = add i32 3, 0
    %7 = load i32** %b
    %8 = getelementptr i32* %7, i32 %6
    store i32 %5, i32* %8

    %9 = load i1* %a
    %10 = add i1 %9, 0
    %11 = icmp eq i1 %10, 0
    br i1 %11, label %then0, label %else0

  then0:
    %12 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %13 = call i32 (i8*, ...)* @printf( i8* %12)
    br label %ifcont0

  else0:
    %14 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %15 = call i32 (i8*, ...)* @printf( i8* %14)
    br label %ifcont0

  ifcont0:

    %16 = add i32 1, 0
    ret i32 %16
}

declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
