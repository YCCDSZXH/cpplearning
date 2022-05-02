#s3-6用户登录模拟
users = ( ('Alice', '12345678'), ('Bob','abcdef'),
           ('Admin','admin'), ('Geoge','123abc'),
           ('Rose','goog1290'), ('Mike', '98760dns'))
for i in range(3):
    strs = input('请输入用户名和密码，以空格分隔：')
##########补充代码开始##########
    # 对输入的账号密码进行处理
    inputinfo = strs.split(' ')
    
    if len(inputinfo) == 1:
        print("格式错误,请输入用户名和密码，以空格分隔：")
        continue
    # 开始比对数据
    for user in users:
        if inputinfo[0] == user[0] and inputinfo[1] == user[1]:
            print('登录成功')
            exit()
        

##########补充代码结束##########
#请勿修改下面的代码
else:  #这是for循环的else
    print('次数用尽，请稍后再试！')