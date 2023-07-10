passwd
======

## SYNOPSIS

	passwd [-a ALG] [-dlu] [USER]

## DESCRIPTION

修改 USER 密码，默认当前用户

每个用户都在 `/etc/passwd` 有对应的一行

	root:x:0:0:root:/root:/bin/ash

依次为

	<用户名>:<密码>:<UID>:<GID>:<注释>:<用户家目录>:<登录终端解释器>

其中密码位为 `x` 表明密码在其它配置文件如 `/etc/shadow` 中保存。

系统用户不需要登录终端，因此可设为 busybox 提供的 `/sbin/nologin`。

## OPTIONS

* `-a <ALGORITHM>`  
	可选算法：des md5 sha256/512，默认 sha512
* `-d`  
	设置密码为空（删除密码）
* `-l`  
	锁定（关闭）账户
* `-u`  
	解锁（开启）账户

## FILES

* `/etc/passwd`
* `/etc/shadow`

## EXAMPLES

删除密码

	# passwd -d test-user
	passwd: password for test-user changed by root

与创建用户时不指定密码相比，后者有 `!` 前者没有，`!` 表示无法通过密码登录系统。

	# tail -n 2 /etc/shadow
	test-user::19377:0:99999:7:::
	test-user-2:!:19377:0:99999:7:::

## SOURCE

BusyBox 使用了一个 wrapper 处理权限问题

> `/usr/bin/passwd` links to `/bin/bbsuid` which is busybox's setuid wrapper,
> passwd can't link to `/bin/busybox` because it needs to be setuid,
> it comes from the busybox-suid package though
>
> _from alpine linux irc elly_

## SEE ALSO

* <https://linuxize.com/post/etc-shadow-file/>
* <https://stackoverflow.com/questions/24105498/what-do-and-mean-in-the-password-section-in-etc-shadow>

---

日常 sudo 输入的是当前用户的密码，可以把 sudoers 设置为免密，然后使用 passwd 删除密码。
（SSH 远程时记得保存密钥，不然再进不容易）
