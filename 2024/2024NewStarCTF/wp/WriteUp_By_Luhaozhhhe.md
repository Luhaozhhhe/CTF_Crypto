# WriteUp_By_Luhaozhhhe

# WEEK1

![image-20241006203933773](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006203933773.png)

## Crypto

### xor

```python
#As a freshman starting in 2024, you should know something about XOR, so this task is for you to sign in.

from pwn import xor
#The Python pwntools library has a convenient xor() function that can XOR together data of different types and lengths
from Crypto.Util.number import bytes_to_long

key = b'New_Star_CTF'
flag='flag{*******************}'

m1 = bytes_to_long(bytes(flag[:13], encoding='utf-8'))
m2 = flag[13:]

c1 = m1 ^ bytes_to_long(key)
c2 = xor(key, m2)
print('c1=',c1)
print('c2=',c2)

'''
c1= 8091799978721254458294926060841
c2= b';:\x1c1<\x03>*\x10\x11u;'
'''
```

很简单的xor加密，我们只需要再做一次xor就可以还原回来了

py脚本：

```python
from Crypto.Util.number import long_to_bytes

key = b'New_Star_CTF'
# 确保 key 是字节串类型
key_bytes = key

# 解密 c1
decrypted_m1 = c1 ^ bytes_to_long(key_bytes)
decrypted_flag_part1 = decrypted_m1.to_bytes(13, byteorder='big').decode('utf-8')

# 解密 c2
decrypted_m2 = xor(key_bytes, c2)
decrypted_flag_part2 = decrypted_m2.decode('utf-8')

# 拼接解密后的两部分
decrypted_flag = decrypted_flag_part1 + decrypted_flag_part2
print('Decrypted flag:', decrypted_flag)

#Decrypted flag: flag{0ops!_you_know_XOR!}
```

flag{0ops!_you_know_XOR!}



### Base

```
4C4A575851324332474E324547554B494A5A4446513653434E564D444154545A4B354D45454D434E4959345536544B474D5134513D3D3D3D
```

很简单，用base系列多解密几次就出答案了

第一步，base16解密得LJWXQ2C2GN2EGUKIJZDFQ6SCNVMDATTZK5MEEMCNIY4U6TKGMQ4Q====

第二步，base32解密得ZmxhZ3tCQHNFXzBmX0NyWXB0MF9OMFd9

第三步，base64解密得flag{B@sE_0f_CrYpt0_N0W}



flag{B@sE_0f_CrYpt0_N0W}



### 一眼秒了

经典RSA

n很小，直接用网站分解就可以了

然后得到p和q之后，正常解密就可以

py脚本：

```python
from Crypto.Util.number import *
from gmpy2 import *
n=52147017298260357180329101776864095134806848020663558064141648200366079331962132411967917697877875277103045755972006084078559453777291403087575061382674872573336431876500128247133861957730154418461680506403680189755399752882558438393107151815794295272358955300914752523377417192504702798450787430403387076153
c=48757373363225981717076130816529380470563968650367175499612268073517990636849798038662283440350470812898424299904371831068541394247432423751879457624606194334196130444478878533092854342610288522236409554286954091860638388043037601371807379269588474814290382239910358697485110591812060488786552463208464541069
p=7221289171488727827673517139597844534869368289455419695964957239047692699919030405800116133805855968123601433247022090070114331842771417566928809956044421
q=7221289171488727827673517139597844534869368289455419695964957239047692699919030405800116133805855968123601433247022090070114331842771417566928809956045093
e=65537
phi=(p-1)*(q-1)
d=invert(e,phi)
print(long_to_bytes(pow(c,d,n)))
#b'flag{9cd4b35a-affc-422a-9862-58e1cc3ff8d2}'
```

flag{9cd4b35a-affc-422a-9862-58e1cc3ff8d2}



### Strange King

```
ksjr{EcxvpdErSvcDgdgEzxqjql}
```

观察一下就知道，前四位分别和flag对应，我们直接比较ascii的值就可以出来了

转化为十进制：107 115 106 114 123 69 99 120 118 112 100 69 114 83 118 99 68 103 100 103 69 122 120 113 106 113 108 125

flag的十进制：102 108 97 103

所以加了5,7,9,11，有规律了

