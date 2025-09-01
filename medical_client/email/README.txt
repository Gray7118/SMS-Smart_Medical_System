Email编译与运行流程说明
(序号前有#可以略过）

1. 清理旧库和临时文件
echo "清理旧库和临时文件..."
cd ~/桌面/Email/src
(共享目录:cd /mnt/hgfs/share/SMS-Smart_Medical_System/medical_client/email/src)

rm -f libSmtpMime.so* *.o moc_*.o

# 解释：删除上一次生成的动态库、对象文件以及 moc 文件，保证干净的编译环境




2. 编译 SMTPEmail 动态库
echo "编译 libSmtpMime.so..."
/opt/Qt5.12.8/5.12.8/gcc_64/bin/qmake SMTPEmail.pro
(共享目录:/opt/Qt5.12.8/5.12.8/gcc_64/bin/qmake SMTPEmail.pro)

make

# 解释：使用 Qt 5.12.8(根据自己版本进行修改） 的 qmake 生成 Makefile 并编译生成 libSmtpMime.so 动态库

补充：由于因为在 /mnt/hgfs/ 共享目录里不能建立符号链接 (ln -s)，所以这里需要手动：
cd /mnt/hgfs/share/SMS-Smart_Medical_System/medical_client/email/src
cp libSmtpMime.so.2.0.0 libSmtpMime.so
cp libSmtpMime.so.2.0.0 libSmtpMime.so.2
cp libSmtpMime.so.2.0.0 libSmtpMime.so.2.0

3. 编译 demo2 可执行文件
cd ~/桌面/Email/demos/demo2
(共享目录:cd /mnt/hgfs/share/SMS-Smart_Medical_System/medical_client/email/demos/demo2)

/opt/Qt5.12.8/5.12.8/gcc_64/bin/qmake demo2.pro
(共享目录:/opt/Qt5.12.8/5.12.8/gcc_64/bin/qmake demo2.pro)

make

# 解释：生成 demo2 可执行文件，需要链接 libSmtpMime.so

补充：同理，由于因为在 /mnt/hgfs/ 共享目录里不能建立符号链接 (ln -s)，需要手动：
cd /mnt/hgfs/share/SMS-Smart_Medical_System/medical_client/email/demos/demo2
cp libSmtpMime.so.2.0.0 libSmtpMime.so.2
cp libSmtpMime.so.2.0.0 libSmtpMime.so

#4. 拷贝库到 demo2 目录
#echo "拷贝 libSmtpMime.so* 到 demo2 目录..."
#cp ~/桌面/Email/src/libSmtpMime.so* .
# 解释：把动态库拷贝到 demo2 可执行文件所在目录，方便运行时找到库

（运行到这里就可以了！可以完成后面两步来检测是否成功运行,建议第一次运行的时候还是运行一下）


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)

./demo2






#5. 设置运行时库路径
#echo "设置 LD_LIBRARY_PATH..."
#export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
# 解释：将当前目录加入 LD_LIBRARY_PATH，使得运行时可以加载 #libSmtpMime.so

#6. 运行 demo2
#echo "运行 demo2..."
#./demo2
# 解释：直接运行 demo2 可执行文件，启动邮件发送界面

