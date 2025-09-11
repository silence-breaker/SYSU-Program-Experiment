#!/bin/bash

# 脚本名: compile_and_run.sh
# 功能: 自动编译并运行当前目录下的C++文件
# 用法: ./compile_and_run.sh [文件名.cpp]
#       如果未提供文件名，则编译当前目录下的所有.cpp文件

# 设置颜色输出
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 编译函数
compile_file() {
    local cpp_file=$1
    local exe_file="${cpp_file%.*}"
    
    echo -e "${YELLOW}正在编译 $cpp_file...${NC}"
    g++ -std=c++11 -Wall "$cpp_file" -o "$exe_file"
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}编译成功: $cpp_file -> $exe_file${NC}"
        return 0
    else
        echo -e "${RED}编译失败: $cpp_file${NC}"
        return 1
    fi
}

# 运行函数
run_executable() {
    local exe_file=$1
    
    echo -e "${YELLOW}正在运行 $exe_file...${NC}"
    echo -e "${YELLOW}========== 程序输出 ==========${NC}"
    ./"$exe_file"
    local exit_code=$?
    echo -e "${YELLOW}========== 程序结束 ==========${NC}"
    echo -e "${GREEN}退出代码: $exit_code${NC}"
}

# 主函数
main() {
    # 检查是否有指定文件
    if [ $# -gt 0 ]; then
        # 处理指定的文件
        for file in "$@"; do
            # 检查文件是否存在
            if [ ! -f "$file" ]; then
                echo -e "${RED}错误: 文件 '$file' 不存在${NC}"
                continue
            fi
            
            # 检查是否为.cpp文件
            if [[ "$file" != *.cpp ]]; then
                echo -e "${RED}错误: '$file' 不是.cpp文件${NC}"
                continue
            fi
            
            # 编译文件
            if compile_file "$file"; then
                # 询问是否运行
                read -p "是否运行编译后的程序? (y/n): " choice
                if [[ "$choice" == "y" || "$choice" == "Y" ]]; then
                    run_executable "${file%.*}"
                fi
            fi
        done
    else
        # 处理当前目录下的所有.cpp文件
        cpp_files=(*.cpp)
        
        # 检查是否找到.cpp文件
        if [ ! -f "${cpp_files[0]}" ]; then
            echo -e "${RED}错误: 当前目录下没有找到.cpp文件${NC}"
            exit 1
        fi
        
        echo -e "${YELLOW}发现 ${#cpp_files[@]} 个.cpp文件${NC}"
        
        # 编译所有.cpp文件
        for file in "${cpp_files[@]}"; do
            compile_file "$file"
        done
        
        # 询问是否运行某个编译好的程序
        echo ""
        echo -e "${YELLOW}请选择要运行的程序:${NC}"
        
        # 创建可执行文件列表
        executables=()
        for file in "${cpp_files[@]}"; do
            exe="${file%.*}"
            if [ -x "$exe" ]; then
                executables+=("$exe")
            fi
        done
        
        # 显示可执行文件列表
        for i in "${!executables[@]}"; do
            echo -e "$((i+1)). ${executables[$i]}"
        done
        echo "0. 退出"
        
        read -p "请选择 (输入数字): " selection
        if [ "$selection" -gt 0 ] && [ "$selection" -le "${#executables[@]}" ]; then
            run_executable "${executables[$((selection-1))]}";
        elif [ "$selection" -ne 0 ]; then
            echo -e "${RED}无效的选择${NC}"
        fi
    fi
}

# 执行主函数
main "$@"