转化为：102 108  97  103 123 80 108 101 97 115 101 68 111 78 111 116 83 116 111  112 76  101  97 114 105 110 103 125

求字符即可

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004170343970.png" alt="image-20241004170343970" style="zoom:50%;" />

flag{PleaseDoNotStopLearing}



## Web

### headach3

打开网址，为该界面

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004161840131.png" alt="image-20241004161840131" style="zoom:50%;" />

F12查看控制台，选择网络

F5刷新，就出来了，在响应头中有flag

![image-20241004162026573](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004162026573.png)

flag{You_Ar3_R3Ally_A_9ooD_d0ctor}



### 会赢吗

打开网址

按下F12 打开控制台

![image-20241005194141729](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005194141729.png)

第一部分：flag第一部分：ZmxhZ3tXQTB3，开始你的新学期吧！:/4cqu1siti0n 

![image-20241005194249247](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005194249247.png)

第二部分：

![image-20241005200036919](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005200036919.png)

flag: IV95NF9yM2Fs

时光荏苒，你成长了很多，也发生了一些事情。去看看吧：/s34l

输入控制台

```c
            const form = document.getElementById('seal_him');
            const stateElement = document.getElementById('state');
            const messageElement = document.getElementById('message');
try {
                    const response = await fetch('/api/flag/s34l', {
                        method: 'POST',
                        headers: {
                            'Content-Type': 'application/json'
                        },
                        body: JSON.stringify({ csrf_token: document.getElementById('csrf_token').value })
                    });

                    if (response.ok) {
                        const data = await response.json();
                        messageElement.textContent = `第三部分Flag: ${data.flag}, 你解救了五条悟！下一关: /${data.nextLevel || '无'}`;
                    } else {
                        messageElement.textContent = '请求失败，请重试。';
                    }
                } catch (error) {
                    messageElement.textContent = '请求过程中出现错误，请重试。';
                }
```

第三部分flag：MXlfR3I0c1B

下一关：/Ap3x

第四部分抓包即可，flag为fskpKcyF9

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006085053962.png" alt="image-20241006085053962" style="zoom:50%;" />

综上所述，flag合起来为ZmxhZ3tXQTB3IV95NF9yM2FsMXlfR3I0c1BfSkpKcyF9

base64解密得flag

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006085337868.png" alt="image-20241006085337868" style="zoom: 50%;" />



flag{WA0w!_y4_r3al1y_Gr4sP_JJJs!}



### 谢谢皮蛋

sql注入

-1 union select 1,group_concat(id,':',des,':',value) from Fl4g

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005201426227.png" alt="image-20241005201426227" style="zoom:50%;" />



### 智械危机

访问robots.txt得到后门

访问后门，发现一个cmd和key的脚本，就是要构造出符合条件的值即可

先用base64加密，然后反序，md5，然后再base64即可得到我们的key

![image-20241006202709512](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006202709512.png)

flag{baf78890-09c0-4cc1-a9e0-a25d83a3fd17}



## Pwn







## Reverse

### begin

用ida打开exe文件

![image-20241004162150037](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004162150037.png)

根据提示，先按下F5进行反汇编

![image-20241004162237011](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004162237011.png)

按下flag_part1，跳转到汇编段，根据提示按下a，第一部分flag就到手了

```
flag{Mak3_aN_
```

第二部分只需要选中函数flag_part2直接打开就行了

![image-20241004162407895](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004162407895.png)

```
3Ff0rt_tO_5eArcH_
```

第三部分就是函数名

![image-20241004162752375](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004162752375.png)

```
F0r_th3_f14g_C0Rpse}
```



flag{Mak3_aN_3Ff0rt_tO_5eArcH_F0r_th3_f14g_C0Rpse}



### base64

打开ida，找到了和flag有关的函数部分

![image-20241004162908213](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004162908213.png)

发现有一串base64的编码，和sub_1400014E0相关

我们找到对应的函数

