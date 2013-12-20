;author ZZQ
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @printf(i8*, ...)
declare i32 @__isoc99_scanf(i8*, ...)
define i32 @main() {
entry:
%tmp_0 = icmp eq i32 1, 2
br i1 %tmp_0, label %if.then1, label %if.else1

if.then1:
%call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  345)
br label %if.end1

if.else1:
%call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  678)
br label %if.end1

if.end1:
ret i32 0
}
