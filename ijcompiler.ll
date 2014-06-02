@a = common global i32 0
@y = common global i1 0

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %i = alloca i32

    %0 = load i32* %i
    %1 = add i32 %0, 0
    %2 = add i32 1, 0
    %3 = add i32 %1, %2
    %4 = getelementptr i32* %i, i32 0
    store i32 %3, i32* %4

    br label %return

  return:
    ret i32 0
}


declare i32 @atoi(i8*)
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
