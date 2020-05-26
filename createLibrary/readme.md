本示例实现VScode结合cmake编译调试C++工程，VScode中一键F5自动进行。
每次F5都将整体重新编译一次，适合库文件开发和Debug工程。

0、环境
    ubuntu18.04
    VS code 1.45.1
    Cmake3.10.2

1、以下为make后目录结构（删去build目录中内容）
    注意：借用https://my.oschina.net/iamhere/blog/515660 改造而成。  
.  
├── bin  
│   └── libApp  
├── build  
├── build.sh  
├── CMakeLists.txt  
├── include  
│   └── person.h  
├── lib  
│   ├── libperson_d.a  
│   ├── libperson_d.so -> libperson_d.so.1  
│   ├── libperson_d.so.1 -> libperson_d.so.1.0  
│   └── libperson_d.so.1.0  
├── readme.md  
└── src  
    ├── app  
    │   ├── CMakeLists.txt  
    │   └── libApp.cpp  
    ├── CMakeLists.txt  
    └── src  
        ├── CMakeLists.txt  
        └── person.cpp  
  
2、特点
    1）VScode结合cmake编译调试
        cmake编译
        VScode调试
    2）cmake编译输出模式可配置
        build.sh中，按需设置
            cmake -DCMAKE_BUILD_TYPE=Debug/Release/RelWithDebInfo
        生成的lib库，将带有后缀-d/（Release版无）/-rd
        其配置，见./CMakeLists.txt
    3）VScode中一键F5自动进行
        参考https://zhuanlan.zhihu.com/p/133530843
        即通过build.sh中继
        每次F5都将整体重新编译一次
        适合库文件开发和Debug工程

3、使用
    1）主要面向库文件工程，
        添加.h文件到./include目录
        添加库.cpp文件到./src/src目录
        添加库应用.cpp文件到./src/app目录（常见main.cpp文件）
    2）默认将./src/src目录下所有文件编译为一个库文件（分.a和.so两个版本）
        修改输出库文件名称，请修改./src/src目录下CMakeLists.txt中名称字段，
        如person、person_static，为XXXXX、XXXXX_static
        对应的，将./src/app目录下CMakeLists.txt中库名称字段，改为以上所改字段
            target_link_libraries(libApp
                XXXXX #改为所需字段
            )
    3）仅作库应用示例文件./src/app/libApp.cpp，其编译见./src/app/CMakeLists.txt
        按需修改add_executable(YYYYY YYYYY.cpp)
        对应的，将./src/app目录下CMakeLists.txt中库应用名称字段，改为以上所改字段
            target_link_libraries(YYYYY #改为所需字段
                XXXXX #改为所需字段
            )