```c++
char *__fastcall sub_1400014E0(char *a1, int a2, _BYTE *a3)
{
  char *result; // rax
  __int64 v5; // rcx
  int v6; // ebx
  char v7; // r9
  __int64 v8; // rdx
  __int64 i; // rdx
  __int64 v10; // rdi
  __int64 v11; // rax
  void *v12; // rcx
  size_t v13; // r8
  unsigned __int8 v14; // [rsp+29h] [rbp-1Fh] BYREF
  unsigned __int8 v15; // [rsp+2Ah] [rbp-1Eh]
  unsigned __int8 v16; // [rsp+2Bh] [rbp-1Dh]
  int v17[7]; // [rsp+2Ch] [rbp-1Ch]

  result = a1;
  if ( a2 )
  {
    v5 = (__int64)&a1[a2 - 1 + 1];
    v6 = 0;
    do
    {
      while ( 1 )
      {
        v7 = *result;
        v8 = v6++;
        ++result;
        *(&v14 + v8) = v7;
        if ( v6 == 3 )
          break;
        if ( result == (char *)v5 )
          goto LABEL_8;
      }
      v17[0] = (v14 >> 2) | (((unsigned __int8)((v15 >> 4) + ((16 * v14) & 0x30)) | (((unsigned __int8)((v16 >> 6) + ((4 * v15) & 0x3C)) | ((v16 & 0x3F) << 8)) << 8)) << 8);
      for ( i = 0i64; i != 4; ++i )
        a3[i] = aWhydo3sthis7ab[*((unsigned __int8 *)v17 + i)];
      a3 += 4;
      v6 = 0;
    }
    while ( result != (char *)v5 );
LABEL_8:
    if ( v6 )
    {
      if ( v6 > 2 )
      {
        v10 = v6;
        v17[0] = (v14 >> 2) | (((unsigned __int8)((v15 >> 4) + ((16 * v14) & 0x30)) | (((unsigned __int8)((v16 >> 6) + ((4 * v15) & 0x3C)) | ((v16 & 0x3F) << 8)) << 8)) << 8);
      }
      else
      {
        v10 = v6;
        memset(&v14 + v6, 0, (unsigned int)(3 - v6));
        v17[0] = (v14 >> 2) | (((unsigned __int8)((v15 >> 4) + ((16 * v14) & 0x30)) | (((unsigned __int8)((v16 >> 6) + ((4 * v15) & 0x3C)) | ((v16 & 0x3F) << 8)) << 8)) << 8);
        if ( v6 < 0 )
        {
LABEL_14:
          v12 = a3;
          v13 = (unsigned int)(3 - v6);
          a3 += v13;
          result = (char *)memset(v12, 61, v13);
          goto LABEL_15;
        }
      }
      v11 = 0i64;
      do
      {
        a3[v11] = aWhydo3sthis7ab[*((unsigned __int8 *)v17 + v11)];
        ++v11;
      }
      while ( v6 >= (int)v11 );
      a3 += v10 + 1;
      goto LABEL_14;
    }
  }
LABEL_15:
  *a3 = 0;
  return result;
}
```

分成三个一组，编写对应的解密脚本即可

c++脚本：

```c++
#include <stdio.h>
#include <string.h>

// 映射表
unsigned char aWhydo3sthis7ab[] = "WHydo3sThiS7ABLElO0k5trange+CZfVIGRvup81NKQbjmPzU4MDc9Y6q2XwFxJ/";

// 构建逆映射表
void build_inv_map(unsigned char inv_map[], const unsigned char* map, int map_size) {
    for (int i = 0; i < map_size; i++) {
        inv_map[map[i]] = i;
    }
}

// 解码函数
void decode(const char* encoded_str, char* decoded_str, int encoded_len, int decoded_len) {
    unsigned char inv_aWhydo3sthis7ab[256];
    build_inv_map(inv_aWhydo3sthis7ab, aWhydo3sthis7ab, sizeof(aWhydo3sthis7ab) - 1);

    int j = 0, shift = 0;
    unsigned char b1, b2, b3, b4;
    for (int i = 0; i < encoded_len; i += 4) {
        b1 = inv_aWhydo3sthis7ab[(unsigned char)encoded_str[i]];
        b2 = inv_aWhydo3sthis7ab[(unsigned char)encoded_str[i + 1]];
        b3 = inv_aWhydo3sthis7ab[(unsigned char)encoded_str[i + 2]];
        b4 = encoded_str[i + 3] == '=' ? 0 : inv_aWhydo3sthis7ab[(unsigned char)encoded_str[i + 3]];

        unsigned int v = (b1 << 18) | (b2 << 12) | (b3 << 6) | b4;
        decoded_str[j++] = (v >> 16) & 0xFF;
        if (j < decoded_len) {
            decoded_str[j++] = (v >> 8) & 0xFF;
        }
        if (j < decoded_len) {
            decoded_str[j++] = v & 0xFF;
        }
    }
    decoded_str[j] = '\0';
}

int main() {
    const char* encoded_str = "g84Gg6m2ATtVeYqUZ9xRnaBpBvOVZYtj+Tc=";
    int encoded_len = strlen(encoded_str);
    int decoded_len = 26; // 假设原始字符串长度为26
    char decoded_str[27]; // 额外的一个字节用于存储字符串结束符'\0'

    decode(encoded_str, decoded_str, encoded_len, decoded_len);
    printf("Decoded string: %s\n", decoded_str);
    return 0;
}
```

