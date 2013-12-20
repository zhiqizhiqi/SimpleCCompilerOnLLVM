;author ZZQ
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @printf(i8*, ...)
declare i32 @__isoc99_scanf(i8*, ...)
%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld = type {i32}
%struct.haoehaoehaoewozhendehaoe = type {i32,i32,i32,i32}
%struct.doubleO = type {i32,i32,i32,i32,i32}
@A = common global %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@B = common global %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@C = common global %struct.haoehaoehaoewozhendehaoe zeroinitializer, align 4
@R = common global %struct.doubleO zeroinitializer, align 4
@G = common global %struct.doubleO zeroinitializer, align 4
@T = common global %struct.doubleO zeroinitializer, align 4
define i32 @main() {
entry:
%tmp_1 = getelementptr inbounds %struct.doubleO* @T, i32 0, i32 0
%call2 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %tmp_1)
%tmp_4 = getelementptr inbounds %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld* @A, i32 0, i32 0
%call5 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %tmp_4)
%tmp_7 = getelementptr inbounds %struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 1
%call8 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %tmp_7)
%tmp_11 = getelementptr inbounds %struct.doubleO* @G, i32 0, i32 1
%tmp_15 = getelementptr inbounds %struct.doubleO* @T, i32 0, i32 0
%tmp_14 = load i32* %tmp_15, align 4
%tmp_18 = getelementptr inbounds %struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 1
%tmp_17 = load i32* %tmp_18, align 4
%tmp_12 = xor i32 %tmp_14, %tmp_17
store i32 %tmp_12, i32* %tmp_11, align 4
%tmp_22 = getelementptr inbounds %struct.doubleO* @G, i32 0, i32 1
%tmp_21 = load i32* %tmp_22, align 4
%tmp_25 = getelementptr inbounds %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld* @A, i32 0, i32 0
%tmp_24 = load i32* %tmp_25, align 4
%tmp_19 = icmp eq i32 %tmp_21, %tmp_24
br i1 %tmp_19, label %if.then26, label %if.else26

if.then26:
%tmp_29 = getelementptr inbounds %struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0
store i32 215, i32* %tmp_29, align 4
br label %if.end26

if.else26:
%tmp_32 = getelementptr inbounds %struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0
store i32 0, i32* %tmp_32, align 4
br label %if.end26

if.end26:
%tmp_35 = getelementptr inbounds %struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0
%tmp_34 = load i32* %tmp_35, align 4
%call36 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %tmp_34)
%tmp_38 = getelementptr inbounds %struct.doubleO* @R, i32 0, i32 2
%call39 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %tmp_38)
%tmp_42 = getelementptr inbounds %struct.doubleO* @R, i32 0, i32 2
%tmp_41 = load i32* %tmp_42, align 4
%tmp_43 = icmp ne i32 %tmp_41, 0
br i1 %tmp_43, label %if.then44, label %if.else44

if.then44:
%call45 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  215)
br label %if.end44

if.else44:
%tmp_46 = sub i32 0, 215
%call47 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32  %tmp_46)
br label %if.end44

if.end44:
ret i32 0
}
