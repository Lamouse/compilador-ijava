@a = common global i32 0

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %i = alloca i32

    %0 = add i32 0, 0
    %1 = getelementptr i32* %i, i32 0
    store i32 %0, i32* %1

    %2 = add i32 1, 0
    %3 = add i32 %2, 1
    %4 = getelementptr i8** %args, i32 %3
    %5 = load i8** %4
    %6 = call i32 (i8*)* @atoi(i8* %5)
    %7 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %8 = call i32 (i8*, ...)* @printf( i8* %7, i32 %6)

    %9 = sub nsw i32 %args.tam, 1
    %10 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %11 = call i32 (i8*, ...)* @printf( i8* %10, i32 %9)

    br label %cond0

  cond0:
    %12 = load i32* %i
    %13 = add i32 %12, 0
    %14 = sub nsw i32 %args.tam, 1
    %15 = icmp slt i32 %13, %14
    %16 = icmp eq i1 %15, 1
    br i1 %16, label %while0, label %whilecont0

  while0:

    %17 = load i32* %i
    %18 = add i32 %17, 0
    %19 = add i32 %18, 1
    %20 = getelementptr i8** %args, i32 %19
    %21 = load i8** %20
    %22 = call i32 (i8*)* @atoi(i8* %21)
    %23 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %24 = call i32 (i8*, ...)* @printf( i8* %23, i32 %22)

    %25 = load i32* %i
    %26 = add i32 %25, 0
    %27 = add i32 1, 0
    %28 = add i32 %26, %27
    %29 = getelementptr i32* %i, i32 0
    store i32 %28, i32* %29
    br label %cond0
  whilecont0:

    %30 = add i32 3, 0
    %31 = getelementptr i32* @a, i32 0
    store i32 %30, i32* %31

    %32 = load i32* @a
    %33 = add i32 %32, 0
    %34 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %35 = call i32 (i8*, ...)* @printf( i8* %34, i32 %33)

    %36 = load i32* @a
    %37 = add i32 %36, 0
    %38 = load i32* @a
    %39 = add i32 %38, 0
    %40 = call i32 @soma(i32 %39)
    %41 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %42 = call i32 (i8*, ...)* @printf( i8* %41, i32 %40)

    %43 = load i32* @a
    %44 = add i32 %43, 0
    %45 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %46 = call i32 (i8*, ...)* @printf( i8* %45, i32 %44)

    br label %return

  return:
    ret i32 0
}


define i32 @soma(i32 %x.temp) {
  entry:
    %x = alloca i32
    store i32 %x.temp, i32* %x
    %.return = alloca i32
    store i32 0, i32* %.return

    %0 = load i32* %x
    %1 = add i32 %0, 0
    %2 = add i32 1, 0
    %3 = add i32 %1, %2
    store i32 %3, i32* %.return
    br label %return

  return:
    %4 = load i32* %.return
    ret i32 %4
}


declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1)
declare i32 @atoi(i8*)
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
