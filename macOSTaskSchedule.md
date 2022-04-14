# macOS 计划任务生成指南
> 真不是我不愿意做
> 
> macOS的计划任务机制太神奇

## 步骤
- 一、数据修改
  - 1. 用文本编辑器打开```res```目录下的```plist```文件
  - 2. 修改```plist```文件中要求修改的两个字段
  - 3. 保存退出
- 二、系统设置
  - 1. 在桌面点击上方任务栏中的前往，输入```~/Library/LaunchAgents```
  - 2. 然后将第一步中的```plist```文件拷贝到打开的文件夹
  - 3. 打开终端，输入以下指令：```launchctl load ~/Library/LaunchAgents/com.qhy040404.library.plist```
- 到这里任务计划就设置完成了

## 删除任务计划
- 打开终端运行```launchctl unload ~/Library/LaunchAgents/com.test.plist```，然后前往文件夹删除这个```plist```文件即可