su
===

## SYNOPSIS

	su [-lmp] [-s SH] [-] [USER [FILE ARGS | -c 'CMD' [ARG0 ARGS]]]

## DESCRIPTION

正如命令的全称 **su**bstitute 或 **s**witch **u**ser，在当前会话中切换用户。
需要输入目标用户的密码，未指定目标用户时默认 root 用户。会话的环境变量将会被替代，但是当前路径不变。

对 su 会暴露目标用户如 `root` 的更多信息，所以更推荐使用 sudo、doas 执行需要权限的命令。

## ENVIRONMENT

* $HOME
* $SHELL
* $USER
* $LOGNAME

## OPTIONS

* `-, -l` login  
	清除环境变量，切换到目标用户的家目录，以登录 shell 运行
* `-p, -m` preserve-environment  
	保留当前的环境变量，不修改 $HOME, $SHELL, $USER, $LOGNAME
* `-c <CMD> [ARG0 ARGS]`  
	不进入交互式终端，仅执行调用
* `-s <SHELL>`  
	切换用户后运行的终端，需要注意是否在 `/etc/shells` 中



## EXAMPLES

执行命令即退出，使用 whoami 查看用户身份

	$ su -c whoami
	Password:
	root
	$ whoami
	qaq


## SOURCE

https://github.com/mirror/busybox/blob/master/loginutils/su.c

## SEE ALSO

* <https://linuxize.com/post/su-command-in-linux/>
* <https://phoenixnap.com/kb/sudo-vs-su-differences>
* <https://superuser.com/questions/785187/sudoedit-why-use-it-over-sudo-vi/1062377#1062377>
* <https://unix.stackexchange.com/questions/1262/where-did-the-wheel-group-get-its-name>

---

su 需要输入的是目标用户的密码，而 sudo 输入的是当前用户的密码。

有的发行版禁用 root 登录，可以使用 `sudo su` 或 `sudo -i` 进入 root 用户。

**visudo** 为编辑 sudoers 配置文件专用，它会锁定文件避免多人同时编辑，以及检查权限。

	# This file MUST be edited with the 'visudo' command as root.

**sudoedit** 为编辑任意文件用，避免以 root 身份运行编辑器，同时能保留编辑器的配置插件等。

	$ sudoedit /etc/hosts

**doas** 是 OpenBSD 出品的 sudo 替代，它的配置文件是 `/etc/doas.d/doas.conf`。

	permit persist :wheel

permit 表示加入 wheel 组的用户可以使用 root，persist 表示在一段时间内不需要再次输入密码。
