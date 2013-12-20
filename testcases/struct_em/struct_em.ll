;author ZZQ
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @printf(i8*, ...)
declare i32 @__isoc99_scanf(i8*, ...)
%struct.s = type {i32,i32}
%struct.ss = type {i32,i32,i32,%struct.s}
@S = common global %struct.ss zeroinitializer, align 4
define i32 @main() {
entry:
%tmp_3 = getelementptr inbounds %struct.ss* @S, i32 0, i32 3
%tmp_1 = getelementptr inbounds %struct.s* %tmp_3, i32 0, i32 0
%call4 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %tmp_1)
%tmp_8 = getelementptr inbounds %struct.ss* @S, i32 0, i32 3
%tmp_9 = getelementptr inbounds %struct.s* %tmp_8, i32 0, i32 0
%tmp_6 = load i32* %tmp_9, align 4
%call10 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %tmp_6)
%tmp_12 = getelementptr inbounds %struct.ss* @S, i32 0, i32 0
%call13 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %tmp_12)
%tmp_16 = getelementptr inbounds %struct.ss* @S, i32 0, i32 0
%tmp_15 = load i32* %tmp_16, align 4
%call17 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %tmp_15)
ret i32 0
}
