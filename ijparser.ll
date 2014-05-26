@d = common global i32 0
@e = common global i32* null

define i32 @main(i32 %args.tam, i8** %args.temp) {
  entry:
    %args = alloca i8**
    %0 = mul i32 4, %args.tam
    %1 = call noalias i8* @malloc(i32 %0)
    %2 = bitcast i8* %1 to i8**
    store i8** %2, i8*** %args
    %3 = add i32 %args.tam, -1
    %4 = sext i32 %3 to i64
    %5 = inttoptr i64 %4 to i8*
    %6 = load i8*** %args
    %7 = getelementptr inbounds i8** %6, i32 0
    store i8* %5, i8** %7
    %8 = add i32 %args.tam, -1
    %9 = load i8*** %args
    %10 = getelementptr inbounds i8** %9, i32 1
    %11 = bitcast i8** %10 to i8*
    %12 = getelementptr inbounds i8** %args.temp, i32 1
    %13 = bitcast i8** %12 to i8*
    %14 = sub nsw i32 %args.tam, 1
    %15 = sext i32 %14 to i32
    %16 = mul i32 %15, 8
    call void @llvm.memcpy.p0i8.p0i8.i32(i8* %11, i8* %13, i32 %16, i32 8, i1 false)    %a = alloca i1
    %b = alloca i32*
    %c = alloca i1*
    %i = alloca i32

    %17 = add i32 3, 0
    %18 = add i32 %17, 1
    %19 = mul i32 %18, 4
    %20 = call noalias i8* @malloc(i32 %19)
    %21 = bitcast i8* %20 to i32*
    store i32 %17, i32* %21
    %22 = alloca i32*
    store i32* %21, i32** %22
    %23 = load i32** %22
    %24 = getelementptr inbounds i32* %23, i64 0
    %25 = load i32* %24
    %26 = ptrtoint i32 %25 to i32
    %27 = add i32 3, 0
    %28 = icmp sgt i32 %26, %27
    %29 = icmp eq i1 %28, 1
    br i1 %29, label %then0, label %else0

  then0:

    %30 = add i32 0, 0
    %31 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %32 = call i32 (i8*, ...)* @printf( i8* %31, i32 %30)
    br label %ifcont0

  else0:

    %33 = add i32 1, 0
    %34 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %35 = call i32 (i8*, ...)* @printf( i8* %34, i32 %33)
    br label %ifcont0

  ifcont0:

    %36 = add i32 3, 0
    %37 = add i32 %36, 1
    %38 = mul i32 %37, 4
    %39 = call noalias i8* @malloc(i32 %38)
    %40 = bitcast i8* %39 to i32*
    store i32 %36, i32* %40
    %41 = alloca i32*
    store i32* %40, i32** %41
    %42 = load i32** %41
    %43 = getelementptr inbounds i32* %42, i64 0
    %44 = load i32* %43
    %45 = ptrtoint i32 %44 to i32
    %46 = getelementptr i32* %i, i32 0
    store i32 %45, i32* %46

    %47 = load i32* %i
    %48 = add i32 %47, 0
    %49 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %50 = call i32 (i8*, ...)* @printf( i8* %49, i32 %48)

    %51 = load i8*** %args
    %52 = getelementptr inbounds i8** %51, i64 0
    %53 = load i8** %52
    %54 = ptrtoint i8* %53 to i32
    %55 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %56 = call i32 (i8*, ...)* @printf( i8* %55, i32 %54)

    %57 = add i32 5, 0
    %58 = add i32 %57, 1
    %59 = mul i32 %58, 4
    %60 = call noalias i8* @malloc(i32 %59)
    %61 = bitcast i8* %60 to i32*
    store i32 %57, i32* %61
    %62 = alloca i32*
    store i32* %61, i32** %62
    %63 = load i32** %62
store i32* %63, i32** %b

    %64 = add i32 15, 0
    %65 = add i32 %64, 1
    %66 = call noalias i8* @malloc(i32 %65)
    %67 = bitcast i8* %66 to i1*
    %68 = bitcast i1* %67 to i32*
    store i32 %64, i32* %68
    %69 = alloca i1*
    store i1* %67, i1** %69
    %70 = load i1** %69
store i1* %70, i1** %c

    %71 = add i32 4, 0
    %72 = add i32 0, 0
    %73 = add i32 %72, 1
    %74 = load i32** %b
    %75 = getelementptr i32* %74, i32 %73
    store i32 %71, i32* %75

    %76 = add i1 0, 0
    %77 = add i32 1, 0
    %78 = add i32 %77, 1
    %79 = load i1** %c
    %80 = getelementptr i1* %79, i32 %78
    store i1 %76, i1* %80

    %81 = call i32 @teste_array(i32** %b)
    %82 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %83 = call i32 (i8*, ...)* @printf( i8* %82, i32 %81)

    %84 = add i32 3, 0
    %85 = load i32** %b
    %86 = add i32 %84, 1
    %87 = getelementptr i32* %85, i32 %86
    %88 = load i32* %87
    %89 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %90 = call i32 (i8*, ...)* @printf( i8* %89, i32 %88)

    %91 = add i32 1, 0
    %92 = load i1** %c
    %93 = add i32 %91, 1
    %94 = getelementptr i1* %92, i32 %93
    %95 = load i1* %94
    %96 = icmp eq i1 %95, 0
    br i1 %96, label %then1, label %else1

  then1:
    %97 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %98 = call i32 (i8*, ...)* @printf( i8* %97)
    br label %ifcont1

  else1:
    %99 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %100 = call i32 (i8*, ...)* @printf( i8* %99)
    br label %ifcont1

  ifcont1:

    %101 = load i32** %b
    %102 = getelementptr inbounds i32* %101, i64 0
    %103 = load i32* %102
    %104 = ptrtoint i32 %103 to i32
    %105 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %106 = call i32 (i8*, ...)* @printf( i8* %105, i32 %104)

    %107 = load i1** %c
    %108 = getelementptr inbounds i1* %107, i64 0
    %109 = bitcast i1* %108 to i32*
    %110 = load i32* %109
    %111 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %112 = call i32 (i8*, ...)* @printf( i8* %111, i32 %110)

    %113 = add i32 0, 0
    %114 = load i8*** %args
    %115 = add i32 %113, 1
    %116 = getelementptr i8** %114, i32 %115
    %117 = load i8** %116
    %118 = call i64 @strtol(i8* %117, i8** null, i32 0)
    %119 = trunc i64 %118 to i32
    %120 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %121 = call i32 (i8*, ...)* @printf( i8* %120, i32 %119)

    %122 = add i32 1, 0
    %123 = load i8*** %args
    %124 = add i32 %122, 1
    %125 = getelementptr i8** %123, i32 %124
    %126 = load i8** %125
    %127 = call i64 @strtol(i8* %126, i8** null, i32 0)
    %128 = trunc i64 %127 to i32
    %129 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %130 = call i32 (i8*, ...)* @printf( i8* %129, i32 %128)

    %131 = add i1 0, 0
    %132 = alloca i1
    %133 = icmp eq i1 %131, 1
    br i1 %133, label %then2, label %else2

  then2:
    %134 = add i1 1, 0
    %135 = add i1 %134, 0
    store i1 %135, i1* %132
    br label %ifcont2

  else2:
    %136 = add i1 %131, 0
    store i1 %136, i1* %132
    br label %ifcont2

  ifcont2:
    %137 = load i1* %132
    %138 = add i1 0, 0
    %139 = alloca i1
    %140 = icmp eq i1 %138, 1
    br i1 %140, label %then3, label %else3

  then3:
    %141 = add i1 1, 0
    %142 = add i1 %141, 0
    store i1 %142, i1* %139
    br label %ifcont3

  else3:
    %143 = add i1 %138, 0
    store i1 %143, i1* %139
    br label %ifcont3

  ifcont3:
    %144 = load i1* %139
    %145 = call i1 @a(i1 %144)
    %146 = icmp eq i1 %145, 0
    br i1 %146, label %then4, label %else4

  then4:
    %147 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %148 = call i32 (i8*, ...)* @printf( i8* %147)
    br label %ifcont4

  else4:
    %149 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %150 = call i32 (i8*, ...)* @printf( i8* %149)
    br label %ifcont4

  ifcont4:

    %151 = add i1 1, 0
    %152 = alloca i1
    %153 = icmp eq i1 %151, 0
    br i1 %153, label %then5, label %else5

  then5:
    %154 = add i1 0, 0
    %155 = alloca i1
    %156 = icmp eq i1 %154, 0
    br i1 %156, label %then6, label %else6

  then6:
    %157 = add i1 0, 0
    %158 = add i1 %157, 0
    store i1 %158, i1* %155
    br label %ifcont6

  else6:
    %159 = add i1 %154, 0
    store i1 %159, i1* %155
    br label %ifcont6

  ifcont6:
    %160 = load i1* %155
    %161 = add i1 %160, 0
    store i1 %161, i1* %152
    br label %ifcont5

  else5:
    %162 = add i1 %151, 0
    store i1 %162, i1* %152
    br label %ifcont5

  ifcont5:
    %163 = load i1* %152
    %164 = icmp eq i1 %163, 0
    br i1 %164, label %then7, label %else7

  then7:
    %165 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %166 = call i32 (i8*, ...)* @printf( i8* %165)
    br label %ifcont7

  else7:
    %167 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %168 = call i32 (i8*, ...)* @printf( i8* %167)
    br label %ifcont7

  ifcont7:

    %169 = add i32 10, 0
    %170 = getelementptr i32* %i, i32 0
    store i32 %169, i32* %170

    br label %cond0

  cond0:
    %171 = load i32* %i
    %172 = add i32 %171, 0
    %173 = add i32 10, 0
    %174 = mul i32 %173, -1
    %175 = icmp sge i32 %172, %174
    %176 = icmp eq i1 %175, 1
    br i1 %176, label %while0, label %whilecont0

  while0:

    %177 = load i32* %i
    %178 = add i32 %177, 0
    %179 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %180 = call i32 (i8*, ...)* @printf( i8* %179, i32 %178)

    %181 = load i32* %i
    %182 = add i32 %181, 0
    %183 = add i32 0, 0
    %184 = icmp sgt i32 %182, %183
    %185 = icmp eq i1 %184, 1
    br i1 %185, label %then8, label %else8

  then8:

    %186 = load i32* %i
    %187 = add i32 %186, 0
    %188 = add i32 1, 0
    %189 = sub nsw i32 %187, %188
    %190 = getelementptr i32* %i, i32 0
    store i32 %189, i32* %190
    br label %ifcont8

  else8:

    %191 = load i32* %i
    %192 = add i32 %191, 0
    %193 = add i32 2, 0
    %194 = sub nsw i32 %192, %193
    %195 = getelementptr i32* %i, i32 0
    store i32 %194, i32* %195
    br label %ifcont8

  ifcont8:
    br label %cond0
  whilecont0:

    %196 = add i32 1, 0
    %197 = add i32 1, 0
    %198 = add i32 2, 0
    %199 = call i1 @compare(i32 %197, i32 %198)
    %200 = icmp eq i1 %199, 0
    br i1 %200, label %then9, label %else9

  then9:
    %201 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %202 = call i32 (i8*, ...)* @printf( i8* %201)
    br label %ifcont9

  else9:
    %203 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %204 = call i32 (i8*, ...)* @printf( i8* %203)
    br label %ifcont9

  ifcont9:

    %205 = add i32 2, 0
    %206 = add i32 2, 0
    %207 = add i32 1, 0
    %208 = add i32 1, 0
    %209 = add i32 %207, %208
    %210 = call i1 @compare(i32 %206, i32 %209)
    %211 = icmp eq i1 %210, 0
    br i1 %211, label %then10, label %else10

  then10:
    %212 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %213 = call i32 (i8*, ...)* @printf( i8* %212)
    br label %ifcont10

  else10:
    %214 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %215 = call i32 (i8*, ...)* @printf( i8* %214)
    br label %ifcont10

  ifcont10:

    %216 = add i32 10, 0
    %217 = add i32 10, 0
    %218 = add i32 20, 0
    %219 = add i32 15, 0
    %220 = sub nsw i32 %218, %219
    %221 = add i32 5, 0
    %222 = add i32 %220, %221
    %223 = call i1 @compare(i32 %217, i32 %222)
    %224 = icmp eq i1 %223, 0
    br i1 %224, label %then11, label %else11

  then11:
    %225 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %226 = call i32 (i8*, ...)* @printf( i8* %225)
    br label %ifcont11

  else11:
    %227 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %228 = call i32 (i8*, ...)* @printf( i8* %227)
    br label %ifcont11

  ifcont11:

    %229 = add i32 2, 0
    %230 = getelementptr i32* @d, i32 0
    store i32 %229, i32* %230

    %231 = add i32 1, 0
    %232 = add i32 %231, 1
    %233 = mul i32 %232, 4
    %234 = call noalias i8* @malloc(i32 %233)
    %235 = bitcast i8* %234 to i32*
    store i32 %231, i32* %235
    %236 = alloca i32*
    store i32* %235, i32** %236
    %237 = load i32** %236
store i32* %237, i32** @e

    %238 = add i32 3, 0
    %239 = add i32 0, 0
    %240 = add i32 %239, 1
    %241 = load i32** @e
    %242 = getelementptr i32* %241, i32 %240
    store i32 %238, i32* %242

    %243 = add i32 0, 0
    %244 = load i32** @e
    %245 = add i32 %243, 1
    %246 = getelementptr i32* %244, i32 %245
    %247 = load i32* %246
    %248 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %249 = call i32 (i8*, ...)* @printf( i8* %248, i32 %247)

    %250 = load i32** @e
    %251 = getelementptr inbounds i32* %250, i64 0
    %252 = load i32* %251
    %253 = ptrtoint i32 %252 to i32
    %254 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %255 = call i32 (i8*, ...)* @printf( i8* %254, i32 %253)

    %256 = add i32 6, 0
    %257 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %258 = call i32 (i8*, ...)* @printf( i8* %257, i32 %256)

    %259 = add i32 15, 0
    %260 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %261 = call i32 (i8*, ...)* @printf( i8* %260, i32 %259)

    %262 = add i32 2, 0
    %263 = add i32 2, 0
    %264 = add i32 5, 0
    %265 = add i32 %263, %264
    %266 = add i32 5, 0
    %267 = mul i32 %265, %266
    %268 = add i32 %262, %267
    %269 = getelementptr i32* %i, i32 0
    store i32 %268, i32* %269

    %270 = add i1 0, 0
    %271 = alloca i1
    %272 = icmp eq i1 %270, 0
    br i1 %272, label %then12, label %else12

  then12:
    %273 = add i1 1, 0
    %274 = alloca i1
    %275 = icmp eq i1 %273, 1
    br i1 %275, label %then13, label %else13

  then13:
    %276 = add i1 1, 0
    %277 = alloca i1
    %278 = icmp eq i1 %276, 0
    br i1 %278, label %then14, label %else14

  then14:
    %279 = add i1 0, 0
    %280 = add i1 %279, 0
    store i1 %280, i1* %277
    br label %ifcont14

  else14:
    %281 = add i1 %276, 0
    store i1 %281, i1* %277
    br label %ifcont14

  ifcont14:
    %282 = load i1* %277
    %283 = add i1 %282, 0
    store i1 %283, i1* %274
    br label %ifcont13

  else13:
    %284 = add i1 %273, 0
    store i1 %284, i1* %274
    br label %ifcont13

  ifcont13:
    %285 = load i1* %274
    %286 = add i1 %285, 0
    store i1 %286, i1* %271
    br label %ifcont12

  else12:
    %287 = add i1 %270, 0
    store i1 %287, i1* %271
    br label %ifcont12

  ifcont12:
    %288 = load i1* %271
    %289 = getelementptr i1* %a, i32 0
    store i1 %288, i1* %289

    %290 = load i32* %i
    %291 = add i32 %290, 0
    %292 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %293 = call i32 (i8*, ...)* @printf( i8* %292, i32 %291)

    %294 = load i1* %a
    %295 = add i1 %294, 0
    %296 = icmp eq i1 %295, 0
    br i1 %296, label %then15, label %else15

  then15:
    %297 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %298 = call i32 (i8*, ...)* @printf( i8* %297)
    br label %ifcont15

  else15:
    %299 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %300 = call i32 (i8*, ...)* @printf( i8* %299)
    br label %ifcont15

  ifcont15:

    %301 = add i32 0, 0
    ret i32 %301
}


define i32 @teste_array(i32** %a) {
  entry:

    %0 = load i32** %a
    %1 = getelementptr inbounds i32* %0, i64 0
    %2 = load i32* %1
    %3 = ptrtoint i32 %2 to i32
    %4 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %5 = call i32 (i8*, ...)* @printf( i8* %4, i32 %3)

    %6 = add i32 0, 0
    %7 = load i32** %a
    %8 = add i32 %6, 1
    %9 = getelementptr i32* %7, i32 %8
    %10 = load i32* %9
    ret i32 %10
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


declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1)
declare i64 @strtol(i8*, i8**, i32)
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
