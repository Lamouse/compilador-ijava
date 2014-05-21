@x = common global i1 0
@y = common global i1 0
@a = common global i32 0
@b = common global i32* null

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %args.length = alloca i32
    %0 = add i32 %args.tam, -1
    store i32 %0, i32* %args.length

    %x = alloca i32
    %y = alloca i32
    %a = alloca i1

    %1 = add i32 100, 0
    %2 = add i32 10, 0
    %3 = sub nsw i32 %1, %2
    %4 = add i32 10, 0
    %5 = add i32 %3, %4
    %6 = add i32 10, 0
    %7 = sub nsw i32 %5, %6
    %8 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %9 = call i32 (i8*, ...)* @printf( i8* %8, i32 %7)
    %10 = add i32 1, 0
    ret i32 %10
}

declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
