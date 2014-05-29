@d = common global i32 0
@e = common global i32* null

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %a = alloca i1
    %b = alloca i32*
    %c = alloca i1*
    %i = alloca i32

    %0 = add i32 3, 0
    %1 = add i32 %0, 1
    %2 = mul i32 %1, 4
    %3 = call noalias i8* @malloc(i32 %2)
    %4 = bitcast i8* %3 to i32*
    store i32 %0, i32* %4
    %5 = alloca i32*
    store i32* %4, i32** %5
    %6 = load i32** %5
    %7 = getelementptr inbounds i32* %6, i64 0
    %8 = load i32* %7
    %9 = ptrtoint i32 %8 to i32
    %10 = add i32 3, 0
    %11 = icmp sgt i32 %9, %10
    %12 = icmp eq i1 %11, 1
    br i1 %12, label %then0, label %else0

  then0:

    %13 = add i32 0, 0
    %14 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %15 = call i32 (i8*, ...)* @printf( i8* %14, i32 %13)
    br label %ifcont0

  else0:

    %16 = add i32 1, 0
    %17 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %18 = call i32 (i8*, ...)* @printf( i8* %17, i32 %16)
    br label %ifcont0

  ifcont0:

    %19 = add i32 3, 0
    %20 = add i32 %19, 1
    %21 = mul i32 %20, 4
    %22 = call noalias i8* @malloc(i32 %21)
    %23 = bitcast i8* %22 to i32*
    store i32 %19, i32* %23
    %24 = alloca i32*
    store i32* %23, i32** %24
    %25 = load i32** %24
    %26 = getelementptr inbounds i32* %25, i64 0
    %27 = load i32* %26
    %28 = ptrtoint i32 %27 to i32
    %29 = getelementptr i32* %i, i32 0
    store i32 %28, i32* %29

    %30 = load i32* %i
    %31 = add i32 %30, 0
    %32 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %33 = call i32 (i8*, ...)* @printf( i8* %32, i32 %31)

    %34 = sub nsw i32 %args.tam, 1
    %35 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %36 = call i32 (i8*, ...)* @printf( i8* %35, i32 %34)

    %37 = add i32 5, 0
    %38 = add i32 %37, 1
    %39 = mul i32 %38, 4
    %40 = call noalias i8* @malloc(i32 %39)
    %41 = bitcast i8* %40 to i32*
    store i32 %37, i32* %41
    %42 = alloca i32*
    store i32* %41, i32** %42
    %43 = load i32** %42
    store i32* %43, i32** %b

    %44 = add i32 15, 0
    %45 = add i32 %44, 4
    %46 = call noalias i8* @malloc(i32 %45)
    %47 = bitcast i8* %46 to i1*
    %48 = bitcast i1* %47 to i32*
    store i32 %44, i32* %48
    %49 = alloca i1*
    store i1* %47, i1** %49
    %50 = load i1** %49
    store i1* %50, i1** %c

    %51 = add i32 4, 0
    %52 = add i32 0, 0
    %53 = add i32 %52, 1
    %54 = load i32** %b
    %55 = getelementptr i32* %54, i32 %53
    store i32 %51, i32* %55

    %56 = add i1 0, 0
    %57 = add i32 1, 0
    %58 = add i32 %57, 4
    %59 = load i1** %c
    %60 = getelementptr i1* %59, i32 %58
    store i1 %56, i1* %60

    %61 = load i1** %c
    %62 = getelementptr inbounds i1* %61, i64 0
    %63 = bitcast i1* %62 to i32*
    %64 = load i32* %63
    %65 = add i32 1, 0
    %66 = sub nsw i32 %64, %65
    %67 = getelementptr i32* %i, i32 0
    store i32 %66, i32* %67

    br label %cond0

  cond0:
    %68 = load i32* %i
    %69 = add i32 %68, 0
    %70 = add i32 0, 0
    %71 = icmp sge i32 %69, %70
    %72 = icmp eq i1 %71, 1
    br i1 %72, label %while0, label %whilecont0

  while0:

    %73 = add i1 1, 0
    %74 = load i32* %i
    %75 = add i32 %74, 0
    %76 = add i32 %75, 4
    %77 = load i1** %c
    %78 = getelementptr i1* %77, i32 %76
    store i1 %73, i1* %78

    %79 = load i32* %i
    %80 = add i32 %79, 0
    %81 = load i1** %c
    %82 = add i32 %80, 4
    %83 = getelementptr i1* %81, i32 %82
    %84 = load i1* %83
    %85 = icmp eq i1 %84, 0
    br i1 %85, label %then1, label %else1

  then1:
    %86 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %87 = call i32 (i8*, ...)* @printf( i8* %86)
    br label %ifcont1

  else1:
    %88 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %89 = call i32 (i8*, ...)* @printf( i8* %88)
    br label %ifcont1

  ifcont1:

    %90 = load i32* %i
    %91 = add i32 %90, 0
    %92 = add i32 1, 0
    %93 = sub nsw i32 %91, %92
    %94 = getelementptr i32* %i, i32 0
    store i32 %93, i32* %94
    br label %cond0
  whilecont0:

    %95 = load i1** %c
    %96 = getelementptr inbounds i1* %95, i64 0
    %97 = bitcast i1* %96 to i32*
    %98 = load i32* %97
    %99 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %100 = call i32 (i8*, ...)* @printf( i8* %99, i32 %98)

    %101 = call i1 @teste_array(i1** %c)
    %102 = icmp eq i1 %101, 0
    br i1 %102, label %then2, label %else2

  then2:
    %103 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %104 = call i32 (i8*, ...)* @printf( i8* %103)
    br label %ifcont2

  else2:
    %105 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %106 = call i32 (i8*, ...)* @printf( i8* %105)
    br label %ifcont2

  ifcont2:

    %107 = add i32 0, 0
    %108 = load i32** %b
    %109 = add i32 %107, 1
    %110 = getelementptr i32* %108, i32 %109
    %111 = load i32* %110
    %112 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %113 = call i32 (i8*, ...)* @printf( i8* %112, i32 %111)

    %114 = add i32 1, 0
    %115 = load i1** %c
    %116 = add i32 %114, 4
    %117 = getelementptr i1* %115, i32 %116
    %118 = load i1* %117
    %119 = icmp eq i1 %118, 0
    br i1 %119, label %then3, label %else3

  then3:
    %120 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %121 = call i32 (i8*, ...)* @printf( i8* %120)
    br label %ifcont3

  else3:
    %122 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %123 = call i32 (i8*, ...)* @printf( i8* %122)
    br label %ifcont3

  ifcont3:

    %124 = load i32** %b
    %125 = getelementptr inbounds i32* %124, i64 0
    %126 = load i32* %125
    %127 = ptrtoint i32 %126 to i32
    %128 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %129 = call i32 (i8*, ...)* @printf( i8* %128, i32 %127)

    %130 = load i1** %c
    %131 = getelementptr inbounds i1* %130, i64 0
    %132 = bitcast i1* %131 to i32*
    %133 = load i32* %132
    %134 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %135 = call i32 (i8*, ...)* @printf( i8* %134, i32 %133)

    %136 = add i32 0, 0
    %137 = add i32 %136, 1
    %138 = getelementptr i8** %args, i32 %137
    %139 = load i8** %138
    %140 = call i32 (i8*)* @atoi(i8* %139)
    %141 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %142 = call i32 (i8*, ...)* @printf( i8* %141, i32 %140)

    %143 = add i32 1, 0
    %144 = add i32 %143, 1
    %145 = getelementptr i8** %args, i32 %144
    %146 = load i8** %145
    %147 = call i32 (i8*)* @atoi(i8* %146)
    %148 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %149 = call i32 (i8*, ...)* @printf( i8* %148, i32 %147)

    %150 = add i1 0, 0
    %151 = alloca i1
    %152 = icmp eq i1 %150, 1
    br i1 %152, label %then4, label %else4

  then4:
    %153 = add i1 1, 0
    %154 = add i1 %153, 0
    store i1 %154, i1* %151
    br label %ifcont4

  else4:
    %155 = add i1 %150, 0
    store i1 %155, i1* %151
    br label %ifcont4

  ifcont4:
    %156 = load i1* %151
    %157 = add i1 0, 0
    %158 = alloca i1
    %159 = icmp eq i1 %157, 1
    br i1 %159, label %then5, label %else5

  then5:
    %160 = add i1 1, 0
    %161 = add i1 %160, 0
    store i1 %161, i1* %158
    br label %ifcont5

  else5:
    %162 = add i1 %157, 0
    store i1 %162, i1* %158
    br label %ifcont5

  ifcont5:
    %163 = load i1* %158
    %164 = call i1 @a(i1 %163)
    %165 = icmp eq i1 %164, 0
    br i1 %165, label %then6, label %else6

  then6:
    %166 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %167 = call i32 (i8*, ...)* @printf( i8* %166)
    br label %ifcont6

  else6:
    %168 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %169 = call i32 (i8*, ...)* @printf( i8* %168)
    br label %ifcont6

  ifcont6:

    %170 = add i1 1, 0
    %171 = alloca i1
    %172 = icmp eq i1 %170, 0
    br i1 %172, label %then7, label %else7

  then7:
    %173 = add i1 0, 0
    %174 = alloca i1
    %175 = icmp eq i1 %173, 0
    br i1 %175, label %then8, label %else8

  then8:
    %176 = add i1 0, 0
    %177 = add i1 %176, 0
    store i1 %177, i1* %174
    br label %ifcont8

  else8:
    %178 = add i1 %173, 0
    store i1 %178, i1* %174
    br label %ifcont8

  ifcont8:
    %179 = load i1* %174
    %180 = add i1 %179, 0
    store i1 %180, i1* %171
    br label %ifcont7

  else7:
    %181 = add i1 %170, 0
    store i1 %181, i1* %171
    br label %ifcont7

  ifcont7:
    %182 = load i1* %171
    %183 = icmp eq i1 %182, 0
    br i1 %183, label %then9, label %else9

  then9:
    %184 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %185 = call i32 (i8*, ...)* @printf( i8* %184)
    br label %ifcont9

  else9:
    %186 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %187 = call i32 (i8*, ...)* @printf( i8* %186)
    br label %ifcont9

  ifcont9:

    %188 = add i32 10, 0
    %189 = getelementptr i32* %i, i32 0
    store i32 %188, i32* %189

    br label %cond1

  cond1:
    %190 = load i32* %i
    %191 = add i32 %190, 0
    %192 = add i32 10, 0
    %193 = mul i32 %192, -1
    %194 = icmp sge i32 %191, %193
    %195 = icmp eq i1 %194, 1
    br i1 %195, label %while1, label %whilecont1

  while1:

    %196 = load i32* %i
    %197 = add i32 %196, 0
    %198 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %199 = call i32 (i8*, ...)* @printf( i8* %198, i32 %197)

    %200 = load i32* %i
    %201 = add i32 %200, 0
    %202 = add i32 0, 0
    %203 = icmp sgt i32 %201, %202
    %204 = icmp eq i1 %203, 1
    br i1 %204, label %then10, label %else10

  then10:

    %205 = load i32* %i
    %206 = add i32 %205, 0
    %207 = add i32 1, 0
    %208 = sub nsw i32 %206, %207
    %209 = getelementptr i32* %i, i32 0
    store i32 %208, i32* %209
    br label %ifcont10

  else10:

    %210 = load i32* %i
    %211 = add i32 %210, 0
    %212 = add i32 2, 0
    %213 = sub nsw i32 %211, %212
    %214 = getelementptr i32* %i, i32 0
    store i32 %213, i32* %214
    br label %ifcont10

  ifcont10:
    br label %cond1
  whilecont1:

    %215 = add i32 1, 0
    %216 = add i32 1, 0
    %217 = add i32 2, 0
    %218 = call i1 @compare(i32 %216, i32 %217)
    %219 = icmp eq i1 %218, 0
    br i1 %219, label %then11, label %else11

  then11:
    %220 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %221 = call i32 (i8*, ...)* @printf( i8* %220)
    br label %ifcont11

  else11:
    %222 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %223 = call i32 (i8*, ...)* @printf( i8* %222)
    br label %ifcont11

  ifcont11:

    %224 = add i32 2, 0
    %225 = add i32 2, 0
    %226 = add i32 1, 0
    %227 = add i32 1, 0
    %228 = add i32 %226, %227
    %229 = call i1 @compare(i32 %225, i32 %228)
    %230 = icmp eq i1 %229, 0
    br i1 %230, label %then12, label %else12

  then12:
    %231 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %232 = call i32 (i8*, ...)* @printf( i8* %231)
    br label %ifcont12

  else12:
    %233 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %234 = call i32 (i8*, ...)* @printf( i8* %233)
    br label %ifcont12

  ifcont12:

    %235 = add i32 10, 0
    %236 = add i32 10, 0
    %237 = add i32 20, 0
    %238 = add i32 15, 0
    %239 = sub nsw i32 %237, %238
    %240 = add i32 5, 0
    %241 = add i32 %239, %240
    %242 = call i1 @compare(i32 %236, i32 %241)
    %243 = icmp eq i1 %242, 0
    br i1 %243, label %then13, label %else13

  then13:
    %244 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %245 = call i32 (i8*, ...)* @printf( i8* %244)
    br label %ifcont13

  else13:
    %246 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %247 = call i32 (i8*, ...)* @printf( i8* %246)
    br label %ifcont13

  ifcont13:

    %248 = add i32 2, 0
    %249 = getelementptr i32* @d, i32 0
    store i32 %248, i32* %249

    %250 = add i32 1, 0
    %251 = add i32 %250, 1
    %252 = mul i32 %251, 4
    %253 = call noalias i8* @malloc(i32 %252)
    %254 = bitcast i8* %253 to i32*
    store i32 %250, i32* %254
    %255 = alloca i32*
    store i32* %254, i32** %255
    %256 = load i32** %255
    store i32* %256, i32** @e

    %257 = add i32 3, 0
    %258 = add i32 0, 0
    %259 = add i32 %258, 1
    %260 = load i32** @e
    %261 = getelementptr i32* %260, i32 %259
    store i32 %257, i32* %261

    %262 = add i32 0, 0
    %263 = load i32** @e
    %264 = add i32 %262, 1
    %265 = getelementptr i32* %263, i32 %264
    %266 = load i32* %265
    %267 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %268 = call i32 (i8*, ...)* @printf( i8* %267, i32 %266)

    %269 = load i32** @e
    %270 = getelementptr inbounds i32* %269, i64 0
    %271 = load i32* %270
    %272 = ptrtoint i32 %271 to i32
    %273 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %274 = call i32 (i8*, ...)* @printf( i8* %273, i32 %272)

    %275 = add i32 6, 0
    %276 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %277 = call i32 (i8*, ...)* @printf( i8* %276, i32 %275)

    %278 = add i32 15, 0
    %279 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %280 = call i32 (i8*, ...)* @printf( i8* %279, i32 %278)

    %281 = add i32 2, 0
    %282 = add i32 2, 0
    %283 = add i32 5, 0
    %284 = add i32 %282, %283
    %285 = add i32 5, 0
    %286 = mul i32 %284, %285
    %287 = add i32 %281, %286
    %288 = getelementptr i32* %i, i32 0
    store i32 %287, i32* %288

    %289 = add i1 0, 0
    %290 = alloca i1
    %291 = icmp eq i1 %289, 0
    br i1 %291, label %then14, label %else14

  then14:
    %292 = add i1 1, 0
    %293 = alloca i1
    %294 = icmp eq i1 %292, 1
    br i1 %294, label %then15, label %else15

  then15:
    %295 = add i1 1, 0
    %296 = alloca i1
    %297 = icmp eq i1 %295, 0
    br i1 %297, label %then16, label %else16

  then16:
    %298 = add i1 0, 0
    %299 = add i1 %298, 0
    store i1 %299, i1* %296
    br label %ifcont16

  else16:
    %300 = add i1 %295, 0
    store i1 %300, i1* %296
    br label %ifcont16

  ifcont16:
    %301 = load i1* %296
    %302 = add i1 %301, 0
    store i1 %302, i1* %293
    br label %ifcont15

  else15:
    %303 = add i1 %292, 0
    store i1 %303, i1* %293
    br label %ifcont15

  ifcont15:
    %304 = load i1* %293
    %305 = add i1 %304, 0
    store i1 %305, i1* %290
    br label %ifcont14

  else14:
    %306 = add i1 %289, 0
    store i1 %306, i1* %290
    br label %ifcont14

  ifcont14:
    %307 = load i1* %290
    %308 = getelementptr i1* %a, i32 0
    store i1 %307, i1* %308

    %309 = load i32* %i
    %310 = add i32 %309, 0
    %311 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %312 = call i32 (i8*, ...)* @printf( i8* %311, i32 %310)

    %313 = load i1* %a
    %314 = add i1 %313, 0
    %315 = icmp eq i1 %314, 0
    br i1 %315, label %then17, label %else17

  then17:
    %316 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %317 = call i32 (i8*, ...)* @printf( i8* %316)
    br label %ifcont17

  else17:
    %318 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %319 = call i32 (i8*, ...)* @printf( i8* %318)
    br label %ifcont17

  ifcont17:

    %320 = call i1** @teste_array1(i1** %c)
    %321 = load i1** %320
    %322 = getelementptr inbounds i1* %321, i64 0
    %323 = bitcast i1* %322 to i32*
    %324 = load i32* %323
    %325 = getelementptr i32* %i, i32 0
    store i32 %324, i32* %325

    %326 = load i32* %i
    %327 = add i32 %326, 0
    %328 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %329 = call i32 (i8*, ...)* @printf( i8* %328, i32 %327)

    br label %return

  return:
    ret i32 0
}


