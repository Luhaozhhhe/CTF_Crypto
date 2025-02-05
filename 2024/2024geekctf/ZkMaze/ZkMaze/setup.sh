#!/bin/bash

# 检查输入参数个数
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 <circom_filename> <output_directory> <input_json_file> <OPTIMATION>"
    exit 1
fi

# 读取参数到变量
CIRCOM_FILE=$1
OUTPUT_DIR=$2
INPUT_JSON_FILE=$3
OPTIMATION=${4:-O2}

# 确保输出目录存在
mkdir -p "$OUTPUT_DIR"

# 编译circom文件
echo "circom "$CIRCOM_FILE" --r1cs --sym --wasm --json --c --$OPTIMATION -o "$OUTPUT_DIR/""
circom "$CIRCOM_FILE" --r1cs --sym --wasm --json --c --$OPTIMATION -o "$OUTPUT_DIR/"
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

# 进入输出目录
# cd "$OUTPUT_DIR/" || exit

# 替换路径中的特殊字符以适应文件名
CLEAN_CIRCOM_FILE=$(echo "$CIRCOM_FILE" | sed 's/@/\@/g' | sed 's/=/\=/g' | sed 's/\.[^.]*$//')

# 生成见证，使用提供的input.json文件
node "${OUTPUT_DIR}/${CLEAN_CIRCOM_FILE}_js/generate_witness.js" "${OUTPUT_DIR}/${CLEAN_CIRCOM_FILE}_js/${CLEAN_CIRCOM_FILE}.wasm" "$INPUT_JSON_FILE" "${OUTPUT_DIR}"/witness.wtns

cd "$OUTPUT_DIR/"
# 开始powersoftau过程
echo "snarkjs powersoftau new bn128 15 pot12_0000.ptau"
snarkjs powersoftau new bn128 15 pot12_0000.ptau -v > /dev/null
# 检查上一条命令的退出状态
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

# 对powersoftau进行贡献
echo "snarkjs powersoftau contribute pot12_0000.ptau pot12_0001.ptau --name="First contribution" -v"
# snarkjs powersoftau contribute pot12_0000.ptau pot12_0001.ptau --name="First contribution" -v 2>/dev/null
snarkjs powersoftau contribute pot12_0000.ptau pot12_0001.ptau --name="First contribution"
# 检查上一条命令的退出状态
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

# 准备powersoftau的第二阶段
echo "snarkjs powersoftau prepare phase2 pot12_0001.ptau pot12_final.ptau -v"
snarkjs powersoftau prepare phase2 pot12_0001.ptau pot12_final.ptau -v > /dev/null
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

# 进行groth16设置
echo "snarkjs groth16 setup "${CLEAN_CIRCOM_FILE}.r1cs" pot12_final.ptau circuit0.zkey"
snarkjs groth16 setup "${CLEAN_CIRCOM_FILE}.r1cs" pot12_final.ptau circuit0.zkey
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

# 对zkey进行贡献
echo "snarkjs zkey contribute circuit0.zkey circuit1.zkey --name="1st Contributor Name" -v"
snarkjs zkey contribute circuit0.zkey circuit1.zkey --name="1st Contributor Name" -v
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

rm circuit0.zkey

# 导出验证密钥
echo "snarkjs zkey export verificationkey circuit1.zkey verification_key.json"
snarkjs zkey export verificationkey circuit1.zkey verification_key.json
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

# 生成证明
echo "snarkjs groth16 prove circuit1.zkey witness.wtns proof.json public.json"
snarkjs groth16 prove circuit1.zkey witness.wtns proof.json public.json > /dev/null
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

echo "snarkjs zkey export solidityverifier circuit1.zkey verifier.sol"
snarkjs zkey export solidityverifier circuit1.zkey verifier.sol > /dev/null
if [ $? -eq 0 ]; then
    echo "successful."
else
    echo "Command failed."
    exit 1
fi

echo "Verify the proof"
echo "snarkjs groth16 verify verification_key.json public.json proof.json"
snarkjs groth16 verify verification_key.json public.json proof.json
echo "Script execution completed."