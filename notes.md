## 小组项目 Github 工作流程

``` bash
# =====================================
# 🚀 小组项目 GitHub 单人工作完整流程
# =====================================

# 0. 克隆仓库（第一次参与时才需要）
git clone 仓库地址
cd 仓库目录

# ------------------------------------------------
# 1. 每次开始写代码前，先更新本地 main 分支
# ------------------------------------------------
git checkout main               # 切换到主分支
git pull origin main            # 拉取远端最新代码，保持和团队一致

# ------------------------------------------------
# 2. 从 main 新建一个自己的开发分支
# ------------------------------------------------
# 分支命名建议: feature/xxx 或 fix/xxx
git checkout -b feature/任务名称

# （例子：我要做登录功能）
# git checkout -b feature/login

# ------------------------------------------------
# 3. 在自己的分支上开发
# ------------------------------------------------
# 编辑代码...（写代码、加文件、改文件）
# 完成后保存改动并提交
git add .                               # 添加改动
git commit -m "feat: 完成登录接口"      # 提交改动（commit 信息要写清楚）

# ------------------------------------------------
# 4. 保持分支最新，避免冲突
# ------------------------------------------------
# 在推送前，把 main 的最新改动合并到当前分支
git checkout main
git pull origin main                   # 更新主分支
git checkout feature/任务名称
git merge main                         # 合并最新 main

# 👉 如果有冲突，手动修改冲突的文件，
# 然后再次 git add . && git commit -m "fix: 解决冲突"

# ------------------------------------------------
# 5. 推送到远端（GitHub）
# ------------------------------------------------
git push origin feature/任务名称

# ------------------------------------------------
# 6. 在 GitHub 网页端提交 Pull Request
# ------------------------------------------------
# 打开仓库 -> 会看到 "Compare & Pull Request" 提示
# - base 分支: main
# - compare 分支: feature/任务名称
# 写清楚改动内容，提交 PR
# 等待队友 Review 通过后，合并进 main

# ------------------------------------------------
# 7. 清理分支，保持本地整洁
# ------------------------------------------------
git checkout main
git pull origin main                   # 更新 main
git branch -d feature/任务名称          # 删除本地分支
git push origin --delete feature/任务名称  # 删除远端分支（可选）

# =====================================
# ✅ 流程总结（单个成员操作顺序）
# =====================================
# 1. git pull origin main          （更新主分支）
# 2. git checkout -b feature/xxx   （新建开发分支）
# 3. 开发代码 + git add + git commit
# 4. git merge main                （保持分支最新，解决冲突）
# 5. git push origin feature/xxx   （推送代码）
# 6. 提交 Pull Request 并等待合并
# 7. git pull origin main          （更新本地，清理分支）

# =====================================
# ⚡ 注意事项
# =====================================
# - 千万不要直接在 main 上开发！
# - 每次写代码前一定要 git pull
# - commit 信息要简洁明了，比如：
#   feat: 新增注册接口
#   fix: 修复登录时的密码校验
#   docs: 更新 README
# - 冲突要在本地自己分支解决，不要等到 PR 里再解决

```



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





