scp是linux系统下基于ssh登陆进行安全的远程文件拷贝命令.

1.从本地复制到远程
```bash
scp local_file remote_username@remote_ip:remote_folder 
 
scp local_file remote_username@remote_ip:remote_file 

scp local_file remote_ip:remote_folder 

scp local_file remote_ip:remote_file

scp -r local_folder remote_username@remote_ip:remote_folder 

scp -r local_folder remote_ip:remote_folder
```

2.从远程复制到本地
```bash
scp remote_username@remote_ip:remote_folder local_file
 
scp remote_username@remote_ip:remote_file local_file

scp remote_ip:remote_folder local_file

scp remote_ip:remote_file local_file

scp -r remote_username@remote_ip:remote_folder local_folder

scp -r remote_ip:remote_folder local_folder
```