from pypinyin import pinyin, Style


def convert_to_pinyin(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            names = file.readlines()

        pinyin_names = []
        for name in names:
            name = name.strip()
            pinyin_list = pinyin(name, style=Style.NORMAL)
            pinyin_name = ' '.join([p[0] for p in pinyin_list])
            pinyin_names.append(pinyin_name)

        with open(r'.\text_files\pinyin.txt', 'w', encoding='utf-8') as output_file:
            for pinyin_name in pinyin_names:
                output_file.write(pinyin_name + '\n')

        print("转换完成，结果已保存到 text_files/pinyin.txt 文件中。")
    except FileNotFoundError:
        print("错误: 文件未找到!")
    except Exception as e:
        print(f"错误: 发生了一个未知错误: {e}")


if __name__ == "__main__":
    file_path = r".\text_files\Chinese_name.txt"  # 请将此替换为你的实际文件路径
    convert_to_pinyin(file_path)
