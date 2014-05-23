@d = common global i32 0
@e = common global i32* null
@e.length = common global i32 0

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %args.length = alloca i32
    %0 = add i32 %args.tam, -1
    store i32 %0, i32* %args.length

    %a = alloca i1
    %b = alloca i32*
    %b.length = alloca i32
    %c = alloca i1*
    %c.length = alloca i32
    %i = alloca i32

    %1 = add i1 0, 0
    %2 = getelementptr i1* %a, i32 0
    store i1 %1, i1* %2

    %3 = add i32 3, 0
    %4 = call noalias i8* @malloc(i32 %3)
    %5 = bitcast i8* %4 to i32*
    store i32* %5, i32** %b
    store i32 %3, i32* %b.length

    %6 = add i32 2, 0
    %7 = call noalias i8* @malloc(i32 %6)
    %8 = bitcast i8* %7 to i1*
    store i1* %8, i1** %c
    store i32 %6, i32* %c.length

    %9 = add i32 2, 0
    %10 = add i32 3, 0
    %11 = load i32** %b
    %12 = getelementptr i32* %11, i32 %10
    store i32 %9, i32* %12

    %13 = add i1 0, 0
    %14 = add i32 1, 0
    %15 = load i1** %c
    %16 = getelementptr i1* %15, i32 %14
    store i1 %13, i1* %16

    %17 = add i32 3, 0
    %18 = load i32** %b
    %19 = getelementptr i32* %18, i32 %17
    %20 = load i32* %19
    %21 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %22 = call i32 (i8*, ...)* @printf( i8* %21, i32 %20)

    %23 = add i32 1, 0
    %24 = load i1** %c
    %25 = getelementptr i1* %24, i32 %23
    %26 = load i1* %25
    %27 = icmp eq i1 %26, 0
    br i1 %27, label %then0, label %else0

  then0:
    %28 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %29 = call i32 (i8*, ...)* @printf( i8* %28)
    br label %ifcont0

  else0:
    %30 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %31 = call i32 (i8*, ...)* @printf( i8* %30)
    br label %ifcont0

  ifcont0:

    %32 = load i32* %b.length
    %33 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %34 = call i32 (i8*, ...)* @printf( i8* %33, i32 %32)

    %35 = load i32* %c.length
    %36 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %37 = call i32 (i8*, ...)* @printf( i8* %36, i32 %35)

    %38 = add i32 0, 0
    %39 = add i32 %38, 1
    %40 = getelementptr i8** %args, i32 %39
    %41 = load i8** %40
    %42 = call i64 @strtol(i8* %41, i8** null, i32 0)
    %43 = trunc i64 %42 to i32
    %44 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %45 = call i32 (i8*, ...)* @printf( i8* %44, i32 %43)

    %46 = add i32 1, 0
    %47 = add i32 %46, 1
    %48 = getelementptr i8** %args, i32 %47
    %49 = load i8** %48
    %50 = call i64 @strtol(i8* %49, i8** null, i32 0)
    %51 = trunc i64 %50 to i32
    %52 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %53 = call i32 (i8*, ...)* @printf( i8* %52, i32 %51)

    %54 = add i1 0, 0
    %55 = alloca i1    %56 = icmp eq i1 %54, 1
    br i1 %56, label %then1, label %else1

  then1:
    %57 = add i1 1, 0
    %58 = add i1 %57, 0
    store i1 %58, i1* %55
    br label %ifcont1

  else1:
    %59 = add i1 %54, 0
    store i1 %59, i1* %55
    br label %ifcont1

  ifcont1:
    %60 = load i1* %55    %61 = add i1 0, 0
    %62 = alloca i1    %63 = icmp eq i1 %61, 1
    br i1 %63, label %then2, label %else2

  then2:
    %64 = add i1 1, 0
    %65 = add i1 %64, 0
    store i1 %65, i1* %62
    br label %ifcont2

  else2:
    %66 = add i1 %61, 0
    store i1 %66, i1* %62
    br label %ifcont2

  ifcont2:
    %67 = load i1* %62    %68 = call i1 @a(i1 %67)
    %69 = icmp eq i1 %68, 0
    br i1 %69, label %then3, label %else3

  then3:
    %70 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %71 = call i32 (i8*, ...)* @printf( i8* %70)
    br label %ifcont3

  else3:
    %72 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %73 = call i32 (i8*, ...)* @printf( i8* %72)
    br label %ifcont3

  ifcont3:

    %74 = add i32 10, 0
    %75 = getelementptr i32* %i, i32 0
    store i32 %74, i32* %75

    br label %cond0

  cond0:
    %76 = load i32* %i
    %77 = add i32 %76, 0
    %78 = add i32 10, 0
    %79 = mul i32 %78, -1
    %80 = icmp sge i32 %77, %79
    %81 = icmp eq i1 %80, 1
    br i1 %81, label %while0, label %whilecont0

  while0:

    %82 = load i32* %i
    %83 = add i32 %82, 0
    %84 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %85 = call i32 (i8*, ...)* @printf( i8* %84, i32 %83)

    %86 = load i32* %i
    %87 = add i32 %86, 0
    %88 = add i32 0, 0
    %89 = icmp sgt i32 %87, %88
    %90 = icmp eq i1 %89, 1
    br i1 %90, label %then4, label %else4

  then4:

    %91 = load i32* %i
    %92 = add i32 %91, 0
    %93 = add i32 1, 0
    %94 = sub nsw i32 %92, %93
    %95 = getelementptr i32* %i, i32 0
    store i32 %94, i32* %95
    br label %ifcont4

  else4:

    %96 = load i32* %i
    %97 = add i32 %96, 0
    %98 = add i32 2, 0
    %99 = sub nsw i32 %97, %98
    %100 = getelementptr i32* %i, i32 0
    store i32 %99, i32* %100
    br label %ifcont4

  ifcont4:
    br label %cond0
  whilecont0:

    %101 = add i32 1, 0
    %102 = add i32 1, 0
    %103 = add i32 2, 0
    %104 = call i1 @compare(i32 %102, i32 %103)
    %105 = icmp eq i1 %104, 0
    br i1 %105, label %then5, label %else5

  then5:
    %106 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %107 = call i32 (i8*, ...)* @printf( i8* %106)
    br label %ifcont5

  else5:
    %108 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %109 = call i32 (i8*, ...)* @printf( i8* %108)
    br label %ifcont5

  ifcont5:

    %110 = add i32 2, 0
    %111 = add i32 2, 0
    %112 = add i32 1, 0
    %113 = add i32 1, 0
    %114 = add i32 %112, %113
    %115 = call i1 @compare(i32 %111, i32 %114)
    %116 = icmp eq i1 %115, 0
    br i1 %116, label %then6, label %else6

  then6:
    %117 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %118 = call i32 (i8*, ...)* @printf( i8* %117)
    br label %ifcont6

  else6:
    %119 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %120 = call i32 (i8*, ...)* @printf( i8* %119)
    br label %ifcont6

  ifcont6:

    %121 = add i32 10, 0
    %122 = add i32 10, 0
    %123 = add i32 20, 0
    %124 = add i32 15, 0
    %125 = sub nsw i32 %123, %124
    %126 = add i32 5, 0
    %127 = add i32 %125, %126
    %128 = call i1 @compare(i32 %122, i32 %127)
    %129 = icmp eq i1 %128, 0
    br i1 %129, label %then7, label %else7

  then7:
    %130 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %131 = call i32 (i8*, ...)* @printf( i8* %130)
    br label %ifcont7

  else7:
    %132 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %133 = call i32 (i8*, ...)* @printf( i8* %132)
    br label %ifcont7

  ifcont7:

    %134 = add i32 2, 0
    %135 = getelementptr i32* @d, i32 0
    store i32 %134, i32* %135

    %136 = add i32 1, 0
    %137 = call noalias i8* @malloc(i32 %136)
    %138 = bitcast i8* %137 to i32*
    store i32* %138, i32** @e
    store i32 %136, i32* @e.length

    %139 = add i32 3, 0
    %140 = add i32 0, 0
    %141 = load i32** @e
    %142 = getelementptr i32* %141, i32 %140
    store i32 %139, i32* %142

    %143 = add i32 0, 0
    %144 = load i32** @e
    %145 = getelementptr i32* %144, i32 %143
    %146 = load i32* %145
    %147 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %148 = call i32 (i8*, ...)* @printf( i8* %147, i32 %146)

    %149 = load i32* @e.length
    %150 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %151 = call i32 (i8*, ...)* @printf( i8* %150, i32 %149)

    %152 = add i32 6, 0
    %153 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %154 = call i32 (i8*, ...)* @printf( i8* %153, i32 %152)

    %155 = add i32 15, 0
    %156 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %157 = call i32 (i8*, ...)* @printf( i8* %156, i32 %155)

    %158 = load i32* @d
    %159 = add i32 %158, 0
    ret i32 %159
}


define i1 @a(i1 %y.temp) {
  entry:
    %y = alloca i1
    store i1 %y.temp, i1* %y

    %0 = load i1* %y
    %1 = add i1 %0, 0
    ret i1 %1
}


define i1 @compare(i32 %x.temp, i32 %y.temp) {
  entry:
    %x = alloca i32
    store i32 %x.temp, i32* %x
    %y = alloca i32
    store i32 %y.temp, i32* %y
    %a = alloca i1

    %0 = load i32* %x
    %1 = add i32 %0, 0
    %2 = load i32* %y
    %3 = add i32 %2, 0
    %4 = icmp eq i32 %1, %3
    %5 = icmp eq i1 %4, 1
    br i1 %5, label %then0, label %else0

  then0:

    %6 = add i1 1, 0
    %7 = getelementptr i1* %a, i32 0
    store i1 %6, i1* %7
    br label %ifcont0

  else0:

    %8 = add i1 0, 0
    %9 = getelementptr i1* %a, i32 0
    store i1 %8, i1* %9
    br label %ifcont0

  ifcont0:

    %10 = load i1* %a
    %11 = add i1 %10, 0
    ret i1 %11
}


declare i64 @strtol(i8*, i8**, i32)
declare i32 @atoi(i8*)
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
