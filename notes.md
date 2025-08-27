## 安装 Boost 1.86.0

``` shell
sudo apt update
sudo apt install build-essential libssl-dev

# 把boost下载到当前用户的“下载”目录
wget -P ~/Downloads https://archives.boost.io/release/1.86.0/source/boost_1_86_0.tar.bz2

# 切换到Downloads目录
cd
cd Downlodas

# 解压
tar -xzf boost_1_86_0.tar.gz

# 进入解压之后的目录
cd boost_1_86_0/

# 编译和安装
./bootstrap.sh --prefix=/usr/local
sudo ./b2 install

# 配置环境变量
sudo nano /etc/ld.so.conf.d/boost.conf

# 在文件中添加 Boost 库路径：
/usr/local/lib
# 保存退出（按 Ctrl+X，然后 Y，最后 Enter）

# 更新动态链接器缓存
sudo ldconfig

# 检查 Boost 版本，确认安装成功：
cat /usr/local/include/boost/version.hpp | grep "BOOST_LIB_VERSION"
```





