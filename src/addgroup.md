# addgroup

## SYNOPSIS

    addgroup [-g GID] [-S] [USER] GROUP

## DESCRIPTION

新增工作组或添加用户到组。

如果调用时有两个参数 USER 和 GROUP，会将已经存在的用户 USER 添加到已经存在的工作组 GROUP 中。

## FILES

* `/etc/group`  
    工作组及用户信息，见 groups
* `/etc/shadow`  
    密码

## OPTIONS

* `-g <GROUP-ID>`  
    工作组 ID（Group ID）

* `-S`  
    指定为**系统**工作组（System Group）

### System Groups

> There is no inherent difference between system groups and 'normal' groups, just like there is none between system users and regular users. It is by convention that human users are assigned uids from a certain number (e.g. 1000) upwards, whereas system users get uids in a range below that number.
>
> **The actual uid number, apart from the special uid 0 which is reserved for `root`, has no meaning at all and does not convey any privileges.**
>
> We distinguish system users and regular users only because they are treated differently. For instance, there is no point in displaying system users in a graphical login manager. Also, most system users don't need a login shell or home directory, whereas human users (normally) do.
>
> <https://askubuntu.com/questions/523949/what-is-a-system-group-as-opposed-to-a-normal-group>

与系统用户相似，除了创建工作组时 ID 的选取范围不同外，系统工作组和普通工作组没有区别

## EXAMPLES

新建组

    addgroup test-group

添加用户 `qaq` 到组

    addgroup qaq test-group

## SOURCE

<https://github.com/mirror/busybox/blob/master/loginutils/addgroup.c>

## SEE ALSO

* [`delgroup`](./delgroup.md)

* <https://man.archlinux.org/man/groupadd.8>