![image-20241004163648783](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004163648783.png)

flag{y0u_kn0w_base64_well}



### Simple_encryption

F5反汇编

```c++
int __fastcall main(int argc, const char **argv, const char **envp)
{
  int k; // [rsp+24h] [rbp-Ch]
  int j; // [rsp+28h] [rbp-8h]
  int i; // [rsp+2Ch] [rbp-4h]

  _main(argc, argv, envp);
  puts("please input your flag:");
  for ( i = 0; i < len; ++i )
    scanf("%c", &input[i]);
  for ( j = 0; j < len; ++j )
  {
    if ( !(j % 3) )
      input[j] -= 31;
    if ( j % 3 == 1 )
      input[j] += 41;
    if ( j % 3 == 2 )
      input[j] ^= 0x55u;
  }
  for ( k = 0; k < len; ++k )
  {
    printf("0x%02x ", input[k]);
    if ( input[k] != buffer[k] )
    {
      printf("error");
      return 0;
    }
  }
  putchar(10);
  printf("success!");
  return 0;
}
```

题目逻辑很简单，就是分组进行加密，我们直接做对应的还原就可以了

首先if ( input[k] != buffer[k] )告诉我们，我们的输入必须和buffer数组的全部一样，才能输出success，不然就退出

进入buffer内存块读取出对应的数据段

![image-20241004163957731](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004163957731.png)

然后解密即可，c++脚本：

```c++
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    // buffer数组的内容
    std::vector<unsigned char> buffer = {
        0x47, 0x95, 0x34, 0x48, 0xA4, 0x1C, 0x35, 0x88,
        0x64, 0x16, 0x88, 0x07, 0x14, 0x6A, 0x39, 0x12,
        0xA2, 0x0A, 0x37, 0x5C, 0x07, 0x5A, 0x56, 0x60,
        0x12, 0x76, 0x25, 0x12, 0x8E, 0x28
    };

    // 原始的input数组
    std::vector<unsigned char> input(buffer.size(), 0);

    // 逆向变换
    for (size_t i = 0; i < buffer.size(); ++i) {
        if (i % 3 == 2) {
            input[i] = buffer[i] ^ 0x55; // 先处理异或
        }
        if (i % 3 == 1) {
            input[i] = buffer[i] - 0x29; // 处理加法
        }
        if (i % 3 == 0) {
            input[i] = buffer[i] + 0x1F; // 处理减法
        }
    }

    // 输出结果
    std::cout << "The flag is: ";
    for (auto& c : input) {
        if (c >= 0x20 && c <= 0x7E) { // 只打印可打印字符
            std::cout << static_cast<char>(c);
        }
    }
    std::cout << std::endl;

    return 0;
}
```

![image-20241004164021857](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004164021857.png)

flag{IT_15_R3Al1y_V3Ry-51Mp1e}



### ezAndroidStudy

flag1

![image-20241005222215696](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005222215696.png)

flag2

![image-20241005223136860](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005223136860.png)

flag3

![image-20241005222837966](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005222837966.png)

flag4

![image-20241005223343706](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241005223343706.png)

flag5

用IDA打开



flag{Y0u_@r4_900d_andr01d_r4V4rs4r}



### ez_debug

动态调试得到key为ATRI

