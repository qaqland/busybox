# id

## SYNOPSIS

    id [-ugGnr] [USER]

## DESCRIPTION

输出 USER 用户的相关信息。

没有 OPTIONS 时输出用户的所有信息，没有给定用户时默认当前用户。

## OPTIONS

| Option |     Meaning     |     Description      |
| :----: | :-------------: | :------------------: |
|  `-u`  |     User ID     | 用户 USER ID         |
|  `-g`  |    Group ID     | 本组 GROUP ID        |
|  `-G`  |    All Groups   | 追加组（所有组） ID  |
|  `-n`  | Name Not Number | 打印名称而非数字     |
|  `-r`  |   Real User ID  | 真实用户而非执行用户 |

## EXAMPLES

    $ id -u
    1000

    $ id -un
    qaq

    $ id -g
    1000

    $ id -G
    1000 10 18 27 28 103

常用等同于 `whoami`，查看当前用户名

    $ id -un
    qaq

## Real ID & Effective ID

> Real user id is the user that spawned the process.
>
> Effective user id is the user determined by the setuid bit on the binary being executed.
>
> [_Difference between Real User ID, Effective User ID and Saved User ID_](https://stackoverflow.com/questions/32455684/difference-between-real-user-id-effective-user-id-and-saved-user-id)

【演示】可执行脚本文件不允许设置 suid 或者不会生效，我们需要制作一个二进制文件

```c
{{#include demo/id-r.c}}
```

编译之后修改权限

    $ sudo chown root:root a.out
    $ sudo chmod ugo+sx a.out
    $ ls -l
    total 24
    -rwsr-sr-x    1 root     root         18272 Mar 21 23:22 a.out
    -rw-rw-rw-    1 qaq      qaq            208 Mar 21 23:21 id-r.c

可以看到程序的 real ID 是 qaq，effective ID 是 root

    $ ./a.out
    ruid:1000, euid:0

## SOURCE

<https://github.com/mirror/busybox/blob/master/coreutils/id.c>

## SEE ALSO

* [`whoami`](./whoami.md)

* <https://en.wikipedia.org/wiki/User_identifier>
