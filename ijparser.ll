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

    %1 = add i32 2, 0
    %2 = mul i32 %1, -1
    %3 = add i32 1, 0
    %4 = mul i32 %3, -1
    %5 = icmp slt i32 %2, %4
    %6 = icmp eq i1 %5, 0
    br i1 %6, label %then0, label %else0

  then0:
    %7 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %8 = call i32 (i8*, ...)* @printf( i8* %7)
    br label %ifcont0

  else0:
    %9 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %10 = call i32 (i8*, ...)* @printf( i8* %9)
    br label %ifcont0

  ifcont0:
    %11 = add i32 1, 0
    ret i32 %11
}

declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