编写脚本破解即可

```python
key = "ATRI"
flag = [  0x30, 0x2F, 0x24, 0x39, 0x2D, 0x3A, 0x75, 0x2B, 0x09, 0x22, 0x37, 0x6D, 0x09, 0x24, 0x75, 0x31, 0x32, 0x1C, 0x05, 0x01,0x12,0x26,0x27,0x2b,0x6f,0x3e]

decrypted_flag = ""
for i in range(len(flag)):
    decrypted_flag += chr(0x17^flag[i] ^ ord(key[i % len(key)]))

print("Decrypted flag:", decrypted_flag)
```

flag{y0u_ar3_g0od_@_Debu9}



## Misc

### decompress

下载压缩包，先把能解压的都解压了

![image-20241004154406645](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004154406645.png)

然后出现两个文件夹，查看对应的hint，发现是一个正则表达式，说明密码的组成为3个小写字母加一个数字加一个小写字母 

直接暴力破解就可以了

用软件ARCHPR，一个小时就破解出密码为xtr4m

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\26efbf71f8b0838183c15cdcdd5821e.png" alt="26efbf71f8b0838183c15cdcdd5821e" style="zoom:50%;" />

然后解压就可以了，最后得到解压后的文件flag.txt

```
flag **should** be `$uuid_oOo0hhh_U_r3411y_K0nw_h0w_2_d3c0mpr355_Multi-part_archive_$uuid_&_Th1s_f1ag_15_s0O0oO_l0oOoOng999_$uuid` if it hadn't been leaked, but now the **true** flag is flag{U_R_th3_ma5ter_0f_dec0mpress}
```

flag{U_R_th3_ma5ter_0f_dec0mpress}



### Labyrinth

题目给提示了，是LSB加密，我们直接工具一把梭

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004155021907.png" alt="image-20241004155021907" style="zoom: 33%;" />

发现red plane中出现了一张二维码，保存扫描就能得到flag了

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004155204113.png" alt="image-20241004155204113" style="zoom:33%;" />

flag{e33bb7a1-ac94-4d15-8ff7-fd8c88547b43}



### 兑换码

用随波逐流打开，直接图片隐写解密就可以了

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004154803763.png" alt="image-20241004154803763" style="zoom: 50%;" />

flag{La_vaguelette}



### pleasingMusic

先听一遍 发现最后有打点，直接将音乐倒置一下

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004171240367.png" alt="image-20241004171240367" style="zoom:50%;" />

经典摩斯密码，我们直接记录一下对应的大小点即可

```
. --.. ..--.- -- --- .-. ... . ..--.- -.-. --- -.. .
```

解码后，为EZ_MORSE_CODE



flag{ez_morse_code}



### WhereIsFlag

是一个linux命令行的使用

![image-20241004172203591](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004172203591.png)

首先ls查看文件夹

然后一个一个试，看看有没有权限访问

最后试到proc文件夹，貌似是对的，进入self/文件夹

![image-20241004183153597](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004183153597.png)

访问environ得到flag



flag{bc8b5eb5-e651-49d5-9728-fa46b1fde29e}



## Signin

### ez_answer

签到，填写问卷，就出flag了

![image-20241004164135266](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241004164135266.png)



flag{I_Agr3e_to_FoL10w_th3_ru1es_c41fa97d}





# WEEK2

## Crypto

### 这是几次方？ 疑惑！

```python
hint = p^e + 10086
```

其实先计算的是+，所以我们只需要将p恢复出来，就可以获得p和q了，然后就是简单的rsa

py脚本：

```python
hint=12578819356802034679792891975754306960297043516674290901441811200649679289740456805726985390445432800908006773857670255951581884098015799603908242531673390
p=hint^(65537+10086)
print(p)
```

p=12578819356802034679792891975754306960297043516674290901441811200649679289740456805726985390445432800908006773857670255951581884098015799603908242531598921

