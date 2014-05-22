@x = common global i1 0
@y = common global i1 0
@a = common global i32 0
@b = common global i32* null

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %args.length = alloca i32
    %0 = add i32 %args.tam, -1
    store i32 %0, i32* %args.length

    %x = alloca i32*
    %y = alloca i32*

    %1 = add i32 10, 0
    %2 = add i32 5, 0
    %3 = sdiv i32 %1, %2
    %4 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %5 = call i32 (i8*, ...)* @printf( i8* %4, i32 %3)
    %6 = add i32 1, 0
    ret i32 %6
}

declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
