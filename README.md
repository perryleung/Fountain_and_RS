# Fountain_and_RS
my work in master

==仿真步骤==

- 1.进入仿真信道文件夹启动仿真信道
$ python tornadoChannel.py

- 2.进入通信栈stack文件夹,在configX.yaml调整节点参数,在moduleconfig.h中调整各层协议
$ make clean
$ make
$ python start_nodes.py 1 2
上句命令是启动第一和第二节点

- 3.根据需要调整发送节点的ID和接收节点的ID
$ cd img_dwt/lib
$ vim stack_manager.py    备注:这是喷泉码
$ vim stack_file.py       备注:这是RS码

- 4.先启动接受端,再启动发送端,发送端和接收端需要在不同的终端
$ ~/anaconda2/bin/ipython stack_manager.py recv
$ ~/anaconda2/bin/ipython stack_manager.py send
