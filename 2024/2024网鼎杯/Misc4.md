# Misc4

是一种皮亚诺曲线的加密

解密脚本如下：参考了https://almostgph.github.io/2024/01/08/IrisCTF2024/

```python
from PIL import Image
from tqdm import tqdm

def peano(n):
    if n == 0:
        return [[0,0]]
    else:
        in_lst = peano(n - 1)
        lst = in_lst.copy()
        px,py = lst[-1]
        lst.extend([px - i[0], py + 1 + i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px + i[0], py + 1 + i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px + 1 + i[0], py - i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px - i[0], py - 1 - i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px + i[0], py - 1 - i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px + 1 + i[0], py + i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px - i[0], py + 1 + i[1]] for i in in_lst)
        px,py = lst[-1]
        lst.extend([px + i[0], py + 1 + i[1]] for i in in_lst)
        return lst

order = peano(6)

img = Image.open(r"C:\Users\Lenovo\Desktop\1.png")

width, height = img.size

block_width = width # // 3
block_height = height # // 3

new_image = Image.new("RGB", (width, height))

for i, (x, y) in tqdm(enumerate(order)):
    # 根据列表顺序获取新的坐标
    new_x, new_y = i % width, i // width
    # 获取原图像素
    pixel = img.getpixel((x, height - 1 - y))
    # 在新图像中放置像素
    new_image.putpixel((new_x, new_y), pixel)

new_image.save("rearranged_image.jpg") 
```

![image-20241029170535829](C:\Users\Lenovo\Desktop\Misc4.assets\image-20241029170535829.png)

跑出来的结果存在了anaconda目录下 打开得到二维码

<img src="C:\Users\Lenovo\Desktop\Misc4.assets\image-20241029170840056.png" alt="image-20241029170840056" style="zoom:50%;" />

扫描二维码得到flag

```
wdflag{b9367dd6-2d7e-4ef7-ba5c-270a6c6220cd}
```

