@x = common global i1 0
@y = common global i1 0
@a = common global i32 0
@b = common global i32* null

define i1 @main(i32 %args.tam, i8** %args) {
  entry:
    %args.length = alloca i32
    %0 = add i32 %args.tam, -1
    store i32 %0, i32* %args.length

    %x = alloca i32
    %y = alloca i32
    %a = alloca i1

    %1 = add i1 1, 0
    %2 = alloca i1    %3 = icmp eq i1 %1, 1
    br i1 %3, label %then0, label %else0

  then0:
    %4 = add i1 0, 0
    %5 = add i1 %4, 0
    store i1 %5, i1* %2
    br label %ifcont0

  else0:
    %6 = add i1 %1, 0
    store i1 %6, i1* %2
    br label %ifcont0

  ifcont0:
    %7 = load i1* %2    %8 = icmp eq i1 %7, 0
    br i1 %8, label %then1, label %else1

  then1:
    %9 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %10 = call i32 (i8*, ...)* @printf( i8* %9)
    br label %ifcont1

  else1:
    %11 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %12 = call i32 (i8*, ...)* @printf( i8* %11)
    br label %ifcont1

  ifcont1:
    ret i1 0
}

declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