define i1** @teste_array1(i1** %a) {
  entry:
    %.return = alloca i1*
    store i1* null, i1** %.return

    %0 = load i1** %a
    store i1* %0, i1** %.return
    br label %return

  return:
    ret i1** %.return
}


define i1 @teste_array(i1** %a) {
  entry:
    %.return = alloca i1
    store i1 0, i1* %.return

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
    store i1 %10, i1* %.return
    br label %return

  return:
    %11 = load i1* %.return
    ret i1 %11
}


define i1 @a(i1 %y.temp) {
  entry:
    %y = alloca i1
    store i1 %y.temp, i1* %y
    %.return = alloca i1
    store i1 0, i1* %.return

    %0 = load i1* %y
    %1 = add i1 %0, 0
    store i1 %1, i1* %.return
    br label %return

  return:
    %2 = load i1* %.return
    ret i1 %2
}


define i1 @compare(i32 %x.temp, i32 %y.temp) {
  entry:
    %x = alloca i32
    store i32 %x.temp, i32* %x
    %y = alloca i32
    store i32 %y.temp, i32* %y
    %.return = alloca i1
    store i1 0, i1* %.return
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
    store i1 %11, i1* %.return
    br label %return

  return:
    %12 = load i1* %.return
    ret i1 %12
}


declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1)
declare i32 @atoi(i8*)
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
