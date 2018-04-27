#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-09 23:36:40
# @Author  : mohailang (1198534595@qq.com)


from PIL import Image
import argparse

# 命令行输入参数处理
parser = argparse.ArgumentParser()

parser.add_argument('file')  # 输入文件
parser.add_argument('-o', '--output')  # 输出文件
parser.add_argument('--width', type=int, default=80)  # 输出字符画宽
parser.add_argument('--height', type=int, default=80)  # 输出字符画高

# 获取参数
args = parser.parse_args()

IMG = args.file     # 所输入的文件名
WIDTH = args.width
HEIGHT = args.height
OUTPUT = args.output

ascii_char = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ")

# 将256灰度映射到70个字符上


def get_char(r, g, b, alpha=256):
    if alpha == 0:
        return ' '
    length = len(ascii_char)
    gray = int(0.2126 * r + 0.7152 * g + 0.0722 * b)

    unit = (256.0 + 1) / length     # 计算每个字符对应多少种颜色
    return ascii_char[int(gray / unit)]     # 定位表示该灰度值的字符


if __name__ == '__main__':

    im = Image.open(IMG)        # 打开图像文件
    im = im.resize((WIDTH, HEIGHT), Image.NEAREST)

    txt = ""

    for i in range(HEIGHT):
        for j in range(WIDTH):
            # getpixel()检索指定坐标的RGB颜色值
            txt += get_char(*im.getpixel((j, i)))
        txt += '\n'

    print txt

    # 字符画输出到文件
    if OUTPUT:
        with open(OUTPUT, 'w') as f:
            f.write(txt)
    else:
        with open("output.txt", 'w') as f:
            f.write(txt)
