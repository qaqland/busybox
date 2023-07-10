# BB 中

以下是可能用到的环境布置

## mdbook

	mdbook serve -n 0.0.0.0 -p 3030

## docker

安装 docker 并把用户添加到 docker 工作组，这样以后就不用每次 sudo 了

	# apk add docker
	# addgroup <user> docker

添加 docker 守护进程的自启动，并手动开启服务（再重启不用手动）

	# rc-update add docker default
	# rc-service docker start

拉取 alpine Linux 的镜像到本地，默认是 last 标签

	$ docker pull alpine

编写 `Dockerfile` 如下，期望是进入容器使用 fish 终端

	FROM alpine
	RUN apk add fish
	CMD /usr/bin/fish

在当前文件夹内执行构建镜像

	docker build -t fish-alpine

随便找个地方运行实例

	docker run -it fish-alpine

没有保存数据，退出即销毁

## strace

查看系统调用

	strace -f -e trace=open,stat,read,write,execve,file [CMD...]

---

## NAME
## SYNOPSIS
## DESCRIPTION
## OPTIONS
## SYNTAX
## ENVIRONMENT
## FILES
## EXAMPLES
## EXIT STATUS
## STANDARDS
## WARNINGS
## BUGS
## SOURCE
## AUTHOR
## SEE ALSO

