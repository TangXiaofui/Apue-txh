man awk

awk '{pattern + action}' {filename}
pattern 表示 AWK 在数据中查找的内容，而 action 是在找到匹配内容时所执行的一系列命令。花括号（{}）不需要在程序中始终出现，但它们用于根据特定的模式对一系列指令进行分组。 pattern就是要表示的正则表达式，用斜杠括起来。

1.命令行方式
awk [-F  field-separator]  'commands'  input-file(s)
其中，commands 是真正awk命令，[-F域分隔符]是可选的。 input-file(s) 是待处理的文件。
在awk中，文件的每一行中，由域分隔符分开的每一项称为一个域。通常，在不指名-F域分隔符的情况下，默认的域分隔符是空格。

2.shell脚本方式
将所有的awk命令插入一个文件，并使awk程序可执行，然后awk命令解释器作为脚本的首行，一遍通过键入脚本名称来调用。
相当于shell脚本首行的：#!/bin/sh
可以换成：#!/bin/awk

3.将所有的awk命令插入一个单独文件，然后调用：
awk -f awk-script-file input-file(s)
其中，-f选项加载awk-script-file中的awk脚本，input-file(s)跟上面的是一样的。


usage:
	last -n 5 | awk '{print $1}' 
	awk工作流程是这样的：读入有'\n'换行符分割的一条记录，然后将记录按指定的域分隔符划分域，填充域，$0则表示所有域,$1表示第一个域,$n表示第n个域。默认域分隔符是"空白键" 或 "[tab]键",所以$1表示登录用户，$3表示登录用户ip,以此类推。

	cat /etc/passwd |awk  -F ':'  '{print $1}' 
	这种是awk+action的示例，每行都会执行action{print $1}。-F指定域分隔符为':'。	

 	cat /etc/passwd |awk  -F ':'  'BEGIN {print "name,shell"}  {print $1"\t"$7} END {print "blue\t/bin/nosh"}'
	awk工作流程是这样的：先执行BEGING，然后读取文件，读入有/n换行符分割的一条记录，然后将记录按指定的域分隔符划分域，填充域，$0则表示所有域,$1表示第一个域,$n表示第n个域,随后开始执行模式所对应的动作action。接着开始读入第二条记录······直到所有的记录都读完，最后执行END操作。

	awk -F: '/root/' /etc/passwd
	这种是pattern的使用示例，匹配了pattern(这里是root)的行才会执行action(没有指定action，默认输出每行的内容)。	搜索支持正则，例如找root开头的: awk -F: '/^root/' /etc/passwd

	awk -F: '/root/{print $7}' /etc/passwd             

	awk  -F ':'  '{printf("filename:%10s,linenumber:%s,columns:%s,linecontent:%s\n",FILENAME,NR,NF,$0)}' /etc/passwd
	ARGC               命令行参数个数
	ARGV               命令行参数排列
	ENVIRON            支持队列中系统环境变量的使用
	FILENAME           awk浏览的文件名
	FNR                浏览文件的记录数
	FS                 设置输入域分隔符，等价于命令行 -F选项
	NF                 浏览记录的域的个数
	NR                 已读的记录数
	OFS                输出域分隔符
	ORS                输出记录分隔符
	RS                 控制记录分隔符

	awk '{count++;print $0;} END{print "user count is ", count}' /etc/passwd
	awk 'BEGIN {count=0;print "[start]user count is ", count} {count=count+1;print $0;} END{print "[end]user count is ", count}' /etc/passwd

	统计某个文件夹下的文件占用的字节数
	ls -l | awk 'BEGIN{size=0} {size = size + $5} END{print size}'
	ls -l |awk 'BEGIN {size=0;print "[start]size is ", size} {if($5!=4096){size=size+$5;}} END{print "[end]size is ", size/1024/1024,"M"}' 
	awk -F ':' 'BEGIN {count=0;} {name[count] = $1;count++;}; END{for (i = 0; i < NR; i++) print i, name[i]}' /etc/passwd	
