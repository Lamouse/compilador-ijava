@d = common global i32 0
@e = common global i32* null

define i32 @main(i32 %args.tam, i8** %args) {
  entry:
    %.return = alloca i32
    store i32 0, i32* %.return
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

    %34 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %35 = call i32 (i8*, ...)* @printf( i8* %34, i32 %args.tam)

    %36 = add i32 5, 0
    %37 = add i32 %36, 1
    %38 = mul i32 %37, 4
    %39 = call noalias i8* @malloc(i32 %38)
    %40 = bitcast i8* %39 to i32*
    store i32 %36, i32* %40
    %41 = alloca i32*
    store i32* %40, i32** %41
    %42 = load i32** %41
    store i32* %42, i32** %b

    %43 = add i32 15, 0
    %44 = add i32 %43, 4
    %45 = call noalias i8* @malloc(i32 %44)
    %46 = bitcast i8* %45 to i1*
    %47 = bitcast i1* %46 to i32*
    store i32 %43, i32* %47
    %48 = alloca i1*
    store i1* %46, i1** %48
    %49 = load i1** %48
    store i1* %49, i1** %c

    %50 = add i32 4, 0
    %51 = add i32 0, 0
    %52 = add i32 %51, 1
    %53 = load i32** %b
    %54 = getelementptr i32* %53, i32 %52
    store i32 %50, i32* %54

    %55 = add i1 0, 0
    %56 = add i32 1, 0
    %57 = add i32 %56, 4
    %58 = load i1** %c
    %59 = getelementptr i1* %58, i32 %57
    store i1 %55, i1* %59

    %60 = load i1** %c
    %61 = getelementptr inbounds i1* %60, i64 0
    %62 = bitcast i1* %61 to i32*
    %63 = load i32* %62
    %64 = add i32 1, 0
    %65 = sub nsw i32 %63, %64
    %66 = getelementptr i32* %i, i32 0
    store i32 %65, i32* %66

    br label %cond0

  cond0:
    %67 = load i32* %i
    %68 = add i32 %67, 0
    %69 = add i32 0, 0
    %70 = icmp sge i32 %68, %69
    %71 = icmp eq i1 %70, 1
    br i1 %71, label %while0, label %whilecont0

  while0:

    %72 = add i1 1, 0
    %73 = load i32* %i
    %74 = add i32 %73, 0
    %75 = add i32 %74, 4
    %76 = load i1** %c
    %77 = getelementptr i1* %76, i32 %75
    store i1 %72, i1* %77

    %78 = load i32* %i
    %79 = add i32 %78, 0
    %80 = load i1** %c
    %81 = add i32 %79, 4
    %82 = getelementptr i1* %80, i32 %81
    %83 = load i1* %82
    %84 = icmp eq i1 %83, 0
    br i1 %84, label %then1, label %else1

  then1:
    %85 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %86 = call i32 (i8*, ...)* @printf( i8* %85)
    br label %ifcont1

  else1:
    %87 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %88 = call i32 (i8*, ...)* @printf( i8* %87)
    br label %ifcont1

  ifcont1:

    %89 = load i32* %i
    %90 = add i32 %89, 0
    %91 = add i32 1, 0
    %92 = sub nsw i32 %90, %91
    %93 = getelementptr i32* %i, i32 0
    store i32 %92, i32* %93
    br label %cond0
  whilecont0:

    %94 = load i1** %c
    %95 = getelementptr inbounds i1* %94, i64 0
    %96 = bitcast i1* %95 to i32*
    %97 = load i32* %96
    %98 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %99 = call i32 (i8*, ...)* @printf( i8* %98, i32 %97)

    %100 = call i1 @teste_array(i1** %c)
    %101 = icmp eq i1 %100, 0
    br i1 %101, label %then2, label %else2

  then2:
    %102 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %103 = call i32 (i8*, ...)* @printf( i8* %102)
    br label %ifcont2

  else2:
    %104 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %105 = call i32 (i8*, ...)* @printf( i8* %104)
    br label %ifcont2

  ifcont2:

    %106 = add i32 0, 0
    %107 = load i32** %b
    %108 = add i32 %106, 1
    %109 = getelementptr i32* %107, i32 %108
    %110 = load i32* %109
    %111 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %112 = call i32 (i8*, ...)* @printf( i8* %111, i32 %110)

    %113 = add i32 1, 0
    %114 = load i1** %c
    %115 = add i32 %113, 4
    %116 = getelementptr i1* %114, i32 %115
    %117 = load i1* %116
    %118 = icmp eq i1 %117, 0
    br i1 %118, label %then3, label %else3

  then3:
    %119 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %120 = call i32 (i8*, ...)* @printf( i8* %119)
    br label %ifcont3

  else3:
    %121 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %122 = call i32 (i8*, ...)* @printf( i8* %121)
    br label %ifcont3

  ifcont3:

    %123 = load i32** %b
    %124 = getelementptr inbounds i32* %123, i64 0
    %125 = load i32* %124
    %126 = ptrtoint i32 %125 to i32
    %127 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %128 = call i32 (i8*, ...)* @printf( i8* %127, i32 %126)

    %129 = load i1** %c
    %130 = getelementptr inbounds i1* %129, i64 0
    %131 = bitcast i1* %130 to i32*
    %132 = load i32* %131
    %133 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %134 = call i32 (i8*, ...)* @printf( i8* %133, i32 %132)

    %135 = add i32 0, 0
    %136 = add i32 %135, 1
    %137 = getelementptr i8** %args, i32 %136
    %138 = load i8** %137
    %139 = call i32 (i8*)* @atoi(i8* %138)
    %140 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %141 = call i32 (i8*, ...)* @printf( i8* %140, i32 %139)

    %142 = add i32 1, 0
    %143 = add i32 %142, 1
    %144 = getelementptr i8** %args, i32 %143
    %145 = load i8** %144
    %146 = call i32 (i8*)* @atoi(i8* %145)
    %147 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %148 = call i32 (i8*, ...)* @printf( i8* %147, i32 %146)

    %149 = add i1 0, 0
    %150 = alloca i1
    %151 = icmp eq i1 %149, 1
    br i1 %151, label %then4, label %else4

  then4:
    %152 = add i1 1, 0
    %153 = add i1 %152, 0
    store i1 %153, i1* %150
    br label %ifcont4

  else4:
    %154 = add i1 %149, 0
    store i1 %154, i1* %150
    br label %ifcont4

  ifcont4:
    %155 = load i1* %150
    %156 = add i1 0, 0
    %157 = alloca i1
    %158 = icmp eq i1 %156, 1
    br i1 %158, label %then5, label %else5

  then5:
    %159 = add i1 1, 0
    %160 = add i1 %159, 0
    store i1 %160, i1* %157
    br label %ifcont5

  else5:
    %161 = add i1 %156, 0
    store i1 %161, i1* %157
    br label %ifcont5

  ifcont5:
    %162 = load i1* %157
    %163 = call i1 @a(i1 %162)
    %164 = icmp eq i1 %163, 0
    br i1 %164, label %then6, label %else6

  then6:
    %165 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %166 = call i32 (i8*, ...)* @printf( i8* %165)
    br label %ifcont6

  else6:
    %167 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %168 = call i32 (i8*, ...)* @printf( i8* %167)
    br label %ifcont6

  ifcont6:

    %169 = add i1 1, 0
    %170 = alloca i1
    %171 = icmp eq i1 %169, 0
    br i1 %171, label %then7, label %else7

  then7:
    %172 = add i1 0, 0
    %173 = alloca i1
    %174 = icmp eq i1 %172, 0
    br i1 %174, label %then8, label %else8

  then8:
    %175 = add i1 0, 0
    %176 = add i1 %175, 0
    store i1 %176, i1* %173
    br label %ifcont8

  else8:
    %177 = add i1 %172, 0
    store i1 %177, i1* %173
    br label %ifcont8

  ifcont8:
    %178 = load i1* %173
    %179 = add i1 %178, 0
    store i1 %179, i1* %170
    br label %ifcont7

  else7:
    %180 = add i1 %169, 0
    store i1 %180, i1* %170
    br label %ifcont7

  ifcont7:
    %181 = load i1* %170
    %182 = icmp eq i1 %181, 0
    br i1 %182, label %then9, label %else9

  then9:
    %183 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %184 = call i32 (i8*, ...)* @printf( i8* %183)
    br label %ifcont9

  else9:
    %185 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %186 = call i32 (i8*, ...)* @printf( i8* %185)
    br label %ifcont9

  ifcont9:

    %187 = add i32 10, 0
    %188 = getelementptr i32* %i, i32 0
    store i32 %187, i32* %188

    br label %cond1

  cond1:
    %189 = load i32* %i
    %190 = add i32 %189, 0
    %191 = add i32 10, 0
    %192 = mul i32 %191, -1
    %193 = icmp sge i32 %190, %192
    %194 = icmp eq i1 %193, 1
    br i1 %194, label %while1, label %whilecont1

  while1:

    %195 = load i32* %i
    %196 = add i32 %195, 0
    %197 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %198 = call i32 (i8*, ...)* @printf( i8* %197, i32 %196)

    %199 = load i32* %i
    %200 = add i32 %199, 0
    %201 = add i32 0, 0
    %202 = icmp sgt i32 %200, %201
    %203 = icmp eq i1 %202, 1
    br i1 %203, label %then10, label %else10

  then10:

    %204 = load i32* %i
    %205 = add i32 %204, 0
    %206 = add i32 1, 0
    %207 = sub nsw i32 %205, %206
    %208 = getelementptr i32* %i, i32 0
    store i32 %207, i32* %208
    br label %ifcont10

  else10:

    %209 = load i32* %i
    %210 = add i32 %209, 0
    %211 = add i32 2, 0
    %212 = sub nsw i32 %210, %211
    %213 = getelementptr i32* %i, i32 0
    store i32 %212, i32* %213
    br label %ifcont10

  ifcont10:
    br label %cond1
  whilecont1:

    %214 = add i32 1, 0
    %215 = add i32 1, 0
    %216 = add i32 2, 0
    %217 = call i1 @compare(i32 %215, i32 %216)
    %218 = icmp eq i1 %217, 0
    br i1 %218, label %then11, label %else11

  then11:
    %219 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %220 = call i32 (i8*, ...)* @printf( i8* %219)
    br label %ifcont11

  else11:
    %221 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %222 = call i32 (i8*, ...)* @printf( i8* %221)
    br label %ifcont11

  ifcont11:

    %223 = add i32 2, 0
    %224 = add i32 2, 0
    %225 = add i32 1, 0
    %226 = add i32 1, 0
    %227 = add i32 %225, %226
    %228 = call i1 @compare(i32 %224, i32 %227)
    %229 = icmp eq i1 %228, 0
    br i1 %229, label %then12, label %else12

  then12:
    %230 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %231 = call i32 (i8*, ...)* @printf( i8* %230)
    br label %ifcont12

  else12:
    %232 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %233 = call i32 (i8*, ...)* @printf( i8* %232)
    br label %ifcont12

  ifcont12:

    %234 = add i32 10, 0
    %235 = add i32 10, 0
    %236 = add i32 20, 0
    %237 = add i32 15, 0
    %238 = sub nsw i32 %236, %237
    %239 = add i32 5, 0
    %240 = add i32 %238, %239
    %241 = call i1 @compare(i32 %235, i32 %240)
    %242 = icmp eq i1 %241, 0
    br i1 %242, label %then13, label %else13

  then13:
    %243 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %244 = call i32 (i8*, ...)* @printf( i8* %243)
    br label %ifcont13

  else13:
    %245 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %246 = call i32 (i8*, ...)* @printf( i8* %245)
    br label %ifcont13

  ifcont13:

    %247 = add i32 2, 0
    %248 = getelementptr i32* @d, i32 0
    store i32 %247, i32* %248

    %249 = add i32 1, 0
    %250 = add i32 %249, 1
    %251 = mul i32 %250, 4
    %252 = call noalias i8* @malloc(i32 %251)
    %253 = bitcast i8* %252 to i32*
    store i32 %249, i32* %253
    %254 = alloca i32*
    store i32* %253, i32** %254
    %255 = load i32** %254
    store i32* %255, i32** @e

    %256 = add i32 3, 0
    %257 = add i32 0, 0
    %258 = add i32 %257, 1
    %259 = load i32** @e
    %260 = getelementptr i32* %259, i32 %258
    store i32 %256, i32* %260

    %261 = add i32 0, 0
    %262 = load i32** @e
    %263 = add i32 %261, 1
    %264 = getelementptr i32* %262, i32 %263
    %265 = load i32* %264
    %266 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %267 = call i32 (i8*, ...)* @printf( i8* %266, i32 %265)

    %268 = load i32** @e
    %269 = getelementptr inbounds i32* %268, i64 0
    %270 = load i32* %269
    %271 = ptrtoint i32 %270 to i32
    %272 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %273 = call i32 (i8*, ...)* @printf( i8* %272, i32 %271)

    %274 = add i32 6, 0
    %275 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %276 = call i32 (i8*, ...)* @printf( i8* %275, i32 %274)

    %277 = add i32 15, 0
    %278 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %279 = call i32 (i8*, ...)* @printf( i8* %278, i32 %277)

    %280 = add i32 2, 0
    %281 = add i32 2, 0
    %282 = add i32 5, 0
    %283 = add i32 %281, %282
    %284 = add i32 5, 0
    %285 = mul i32 %283, %284
    %286 = add i32 %280, %285
    %287 = getelementptr i32* %i, i32 0
    store i32 %286, i32* %287

    %288 = add i1 0, 0
    %289 = alloca i1
    %290 = icmp eq i1 %288, 0
    br i1 %290, label %then14, label %else14

  then14:
    %291 = add i1 1, 0
    %292 = alloca i1
    %293 = icmp eq i1 %291, 1
    br i1 %293, label %then15, label %else15

  then15:
    %294 = add i1 1, 0
    %295 = alloca i1
    %296 = icmp eq i1 %294, 0
    br i1 %296, label %then16, label %else16

  then16:
    %297 = add i1 0, 0
    %298 = add i1 %297, 0
    store i1 %298, i1* %295
    br label %ifcont16

  else16:
    %299 = add i1 %294, 0
    store i1 %299, i1* %295
    br label %ifcont16

  ifcont16:
    %300 = load i1* %295
    %301 = add i1 %300, 0
    store i1 %301, i1* %292
    br label %ifcont15

  else15:
    %302 = add i1 %291, 0
    store i1 %302, i1* %292
    br label %ifcont15

  ifcont15:
    %303 = load i1* %292
    %304 = add i1 %303, 0
    store i1 %304, i1* %289
    br label %ifcont14

  else14:
    %305 = add i1 %288, 0
    store i1 %305, i1* %289
    br label %ifcont14

  ifcont14:
    %306 = load i1* %289
    %307 = getelementptr i1* %a, i32 0
    store i1 %306, i1* %307

    %308 = load i32* %i
    %309 = add i32 %308, 0
    %310 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %311 = call i32 (i8*, ...)* @printf( i8* %310, i32 %309)

    %312 = load i1* %a
    %313 = add i1 %312, 0
    %314 = icmp eq i1 %313, 0
    br i1 %314, label %then17, label %else17

  then17:
    %315 = getelementptr [7 x i8]* @str.false, i32 0, i32 0
    %316 = call i32 (i8*, ...)* @printf( i8* %315)
    br label %ifcont17

  else17:
    %317 = getelementptr [6 x i8]* @str.true, i32 0, i32 0
    %318 = call i32 (i8*, ...)* @printf( i8* %317)
    br label %ifcont17

  ifcont17:

    %319 = call i1** @teste_array1(i1** %c)
    %320 = load i1** %319
    %321 = getelementptr inbounds i1* %320, i64 0
    %322 = bitcast i1* %321 to i32*
    %323 = load i32* %322
    %324 = getelementptr i32* %i, i32 0
    store i32 %323, i32* %324

    %325 = load i32* %i
    %326 = add i32 %325, 0
    %327 = getelementptr [4 x i8]* @str.int, i32 0, i32 0
    %328 = call i32 (i8*, ...)* @printf( i8* %327, i32 %326)

    %329 = load i32* %i
    %330 = add i32 %329, 0
    %331 = add i32 15, 0
    %332 = icmp eq i32 %330, %331
    %333 = icmp eq i1 %332, 1
    br i1 %333, label %then18, label %else18

  then18:

    %334 = add i32 1, 0
    store i32 %334, i32* %.return
    br label %return

    %335 = add i32 1, 0
    %336 = getelementptr i32* %i, i32 0
    store i32 %335, i32* %336
    br label %ifcont18

  else18:

    %337 = add i32 2, 0
    store i32 %337, i32* %.return
    br label %return
    br label %ifcont18

  ifcont18:

    %338 = add i32 0, 0
    store i32 %338, i32* %.return
    br label %return

    br label %return

  return:
    %.ret = load i32* %.return
    ret i32 %.ret
}


define i1** @teste_array1(i1** %a) {
  entry:
    %.return = alloca i1*
    store i1* null, i1** %.return

    %0 = load i1** %a
    store i1* %0, i1** %.return
    br label %return

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

    br label %return

  return:
    %.ret = load i1* %.return
    ret i1 %.ret
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

    br label %return

  return:
    %.ret = load i1* %.return
    ret i1 %.ret
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

    br label %return

  return:
    %.ret = load i1* %.return
    ret i1 %.ret
}


declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1)
declare i32 @atoi(i8*)
declare noalias i8* @malloc(i32)
declare i32 @printf(i8*, ...) nounwind
@str.int = internal constant [4 x i8] c"%d\0A\00"
@str.true = private unnamed_addr constant [6 x i8] c"true\0A\00"
@str.false = private unnamed_addr constant [7 x i8] c"false\0A\00"
