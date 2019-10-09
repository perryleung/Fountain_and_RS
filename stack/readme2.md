==动态测试下:
-1. 网络层:DrtPlus
-2. Mac层:new_aloha
-3. 节点配置文件的test模块的othernodeID要添加完

==静态界面传消息与图:
-1. 网络层是静态路由2
-2. Mac层:AlohaSpecial
-3. 节点配置文件的testmode要设为0

==增加节点的程序代码地方:
-1. usermainwindow.cpp
     case 5:
         tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 9084);
         break;
+    case 6:
+        tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 9085);
+        break;

-2. test_mode_panel.cpp
 void test_mode_panel::init_(){
-    int delay[5] = {0, 45, 110, 190};
+    int delay[6] = {2, 10, 20, 30, 40, 50};
     ui->btn_show_log->close();
     setWindowTitle("Test Config");
     node_list.push_back(ui->cb_node_1);
@@ -30,24 +30,28 @@ void test_mode_panel::init_(){
     node_list.push_back(ui->cb_node_3);
     node_list.push_back(ui->cb_node_4);
     node_list.push_back(ui->cb_node_5);
+    node_list.push_back(ui->cb_node_6);
 
     delay_list.push_back(ui->le_node_delay_1);
     delay_list.push_back(ui->le_node_delay_2);
     delay_list.push_back(ui->le_node_delay_3);
     delay_list.push_back(ui->le_node_delay_4);
     delay_list.push_back(ui->le_node_delay_5);
+    delay_list.push_back(ui->le_node_delay_6);
 
     packet_num_list.push_back(ui->le_packet_num_1);
     packet_num_list.push_back(ui->le_packet_num_2);
     packet_num_list.push_back(ui->le_packet_num_3);
     packet_num_list.push_back(ui->le_packet_num_4);
     packet_num_list.push_back(ui->le_packet_num_5);
+    packet_num_list.push_back(ui->le_packet_num_6);
 
     nodes_status_list.push_back(ui->lab_node_status_1);
     nodes_status_list.push_back(ui->lab_node_status_2);
     nodes_status_list.push_back(ui->lab_node_status_3);
     nodes_status_list.push_back(ui->lab_node_status_4);
     nodes_status_list.push_back(ui->lab_node_status_5);
+    nodes_status_list.push_back(ui->lab_node_status_6);

-3. showfigwidget.h	//添加的是偏移量
@@ -20,7 +20,7 @@ public:
     ~ShowFigWidget();
 
 public:
-    void set_send_image_status(int status);
+    void set_send_image_status(int status, int bodyIndex=0);

-4. server.cc
-#define MAX_CONNECTION 5
+#define MAX_CONNECTION 6

-5. select_node.cpp
 void select_node::init_(){
     setWindowTitle("Input Node ID");
-    ui->le_node_id->setValidator(new QIntValidator(1, 5, this));
+    ui->le_node_id->setValidator(new QIntValidator(1, 6, this));

-6. python_script/node_lib.py
@@ -31,9 +31,10 @@ CONFIG_B = os.path.join(STACK_DIR, 'configB.yaml')
 CONFIG_C = os.path.join(STACK_DIR, 'configC.yaml')
 CONFIG_D = os.path.join(STACK_DIR, 'configD.yaml')
 CONFIG_E = os.path.join(STACK_DIR, 'configE.yaml')
+CONFIG_F = os.path.join(STACK_DIR, 'configF.yaml')
 CONFIG_T = 'configC.yaml'
 
-all_config = [CONFIG_A, CONFIG_B, CONFIG_C, CONFIG_D, CONFIG_E]
+all_config = [CONFIG_A, CONFIG_B, CONFIG_C, CONFIG_D, CONFIG_E, CONFIG_F]
 
 tra = dict({'0':1})
 net = dict({'0':2, '1':5, '2':1})
@@ -74,7 +75,7 @@ def start_a_test_node(in_str):
 
     config = all_config[node_id - 1]
     command_header ="gnome-terminal -e 'bash -c \"ls; \" '"
-    shell_command1 = "python " + transmitPort_path + " "+ str(9080 + node_id - 1) + " "
+    shell_command1 = "~/anaconda2/bin/ipython " + transmitPort_path + " "+ str(9080 + node_id - 1) + " "
     shell_command = "sleep " + str(delay) + " && " + shell_command1 + " && "
     shell_command += os.path.join(STACK_DIR, 'RoastFish')
     shell_command += ' '
@@ -106,7 +107,7 @@ def show_test_log():
     log_name = a_test_log_dir + "/trace_handler.log"
     f = open(log_name,"w")
     f.close()
-    shell_command = "python " + TRACE_HANDLER_SERVER + " >> " + log_name + " | tail -f " + log_name 
+    shell_command = "~/anaconda2/bin/ipython " + TRACE_HANDLER_SERVER + " >> " + log_name + " | tail -f " + log_name 
     command_header ="gnome-terminal -e 'bash -c \"ls; \" '"
     command_header = command_header.replace('ls', shell_command)
     os.system(command_header)

-7. fsk_config.cpp
-    for(int i = 0; i<5; i++){
+    for(int i = 0; i<6; i++){

-8. 






































