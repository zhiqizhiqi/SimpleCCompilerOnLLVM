;author ZZQ
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @printf(i8*, ...)
declare i32 @__isoc99_scanf(i8*, ...)
@n = common global i32 zeroinitializer, align 4
@ans = common global i32 0, align 4
@b = common global [20 x i32] zeroinitializer, align 4
@l = common global [40 x i32] zeroinitializer, align 4
@r = common global [40 x i32] zeroinitializer, align 4
define i32 @dfs(i32 %x) {
entry:
%x.addr = alloca i32, align 4
store i32 %x, i32* %x.addr, align 4
%i = alloca i32, align 4
%tmp_1 = load i32* %x.addr, align 4
%tmp_2 = load i32* @n, align 4
%tmp_0 = icmp eq i32 %tmp_1, %tmp_2
br i1 %tmp_0, label %if.then3, label %if.else3

if.then3:
%tmp_5 = load i32* @ans, align 4
%tmp_4 = add i32 %tmp_5, 1 
store i32 %tmp_4, i32* @ans, align 4
ret i32 0
br label %if.end3

if.else3:
br label %if.end3

if.end3:
store i32 0, i32* %i, align 4
br label %for.cond6

for.cond6:
%tmp_9 = load i32* %i, align 4
%tmp_10 = load i32* @n, align 4
%tmp_8 = icmp slt i32 %tmp_9, %tmp_10
br i1 %tmp_8, label %for.body6, label %for.end6

for.body6:
%tmp_15 = load i32* %i, align 4
%tmp_16 = getelementptr inbounds [20 x i32]* @b, i32 0, i32 %tmp_15
%tmp_14 = load i32* %tmp_16, align 4
%tmp_13 = icmp eq i32 %tmp_14, 0
%tmp_20 = load i32* %i, align 4
%tmp_21 = load i32* %x.addr, align 4
%tmp_19 = add i32 %tmp_20, %tmp_21 
%tmp_22 = getelementptr inbounds [40 x i32]* @l, i32 0, i32 %tmp_19
%tmp_18 = load i32* %tmp_22, align 4
%tmp_17 = icmp eq i32 %tmp_18, 0
%tmp_12 = and i1 %tmp_13, %tmp_17
%tmp_28 = load i32* %i, align 4
%tmp_29 = load i32* %x.addr, align 4
%tmp_27 = sub i32 %tmp_28, %tmp_29
%tmp_30 = load i32* @n, align 4
%tmp_26 = add i32 %tmp_27, %tmp_30 
%tmp_25 = sub i32 %tmp_26, 1
%tmp_31 = getelementptr inbounds [40 x i32]* @r, i32 0, i32 %tmp_25
%tmp_24 = load i32* %tmp_31, align 4
%tmp_23 = icmp eq i32 %tmp_24, 0
%tmp_11 = and i1 %tmp_12, %tmp_23
br i1 %tmp_11, label %if.then32, label %if.else32

if.then32:
%tmp_35 = load i32* %i, align 4
%tmp_34 = getelementptr inbounds [20 x i32]* @b, i32 0, i32 %tmp_35
store i32 1, i32* %tmp_34, align 4
%tmp_39 = load i32* %i, align 4
%tmp_40 = load i32* %x.addr, align 4
%tmp_38 = add i32 %tmp_39, %tmp_40 
%tmp_37 = getelementptr inbounds [40 x i32]* @l, i32 0, i32 %tmp_38
store i32 1, i32* %tmp_37, align 4
%tmp_46 = load i32* %i, align 4
%tmp_47 = load i32* %x.addr, align 4
%tmp_45 = sub i32 %tmp_46, %tmp_47
%tmp_48 = load i32* @n, align 4
%tmp_44 = add i32 %tmp_45, %tmp_48 
%tmp_43 = sub i32 %tmp_44, 1
%tmp_42 = getelementptr inbounds [40 x i32]* @r, i32 0, i32 %tmp_43
store i32 1, i32* %tmp_42, align 4
%tmp_50 = load i32* %x.addr, align 4
%tmp_49 = add i32 %tmp_50, 1 
%call51 = call i32 @dfs (i32  %tmp_49)
%tmp_54 = load i32* %i, align 4
%tmp_53 = getelementptr inbounds [20 x i32]* @b, i32 0, i32 %tmp_54
store i32 0, i32* %tmp_53, align 4
%tmp_58 = load i32* %i, align 4
%tmp_59 = load i32* %x.addr, align 4
%tmp_57 = add i32 %tmp_58, %tmp_59 
%tmp_56 = getelementptr inbounds [40 x i32]* @l, i32 0, i32 %tmp_57
store i32 0, i32* %tmp_56, align 4
%tmp_65 = load i32* %i, align 4
%tmp_66 = load i32* %x.addr, align 4
%tmp_64 = sub i32 %tmp_65, %tmp_66
%tmp_67 = load i32* @n, align 4
%tmp_63 = add i32 %tmp_64, %tmp_67 
%tmp_62 = sub i32 %tmp_63, 1
%tmp_61 = getelementptr inbounds [40 x i32]* @r, i32 0, i32 %tmp_62
store i32 0, i32* %tmp_61, align 4
br label %if.end32

if.else32:
br label %if.end32

if.end32:
br label %for.inc6

for.inc6:
%tmp_69 = load i32* %i, align 4
%tmp_68 = add i32 %tmp_69, 1 
store i32 %tmp_68, i32* %i, align 4
br label %for.cond6

for.end6:
ret i32 0
}
define i32 @main() {
entry:
%call70 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @n)
%tmp_72 = load i32* @n, align 4
%tmp_71 = icmp sgt i32 %tmp_72, 16
br i1 %tmp_71, label %if.then73, label %if.else73

if.then73:
%tmp_74 = sub i32 0, 1
%call75 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %tmp_74)
br label %if.end73

if.else73:
%call76 = call i32 @dfs (i32  0)
%tmp_77 = load i32* @ans, align 4
%call78 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %tmp_77)
br label %if.end73

if.end73:
ret i32 0
}
