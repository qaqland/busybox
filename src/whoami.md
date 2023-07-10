whoami
======

## SYNOPSIS

	whoami

## DESCRIPTION

输出当前用户关联的执行用户。

用户使用此命令可以以此知道自己正在使用的用户。

脚本运行时检测是否提权。

## ENVIRONMENT

* `$USER` 有差异：环境变量不会显示执行用户 ID，除此之外相同

## Example

打印当前用户名，等同于 `id -un`

	$ whoami
	qaq


还可使用此命令检测用户是否具有 sudo 权限，这里的 root 即为执行用户

	$ sudo whoami
	root


## See also

* [`id`](./id.md)
