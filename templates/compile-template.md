# C言語のコンパイル用テンプレート

## 1. コンパイル用テンプレート (基本形)
```bash
gcc -o program main.c
```
## 2. 複数のソースファイルをコンパイルする場合
```
gcc -o [出力ファイル名] [ソースファイル1.c] [ソースファイル2.c] [その他のソースファイル.c]
```

### 例: main.c、utils.c、helper.cをコンパイルしてprogramを生成する

```
gcc -o program main.c utils.c helper.c
```
## 1. 数学ライブラリをリンクしてコンパイル

もし、math.h を使って数学的な関数を利用する場合、以下のようにコンパイルします。
```
gcc -o program main.c -lm  # 正しくリンクして実行ファイルを作成
```
