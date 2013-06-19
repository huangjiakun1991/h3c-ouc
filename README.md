README
======
h3c-ouc 是适用于中国海洋大学宿舍区的 h3c UNIX/Linux 下上网客户端，主要依赖 libpcap 和 libgcrypt 库。我们的目的就是通过研究学习 h3c 802.1x 上网认证系统的协议和认证机制，开发 UNIX/Linux 下上网客户端，并方便 UNIX/Linux 用户上网。目前的版本支持 CLI（Command Line Interface）方式和GUI（Graphical User Interface）方式，其中GUI方式中带有二次认证，CLI方式的二次认证正在开发中。

## CONTACT
如果您对我们的代码或者对我们以后的版本有什么建议，请联系我们的邮箱 huangjiakun1991@gmail.com 或 cuiluji@gmail.com。

## WEBSITE
我们的项目网站：https://github.com/huangjiakun1991/h3c-ouc/，其中提供源代码下载。

## INSTALLATION
Ubuntu 10.10

### CLI
安装依赖库 libpcap 和 libgcrypt：
 $ sudo apt-get install libpcap-dev
 $ sudo apt-get install libgcrypt-dev

编译：
 $ tar xvfz /path/to/h3c-ouc-x.x.tar.gz
 $ cd /path/to/h3c-ouc/
 $ make CLI

安装：
 $ sudo make install-CLI

### GUI
运行需要Pyhton环境，Linux系统一般默认安装Python。 依赖模块wxPython:
 $ sudo apt-get install python-wxtools
或者下载源代码安装，网址：http://www.wxpython.org/download.php#stable。
 
编译：
 $ tar xvfz /path/to/h3c-ouc-x.x.tar.gz
 $ cd /path/to/h3c-ouc/
 $ make GUI

安装：
 $ sudo make install-GUI

### ALL
包括CLI和GUI

编译：
 $ tar xvfz /path/to/h3c-ouc-x.x.tar.gz
 $ cd /path/to/h3c-ouc/
 $ make

安装：
 $ sudo make install


USAGE
=====
## CLI
规则：h3c_ouc -u [用户名] -p [密码] -d [网卡名称]
使用 h3c_ouc -u 按照提示输入。
使用 h3c_ouc -l [网卡名称] 注销登录。
使用 h3c_ouc --help 来查看详细帮助。 
目前认证完后需要在网页进行二次登录，不需要二次认证的功能正在开发中。 

## GUI
参照界面的提示执行。

UNINSTALLATION
==============
 $ cd /path/to/h3c-ouc/

## CLI
 $ make uninstall-CLI

## GUI
 $ make uninstall-GUI

## ALL
 $ make uninstall
