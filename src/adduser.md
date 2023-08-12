# adduser

## SYNOPSIS

    adduser [OPTIONS] USER [GROUP]

## DESCRIPTION

创建新用户或添加用户 USER 到工作组 GROUP

## FILES

* `/etc/group`  
    工作组及用户信息，见 groups

## OPTIONS

* `-h <HOME-DIR>`       用户家目录
* `-g <GECOS>`          备注栏
* `-s <LOGIN-SHELL>`    用户登录终端
* `-G <GROUP>`          工作组
* `-S`                  系统用户
* `-D`                  不分配密码
* `-H`                  不创建家目录
* `-u <USER-ID>`        用户 ID
* `-k <SKEL>`           用户家目录的初始模板 Skeleton Directory

### System User

// TODO 系统用户与普通用户的区别

### Login Shell

用户登录终端，系统用户可以指定为 nologin

### Skeleton Directory

> Directory `/etc/skel/` (skel is derived from the “skeleton”) is used to initiate home directory when a user is first created.
>
> <https://www.thegeekdiary.com/understanding-the-etc-skel-directory-in-linux/>

不过 Alpine Linux 默认没有 `/etc/skel`，文中提到的记录 SKEL 的配置文件 `/etc/default/useradd` 也不存在

## EXAMPLES

创建用户 test-user 并添加到已存在的工作组

    # adduser -G qaq -H test-user
    Changing password for test-user
    New password:
    Retype password:
    passwd: password for test-user changed by root

创建用户 test-user-2 时指定无密码

    adduser -H -D test-user-2

添加用户到工作组

    adduser test-user-2 writefreely

## SEE ALSO

* [groups](./groups.md)
* [deluser](./deluser.md)
* [passwd](./passwd.md)
