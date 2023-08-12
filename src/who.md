# who

## SYNOPSIS

    who [-aH]

## DESCRIPTION

显示在线的用户

## OPTIONS

* `-a` 全部
* `-H` 表头

## WARNINGS

> Some programs like wall(1) depend on a libc feature named "utmp", that cannot be implemented in libc securely.
> For this reason, musl (the libc that Alpine uses) does not implement utmp. Instead, it provides stubs that do nothing.
>
> That is why programs that use utmp - such as wall, who or w - output nothing but still exit successfully. This is expected, a feature, and cannot be fixed easily.
>
> [_GNU core utilities - Alpine Linux_](https://wiki.alpinelinux.org/wiki/GNU_core_utilities)

此命令依赖 utmp 而 Alpine Linux 当前原生不支持（无法开箱即用），因此只会显示空白