```python
q=9894080171409167477731048775117450997716595135307245061889351408996079284609420327696692120762586015707305237750670080746600707139163744385937564246995541
p=12578819356802034679792891975754306960297043516674290901441811200649679289740456805726985390445432800908006773857670255951581884098015799603908242531598921
n=124455847177872829086850368685666872009698526875425204001499218854100257535484730033567552600005229013042351828575037023159889870271253559515001300645102569745482135768148755333759957370341658601268473878114399708702841974488367343570414404038862892863275173656133199924484523427712604601606674219929087411261
e=65537
c=36513006092776816463005807690891878445084897511693065366878424579653926750135820835708001956534802873403195178517427725389634058598049226914694122804888321427912070308432512908833529417531492965615348806470164107231108504308584954154513331333004804817854315094324454847081460199485733298227480134551273155762
from Crypto.Util.number import *
from gmpy2 import *
phi=(p-1)*(q-1)
d=invert(e,phi)
print(long_to_bytes(pow(c,d,n)))
```

flag{yihuo_yuan_lai_xian_ji_suan_liang_bian_de2333}



### Since you konw something

首先将c还原回字符形式

然后我们爆破一下key

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241007005308071.png" alt="image-20241007005308071" style="zoom: 50%;" />

发现key为2位，key=ns

py脚本：

```python
from pwn import xor
#The Python pwntools library has a convenient xor() function that can XOR together data of different types and lengths
from Crypto.Util.number import bytes_to_long

key = 'ns' #extremely short

c=b'\x08\x1f\x0f\x14\x15*^\x061\x18\x00C\x19,\x1a\x1b],6C\x1c,\x0c@\x1a\x07]\x01\x13'

flag=xor(c,key)
print(flag)
```

flag{Y0u_kn0w_th3_X0r_b3tt3r}



### 茶里茶气

tea加密，逆向解密一下就出来了

```python
l = 199
p = 446302455051275584229157195942211
v0 = 190997821330413928409069858571234
v1 = 137340509740671759939138452113480
v2 = 0
derta = 462861781278454071588539315363
v3 = 489552116384728571199414424951
v4 = 469728069391226765421086670817
v5 = 564098252372959621721124077407
v6 = 335640247620454039831329381071

vv2 = []
for i in range(32):
    v2 += derta
    v2 %= p

for i in range(32):
    v2 -= derta
    v0 -= (v1 + v2) ^ (8 * v1 + v5) ^ ((v1 >> 7) + v6);
    v0 = v0 % p
    v1 -= (v0 + v2) ^ (8 * v0 + v3) ^ ((v0 >> 7) + v4);
    v1 = v1 % p


def recover_a(v0, v1):
    l = (v0 << (199 // 2)) + v1
    print(l)

    hex_a = hex(l)[2:]

    flag = ''.join(chr(int(hex_a[i:i + 2], 16)) for i in range(0, len(hex_a), 2))

    return flag


a = recover_a(v0, v1)
print("Recovered a:", a)
```

flag{f14gg9_te2_1i_7ea_7}



### Just one and more than two

就是欧拉函数的运用，两部分拼接起来就可以了

py脚本：

```python
p=11867061353246233251584761575576071264056514705066766922825303434965272105673287382545586304271607224747442087588050625742380204503331976589883604074235133
q=11873178589368883675890917699819207736397010385081364225879431054112944129299850257938753554259645705535337054802699202512825107090843889676443867510412393
r=12897499208983423232868869100223973634537663127759671894357936868650239679942565058234189535395732577137079689110541612150759420022709417457551292448732371
c1=8705739659634329013157482960027934795454950884941966136315983526808527784650002967954059125075894300750418062742140200130188545338806355927273170470295451
c2=1004454248332792626131205259568148422136121342421144637194771487691844257449866491626726822289975189661332527496380578001514976911349965774838476334431923162269315555654716024616432373992288127966016197043606785386738961886826177232627159894038652924267065612922880048963182518107479487219900530746076603182269336917003411508524223257315597473638623530380492690984112891827897831400759409394315311767776323920195436460284244090970865474530727893555217020636612445
e=65537
from Crypto.Util.number import *
from gmpy2 import *

#task1
d=invert(e,p-1)
m1=pow(c1,d,p)

#task2
phi=(p-1)*(q-1)*(r-1)
d2=invert(e,phi)
m2=pow(c2,d2,p*q*r)

print(long_to_bytes(m1)+long_to_bytes(m2))
```

flag{Y0u_re4lly_kn0w_Euler_4nd_N3xt_Eu1er_is_Y0u!}







