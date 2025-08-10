+++
date = '2025-02-04T23:16:06+08:00'
draft = false
title = 'hugo+github page+CDN加速，如何搭建个人博客网站'

+++


## 参考
[为什么要从 Hexo 转到 Hugo？](https://sdl.moe/post/why-hugo/)


## 目标

hugo+github page+CDN加速，搭建个人博客网站
### deepseek提示词，选R1

已经安装hugo，已经创建github page个人仓，已将github page仓下载到本地，如何hugo创建个人博客网站，已选择hugo-theme-stack作为主题。如何配置hugo.toml文件，github pages的url是https://jf-chen.github.io/
## 步骤

### 1、创建username.github.io
建个仓就行，参考 https://docs.github.com/en/pages/quickstart ，Changing the title and description开始的步骤不必要，后面用hugo就行。
设置 GitHub Pages 源
- 进入仓库的 **Settings → Pages**。
- 选择分支：`main`，目录：`/docs`。
### 2、配置该代码仓的git信息
```
# 生成密钥对
ssh-keygen -t <密钥类型> -C <注释信息> -f <密钥文件路径及名称>

# 读取公钥文件并复制到剪贴板，贴到github里面
Get-Content -Path "C:\path\to\your\file.txt" | Set-Clipboard

# 修改.gitconfig;查看ssh连接失败原因;给username.github.io目录下的git仓另外配置
[core]
	sshCommand = "ssh -v"
[includeIf "gitdir:D:/GitHub/"]
    path = D:/GitHub/.gitconfig-specific

# .gitconfig-specific中指定私钥文件
[core]
	sshCommand = "ssh -v -i D:/GitHub/ssh/id_ed_gitpage"

# 拷贝到本地
```

### 3、hugo本地部署

```
# 强制在当前目录初始化 Hugo 项目
hugo new site . --force  

# 选择主题;换成gitcode的快一点
git submodule add https://gitcode.com/gh_mirrors/hu/hugo-theme-stack themes/hugo-theme-stack

# 生成样例，随便写点
hugo new posts/first-post.md

# 本地服务器
hugo server -D
```

修改hugo.toml

```
baseURL = 'https://jf-chen.github.io/'
languageCode = 'zh-cn'
title = 'My New Hugo Site'
theme = "hugo-theme-stack"

# 发布目录设置为 `docs`（GitHub Pages 支持从 `docs` 目录部署）
publishDir = "docs"

# 主题配置示例（根据主题文档自定义）
[params]
  # 主题相关配置，参考主题文档
  [[params.social]]
    name = "GitHub"
    url = "https://github.com/jf-chen"
```

修改之后再build一次，输入hugo就行


### 4、使用 GitHub Actions 自动构建和部署


https://hugo.opendocs.io/hosting-and-deployment/hosting-on-github/

