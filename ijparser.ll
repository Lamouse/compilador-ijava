
define i32 @main() {
  entry:
    %a = alloca i32

    %0 = add i32 2, 0
    %1 = getelementptr i32* %a, i32 0
    store i32 %0, i32* %1

    %2 = load i32* %a    %3 = add i32 %2, 0
    %4 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %5 = call i32 (i8*, ...)* @printf( i8* %4, i32 %3)

    %6 = add i32 1, 0
    ret i32 %6
}

declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
