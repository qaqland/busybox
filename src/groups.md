groups
=====

## SYNOPSIS

	groups [USER]


## DESCRIPTION

打印输出用户 USER 加入的所有组。
用户的工作组信息保存在 `/etc/group`，该命令简化了查看操作。

没有参数时打印输出 `<当前用户>` 的群组信息，但不等同于 `groups <当前用户>`，
后者不需要退出重新登录就能显示修改后的工作组。

BB 不支持 UID 仅支持用户名。

## FILES

* `/etc/group`

## OPTIONS

* `<USER>`  
	用户，默认值是当前用户

## EXAMPLES

不加参数为默认当前用户

	# groups
	qaq wheel audio input video netdev docker seat abuild


查看 root 用户加入的组

	# groups root
	root bin daemon sys adm disk wheel floppy dialout tape video

## SOURCE

https://github.com/mirror/busybox/blob/master/coreutils/id.c

## SEE ALSO

* [`addgroup`](./addgroup.md)
* [`delgroup`](./delgroup.md)

---

u=root,g=shadow 但是 root 不在 shadow 组中 🤔

```sh
localhost:~$ ls -l /etc | grep sha
-rw-r-----    1 root     shadow         742 Jan 18 12:55 shadow
-rw-r-----    1 root     shadow         873 Jan 18 12:54 shadow-
```