## Web

### 复读机

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241007222214838.png" alt="image-20241007222214838" style="zoom:50%;" />

flag{a1789875-f37f-49d1-a883-4ded243e3359}



### 谢谢皮蛋 plus

sql注入，简单

输入：`87"/**/union/**/select/**/group_concat(des),group_concat(value)/**/from/**/Fl4g#`

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241007222325668.png" alt="image-20241007222325668" style="zoom:50%;" />

flag{c1408b42-16b7-4511-8d37-1255354f6e17}







### PangBai 过家家（2）

第一关，找到后门

`/BacKd0or.v2d23AOPpDfEW5Ca.php?NewStar[CTF.2024=Welcome%0a`

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241008110111068.png" alt="image-20241008110111068" style="zoom:50%;" />

第二关，post数据，papa=TfflxoU0ry7c&func=system&args=env

![image-20241008110206024](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241008110206024.png)



查看控制台flag

![image-20241008110224887](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241008110224887.png)

flag{4cc173ac-351e-4723-ab1f-0cb52e408cfb}



### 遗失的拉链

![image-20241008223618437](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241008223618437.png)

flag{bcede967-34b4-49be-903d-516aa7521060}









## Pwn

## Reverse

### UPX

首先使用工具脱壳，用ida打开

发现main函数

```c++
int __fastcall main(int argc, const char **argv, const char **envp)
{
  int status; // [rsp+Ch] [rbp-4h]

  puts("Please input your flag:");
  __isoc99_scanf("%22s", s);
  RC4(s, (__int64)key);
  for ( status = 0; status <= 21; ++status )
  {
    if ( s[status] != data[status] )
    {
      puts("this is Wrong~");
      exit(status);
    }
  }
  puts("this is right~");
  return 0;
}
```

可以发现，使用了RC4加密，这个方法是可逆的，加密的数据为s和key，追踪key的值为NewStar

s的值：

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241007092620272.png" alt="image-20241007092620272" style="zoom:50%;" />

存在byte中，进一步查看，得到：

```asm
endbr64
push    rbp
mov     rbp, rsp
mov     cs:data, 0C4h
mov     cs:byte_4161, 60h ; '`'
mov     cs:byte_4162, 0AFh
mov     cs:byte_4163, 0B9h
mov     cs:byte_4164, 0E3h
mov     cs:byte_4165, 0FFh
mov     cs:byte_4166, 2Eh ; '.'
mov     cs:byte_4167, 9Bh
mov     cs:byte_4168, 0F5h
mov     cs:byte_4169, 10h
mov     cs:byte_416A, 56h ; 'V'
mov     cs:byte_416B, 51h ; 'Q'
mov     cs:byte_416C, 6Eh ; 'n'
mov     cs:byte_416D, 0EEh
mov     cs:byte_416E, 5Fh ; '_'
mov     cs:byte_416F, 7Dh ; '}'
mov     cs:byte_4170, 7Dh ; '}'
mov     cs:byte_4171, 6Eh ; 'n'
mov     cs:byte_4172, 2Bh ; '+'
mov     cs:byte_4173, 9Ch
mov     cs:byte_4174, 75h ; 'u'
mov     cs:byte_4175, 0B5h
nop
pop     rbp
retn
```

于是，得到：

```c++
    unsigned char encrypted_data[] = {
        0xC4, 0x60, 0xAF, 0xB9, 0xE3, 0xFF, 0x2E, 0x9B, 0xF5, 0x10, 0x56, 0x51, 0x6E, 0xEE, 0x5F, 0x7D, 0x7D, 0x6E, 0x2B, 0x9C, 0x75, 0xB5
    };
```

RC4加密只需要再做一遍加密操作就可以解密了，所以编写以下脚本：

```c++
#include <stdio.h>
#include <string.h>

unsigned char sbox[256];

