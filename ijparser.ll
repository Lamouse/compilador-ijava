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

    %57 = add i32 4, 0
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

    %71 = add i32 3, 0
    %72 = add i32 3, 0
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

    %81 = add i32 3, 0
    %82 = load i32** %b
    %83 = add i32 %81, 1
    %84 = getelementptr i32* %82, i32 %83
    %85 = load i32* %84
    %86 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %87 = call i32 (i8*, ...)* @printf( i8* %86, i32 %85)

    %88 = add i32 1, 0
    %89 = load i1** %c
    %90 = add i32 %88, 1
    %91 = getelementptr i1* %89, i32 %90
    %92 = load i1* %91
    %93 = icmp eq i1 %92, 0
    br i1 %93, label %then1, label %else1

  then1:
    %94 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %95 = call i32 (i8*, ...)* @printf( i8* %94)
    br label %ifcont1

  else1:
    %96 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %97 = call i32 (i8*, ...)* @printf( i8* %96)
    br label %ifcont1

  ifcont1:

    %98 = load i32** %b
    %99 = getelementptr inbounds i32* %98, i64 0
    %100 = load i32* %99
    %101 = ptrtoint i32 %100 to i32
    %102 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %103 = call i32 (i8*, ...)* @printf( i8* %102, i32 %101)

    %104 = load i1** %c
    %105 = getelementptr inbounds i1* %104, i64 0
    %106 = bitcast i1* %105 to i32*
    %107 = load i32* %106
    %108 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %109 = call i32 (i8*, ...)* @printf( i8* %108, i32 %107)

    %110 = add i32 0, 0
    %111 = load i8*** %args
    %112 = add i32 %110, 1
    %113 = getelementptr i8** %111, i32 %112
    %114 = load i8** %113
    %115 = call i64 @strtol(i8* %114, i8** null, i32 0)
    %116 = trunc i64 %115 to i32
    %117 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %118 = call i32 (i8*, ...)* @printf( i8* %117, i32 %116)

    %119 = add i32 1, 0
    %120 = load i8*** %args
    %121 = add i32 %119, 1
    %122 = getelementptr i8** %120, i32 %121
    %123 = load i8** %122
    %124 = call i64 @strtol(i8* %123, i8** null, i32 0)
    %125 = trunc i64 %124 to i32
    %126 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %127 = call i32 (i8*, ...)* @printf( i8* %126, i32 %125)

    %128 = add i1 0, 0
    %129 = alloca i1
    %130 = icmp eq i1 %128, 1
    br i1 %130, label %then2, label %else2

  then2:
    %131 = add i1 1, 0
    %132 = add i1 %131, 0
    store i1 %132, i1* %129
    br label %ifcont2

  else2:
    %133 = add i1 %128, 0
    store i1 %133, i1* %129
    br label %ifcont2

  ifcont2:
    %134 = load i1* %129
    %135 = add i1 0, 0
    %136 = alloca i1
    %137 = icmp eq i1 %135, 1
    br i1 %137, label %then3, label %else3

  then3:
    %138 = add i1 1, 0
    %139 = add i1 %138, 0
    store i1 %139, i1* %136
    br label %ifcont3

  else3:
    %140 = add i1 %135, 0
    store i1 %140, i1* %136
    br label %ifcont3

  ifcont3:
    %141 = load i1* %136
    %142 = call i1 @a(i1 %141)
    %143 = icmp eq i1 %142, 0
    br i1 %143, label %then4, label %else4

  then4:
    %144 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %145 = call i32 (i8*, ...)* @printf( i8* %144)
    br label %ifcont4

  else4:
    %146 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %147 = call i32 (i8*, ...)* @printf( i8* %146)
    br label %ifcont4

  ifcont4:

    %148 = add i1 1, 0
    %149 = alloca i1
    %150 = icmp eq i1 %148, 0
    br i1 %150, label %then5, label %else5

  then5:
    %151 = add i1 0, 0
    %152 = alloca i1
    %153 = icmp eq i1 %151, 0
    br i1 %153, label %then6, label %else6

  then6:
    %154 = add i1 0, 0
    %155 = add i1 %154, 0
    store i1 %155, i1* %152
    br label %ifcont6

  else6:
    %156 = add i1 %151, 0
    store i1 %156, i1* %152
    br label %ifcont6

  ifcont6:
    %157 = load i1* %152
    %158 = add i1 %157, 0
    store i1 %158, i1* %149
    br label %ifcont5

  else5:
    %159 = add i1 %148, 0
    store i1 %159, i1* %149
    br label %ifcont5

  ifcont5:
    %160 = load i1* %149
    %161 = icmp eq i1 %160, 0
    br i1 %161, label %then7, label %else7

  then7:
    %162 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %163 = call i32 (i8*, ...)* @printf( i8* %162)
    br label %ifcont7

  else7:
    %164 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %165 = call i32 (i8*, ...)* @printf( i8* %164)
    br label %ifcont7

  ifcont7:

    %166 = add i32 10, 0
    %167 = getelementptr i32* %i, i32 0
    store i32 %166, i32* %167

    br label %cond0

  cond0:
    %168 = load i32* %i
    %169 = add i32 %168, 0
    %170 = add i32 10, 0
    %171 = mul i32 %170, -1
    %172 = icmp sge i32 %169, %171
    %173 = icmp eq i1 %172, 1
    br i1 %173, label %while0, label %whilecont0

  while0:

    %174 = load i32* %i
    %175 = add i32 %174, 0
    %176 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %177 = call i32 (i8*, ...)* @printf( i8* %176, i32 %175)

    %178 = load i32* %i
    %179 = add i32 %178, 0
    %180 = add i32 0, 0
    %181 = icmp sgt i32 %179, %180
    %182 = icmp eq i1 %181, 1
    br i1 %182, label %then8, label %else8

  then8:

    %183 = load i32* %i
    %184 = add i32 %183, 0
    %185 = add i32 1, 0
    %186 = sub nsw i32 %184, %185
    %187 = getelementptr i32* %i, i32 0
    store i32 %186, i32* %187
    br label %ifcont8

  else8:

    %188 = load i32* %i
    %189 = add i32 %188, 0
    %190 = add i32 2, 0
    %191 = sub nsw i32 %189, %190
    %192 = getelementptr i32* %i, i32 0
    store i32 %191, i32* %192
    br label %ifcont8

  ifcont8:
    br label %cond0
  whilecont0:

    %193 = add i32 1, 0
    %194 = add i32 1, 0
    %195 = add i32 2, 0
    %196 = call i1 @compare(i32 %194, i32 %195)
    %197 = icmp eq i1 %196, 0
    br i1 %197, label %then9, label %else9

  then9:
    %198 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %199 = call i32 (i8*, ...)* @printf( i8* %198)
    br label %ifcont9

  else9:
    %200 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %201 = call i32 (i8*, ...)* @printf( i8* %200)
    br label %ifcont9

  ifcont9:

    %202 = add i32 2, 0
    %203 = add i32 2, 0
    %204 = add i32 1, 0
    %205 = add i32 1, 0
    %206 = add i32 %204, %205
    %207 = call i1 @compare(i32 %203, i32 %206)
    %208 = icmp eq i1 %207, 0
    br i1 %208, label %then10, label %else10

  then10:
    %209 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %210 = call i32 (i8*, ...)* @printf( i8* %209)
    br label %ifcont10

  else10:
    %211 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %212 = call i32 (i8*, ...)* @printf( i8* %211)
    br label %ifcont10

  ifcont10:

    %213 = add i32 10, 0
    %214 = add i32 10, 0
    %215 = add i32 20, 0
    %216 = add i32 15, 0
    %217 = sub nsw i32 %215, %216
    %218 = add i32 5, 0
    %219 = add i32 %217, %218
    %220 = call i1 @compare(i32 %214, i32 %219)
    %221 = icmp eq i1 %220, 0
    br i1 %221, label %then11, label %else11

  then11:
    %222 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %223 = call i32 (i8*, ...)* @printf( i8* %222)
    br label %ifcont11

  else11:
    %224 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %225 = call i32 (i8*, ...)* @printf( i8* %224)
    br label %ifcont11

  ifcont11:

    %226 = add i32 2, 0
    %227 = getelementptr i32* @d, i32 0
    store i32 %226, i32* %227

    %228 = add i32 1, 0
    %229 = add i32 %228, 1
    %230 = mul i32 %229, 4
    %231 = call noalias i8* @malloc(i32 %230)
    %232 = bitcast i8* %231 to i32*
    store i32 %228, i32* %232
    %233 = alloca i32*
    store i32* %232, i32** %233
    %234 = load i32** %233
