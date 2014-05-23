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
    %55 = alloca i1
    %56 = icmp eq i1 %54, 1
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
    %62 = alloca i1
    %63 = icmp eq i1 %61, 1
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

    %74 = add i1 1, 0
    %75 = alloca i1
    %76 = icmp eq i1 %74, 0
    br i1 %76, label %then4, label %else4

  then4:
    %77 = add i1 0, 0
    %78 = alloca i1
    %79 = icmp eq i1 %77, 0
    br i1 %79, label %then5, label %else5

  then5:
    %80 = add i1 0, 0
    %81 = add i1 %80, 0
    store i1 %81, i1* %78
    br label %ifcont5

  else5:
    %82 = add i1 %77, 0
    store i1 %82, i1* %78
    br label %ifcont5

  ifcont5:
    %83 = load i1* %78    %84 = add i1 %83, 0
    store i1 %84, i1* %75
    br label %ifcont4

  else4:
    %85 = add i1 %74, 0
    store i1 %85, i1* %75
    br label %ifcont4

  ifcont4:
    %86 = load i1* %75    %87 = icmp eq i1 %86, 0
    br i1 %87, label %then6, label %else6

  then6:
    %88 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %89 = call i32 (i8*, ...)* @printf( i8* %88)
    br label %ifcont6

  else6:
    %90 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %91 = call i32 (i8*, ...)* @printf( i8* %90)
    br label %ifcont6

  ifcont6:

    %92 = add i32 10, 0
    %93 = getelementptr i32* %i, i32 0
    store i32 %92, i32* %93

    br label %cond0

  cond0:
    %94 = load i32* %i
    %95 = add i32 %94, 0
    %96 = add i32 10, 0
    %97 = mul i32 %96, -1
    %98 = icmp sge i32 %95, %97
    %99 = icmp eq i1 %98, 1
    br i1 %99, label %while0, label %whilecont0

  while0:

    %100 = load i32* %i
    %101 = add i32 %100, 0
    %102 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %103 = call i32 (i8*, ...)* @printf( i8* %102, i32 %101)

    %104 = load i32* %i
    %105 = add i32 %104, 0
    %106 = add i32 0, 0
    %107 = icmp sgt i32 %105, %106
    %108 = icmp eq i1 %107, 1
    br i1 %108, label %then7, label %else7

  then7:

    %109 = load i32* %i
    %110 = add i32 %109, 0
    %111 = add i32 1, 0
    %112 = sub nsw i32 %110, %111
    %113 = getelementptr i32* %i, i32 0
    store i32 %112, i32* %113
    br label %ifcont7

  else7:

    %114 = load i32* %i
    %115 = add i32 %114, 0
    %116 = add i32 2, 0
    %117 = sub nsw i32 %115, %116
    %118 = getelementptr i32* %i, i32 0
    store i32 %117, i32* %118
    br label %ifcont7

  ifcont7:
    br label %cond0
  whilecont0:

    %119 = add i32 1, 0
    %120 = add i32 1, 0
    %121 = add i32 2, 0
    %122 = call i1 @compare(i32 %120, i32 %121)
    %123 = icmp eq i1 %122, 0
    br i1 %123, label %then8, label %else8

  then8:
    %124 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %125 = call i32 (i8*, ...)* @printf( i8* %124)
    br label %ifcont8

  else8:
    %126 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %127 = call i32 (i8*, ...)* @printf( i8* %126)
    br label %ifcont8

  ifcont8:

    %128 = add i32 2, 0
    %129 = add i32 2, 0
    %130 = add i32 1, 0
    %131 = add i32 1, 0
    %132 = add i32 %130, %131
    %133 = call i1 @compare(i32 %129, i32 %132)
    %134 = icmp eq i1 %133, 0
    br i1 %134, label %then9, label %else9

  then9:
    %135 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %136 = call i32 (i8*, ...)* @printf( i8* %135)
    br label %ifcont9

  else9:
    %137 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %138 = call i32 (i8*, ...)* @printf( i8* %137)
    br label %ifcont9

  ifcont9:

    %139 = add i32 10, 0
    %140 = add i32 10, 0
    %141 = add i32 20, 0
    %142 = add i32 15, 0
    %143 = sub nsw i32 %141, %142
    %144 = add i32 5, 0
    %145 = add i32 %143, %144
    %146 = call i1 @compare(i32 %140, i32 %145)
    %147 = icmp eq i1 %146, 0
    br i1 %147, label %then10, label %else10

  then10:
    %148 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %149 = call i32 (i8*, ...)* @printf( i8* %148)
    br label %ifcont10

  else10:
    %150 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %151 = call i32 (i8*, ...)* @printf( i8* %150)
    br label %ifcont10

  ifcont10:

    %152 = add i32 2, 0
    %153 = getelementptr i32* @d, i32 0
    store i32 %152, i32* %153

    %154 = add i32 1, 0
    %155 = call noalias i8* @malloc(i32 %154)
    %156 = bitcast i8* %155 to i32*
    store i32* %156, i32** @e
    store i32 %154, i32* @e.length

    %157 = add i32 3, 0
    %158 = add i32 0, 0
    %159 = load i32** @e
    %160 = getelementptr i32* %159, i32 %158
    store i32 %157, i32* %160

    %161 = add i32 0, 0
    %162 = load i32** @e
    %163 = getelementptr i32* %162, i32 %161
    %164 = load i32* %163
    %165 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %166 = call i32 (i8*, ...)* @printf( i8* %165, i32 %164)

    %167 = load i32* @e.length
    %168 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %169 = call i32 (i8*, ...)* @printf( i8* %168, i32 %167)

    %170 = add i32 6, 0
    %171 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %172 = call i32 (i8*, ...)* @printf( i8* %171, i32 %170)

    %173 = add i32 15, 0
    %174 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %175 = call i32 (i8*, ...)* @printf( i8* %174, i32 %173)

    %176 = add i32 2, 0
    %177 = add i32 2, 0
    %178 = add i32 5, 0
    %179 = add i32 %177, %178
    %180 = add i32 5, 0
    %181 = mul i32 %179, %180
    %182 = add i32 %176, %181
    %183 = getelementptr i32* %i, i32 0
    store i32 %182, i32* %183

    %184 = add i1 0, 0
    %185 = alloca i1
    %186 = icmp eq i1 %184, 0
    br i1 %186, label %then11, label %else11

  then11:
    %187 = add i1 1, 0
    %188 = alloca i1
    %189 = icmp eq i1 %187, 1
    br i1 %189, label %then12, label %else12

  then12:
    %190 = add i1 1, 0
    %191 = alloca i1
    %192 = icmp eq i1 %190, 0
    br i1 %192, label %then13, label %else13

  then13:
    %193 = add i1 0, 0
    %194 = add i1 %193, 0
    store i1 %194, i1* %191
    br label %ifcont13

  else13:
    %195 = add i1 %190, 0
    store i1 %195, i1* %191
    br label %ifcont13

  ifcont13:
    %196 = load i1* %191    %197 = add i1 %196, 0
    store i1 %197, i1* %188
    br label %ifcont12

  else12:
    %198 = add i1 %187, 0
    store i1 %198, i1* %188
    br label %ifcont12

  ifcont12:
    %199 = load i1* %188    %200 = add i1 %199, 0
    store i1 %200, i1* %185
    br label %ifcont11

  else11:
    %201 = add i1 %184, 0
    store i1 %201, i1* %185
    br label %ifcont11

  ifcont11:
    %202 = load i1* %185    %203 = getelementptr i1* %a, i32 0
    store i1 %202, i1* %203

    %204 = load i32* %i
    %205 = add i32 %204, 0
    %206 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %207 = call i32 (i8*, ...)* @printf( i8* %206, i32 %205)

    %208 = load i1* %a
    %209 = add i1 %208, 0
    %210 = icmp eq i1 %209, 0
    br i1 %210, label %then14, label %else14

  then14:
    %211 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %212 = call i32 (i8*, ...)* @printf( i8* %211)
    br label %ifcont14

  else14:
    %213 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %214 = call i32 (i8*, ...)* @printf( i8* %213)
    br label %ifcont14

  ifcont14:

    %215 = load i32* @d
    %216 = add i32 %215, 0
    ret i32 %216
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
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
