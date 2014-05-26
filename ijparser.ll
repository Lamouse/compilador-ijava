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
    %65 = add i32 %64, 4
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
    %78 = add i32 %77, 4
    %79 = load i1** %c
    %80 = getelementptr i1* %79, i32 %78
    store i1 %76, i1* %80

    %81 = load i1** %c
    %82 = getelementptr inbounds i1* %81, i64 0
    %83 = bitcast i1* %82 to i32*
    %84 = load i32* %83
    %85 = add i32 1, 0
    %86 = sub nsw i32 %84, %85
    %87 = getelementptr i32* %i, i32 0
    store i32 %86, i32* %87

    br label %cond0

  cond0:
    %88 = load i32* %i
    %89 = add i32 %88, 0
    %90 = add i32 3, 0
    %91 = icmp sge i32 %89, %90
    %92 = icmp eq i1 %91, 1
    br i1 %92, label %while0, label %whilecont0

  while0:

    %93 = add i1 1, 0
    %94 = load i32* %i
    %95 = add i32 %94, 0
    %96 = add i32 %95, 4
    %97 = load i1** %c
    %98 = getelementptr i1* %97, i32 %96
    store i1 %93, i1* %98

    %99 = load i32* %i
    %100 = add i32 %99, 0
    %101 = load i1** %c
    %102 = add i32 %100, 4
    %103 = getelementptr i1* %101, i32 %102
    %104 = load i1* %103
    %105 = icmp eq i1 %104, 0
    br i1 %105, label %then1, label %else1

  then1:
    %106 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %107 = call i32 (i8*, ...)* @printf( i8* %106)
    br label %ifcont1

  else1:
    %108 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %109 = call i32 (i8*, ...)* @printf( i8* %108)
    br label %ifcont1

  ifcont1:

    %110 = load i32* %i
    %111 = add i32 %110, 0
    %112 = add i32 1, 0
    %113 = sub nsw i32 %111, %112
    %114 = getelementptr i32* %i, i32 0
    store i32 %113, i32* %114
    br label %cond0
  whilecont0:

    %115 = load i1** %c
    %116 = getelementptr inbounds i1* %115, i64 0
    %117 = bitcast i1* %116 to i32*
    %118 = load i32* %117
    %119 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %120 = call i32 (i8*, ...)* @printf( i8* %119, i32 %118)

    %121 = call i1 @teste_array(i1** %c)
    %122 = icmp eq i1 %121, 0
    br i1 %122, label %then2, label %else2

  then2:
    %123 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %124 = call i32 (i8*, ...)* @printf( i8* %123)
    br label %ifcont2

  else2:
    %125 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %126 = call i32 (i8*, ...)* @printf( i8* %125)
    br label %ifcont2

  ifcont2:

    %127 = add i32 3, 0
    %128 = load i32** %b
    %129 = add i32 %127, 1
    %130 = getelementptr i32* %128, i32 %129
    %131 = load i32* %130
    %132 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %133 = call i32 (i8*, ...)* @printf( i8* %132, i32 %131)

    %134 = add i32 1, 0
    %135 = load i1** %c
    %136 = add i32 %134, 4
    %137 = getelementptr i1* %135, i32 %136
    %138 = load i1* %137
    %139 = icmp eq i1 %138, 0
    br i1 %139, label %then3, label %else3

  then3:
    %140 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %141 = call i32 (i8*, ...)* @printf( i8* %140)
    br label %ifcont3

  else3:
    %142 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %143 = call i32 (i8*, ...)* @printf( i8* %142)
    br label %ifcont3

  ifcont3:

    %144 = load i32** %b
    %145 = getelementptr inbounds i32* %144, i64 0
    %146 = load i32* %145
    %147 = ptrtoint i32 %146 to i32
    %148 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %149 = call i32 (i8*, ...)* @printf( i8* %148, i32 %147)

    %150 = load i1** %c
    %151 = getelementptr inbounds i1* %150, i64 0
    %152 = bitcast i1* %151 to i32*
    %153 = load i32* %152
    %154 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %155 = call i32 (i8*, ...)* @printf( i8* %154, i32 %153)

    %156 = add i32 0, 0
    %157 = load i8*** %args
    %158 = add i32 %156, 1
    %159 = getelementptr i8** %157, i32 %158
    %160 = load i8** %159
    %161 = call i64 @strtol(i8* %160, i8** null, i32 0)
    %162 = trunc i64 %161 to i32
    %163 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %164 = call i32 (i8*, ...)* @printf( i8* %163, i32 %162)

    %165 = add i32 1, 0
    %166 = load i8*** %args
    %167 = add i32 %165, 1
    %168 = getelementptr i8** %166, i32 %167
    %169 = load i8** %168
    %170 = call i64 @strtol(i8* %169, i8** null, i32 0)
    %171 = trunc i64 %170 to i32
    %172 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %173 = call i32 (i8*, ...)* @printf( i8* %172, i32 %171)

    %174 = add i1 0, 0
    %175 = alloca i1
    %176 = icmp eq i1 %174, 1
    br i1 %176, label %then4, label %else4

  then4:
    %177 = add i1 1, 0
    %178 = add i1 %177, 0
    store i1 %178, i1* %175
    br label %ifcont4

  else4:
    %179 = add i1 %174, 0
    store i1 %179, i1* %175
    br label %ifcont4

  ifcont4:
    %180 = load i1* %175
    %181 = add i1 0, 0
    %182 = alloca i1
    %183 = icmp eq i1 %181, 1
    br i1 %183, label %then5, label %else5

  then5:
    %184 = add i1 1, 0
    %185 = add i1 %184, 0
    store i1 %185, i1* %182
    br label %ifcont5

  else5:
    %186 = add i1 %181, 0
    store i1 %186, i1* %182
    br label %ifcont5

  ifcont5:
    %187 = load i1* %182
    %188 = call i1 @a(i1 %187)
    %189 = icmp eq i1 %188, 0
    br i1 %189, label %then6, label %else6

  then6:
    %190 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %191 = call i32 (i8*, ...)* @printf( i8* %190)
    br label %ifcont6

  else6:
    %192 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %193 = call i32 (i8*, ...)* @printf( i8* %192)
    br label %ifcont6

  ifcont6:

    %194 = add i1 1, 0
    %195 = alloca i1
    %196 = icmp eq i1 %194, 0
    br i1 %196, label %then7, label %else7

  then7:
    %197 = add i1 0, 0
    %198 = alloca i1
    %199 = icmp eq i1 %197, 0
    br i1 %199, label %then8, label %else8

  then8:
    %200 = add i1 0, 0
    %201 = add i1 %200, 0
    store i1 %201, i1* %198
    br label %ifcont8

  else8:
    %202 = add i1 %197, 0
    store i1 %202, i1* %198
    br label %ifcont8

  ifcont8:
    %203 = load i1* %198
    %204 = add i1 %203, 0
    store i1 %204, i1* %195
    br label %ifcont7

  else7:
    %205 = add i1 %194, 0
    store i1 %205, i1* %195
    br label %ifcont7

  ifcont7:
    %206 = load i1* %195
    %207 = icmp eq i1 %206, 0
    br i1 %207, label %then9, label %else9

  then9:
    %208 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %209 = call i32 (i8*, ...)* @printf( i8* %208)
    br label %ifcont9

  else9:
    %210 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %211 = call i32 (i8*, ...)* @printf( i8* %210)
    br label %ifcont9

  ifcont9:

    %212 = add i32 10, 0
    %213 = getelementptr i32* %i, i32 0
    store i32 %212, i32* %213

    br label %cond1

  cond1:
    %214 = load i32* %i
    %215 = add i32 %214, 0
    %216 = add i32 10, 0
    %217 = mul i32 %216, -1
    %218 = icmp sge i32 %215, %217
    %219 = icmp eq i1 %218, 1
    br i1 %219, label %while1, label %whilecont1

  while1:

    %220 = load i32* %i
    %221 = add i32 %220, 0
    %222 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %223 = call i32 (i8*, ...)* @printf( i8* %222, i32 %221)

    %224 = load i32* %i
    %225 = add i32 %224, 0
    %226 = add i32 0, 0
    %227 = icmp sgt i32 %225, %226
    %228 = icmp eq i1 %227, 1
    br i1 %228, label %then10, label %else10

  then10:

    %229 = load i32* %i
    %230 = add i32 %229, 0
    %231 = add i32 1, 0
    %232 = sub nsw i32 %230, %231
    %233 = getelementptr i32* %i, i32 0
    store i32 %232, i32* %233
    br label %ifcont10

  else10:

    %234 = load i32* %i
    %235 = add i32 %234, 0
    %236 = add i32 2, 0
    %237 = sub nsw i32 %235, %236
    %238 = getelementptr i32* %i, i32 0
    store i32 %237, i32* %238
    br label %ifcont10

  ifcont10:
    br label %cond1
  whilecont1:

    %239 = add i32 1, 0
    %240 = add i32 1, 0
    %241 = add i32 2, 0
    %242 = call i1 @compare(i32 %240, i32 %241)
    %243 = icmp eq i1 %242, 0
    br i1 %243, label %then11, label %else11

  then11:
    %244 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %245 = call i32 (i8*, ...)* @printf( i8* %244)
    br label %ifcont11

  else11:
    %246 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %247 = call i32 (i8*, ...)* @printf( i8* %246)
    br label %ifcont11

  ifcont11:

    %248 = add i32 2, 0
    %249 = add i32 2, 0
    %250 = add i32 1, 0
    %251 = add i32 1, 0
    %252 = add i32 %250, %251
    %253 = call i1 @compare(i32 %249, i32 %252)
    %254 = icmp eq i1 %253, 0
    br i1 %254, label %then12, label %else12

  then12:
    %255 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %256 = call i32 (i8*, ...)* @printf( i8* %255)
    br label %ifcont12

  else12:
    %257 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %258 = call i32 (i8*, ...)* @printf( i8* %257)
    br label %ifcont12

  ifcont12:

    %259 = add i32 10, 0
    %260 = add i32 10, 0
    %261 = add i32 20, 0
    %262 = add i32 15, 0
    %263 = sub nsw i32 %261, %262
    %264 = add i32 5, 0
    %265 = add i32 %263, %264
    %266 = call i1 @compare(i32 %260, i32 %265)
    %267 = icmp eq i1 %266, 0
    br i1 %267, label %then13, label %else13

  then13:
    %268 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %269 = call i32 (i8*, ...)* @printf( i8* %268)
    br label %ifcont13

  else13:
    %270 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %271 = call i32 (i8*, ...)* @printf( i8* %270)
    br label %ifcont13

  ifcont13:

    %272 = add i32 2, 0
    %273 = getelementptr i32* @d, i32 0
    store i32 %272, i32* %273

    %274 = add i32 1, 0
    %275 = add i32 %274, 1
    %276 = mul i32 %275, 4
    %277 = call noalias i8* @malloc(i32 %276)
    %278 = bitcast i8* %277 to i32*
    store i32 %274, i32* %278
    %279 = alloca i32*
    store i32* %278, i32** %279
    %280 = load i32** %279
    store i32* %280, i32** @e

    %281 = add i32 3, 0
    %282 = add i32 0, 0
    %283 = add i32 %282, 1
    %284 = load i32** @e
    %285 = getelementptr i32* %284, i32 %283
    store i32 %281, i32* %285

    %286 = add i32 0, 0
    %287 = load i32** @e
    %288 = add i32 %286, 1
    %289 = getelementptr i32* %287, i32 %288
    %290 = load i32* %289
    %291 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %292 = call i32 (i8*, ...)* @printf( i8* %291, i32 %290)

    %293 = load i32** @e
    %294 = getelementptr inbounds i32* %293, i64 0
    %295 = load i32* %294
    %296 = ptrtoint i32 %295 to i32
    %297 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %298 = call i32 (i8*, ...)* @printf( i8* %297, i32 %296)

    %299 = add i32 6, 0
    %300 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %301 = call i32 (i8*, ...)* @printf( i8* %300, i32 %299)

    %302 = add i32 15, 0
    %303 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %304 = call i32 (i8*, ...)* @printf( i8* %303, i32 %302)

    %305 = add i32 2, 0
    %306 = add i32 2, 0
    %307 = add i32 5, 0
    %308 = add i32 %306, %307
    %309 = add i32 5, 0
    %310 = mul i32 %308, %309
    %311 = add i32 %305, %310
    %312 = getelementptr i32* %i, i32 0
    store i32 %311, i32* %312

    %313 = add i1 0, 0
    %314 = alloca i1
    %315 = icmp eq i1 %313, 0
    br i1 %315, label %then14, label %else14

  then14:
    %316 = add i1 1, 0
    %317 = alloca i1
    %318 = icmp eq i1 %316, 1
    br i1 %318, label %then15, label %else15

  then15:
    %319 = add i1 1, 0
    %320 = alloca i1
    %321 = icmp eq i1 %319, 0
    br i1 %321, label %then16, label %else16

  then16:
    %322 = add i1 0, 0
    %323 = add i1 %322, 0
    store i1 %323, i1* %320
    br label %ifcont16

  else16:
    %324 = add i1 %319, 0
    store i1 %324, i1* %320
    br label %ifcont16

  ifcont16:
    %325 = load i1* %320
    %326 = add i1 %325, 0
    store i1 %326, i1* %317
    br label %ifcont15

  else15:
    %327 = add i1 %316, 0
    store i1 %327, i1* %317
    br label %ifcont15

  ifcont15:
    %328 = load i1* %317
    %329 = add i1 %328, 0
    store i1 %329, i1* %314
    br label %ifcont14

  else14:
    %330 = add i1 %313, 0
    store i1 %330, i1* %314
    br label %ifcont14

  ifcont14:
    %331 = load i1* %314
    %332 = getelementptr i1* %a, i32 0
    store i1 %331, i1* %332

    %333 = load i32* %i
    %334 = add i32 %333, 0
    %335 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %336 = call i32 (i8*, ...)* @printf( i8* %335, i32 %334)

    %337 = load i1* %a
    %338 = add i1 %337, 0
    %339 = icmp eq i1 %338, 0
    br i1 %339, label %then17, label %else17

  then17:
    %340 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %341 = call i32 (i8*, ...)* @printf( i8* %340)
    br label %ifcont17

  else17:
    %342 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %343 = call i32 (i8*, ...)* @printf( i8* %342)
    br label %ifcont17

  ifcont17:

    %344 = add i32 0, 0
    ret i32 %344
}


define i1 @teste_array(i1** %a) {
  entry:

    %0 = load i1** %a
    %1 = getelementptr inbounds i1* %0, i64 0
    %2 = bitcast i1* %1 to i32*
    %3 = load i32* %2
    %4 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %5 = call i32 (i8*, ...)* @printf( i8* %4, i32 %3)

    %6 = add i32 1, 0
    %7 = load i1** %a
    %8 = add i32 %6, 4
    %9 = getelementptr i1* %7, i32 %8
    %10 = load i1* %9
    ret i1 %10
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
