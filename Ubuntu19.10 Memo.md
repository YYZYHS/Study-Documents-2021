# Pratical Training Memo（Ubuntu19.10）

[toc]

## 安装谷歌输入法

[Ubuntu上如何安装谷歌输入法][下载谷歌输入法]

[ubuntu安装谷歌输入法][配置谷歌输入法]

```shell
sudo apt-get update
sudo apt-get install fcitx-googlepinyin
# 配置Fcitx
# 设置->区域与语言->管理已安装的语言
# 语言支持->语言->键盘输入法系统：(IBus->fcitx)
sudo reboot
fcitx-configtool
# 查看列表里面有没有googlepinyin
# 如果没有，点击左下角的+号
# 取消复选框：Only Show Current Language
# 输入框(Search Input Language)输入googlepinyin
# 不要将googlepinyin放在Input Method的第一位
sudo reboot
```

[Linux安装中文输入法（Google拼音输入法）](<https://blog.csdn.net/arackethis/article/details/42154029>)

```shell
sudo apt-get remove fcitx*
# 删除之前安装失败的内容
sudo apt-get autoremove
# 删除依赖库
sudo apt-get remove ibus
# 删除默认安装的ibus
# 添加fcitx的nightlyPPA。有两种方式：
# 方法一： 在源中添加nightly源。
sudo gedit /etc/apt/sources.list
# 加入以下两行：
# deb http://ppa.launchpad.net/fcitx-team/nightly/ubuntu quantal main
# deb-src http://ppa.launchpad.net/fcitx-team/nightly/ubuntu quantal main
# 然后：
sudo apt-get update
# 方法二： PPA，在终端输入：
sudo add-apt-repository ppa:fcitx-team/nightly
# 安装fcitx，Google输入法，云输入法
sudo apt-get install fcitx fcitx-config-gtk fcitx-sunpinyin fcitx-googlepinyin fcitx-module-cloudpinyin
sudo apt-get install fcitx-table-all
# 设置fcitx为默认输入法
sudo im-switch -s fcitx -z default
```

## 安装搜狗输入法

[ubuntu16.04安装搜狗输入法][安装搜狗输入法]

```shell
# 下载搜狗输入法Linux版，并移动至Ubuntu下
sudo apt-get install fcitx libssh2-1
sudo apt-get install -f
sudo dpkg -i sogoupinyin_2.3.1.0112_amd64.deb
# 安装fcitx：
sudo apt-get install fcitx
# 安装fcitx的配置工具：
sudo apt-get install fcitx-config-gtk
# 安装fcitx的table-all软件包:
sudo apt-get install fcitx-table-all
# 安装im-switch切换工具：
sudo apt-get install im-switch
# 重启
sudo reboot
fcitx-config-gtk3
```

## 安装Visual Studio Code

[ubuntu安装vscode的两种方法][安装vsCode]

```shell
# 方法1：
sudo add-apt-repository ppa:ubuntu-desktop/ubuntu-make
sudo apt-get update
sudo apt-get install ubuntu-make
umake ide visual-studio-code
# 方法2：
# 下载deb安装包
sudo  dpkg  -i   code_1.31.1-1549938243_amd64.deb
```

## 修改Ubuntu计算机名称

```shell
sudo gedit /etc/hostname
sudo reboot
```

## 安装gcc4.8

[Ubuntu 18.04安装gcc(4.8、4.9)、g++(4.8、4.9)][安装gcc4.8]

```shell
# 1.手动加入更新源
sudo apt-get remove gcc
sudo gedit /etc/apt/sources.list
# sources.list最后添加内容
# deb http://dk.archive.ubuntu.com/ubuntu/ xenial main
# deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe
sudo apt update

# 2.安装
sudo apt-get install gcc-4.8

# 3.更新
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 20
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 20

# 4.验证
gcc --version
```

## 安装vim

```shell
sudo apt-get install vim
```

## 安装交叉编译器

[bash: /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-gcc: 没有那个文件或目录][找不到arm-linux-gcc]

```shell
# 解压缩
sudo tar xvzf arm-linux-gcc-4.5.1-v6-vfp-20101103.tgz -C /
# dr_hayden@VEGA:~$下
vim .bashrc
# 行尾添加：
    ####arm-linux-gcc
    export PATH=/opt/FriendlyARM/toolschain/4.5.1/bin:$PATH
source .bashrc
# bash: /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-gcc: 没有那个文件或目录
sudo apt-get install lsb-core
sudo apt-get install g++-multilib
arm-linux-gcc -v
```

## 安装tslib

[tslib安装与测试][19.10安装tslib]

```shell
sudo mv tslib-1.4.tar.gz /opt
sudo tar zxvf tslib-1.4.tar.gz
cd tslib/
#创建安装目录
mkdir tmp
#设置参数
$ echo "ac_cv_func_malloc_0_nonnull=yes" >arm-linux.cache
#配置到tmp目录下
sudo ./configure --host=arm-linux --cache-file=arm-linux.cache --prefix=$(pwd)/tmp
#编译
sudo make
sudo make install
#安装到temp目录下
#进入tmp, 将tmp里面的bin ，etc，include，lib4个目录下的文件拷贝到文件系统的bin ，etc，include，lib4个目录下  
cd tmp
#强制拷贝temp/下所有文件到/文件系统根目录/下,-d:保持链接，原来的是链接，复制过来的还是链接
sudo mkdir /usr/local/tslib
sudo cp * /usr/local/tslib/ -rfd
#考完bin ，etc，include，lib 4个目录下的所有文件

```

## 安装Qt Creator

```shell
./qt-creator-linux-x86_64-opensource-2.5.2.bin
```

## Qt库源码

```shell
tar zxvf qt-everywhere-opensource-src-4.8.5.tar.gz
sudo cp -r qt-everywhere-opensource-src-4.8.5/ /usr/local/
sudo cd /usr/local/
sudo mv qt-everywhere-opensource-src-4.8.5/ qt-pc
cd /home/dr_hayden/Program/Training/
sudo cp -r qt-everywhere-opensource-src-4.8.5/ /usr/local/
sudo mv qt-everywhere-opensource-src-4.8.5/ qt-arm
```

### Qt-PC

```shell
sudo ./configure
# Basic XLib functionality test failed!
sudo apt-get install libx11-dev libxext-dev libxtst-dev
sudo ./configure
sudo make
sudo make install
```

### Qt-ARM

```shell
sudo vim /usr/local/qt-arm/mkspecs/qws/linux-arm-g++/qmake.conf

#对文件中内容覆盖
# modifications to g++.conf
QMAKE_CC                = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-gcc -lts
QMAKE_CXX               = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-g++ -lts
QMAKE_LINK              = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-g++ -lts
QMAKE_LINK_SHLIB        = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-g++ -lts
# modifications to linux.conf
QMAKE_AR                = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-ar cqs
QMAKE_OBJCOPY           = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-objcopy
QMAKE_STRIP             = /opt/FriendlyARM/toolschain/4.5.1/bin/arm-linux-strip

sudo ./configure -prefix /usr/local/Trolltech/QtEmbedded-4.8.5-arm -opensource -confirm-license -release -shared -embedded arm -xplatform qws/linux-arm-g++ -depths 16,18,24 -fast -optimized-qmake -pch -qt-sql-sqlite -qt-libjpeg -qt-zlib -qt-libpng -qt-freetype -little-endian -host-little-endian -no-qt3support -no-libtiff -no-libmng -no-opengl -no-mmx -no-sse -no-sse2 -no-3dnow -no-openssl -no-webkit -no-qvfb -no-phonon -no-nis -no-opengl -no-cups -no-glib -no-xcursor -no-xfixes -no-xrandr -no-xrender -no-pch -no-separate-debug-info -nomake examples -nomake tools -nomake docs -qt-mouse-tslib -I/usr/local/tslib/include -L/usr/local/tslib/lib

sudo make
sudo make install

```

## ffmpeg

### 安装ffmpeg

```shell
sudo gedit /etc/apt/sources.list
#注释安装gcc-4.8时加入的：
# deb http://dk.archive.ubuntu.com/ubuntu/ xenial main
# deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe
sudo apt update
sudo apt-get -y install autoconf automake build-essential libass-dev libfreetype6-dev libsdl2-dev libtheora-dev libtool libva-dev libvdpau-dev libvorbis-dev libxcb1-dev libxcb-shm0-dev libxcb-xfixes0-dev pkg-config texinfo zlib1g-dev
sudo apt-get install yasm
sudo apt-get install libx264-dev
sudo apt-get install libfdk-aac-dev
sudo apt-get install libmp3lame-dev
sudo apt-get install libopus-dev
sudo apt-get install libvpx-dev
cd /home/dr_hayden/Share/
tar xjvf ffmpeg-3.3.9.tar.bz2
cd ffmpeg-3.3.9/
./configure --prefix=/usr/local/ffmpeg --enable-shared --enable-libx264 --enable-libfdk-aac --enable-libmp3lame --enable-libopus --enable-libvpx --enable-nonfree --enable-gpl
sudo make
sudo make install
cd /usr/local/ffmpeg/lib/
sudo cp * /usr/lib/
sudo cp * /usr/lib/ -rdf
cd ../include/
sudo cp * /usr/include/ -rdf
sudo gedit /etc/profile
#在文件末尾添加
#export FFMPEG_HOME=/usr/local/ffmpeg
#export PATH=$FFMPEG_HOME/bin:$PATH
source /etc/profile
sudo gedit /etc/ld.so.conf
sudo ldconfig -v
```

### 在项目中配置ffmpeg

1. 在项目目录下建个文件夹 ffmpeg，拷贝到这个文件夹

2. 把/usr/local/ffmpeg	lib 和 include 文件拷贝到 QT 项目的 ffmpeg 文件夹（可以不加，也可以加）
3. 在Qt项目xxx.pro文件中添加下面两句话：

```pro
INCLUDEPATH += ./ffmpeg/include
LIBS += -L./ffmpeg/lib/ -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lpostproc -lswscale -lswresample
```

[非常详细的Qt PRO文件语法介绍][pro文件语法]
<!-- 备用链：<https://blog.csdn.net/adriano119/article/details/5878169> -->

[下载谷歌输入法]:https://jingyan.baidu.com/article/49711c618fe633fa441b7c38.html
[配置谷歌输入法]:https://blog.csdn.net/chan70707/article/details/82980499
[安装搜狗输入法]:https://blog.csdn.net/xiaxuesong666/article/details/75127425
[安装vsCode]:https://blog.csdn.net/q357010621/article/details/87891694?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522159064139619195162541547%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=159064139619195162541547&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v2~pc_rank_v3-1-87891694.first_rank_ecpm_v2_pc_rank_v3&utm_term=ubuntu%E5%AE%89%E8%A3%85vscode
[安装gcc4.8]:https://blog.csdn.net/broliao/article/details/104613443
[找不到arm-linux-gcc]:https://blog.csdn.net/floatinglong/article/details/82704390?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase
[19.10安装tslib]:https://blog.csdn.net/qq_22122811/article/details/64541428
[pro文件语法]:https://blog.csdn.net/steven6977/article/details/9124539