void swap(unsigned char* a, unsigned char* b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void init_sbox(unsigned char* key) {
    int i = 0, j = 0;
    for (i = 0; i < 256; i++) {
        sbox[i] = (unsigned char)i;
    }
    int key_len = strlen((char*)key);
    for (i = 0; i < 256; i++) {
        j = (j + sbox[i] + key[i % key_len]) % 256;
        swap(&sbox[i], &sbox[j]);
    }
}

void RC4(unsigned char* data, int data_len, unsigned char* key) {
    int i = 0, j = 0;
    init_sbox(key);
    for (int k = 0; k < data_len; k++) {
        i = (i + 1) % 256;
        j = (j + sbox[i]) % 256;
        swap(&sbox[i], &sbox[j]);
        int ksa = (sbox[i] + sbox[j]) % 256;
        data[k] ^= sbox[ksa];
    }
}

int main() {
    unsigned char encrypted_data[] = {
        0xC4, 0x60, 0xAF, 0xB9, 0xE3, 0xFF, 0x2E, 0x9B, 0xF5, 0x10, 0x56, 0x51, 0x6E, 0xEE, 0x5F, 0x7D, 0x7D, 0x6E, 0x2B, 0x9C, 0x75, 0xB5
    };
    unsigned char key[] = "NewStar";
    int data_len = sizeof(encrypted_data) / sizeof(encrypted_data[0]);

    // 解密数据
    RC4(encrypted_data, data_len, key);

    printf("Decrypted data (ASCII): ");
    for (int i = 0; i < data_len; i++) {
        if (encrypted_data[i] >= 32 && encrypted_data[i] <= 126) {
            printf("%c", encrypted_data[i]);
        }
        else {
            printf(".");
        }
    }
    printf("\n");
    return 0;
}
```

![image-20241007092809849](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241007092809849.png)

flag{Do_you_know_UPX?}



### Dirty_flowers

找出对应的加密数据，用密钥dirty_flower解密即可

```python
enflag = [2,5,19,19,2,30,83,31,92,26,39,67,29,54,67,7,38,45,85,13,3,27,28,45,2,28,28,48,56,50,85,2,27,22,84,15]
key = 'dirty_flower'
for i in range(36):
    print(chr(enflag[i]^ord(key[i%len(key)])&0xff),end='')
```

flag{A5s3mB1y_1s_r3ally_funDAm3nta1}









## Misc

### wireshark_checkin

打开，搜索flag，跟踪到http://192.168.109.128:7070/地址，有flag.txt

直接 跟踪流就可以拿到flag了

![image-20241006211331118](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006211331118.png)

flag{ez_traffic_analyze_isn't_it}



### 字里行间的秘密

![image-20241006212017899](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006212017899.png)

第一步，得到txt文件中的隐写，打开word

第二步，将word全选，字体颜色改为黑色即可

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006212324060.png" alt="image-20241006212324060" style="zoom:50%;" />

flag{you_h4ve_4nyth1n9}





### 用溯流仪见证伏特台风

![image-20241006220015319](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006220015319.png)

先随便找个网址，找到字符串

读取：powerj7kmpzkdhjg4szvcxxgktgk36ezpjxvtosylrpey7svpmrjyuyd.onion

![image-20241006220526677](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006220526677.png)

flag{6c3ea51b6f9d4f5e}



### 你也玩原神吗

打开发现是动图，直接逐帧解析

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006221311490.png" alt="image-20241006221311490" style="zoom:33%;" />

得到含有文字的图像：

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006221301714.png" alt="image-20241006221301714" style="zoom: 25%;" />

网上的解密：

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006221446351.png" alt="image-20241006221446351"  />

解密为：

<img src="E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\28d76e1bb3cc39407c46dae2e0de493.jpg" alt="28d76e1bb3cc39407c46dae2e0de493" style="zoom: 33%;" />

解密为：lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua quis

![36](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\36.png)

四个角落的内容为：flagisasentence   iiaaelgtsfkfa   doyoukonwfence  mesioaabgnhnsgogmyeiade

提示我们，flag是一个句子，fence告诉我们为栅栏加密

iiaaelgtsfkfa

![image-20241006233602199](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006233602199.png)

mesioaabgnhnsgogmyeiade

![image-20241006233757053](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\2024NewStarCTF\wp\WriteUp_By_Luhaozhhhe.assets\image-20241006233757053.png)

flag{maybegenshinisagoodgame}



### wireshark_secret

追踪到sercet.png处，发现有乱码的png文件，直接恢复就可以了

flag{you_are_gooddddd}
