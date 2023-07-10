chpasswd
========

## SYNOPSIS

	chpasswd [-me] [-c ALG] [-R DIR]

## DESCRIPTION

从标准读取用户名和密码的键值对，用此信息更新用户密码。

用户名和密码格式为每行有 `username:password`，用户需要已经存在。

如果没有启用 `/etc/shadow` 就更新 `/etc/passwd` 中的数据。

与 passwd 的交互式设置密码不同，chpasswd 是命令流控制的批量修改，适用于一次性修改多个帐户的大型系统。

## OPTIONS

* `-e, --encrypted`   
	加密形式的密码
* `-m, --md5`  
	使用 MD5
* `-c, --crypt-method <ALGORITHM>`   
	可选算法：des md5 sha256/512，默认 sha512
* `-R, --root <CHROOT_DIR>`  
	修改 chroot 系统的用户密码

## EXAMPLES

直接执行后等待输入，完成时 <kbd>Ctrl+d</kbd> 结束输入 

	# chpasswd
	test-user-2:123
	chpasswd: password for 'test-user-2' changed
	
也可使用重定向从配置文件读取修改

	chpasswd < users.txt

重定向从管道读取

	echo "test-user-2:123" | chpasswd

## SOURCE

<https://github.com/mirror/busybox/blob/master/loginutils/chpasswd.c>  
<https://github.com/mirror/busybox/blob/master/include/usage.src.h>


## SEE ALSO

* [`passwd`](./passwd.md)

* <https://unix.stackexchange.com/questions/345459/whats-the-difference-between-passwd-and-chpasswd>