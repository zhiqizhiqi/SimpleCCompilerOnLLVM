;author ZZQ
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @printf(i8*, ...)
declare i32 @__isoc99_scanf(i8*, ...)
@mat = common global [4 x i32] [i32 0, i32 1, i32 1, i32 1], align 4
@n = common global i32 zeroinitializer, align 4
@MOD = common global i32 10007, align 4
define i32 @solve(i32 %x) {
entry:
%x.addr = alloca i32, align 4
store i32 %x, i32* %x.addr, align 4
%p = alloca i32, align 4
%q = alloca i32, align 4
%r = alloca i32, align 4
%s = alloca i32, align 4
%ans = alloca [2 x i32], align 4
%arrayans.d0 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
store i32 0, i32* %arrayans.d0
%arrayans.d1 = getelementptr inbounds i32* %arrayans.d0, i32 1
store i32 1, i32* %arrayans.d1
br label %for.cond0

for.cond0:
%tmp_1 = load i32* %x.addr, align 4
%tmp_2 = icmp ne i32 %tmp_1, 0
br i1 %tmp_2, label %for.body0, label %for.end0

for.body0:
%tmp_4 = load i32* %x.addr, align 4
%tmp_3 = and i32 %tmp_4, 1
%tmp_5 = icmp ne i32 %tmp_3, 0
br i1 %tmp_5, label %if.then6, label %if.else6

if.then6:
%tmp_11 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
%tmp_10 = load i32* %tmp_11, align 4
%tmp_13 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
%tmp_12 = load i32* %tmp_13, align 4
%tmp_9 = mul i32 %tmp_10, %tmp_12
%tmp_16 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
%tmp_15 = load i32* %tmp_16, align 4
%tmp_18 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
%tmp_17 = load i32* %tmp_18, align 4
%tmp_14 = mul i32 %tmp_15, %tmp_17
%tmp_8 = add i32 %tmp_9, %tmp_14 
store i32 %tmp_8, i32* %p, align 4
%tmp_23 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
%tmp_22 = load i32* %tmp_23, align 4
%tmp_25 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
%tmp_24 = load i32* %tmp_25, align 4
%tmp_21 = mul i32 %tmp_22, %tmp_24
%tmp_28 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
%tmp_27 = load i32* %tmp_28, align 4
%tmp_30 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
%tmp_29 = load i32* %tmp_30, align 4
%tmp_26 = mul i32 %tmp_27, %tmp_29
%tmp_20 = add i32 %tmp_21, %tmp_26 
store i32 %tmp_20, i32* %q, align 4
%tmp_32 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
%tmp_34 = load i32* %p, align 4
%tmp_35 = load i32* @MOD, align 4
%tmp_33 = srem i32 %tmp_34, %tmp_35
store i32 %tmp_33, i32* %tmp_32, align 4
%tmp_37 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
%tmp_39 = load i32* %q, align 4
%tmp_40 = load i32* @MOD, align 4
%tmp_38 = srem i32 %tmp_39, %tmp_40
store i32 %tmp_38, i32* %tmp_37, align 4
br label %if.end6

if.else6:
br label %if.end6

if.end6:
%tmp_45 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
%tmp_44 = load i32* %tmp_45, align 4
%tmp_47 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
%tmp_46 = load i32* %tmp_47, align 4
%tmp_43 = mul i32 %tmp_44, %tmp_46
%tmp_50 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
%tmp_49 = load i32* %tmp_50, align 4
%tmp_52 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
%tmp_51 = load i32* %tmp_52, align 4
%tmp_48 = mul i32 %tmp_49, %tmp_51
%tmp_42 = add i32 %tmp_43, %tmp_48 
store i32 %tmp_42, i32* %p, align 4
%tmp_57 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
%tmp_56 = load i32* %tmp_57, align 4
%tmp_59 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
%tmp_58 = load i32* %tmp_59, align 4
%tmp_55 = mul i32 %tmp_56, %tmp_58
%tmp_62 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
%tmp_61 = load i32* %tmp_62, align 4
%tmp_64 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
%tmp_63 = load i32* %tmp_64, align 4
%tmp_60 = mul i32 %tmp_61, %tmp_63
%tmp_54 = add i32 %tmp_55, %tmp_60 
store i32 %tmp_54, i32* %q, align 4
%tmp_69 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
%tmp_68 = load i32* %tmp_69, align 4
%tmp_71 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
%tmp_70 = load i32* %tmp_71, align 4
%tmp_67 = mul i32 %tmp_68, %tmp_70
%tmp_74 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
%tmp_73 = load i32* %tmp_74, align 4
%tmp_76 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
%tmp_75 = load i32* %tmp_76, align 4
%tmp_72 = mul i32 %tmp_73, %tmp_75
%tmp_66 = add i32 %tmp_67, %tmp_72 
store i32 %tmp_66, i32* %r, align 4
%tmp_81 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
%tmp_80 = load i32* %tmp_81, align 4
%tmp_83 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
%tmp_82 = load i32* %tmp_83, align 4
%tmp_79 = mul i32 %tmp_80, %tmp_82
%tmp_86 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
%tmp_85 = load i32* %tmp_86, align 4
%tmp_88 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
%tmp_87 = load i32* %tmp_88, align 4
%tmp_84 = mul i32 %tmp_85, %tmp_87
%tmp_78 = add i32 %tmp_79, %tmp_84 
store i32 %tmp_78, i32* %s, align 4
%tmp_90 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
%tmp_92 = load i32* %p, align 4
%tmp_93 = load i32* @MOD, align 4
%tmp_91 = srem i32 %tmp_92, %tmp_93
store i32 %tmp_91, i32* %tmp_90, align 4
%tmp_95 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
%tmp_97 = load i32* %q, align 4
%tmp_98 = load i32* @MOD, align 4
%tmp_96 = srem i32 %tmp_97, %tmp_98
store i32 %tmp_96, i32* %tmp_95, align 4
%tmp_100 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
%tmp_102 = load i32* %r, align 4
%tmp_103 = load i32* @MOD, align 4
%tmp_101 = srem i32 %tmp_102, %tmp_103
store i32 %tmp_101, i32* %tmp_100, align 4
%tmp_105 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
%tmp_107 = load i32* %s, align 4
%tmp_108 = load i32* @MOD, align 4
%tmp_106 = srem i32 %tmp_107, %tmp_108
store i32 %tmp_106, i32* %tmp_105, align 4
br label %for.inc0

for.inc0:
%tmp_110 = load i32* %x.addr, align 4
%tmp_109 = lshr i32 %tmp_110, 1 
store i32 %tmp_109, i32* %x.addr, align 4
br label %for.cond0

for.end0:
%tmp_112 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
%tmp_111 = load i32* %tmp_112, align 4
ret i32 %tmp_111
}
define i32 @main() {
entry:
%call113 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @n)
%tmp_114 = load i32* @n, align 4
%call115 = call i32 @solve (i32  %tmp_114)
%call116 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %call115)
ret i32 0
}
