@a = common global i32* null

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %intarray = alloca i32*
    %boolarray = alloca i1*

    br label %return

  return:
    ret i32 0
}


define i32 @printintarray(i32** %intarray) {
  entry:
    %.return = alloca i32
    store i32 0, i32* %.return

    %0 = load i32** %intarray
    %1 = getelementptr inbounds i32* %0, i64 0
    %2 = load i32* %1
    %3 = ptrtoint i32 %2 to i32
    %4 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %5 = call i32 (i8*, ...)* @printf( i8* %4, i32 %3)

    %6 = add i32 1, 0
    %7 = add i32 1, 0
    %8 = add i32 %7, 1
    %9 = load i32** %intarray
    %10 = getelementptr i32* %9, i32 %8
    store i32 %6, i32* %10

    %11 = add i32 0, 0
    store i32 %11, i32* %.return
    br label %return

  return:
    %12 = load i32* %.return
    ret i32 %12
}


define i1 @printboolarray(i1** %boolarray) {
  entry:
    %.return = alloca i1
    store i1 0, i1* %.return

    %0 = load i1** %boolarray
    %1 = getelementptr inbounds i1* %0, i64 0
    %2 = bitcast i1* %1 to i32*
    %3 = load i32* %2
    %4 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %5 = call i32 (i8*, ...)* @printf( i8* %4, i32 %3)

    %6 = add i1 1, 0
    %7 = add i32 1, 0
    %8 = add i32 %7, 4
    %9 = load i1** %boolarray
    %10 = getelementptr i1* %9, i32 %8
    store i1 %6, i1* %10

    %11 = add i1 0, 0
    store i1 %11, i1* %.return
    br label %return

  return:
    %12 = load i1* %.return
    ret i1 %12
}


declare i32 @atoi(i8*)
declare noalias i8* @calloc(i64, i64)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