store i32* %234, i32** @e

    %235 = add i32 3, 0
    %236 = add i32 0, 0
    %237 = add i32 %236, 1
    %238 = load i32** @e
    %239 = getelementptr i32* %238, i32 %237
    store i32 %235, i32* %239

    %240 = add i32 0, 0
    %241 = load i32** @e
    %242 = add i32 %240, 1
    %243 = getelementptr i32* %241, i32 %242
    %244 = load i32* %243
    %245 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %246 = call i32 (i8*, ...)* @printf( i8* %245, i32 %244)

    %247 = load i32** @e
    %248 = getelementptr inbounds i32* %247, i64 0
    %249 = load i32* %248
    %250 = ptrtoint i32 %249 to i32
    %251 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %252 = call i32 (i8*, ...)* @printf( i8* %251, i32 %250)

    %253 = add i32 6, 0
    %254 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %255 = call i32 (i8*, ...)* @printf( i8* %254, i32 %253)

    %256 = add i32 15, 0
    %257 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %258 = call i32 (i8*, ...)* @printf( i8* %257, i32 %256)

    %259 = add i32 2, 0
    %260 = add i32 2, 0
    %261 = add i32 5, 0
    %262 = add i32 %260, %261
    %263 = add i32 5, 0
    %264 = mul i32 %262, %263
    %265 = add i32 %259, %264
    %266 = getelementptr i32* %i, i32 0
    store i32 %265, i32* %266

    %267 = add i1 0, 0
    %268 = alloca i1
    %269 = icmp eq i1 %267, 0
    br i1 %269, label %then12, label %else12

  then12:
    %270 = add i1 1, 0
    %271 = alloca i1
    %272 = icmp eq i1 %270, 1
    br i1 %272, label %then13, label %else13

  then13:
    %273 = add i1 1, 0
    %274 = alloca i1
    %275 = icmp eq i1 %273, 0
    br i1 %275, label %then14, label %else14

  then14:
    %276 = add i1 0, 0
    %277 = add i1 %276, 0
    store i1 %277, i1* %274
    br label %ifcont14

  else14:
    %278 = add i1 %273, 0
    store i1 %278, i1* %274
    br label %ifcont14

  ifcont14:
    %279 = load i1* %274
    %280 = add i1 %279, 0
    store i1 %280, i1* %271
    br label %ifcont13

  else13:
    %281 = add i1 %270, 0
    store i1 %281, i1* %271
    br label %ifcont13

  ifcont13:
    %282 = load i1* %271
    %283 = add i1 %282, 0
    store i1 %283, i1* %268
    br label %ifcont12

  else12:
    %284 = add i1 %267, 0
    store i1 %284, i1* %268
    br label %ifcont12

  ifcont12:
    %285 = load i1* %268
    %286 = getelementptr i1* %a, i32 0
    store i1 %285, i1* %286

    %287 = load i32* %i
    %288 = add i32 %287, 0
    %289 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %290 = call i32 (i8*, ...)* @printf( i8* %289, i32 %288)

    %291 = load i1* %a
    %292 = add i1 %291, 0
    %293 = icmp eq i1 %292, 0
    br i1 %293, label %then15, label %else15

  then15:
    %294 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %295 = call i32 (i8*, ...)* @printf( i8* %294)
    br label %ifcont15

  else15:
    %296 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %297 = call i32 (i8*, ...)* @printf( i8* %296)
    br label %ifcont15

  ifcont15:

    %298 = add i32 0, 0
    ret i32 %298
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
