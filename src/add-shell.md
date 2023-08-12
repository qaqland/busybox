# add-shell

## SYNOPSIS

    add-shell SHELL

## DESCRIPTION

把 SHELL 添加到 /etc/shells

修改默认 shell 时，用户的 shell 路径需要在 /etc/shells 存在，使用此命令可以添加 shell 的路径到这里。`SHELL` 代指 SHELL 的**路径**

注意，通过系统包管理器安装的 shell 会自动添加到这里，例如 fish 的
[fish.post-install](https://git.alpinelinux.org/aports/tree/main/fish/fish.post-install)
安装脚本中已包含此过程：

    #!/bin/sh
    add-shell '/usr/bin/fish'
    exit 0

## FILES

* `/etc/shells` 可用的登录 SHELL

## EXAMPLES

把路径添加到其中即可

    # add-shell /usr/bin/fish

注意以任意字符串为参数也不会报错。

## SEE ALSO

* [`adduser`](./adduser.md)
